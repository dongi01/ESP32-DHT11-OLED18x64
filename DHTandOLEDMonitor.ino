#include "DHT.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET     -1 // Reset pin
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Decleration of DHT11 sensor
#define DHTTYPE DHT11   // define type of DHT sensor
#define DHT11_PIN 4     // define DHT11 data pin

DHT dht(DHT11_PIN, DHTTYPE);                

float temperature;
float humidity;

void setup()
{
  Serial.begin(9600);

  // start dht sensor
  dht.begin();
  
  // initialize the display object
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // display settings
  display.setTextSize(3);
  display.setTextColor(WHITE);
}

void loop() {

  temperature = dht.readTemperature(); // Gets the values of the temperature
  humidity = dht.readHumidity(); // Gets the values of the humidity 

  display.clearDisplay();
  display.setCursor(0,5);
  display.print(temperature, 1);
  display.println(" C");
  display.setCursor(0,37);
  display.print(humidity, 1);
  display.println(" %");
  display.display();
  delay(1000);
  
}
