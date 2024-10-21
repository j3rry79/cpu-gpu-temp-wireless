# Temperature Monitoring System with ESP32 and Python

## Overview

This project consists of a temperature monitoring system that uses an ESP32 microcontroller and a Python script running on a PC. The system monitors CPU and GPU temperatures and displays them on a LiquidCrystal_I2C LCD connected to the ESP32.

## Features

- **Real-time Temperature Monitoring**: Continuously measures CPU and GPU temperatures using the Open Hardware Monitor library.
- **Data Transmission**: Sends temperature data to the ESP32 over Wi-Fi.
- **LCD Display**: Displays CPU and GPU temperatures on a LiquidCrystal_I2C LCD.
- **Background Execution**: The Python script runs automatically in the background on PC startup.

## Requirements

### Hardware

- ESP32 microcontroller
- LiquidCrystal_I2C LCD
- Wi-Fi connection

### Software

- Python 3.x
- Required Python libraries:
  - `wmi` (for Windows)
- Arduino IDE (for ESP32 programming)

## Installation

### Setting Up the ESP32

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the necessary libraries for the ESP32, including `LiquidCrystal_I2C`.
3. Upload the provided Arduino code to the ESP32 using the Arduino IDE.

### Setting Up the Python Script

1. Clone this repository:
   ```bash
   git clone https://github.com/j3rry79/cpu-gpu-temp-wireless.git
   cd cpu-gpu-temp-wireless
