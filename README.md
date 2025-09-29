# 🚀📡 Wireless-Morse-Code-Communication-System
### ✨⚙️  Features
- A peer-to-peer wireless communication system using Arduino Uno, </br>
- This project demonstrates encoding text into Morse code, </br>
- Transmitting it wirelessly, and decoding it back into human-readable form.
- NRF24L01 transceiver modules to transmit and receive Morse code messages.   
- It uses 2.4GHz global open ISM band, license-free in India.
- Range upto 1500 meters in line of sight with SMA Antenna.
- Display messages on a 16×2 LCD screen  
- Option to build circuit **with or without I2C module**  

##

### 📖 Introduction
Morse code is a communication method that uses short and long signals </br>
  - Different combination and sequence of dots `·` and dashes `–` to encode text in morse code.  </br> (space too for switching between words.) </br>
  - This project implements a **wireless Morse code communication system** using **NRF24L01** modules for transmission and reception, and a **16×2 LCD** to display messages.

##

###  🎥📷  Demo 
</br>

<div align="center">
  <img width="600" src="https://github.com/HimanshuChauragade/Wireless-Morse-Code-Communication-System/blob/86382435ac77e1a4fb18aa0ceb3adcf754e91416/Reference_Images/Demo.jpg" />  
  <p><i>Prototype showing wireless Morse code transmission</i></p>

<a href="https://youtube.com/shorts/c4RS-gCCu9A">
  <img src="https://img.youtube.com/vi/c4RS-gCCu9A/hqdefault.jpg" 
       alt="Watch the video" 
       width="600"/>
</a>


  <img width="600" src="https://github.com/HimanshuChauragade/Wireless-Morse-Code-Communication-System/blob/86382435ac77e1a4fb18aa0ceb3adcf754e91416/Reference_Images/AS.jpeg" />  
  <p><i>System in action with LCD display</i></p>
</div>

##

### 🔧🔌 Hardware Used

<div align="center">

| Component                                     | Description                                |
|-----------------------------------------------|--------------------------------------------|
| **Arduino Uno (ATmega328P)**                  | Microcontroller board                      |
| **NRF24L01 2.4 GHz Transceiver Modules (x2)** | Wireless radio communication modules       |
| **16×2 LCD Display (HD44780)**                | Character LCD display                      |
| **I2C Serial Interface Adapter Module (PCF8574)** | Enables I2C communication with LCD     |
| **Push Buttons**                              | User input controls                        |
| **Miscellaneous Components**                  | Resistors, breadboard, jumper wires, etc.  |

</div>

##

### 📦📚 Libraries Used
<div align="center">
  
| Library                      | Purpose                             |
|------------------------------|-------------------------------------|
| `#include <LiquidCrystal.h>` | For LCD display                     |
| `#include <SPI.h>`           | For SPI communication               |
| `#include <avr/wdt.h>`       | Watchdog Timer library              |
| `#include <RF24.h>`          | For NRF24L01 wireless communication |
| `#include <nRF24L01.h>`      | For NRF24L01 wireless communication |

</div>

##

### 📐📊 Circuit Options Comparison
<div align="center">
  
| Option                  | Description                                                                                                |
|-------------------------|------------------------------------------------------------------------------------------------------------|
| **With I2C Module**     | - Simplifies the circuit design <br> - More beginner-friendly <br> - Frees up I/O ports for other uses     |
| **Without I2C Module**  | - Adds complexity to the circuit <br> - Consumes additional I/O pins <br> - Attempt with prior experience. |

</div>

### ⚙️ Circuit With I2C Module
<div align="center">
  <img width="600" src="https://github.com/user-attachments/assets/8af8039a-6693-4ba1-af66-8036a8560465" /> </br>
</div>

<div align="center">
  <img width="600" src="https://github.com/user-attachments/assets/02c909f3-f440-43bd-9ec4-8b776813b809" /> </br>
</div>

##

### ⚙️ Circuit Without I2C Module
<div align="center">
  <img width="600" src="https://github.com/user-attachments/assets/19b03607-b11f-40f9-a3b7-f9d050a86c02" /> </br>
</div>

<div align="center">
  <img width="600" src="https://github.com/user-attachments/assets/8a280b44-5ade-4f2b-bb15-6e0f181de8b4" /> </br>
</div>

##

### 🔮🌱 Future Improvements
- Make a 3D printed portable version with rechargable Li-Polymer battery
- Add buzzer/vibration feedback for Morse input  
- Add support for mesh (multi-node) communication (multiple devices)  
- Implement error-checking for more reliable transmission  


## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Fork the repository**
2. **Create a feature branch**: `git checkout -b feature/amazing-feature`
3. **Commit your changes**: `git commit -m 'Add amazing feature'`
4. **Push to the branch**: `git push origin feature/amazing-feature`
5. **Open a Pull Request**

### 🙌 Development Guidelines

- Follow Arduino coding best practices  
- Keep circuit diagrams clear and well-documented  
- Use meaningful and descriptive commit messages  

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **Arduino** community for open-source hardware & libraries  
- **nRF24L01 & rf24** for the NRF24L01 library support
- **HD44780 & PCF8574** documentation for LCD interfacing  
- **Open-source contributors** for inspiration and resources  
- **Electronics hobbyist forums** for troubleshooting help  

## 📞 Contact

- **GitHub**: [@HimanshuChauragade](https://github.com/HimanshuChauragade)
- **LinkedIn**: [Himanshu Chauragade](https://linkedin.com/in/himanshu-chauragade/)
- **Email**: 2024000129@mssu.ac.in

##

⭐ **Star this repository if you found it helpful!**
