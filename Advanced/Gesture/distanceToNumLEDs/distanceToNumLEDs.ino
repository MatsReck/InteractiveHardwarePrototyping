#include <Adafruit_NeoPixel.h>
#include <HCSR04.h>

// NeoPixel setup
#define PIN            6  // Define the pin where the data line is connected
#define NUMPIXELS      16 // Number of LEDs in the NeoPixel ring
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Ultrasonic Sensor setup
int triggerPin = 13;
int echoPin = 12;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

// Define your color preference here (RGB)
int red = 50;
int green = 255;
int blue = 50;

// Define the range of distance for LED activation
int minDistance = 10;  // Minimum distance in cm
int maxDistance = 150; // Maximum distance in cm

void setup() {
  strip.begin(); // Initialize the strip
  strip.show();  // Initialize all pixels to 'off'
  Serial.begin(9600); // Initialize serial connection to print values from sensor
}

void loop() {
  float distance = distanceSensor.measureDistanceCm(); // Measure distance in centimeters
  int numLEDs = map((int)distance, minDistance, maxDistance, NUMPIXELS, 0); // Map distance to number of LEDs (more LEDs for closer objects)
  numLEDs = constrain(numLEDs, 0, NUMPIXELS); // Ensure the number of LEDs stays within the strip limits

  lightUpLEDs(numLEDs); // Light up the calculated number of LEDs
  
  Serial.println(distance); // Print distance
  delay(500); // Delay between measurements
}

// Function to light up a specific number of LEDs with a specified color
void lightUpLEDs(int numLEDs) {
  strip.clear(); // Clear all pixels
  uint32_t color = strip.Color(red, green, blue); // Set the color
  for (int i = 0; i < numLEDs; i++) {
    strip.setPixelColor(i, color); // Set each pixel up to numLEDs to the specified color
  }
  strip.show(); // Update the strip to new settings
}
