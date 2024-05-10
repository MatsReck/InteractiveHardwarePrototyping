#include <Adafruit_NeoPixel.h>

#define PIN            6  // Define the pin where the data line is connected
#define NUMPIXELS      16 // Number of LEDs in the NeoPixel ring

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


  uint16_t hue = 100; // Hue value for color (scale 0-65535)
  int cometSize = 5; // Size of the comet
  int cometSpeed = 50; // Delay in milliseconds to control speed
  int cometFade = 64; // Larger value for faster fading

void setup() {
  strip.begin(); // Initialize the strip
  strip.show();  // Initialize all pixels to 'off'
}


void loop() {
  drawComet(cometSize, cometSpeed, hue, cometFade);
}

// Function to draw the comet effect with color and fade control
void drawComet(int size, int speed, uint16_t hue, int fade) {
  for (int i = 0; i < strip.numPixels() + size; i++) {
    strip.clear(); // Clear all LEDs

    // Draw the comet:
    for (int j = 0; j < size; j++) {
      int pos = i - j;
      if (pos < 0 || pos >= strip.numPixels()) continue; // Bounds check for comet head

      // Calculate brightness with fade effect:
      int brightness = map(j, 0, size, 255, 0) / fade; // Apply fading factor
      
      // Set color using HSV:
      uint32_t color = strip.ColorHSV(hue, 255, brightness); // Full saturation, variable brightness
      strip.setPixelColor(pos, color);
    }

    strip.show();
    delay(speed); // Controls the speed of the comet
  }
}