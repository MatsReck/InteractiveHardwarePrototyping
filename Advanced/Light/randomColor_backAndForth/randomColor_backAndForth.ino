#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 60

// Declare our NeoPixel ring object:
Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  ring.begin();           // INITIALIZE NeoPixel ring object (REQUIRED)
  ring.show();            // Turn OFF all pixels ASAP
  ring.setBrightness(50); 
}

void loop() {
  for(int i = 0; i < ring.numPixels(); i++){
    ring.setPixelColor(i, random(255), random(255), random(255));
    ring.show();
    delay(50);
  }
  for(int i = ring.numPixels()-1; i >= 0; i--){
    ring.setPixelColor(i, 0, 0, 0);
    ring.show();
    delay(50);
  }
}