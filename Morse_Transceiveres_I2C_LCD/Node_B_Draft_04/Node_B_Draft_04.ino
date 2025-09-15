#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

LiquidCrystal_I2C lcd(0x3f, 16, 2);

#define dashButtonPin A0
#define dotButtonPin A1
#define spaceButtonPin A2
#define backButtonPin 8
#define led 6

int ascii;
int val;
char character = "";
char assembly = "";
char temp = "";

RF24 radio(9, 10);  // CE, CSN
const byte addresses[][6] = { "00001", "00002" };
boolean buttonState = 0;

int dashButtonState = 1;
int dashButtonLastState = 1;
int dotButtonState = 1;
int dotButtonLastState = 1;
int spaceButtonState = 1;
int spaceButtonLastState = 1;
int backButtonState = 1;
int l = 0;

char la;

String tonesBuffer;
String text;
String expectedText;
String last;
String value;
int tex;


String symbolsAlphabet[][2] = {
  { ".-", "A" },
  { "-...", "B" },
  { "-.-.", "C" },
  { "-..", "D" },
  { ".", "E" },
  { "..-.", "F" },
  { "--.", "G" },
  { "....", "H" },
  { "..", "I" },
  { ".---", "J" },
  { "-.-", "K" },
  { ".-..", "L" },
  { "--", "M" },
  { "-.", "N" },
  { "---", "O" },
  { ".--.", "P" },
  { "--.-", "Q" },
  { ".-.", "R" },
  { "...", "S" },
  { "-", "T" },
  { "..-", "U" },
  { "...-", "V" },
  { ".--", "W" },
  { "-..-", "X" },
  { "-.--", "Y" },
  { "--..", "Z" },
  { ".----", "1" },
  { "..---", "2" },
  { "...--", "3" },
  { "....-", "4" },
  { ".....", "5" },
  { "-....", "6" },
  { "--...", "7" },
  { "---..", "8" },
  { "----.", "9" },
  { "-----", "0" }
};


char getInput() {

  if (!dashButtonState && dashButtonLastState)
    return '-';
  if (!dotButtonState && dotButtonLastState)
    return '.';
  if (!spaceButtonState && spaceButtonLastState)
    return ' ';

  return (char)0;
}


char getSymbolFromBuffer() {
  if (tonesBuffer == "")
    return ' ';

  for (int i = 0; i < sizeof symbolsAlphabet / sizeof symbolsAlphabet[0]; i++)
    if (tonesBuffer == symbolsAlphabet[i][0])
      return symbolsAlphabet[i][1][0];

  return (char)0;
}

void extractActionFromTonesBuffer() {
  if (tonesBuffer == "......") {
    text.remove(text.length() - 1, 1);
    ascii = 47;
  }

  if (tonesBuffer == "------")
    text = "";
}


void setup() {

  Serial.begin(9600);


  pinMode(dashButtonPin, INPUT_PULLUP);
  pinMode(dotButtonPin, INPUT_PULLUP);
  pinMode(spaceButtonPin, INPUT_PULLUP);
  pinMode(backButtonPin, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  radio.begin();
  radio.openWritingPipe(addresses[0]);     // 00001
  radio.openReadingPipe(1, addresses[1]);  // 00002
  radio.setPALevel(RF24_PA_MAX);

    lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Txt:");
  lcd.setCursor(0, 1);
  lcd.print("In : ");

}



char con(int asciiCode) {
  if (asciiCode >= 47 && asciiCode <= 90) {
    return (char)asciiCode;
  }
  if (asciiCode == 47) { 
    text.remove(text.length() - 1, 2);   
    value.remove(text.length() - 1, 2);
  }
  return '\0';
}

void backb() {
  if (backButtonState == 0) {
    backButtonState = digitalRead(backButtonPin);
    Serial.println(value);
    Serial.print("backButtonState: ");
    Serial.println(backButtonState);
    //rs(value);
    Serial.print("Updated text:  ");
    Serial.println(value);
    lcd.setCursor(0, 0);
    lcd.print(value);
    digitalWrite(led, 0);
    delay(250);
  }
}

void enee() {

  dashButtonState = digitalRead(dashButtonPin);
  dotButtonState = digitalRead(dotButtonPin);
  spaceButtonState = digitalRead(spaceButtonPin);
  backButtonState = digitalRead(backButtonPin);

  char tone = getInput();
  delay(15);

  if (tone != (char)0) {
    if (tone == ' ') {
      char symbol = getSymbolFromBuffer();
      ascii = (int)symbol;

      if (symbol != (char)0) {
        text += symbol;
        if (text.length() > 16) {
          text = (String)symbol;
        }
      } else {
        extractActionFromTonesBuffer();
      }
      tonesBuffer = "";
      radio.stopListening();
      delay(5);
      radio.write(&ascii, sizeof(ascii));
      delay(15);
      radio.startListening();
    } else {
      tonesBuffer += tone;
      if (tonesBuffer.length() > 10) {
        tonesBuffer = (String)tone;
      }
    }




  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Txt:");
  lcd.setCursor(5, 0);
  lcd.print(text);
  lcd.setCursor(0, 1);
  lcd.print("In: ");
  lcd.setCursor(5, 1);
  lcd.print(tonesBuffer);

    Serial.print("text:  ");
    Serial.println(text);
    Serial.print("tonesBuffer:  ");
    Serial.println(tonesBuffer);
  }

  dashButtonLastState = dashButtonState;
  dotButtonLastState = dotButtonState;
  spaceButtonLastState = spaceButtonState;
}


void loop() {
  backb();
  enee();
  delay(5);
  radio.startListening();
  if (radio.available()) {
    digitalWrite(led, 1);
    radio.read(&tex, sizeof(tex));
    if (tex == 47){
      text.remove(text.length() - 1, 2);
      value.remove(value.length() - 1, 2);
    }
    temp = con(tex);
    Serial.print("tex: ");
    Serial.println(tex);
    Serial.print("temp: ");
    Serial.println(temp);
    value += temp;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Txt:");
    lcd.setCursor(4, 0);
    lcd.print(value);
    Serial.print("text: ");
    Serial.println(value);
    delay(5);
  }
}