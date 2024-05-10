#include <Adafruit_NeoPixel.h>

#define PIN            6  // Define the pin where the data line is connected
#define NUMPIXELS      16 // Number of LEDs in the NeoPixel ring

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); // Initialize the strip
  strip.show();  // Initialize all pixels to 'off'
}

void loop() {
  int red = 255;   // Maximum intensity of red
  int green = 0;   // No green
  int blue = 0;    // No blue
  runner(red, green, blue, 100); // Call the runner function with a 100 ms delay
}

// Function to create a simple runner effect
void runner(int red, int green, int blue, int delayTime) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.clear(); // Clear all pixels on each pass
    
    // Light up the current pixel:
    strip.setPixelColor(i, strip.Color(red, green, blue));
    
    strip.show();
    delay(delayTime);
  }
}
