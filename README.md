# Temperature Monitoring System with ESP32 and Python

![Temperature Monitoring](https://via.placeholder.com/800x200.png?text=Temperature+Monitoring+System)

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Requirements](#requirements)
  - [Hardware](#hardware)
  - [Software](#software)
- [Installation](#installation)
  - [Setting Up the ESP32](#setting-up-the-esp32)
  - [Setting Up the Python Script](#setting-up-the-python-script)
- [Usage](#usage)
- [Troubleshooting](#troubleshooting)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Overview

This project implements a **Temperature Monitoring System** that utilizes an **ESP32 microcontroller** and a **Python script** running on a PC. The system continuously monitors the CPU and GPU temperatures and displays them on a **LiquidCrystal_I2C** LCD connected to the ESP32. This setup is ideal for monitoring system health in real-time.

## Features

- **Real-time Temperature Monitoring**: Captures CPU and GPU temperatures using the Open Hardware Monitor.
- **Data Transmission**: Sends temperature data to the ESP32 over Wi-Fi for display.
- **LCD Display**: Visualizes CPU and GPU temperatures on a LiquidCrystal_I2C LCD screen.
- **Background Execution**: The Python script runs automatically in the background upon system startup.

## Requirements

### Hardware

- **ESP32** microcontroller
- **LiquidCrystal_I2C** LCD
- **Wi-Fi connection**
- A PC running Windows with Open Hardware Monitor installed

### Software

- **Python 3.x**
- Required Python libraries:
  - `wmi`
- **Arduino IDE** (for programming the ESP32)

## Installation

### Setting Up the ESP32

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the necessary libraries, including `LiquidCrystal_I2C`.
3. Open the provided Arduino code in the Arduino IDE.
4. Upload the code to the ESP32.

### Setting Up the Python Script

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/your-repo-name.git
   cd your-repo-name
   ```

2. Install the required Python libraries:
   ```bash
   pip install wmi
   ```

3. Modify the Python script:
   - Update the ESP32 IP address in the script (`send_data_to_esp` function).
   - Ensure that the Open Hardware Monitor is running on your PC.

4. Create a batch file (Windows) or shell script (Linux) to run the Python script automatically at startup.

   - **For Windows**: Create a `.bat` file with the following content:
     ```batch
     @echo off
     start /min pythonw.exe "C:\path\to\your_script.py"
     ```

   - **For Linux**: Create a shell script as follows:
     ```bash
     #!/bin/bash
     nohup python3 /path/to/your_script.py > /dev/null 2>&1 &
     ```

## Usage

1. Ensure the ESP32 is powered and connected to the Wi-Fi network.
2. Run the Python script on your PC.
3. The temperatures will be displayed on the LCD connected to the ESP32.

## Troubleshooting

- **Python Script Not Running**: Ensure Python is installed and added to your PATH.
- **LCD Not Displaying Temperatures**: Check the I2C connections and ensure the correct I2C address is set in the code.
- **Data Not Being Sent**: Ensure the ESP32 is connected to the same network as your PC and verify the IP address.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- [Open Hardware Monitor](http://openhardwaremonitor.org/) - For temperature monitoring.
- [LiquidCrystal_I2C Library](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) - For LCD control.
