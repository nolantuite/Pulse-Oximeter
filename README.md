# Pulse Oximeter

This project uses an Arduino Mega, OLED display (SSD1306), and a MAX30102 sensor to measure and display a person's heart rate and oxygen saturation (SpO2) levels.

![](main.gif)

## Hardware Requirements
- Arduino Mega
- OLED Display (SSD1306)
- MAX30102 Sensor
- 4 Male-to-Female Wires 

## Software Dependencies
- Arduino IDE
- OLED display library (can be downloaded through the Arduino IDE's library manager)
- DFRobot MAX30102 library (can be found [here](https://github.com/DFRobot/DFRobot_MAX30102))

## Setup
1. Connect the OLED display to the Arduino Mega according to the following pin mapping:
  - OLED SDA -> Mega SDA1
  - OLED SCL -> Mega SCL1
  - OLED VCC -> Mega 5V
  - OLED GND -> Mega GND
2. Connect the MAX30102 sensor to the Arduino Mega according to the following pin mapping:
  - MAX30102 SDA -> Mega SDA
  - MAX30102 SCL -> Mega SCL
  - MAX30102 VCC -> Mega 5V
  - MAX30102 GND -> Mega GND
3. Download the required libraries and open the code in the Arduino IDE.
4. Modify the `setup()` function to initialize the OLED display and MAX30102 sensor.
5. Modify the `loop()` function to read heart rate and oxygen saturation data from the MAX30102 sensor and display it on the OLED display.

## Usage
After wiring according to ECAD, upload modified code to the Arduino Mega. Place middle finger of dominant hand on MAX30102 sensor and see heart rate and oxygen saturation readings on OLED.

## Notes
- Make sure to calibrate the sensor according to the manufacturer's instructions before use.
- The OLED display may require a different pin mapping depending on the specific model being used. Check the documentation for your OLED display for the correct pin mapping.
