
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
int PIN = 6;  // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
int NUMPIXELS = 16;  // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int DELAYVAL = 500;  // Time (in milliseconds) to pause between pixels

void setup() {
  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();
}

void loop() {
  pixels.clear();  // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for (int i = 0; i < NUMPIXELS; i++) {  // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));

    pixels.show();  // Send the updated pixel colors to the hardware.

    delay(DELAYVAL);  // Pause before next pass through loop
  }
}
