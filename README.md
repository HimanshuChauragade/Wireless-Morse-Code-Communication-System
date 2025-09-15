# Wireless-Morse-Code-Communication-System
A peer-to-peer wireless communication system using Arduino Uno, </br>
NRF24L01 transceiver modules to transmit and receive Morse code messages.   
This project demonstrates encoding text into Morse code, </br>
transmitting it wirelessly, and decoding it back into human-readable form.

---

🔹 Introduction
Morse code is a communication method that uses short and long signals (dots `·` and dashes `–`) to encode text.  
This project implements a **wireless Morse code communication system** using **NRF24L01** modules for transmission and reception, and a **16×2 LCD** to display messages.

---

🔹 Demo
<div align="center">
  <img width="600" src="https://github.com/HimanshuChauragade/Wireless-Morse-Code-Communication-System/blob/86382435ac77e1a4fb18aa0ceb3adcf754e91416/Reference_Images/Demo.jpg" /> </br>
  
  <img width="600" src="https://github.com/HimanshuChauragade/Wireless-Morse-Code-Communication-System/blob/86382435ac77e1a4fb18aa0ceb3adcf754e91416/Reference_Images/AS.jpeg" /> </br>
</div>

---

🔹 Hardware Used
- Arduino Uno (ATmega328P)
- NRF24L01 2.4 GHz Transceiver Modules (x2)
- 16×2 LCD Display (HD44780)
- I2C Serial Interface Adapter Module (PCF8574)
- Push Buttons
- Miscellaneous components (resistors, breadboard, jumper wires, etc.)

---

🔹 Libraries
This project uses the following Arduino libraries:
- #include <LiquidCrystal.h>   // For LCD display
- #include <SPI.h>             // For SPI communication
- #include <avr/wdt.h>         // Watchdog Timer library
- #include <RF24.h>            
- #include <nRF24L01.h>        // For NRF24L01 wireless communication

---


🔹 Circuit Diagram without I2C</br>
<div align="center">
  <img width="600" src="https://github.com/user-attachments/assets/19b03607-b11f-40f9-a3b7-f9d050a86c02" /> </br>
</div>

<div align="center">
  <img width="600" src="https://github.com/user-attachments/assets/8a280b44-5ade-4f2b-bb15-6e0f181de8b4" /> </br>
</div>

---

🔹 Circuit Diagram with I2C </br>
<div align="center">
  <img width="600" src="https://github.com/user-attachments/assets/8af8039a-6693-4ba1-af66-8036a8560465" /> </br>
</div>

<div align="center">
  <img width="600" src="https://github.com/user-attachments/assets/02c909f3-f440-43bd-9ec4-8b776813b809" /> </br>
</div>

---

