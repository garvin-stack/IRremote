# ESP32 IR Remote Control Web Server
This project sets up an ESP32 microcontroller as a web server that allows you to control an IR device (e.g., a TV) through a web interface. The ESP32 creates a Wi-Fi access point and provides a web page with buttons for toggling power, increasing/decreasing volume, and muting the device.

## Features
- Wi-Fi Access Point: The ESP32 sets up a Wi-Fi access point.
- Web Server: A web server running on the ESP32 serves an HTML page with control buttons.
- IR Remote Control: Control an IR device using buttons on the web page.

## Hardware Required
- ESP32 development board
- IR receiver connected to GPIO 26
- IR transmitter connected to GPIO 33

## Libraries Required
- IRremote: To send and receive IR signals.
- WiFi: For Wi-Fi connectivity.
- WebServer: For running the web server.

## Setup
1. Find appropriate USB to UART driver(CP210x/CH340) that corresponds to your ESP32.
- Install visual studio code
- Go to extensions on visual studio code, download PlatformIO IDE and C/C++
- Open PlatformIO IDE(click on the icon on the side) and create a project
- Select Board: Expressif ESP32 Dev Module and Framework: Arduino
- Go to PlatformIO IDE Libraries and add IRremote project by Armin Joachimsmeyer
- In the platform.ini file type in
```sh
monitor_speed = 115200
```
- Git clone this repository
- Delete the old src file and move src folder out of IRremote folder from repository
- Go into workspace and run >Tasks: Run Build Task and select PlatformIO: Build filename
- Now run >PlatformIO: Upload and follow with >PlatformIo: Serial Monitor

## Usage
### Receive
- Send signal from remote to receiver
- Copy the code from serial monitor that corresponds to it and edit the code
### Transmit
- Power up the ESP32: Once the code is uploaded, the ESP32 will create a Wi-Fi access point with the SSID ESP32_AP5555 and password 123456789.
- Connect to the Wi-Fi network: On your computer or mobile device, connect to the Wi-Fi network created by the ESP32.
- Open the web page: Open a web browser and navigate to http://192.168.1.1. You should see a web page with buttons to control the IR device.
## Web Interface
- Toggle Power: Sends an IR command to toggle the power of the device.
- Volume Up: Sends an IR command to increase the volume.
- Volume Down: Sends an IR command to decrease the volume.
- Mute: Sends an IR command to mute the device.
# Code Overview
## Functions
- setup(): Initializes the serial communication, IR receiver, IR sender, GPIO pins, Wi-Fi access point, and web server routes.
- loop(): Handles incoming web server requests and decodes IR signals.
- handler(): Serves the main web page.
- togglePower(), volUp(), volDown(), mute(): Send corresponding IR commands.
- handle_NotFound(): Handles undefined routes.
- decoder(): Decodes received IR signals and prints them to the serial monitor.
## HTML Interface
- The getHTML() function generates the HTML code for the web page, which includes buttons for controlling the IR device.
## Troubleshooting
- A fatal error occurred: Packet content transfer stopped (received 8 bytes).
-- Avoid gpio pins 12 and 13
- Failed to connect to ESP32: Wrong boot mode detected (0x13)
-- Press boot button on ESP32 when uploading
# License
This project is licensed under the MIT License - see the LICENSE file for details.

# Acknowledgments
- IRremote Library
- ESP32 WiFi Library
- ESP32 WebServer Library
#
Feel free to customize this README further according to your project's specific details and your preferences.
