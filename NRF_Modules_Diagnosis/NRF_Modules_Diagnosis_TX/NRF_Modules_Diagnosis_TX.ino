#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <avr/wdt.h>  // Watchdog Timer library

#define CE_PIN 9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";
const int maxRetries = 10;

void setup() {
    Serial.begin(9600);
    if (!radio.begin()) {
        Serial.println("❌ NRF24L01 not detected! Check wiring.");
        while (1);
    } else{
        Serial.println("✅ NRF24L01 detected");
    }
    connectNRF();
}

bool retrySend(int data) {
    for (int attempt = 0; attempt < maxRetries; attempt++) {
        if (radio.write(&data, sizeof(data))) {
            return true;
        }
        Serial.print("❌ Retry ");
        Serial.print(attempt + 1);
        Serial.println(" failed!  ");
        delay(70);
        connectNRF();
    }
    return false;
}

int data = 0;
void loop() {
    data += 1;
    Serial.print("📤 Sending: ");
    Serial.print(data);

    if (!retrySend(data)) {
        Serial.print(" | ❌ Send failed after multiple retries! ");
        connectNRF();
    } else {
        Serial.print(" | ✅ Send successful! ");
    }

    // Print the current TX power level to monitor signal strength
    int txPower = radio.getPALevel();
    Serial.print(" | 📡 TX Power Level: ");
    switch (txPower) {
        case RF24_PA_MIN:
            Serial.print("Low Power ");
            break;
        case RF24_PA_LOW:
            Serial.print("Medium Power ");
            break;
        case RF24_PA_HIGH:
            Serial.print("High Power ");
            break;
        case RF24_PA_MAX:
            Serial.print("Max Power ");
            break;
    }

    // Monitor RSSI value from receiver (received in Ack Payload)
    if (radio.available()) {
        int receivedRSSI = 0;
        radio.read(&receivedRSSI, sizeof(receivedRSSI));  // Read RSSI value sent by receiver
        Serial.print(" | 📡 Received RSSI: ");
        Serial.print(receivedRSSI);
    }

    // Reset the watchdog timer before the timeout
    wdt_reset();  // This resets the WDT counter (prevents reset)

    Serial.println();  // Move to a new line for the next loop
    delay(100);  // Wait for the next transmission
}

void connectNRF(){
    radio.setChannel(125);               // **Most rare communication channel**
    radio.setPALevel(RF24_PA_MAX);       // Max transmit power
    radio.setDataRate(RF24_250KBPS);     
    radio.setCRCLength(RF24_CRC_16);     
    radio.enableAckPayload();
    radio.enableDynamicPayloads();
    radio.setAutoAck(true);
    radio.setRetries(10, 15);
    radio.openWritingPipe(address);
    radio.stopListening();

    // Set Watchdog Timer (8 seconds)
    wdt_enable(WDTO_4S);  // Set WDT timeout to 8 seconds
}
