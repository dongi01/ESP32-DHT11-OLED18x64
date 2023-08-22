# ESP32-DHT11-OLED18x64
Simple thermometer controlled by an ESP32 using a DHT11 sensor and a 128x64 px OLED screen

# Hardware
* ESP32 (ESP-WROOM-32)
* DHT11 sensor
* 128x64 monochrome OLED screen
* jumper wires
* breadboard

# Circuit Schematic
We will use a breadboard for the circuit because the ESP32-WROOM-32 has only one 3.3V pin.

Do the following connections:
* ESP 3V3, DHT VCC and screen VDD pins to the line marcked with a + sign on the breadboard.
* GND pin of the 3 component to the line marked with a - sign on the breadboard.
* DHT11 DATA pin to ESP GPIO4 pin
* screen SCK pin to ESP GPIO22 pin
* screen SDA pin to ESP GPIO21 pin

# Software
You need to install a couple of libraries. Search for them in the Arduino IDE's board and library manager and install them.
### Board manager
* esp32
### Library manager
* DHT_sensor_library
* Adafruit_GFX
* Adafruit_SSD1306

# Load the program
1. download the file in the repository
2. in Arduino IDE select tools -> board -> ESP32 Boards -> Generic ESP32 Module
3. push the load botton in the top left corner of the app

# Note
An ESP32 is absolutely overkill for this project. I used it to create a very simple temporary thermometer, and that was the only available board I had.
