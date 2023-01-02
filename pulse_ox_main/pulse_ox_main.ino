#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> // OLED libraries

#include <DFRobot_MAX30102.h> //MAX30102 library

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_ADDR   0x3C //OLED adress

DFRobot_MAX30102 particleSensor; //define particle sensor

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); //initialize display

void setup()
{
    //Set Pin 13 to output 5V
    pinMode(13,HIGH);
    digitalWrite(13,HIGH);
    Serial.begin(115200);
    //begin display
    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) { // Address 0x3D for 128x64
      Serial.println(F("SSD1306 allocation failed"));
      for(;;);
    }
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(4,20);
    display.print("Tuning...");
    Serial.print("Init");
    display.display();
    delay(100);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);

    //check to see if MAX30102 is properly connected
    while (!particleSensor.begin()) {
      display.display();
      display.setTextSize(1);
      Serial.println("MAX30102 not found");
      delay(1000);
      display.display();
    }
    
    //configure particle sensor
    particleSensor.sensorConfiguration(/*ledBrightness=*/50, /*sampleAverage=*/SAMPLEAVG_4, \
                        /*ledMode=*/MODE_MULTILED, /*sampleRate=*/SAMPLERATE_100, \
                        /*pulseWidth=*/PULSEWIDTH_411, /*adcRange=*/ADCRANGE_16384);
}

int32_t SPO2; //SPO2
int8_t SPO2Valid; //Flag to display if SPO2 calculation is valid
int32_t heartRate; //Heart-rate
int8_t heartRateValid; //Flag to display if heart-rate calculation is valid 

void loop()
{
    //calculate heart-rate and oxygen saturation
    particleSensor.heartrateAndOxygenSaturation(/**SPO2=*/&SPO2, /**SPO2Valid=*/&SPO2Valid, /**heartRate=*/&heartRate, /**heartRateValid=*/&heartRateValid);
    //check both heart-rate and oxygen saturation are valid
    if (heartRateValid == 1 && SPO2Valid == 1) {
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("BPM:");
      display.println(heartRate);
      display.setCursor(0, 20);
      display.print("SpO2:");
      display.print(SPO2);
      display.println("%");  
      display.display();
      delay(500);
      display.clearDisplay();
    }
    else {
      display.setCursor(35,0);
      display.print("Hold");
      display.setCursor(4,20);
      display.print("Finger on");
      display.setCursor(25,40);
      display.print("Sensor");
      display.display();
      delay(500);
    }
}
