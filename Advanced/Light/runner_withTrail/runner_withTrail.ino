#include <Adafruit_NeoPixel.h>

#define PIN            6  // Define the pin where the data line is connected
#define NUMPIXELS      16 // Number of LEDs in the NeoPixel ring

Adafruit_NeoPixel ring = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  ring.begin(); // Initialize the ring
  ring.show();  // Initialize all pixels to 'off'
}

void loop() {
  int red = 255;   // Red color maximum
  int green = 0;   // Green color zero
  int blue = 0;    // Blue color zero
  int trailLength = 3; // Length of the trail behind the main LED
  runner(red, green, blue, trailLength, 100); // Call the runner function
}

// Function to create a runner effect with a trailing color fade
void runner(int red, int green, int blue, int trailLength, int delayTime) {
  for (int i = 0; i < ring.numPixels(); i++) {
    ring.clear(); // Clear all pixels on each pass

    // Light up the main pixel:
    ring.setPixelColor(i, ring.Color(red, green, blue));

    // Create a trail with decreasing intensity:
    for (int j = 1; j <= trailLength; j++) {
      int index = i - j;
      if (index < 0) index += ring.numPixels(); // Wrap around the ring

      // Calculate the faded color:
      int fadeFactor = pow(2, j); // Exponential fade
      ring.setPixelColor(index, ring.Color(red / fadeFactor, green / fadeFactor, blue / fadeFactor));
    }

    ring.show();
    delay(delayTime);
  }
}
