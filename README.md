# DS1307-LIBRARY
This project provides an Arduino-style C++ library for interfacing the DS1307 RTC (Real-Time Clock) module with the Raspberry Pi Pico using the Pico SDK. The DS1307 uses the I2C protocol to keep track of time (hours, minutes, seconds) and calendar (day, month, year) even when the main power is disconnected, using a backup coin-cell battery.
# DS1307 RTC Library for Raspberry Pi Pico

This project provides an Arduino-style C++ library for the DS1307 Real-Time Clock module, designed to work with the Raspberry Pi Pico using the Pico SDK.

## Features
- I2C communication with DS1307 (address 0x68)
- Functions to set and get current time (hours, minutes, seconds)
- Uses GPIO 0 (SDA) and GPIO 1 (SCL) for I2C
- Outputs time data to UART serial monitor every second

## Usage
1. Connect DS1307 to Pico as follows:
   - SDA to GPIO0
   - SCL to GPIO1
   - VCC to 5V
   - GND to GND
2. Build and flash the project:
mkdir build
cd build
cmake ..
make
3. Copy the generated `.uf2` file to the Pico device.
4. Open serial monitor at 115200 baud to see time updates.

## License
MIT License
