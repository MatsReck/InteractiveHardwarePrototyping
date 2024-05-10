#include <Adafruit_NeoPixel.h>

#define PIN            6  // Define the pin where the data line is connected
#define NUMPIXELS      16 // Number of LEDs in the NeoPixel ring

Adafruit_NeoPixel ring = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  ring.begin(); // Initialize the ring
  ring.show();  // Initialize all pixels to 'off'
  ring.setBrightness(200);
}

void loop() {
  uint16_t hue = 200; // Hue value for color (scale 0-65535)
  uint8_t saturation = 255; // Saturation (0-255), 255 for full color
  breathe(hue, saturation, 255, 50); // Call breathe function with color, max brightness and a delay
}

// Function to create the breathing effect with color control
void breathe(uint16_t hue, uint8_t saturation, uint8_t maxBrightness, int delayTime) {
  // Gradually increase brightness:
  for (int brightness = 0; brightness <= maxBrightness; brightness++) {
    setColor(ring.ColorHSV(hue, saturation, brightness)); // Set color with variable brightness
    ring.show();
    delay(delayTime);
  }
  // Gradually decrease brightness:
  for (int brightness = maxBrightness; brightness >= 0; brightness--) {
    setColor(ring.ColorHSV(hue, saturation, brightness));
    ring.show();
    delay(delayTime);
  }
}

// Helper function to set the color of all pixels
void setColor(uint32_t color) {
  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, color);
  }
}
