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
- Button (optional) connected to GPIO 14

## Libraries Required
- IRremote: To send and receive IR signals.
- WiFi: For Wi-Fi connectivity.
- WebServer: For running the web server.










## Usage
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

# License
This project is licensed under the MIT License - see the LICENSE file for details.

# Acknowledgments
- IRremote Library
- ESP32 WiFi Library
- ESP32 WebServer Library
#
Feel free to customize this README further according to your project's specific details and your preferences.
