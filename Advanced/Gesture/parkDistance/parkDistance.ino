#include <Adafruit_NeoPixel.h>
#include <HCSR04.h>

// NeoPixel setup
#define PIN            6  // Define the pin where the data line is connected
#define NUMPIXELS      16 // Number of LEDs in the NeoPixel ring
Adafruit_NeoPixel ring = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Ultrasonic Sensor setup
int triggerPin = 13;
int echoPin = 12;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

// Define your color preference here (RGB)
int red = 255;
int green = 0;
int blue = 0;

// Define the range of distance for LED activation
int minDistance = 10;  // Minimum distance in cm
int maxDistance = 150; // Maximum distance in cm

// Variables to manage blink timing
unsigned long previousMillis = 0; // Stores last time LEDs were updated
bool ledsOn = false; // LED state tracking

void setup() {
  ring.begin(); // Initialize the ring
  ring.show();  // Initialize all pixels to 'off'
  Serial.begin(9600); // Initialize serial connection to print values from sensor
}

void loop() {
  float distance = distanceSensor.measureDistanceCm(); // Measure distance
  int numLEDs = map((int)distance, minDistance, maxDistance, NUMPIXELS, 0); // Map distance to LED count
  numLEDs = constrain(numLEDs, 0, NUMPIXELS); // Constrain LED count

  int blinkDelay = map((int)distance, minDistance, maxDistance, 50, 500); // Map distance to blink speed
  blinkDelay = constrain(blinkDelay, 50, 500); // Constrain blink speed

  unsigned long currentMillis = millis();

  // Blink LEDs without blocking
  if (currentMillis - previousMillis >= blinkDelay) {
    previousMillis = currentMillis; // Save the last time you blinked the LEDs
    if (ledsOn) {
      ring.clear(); // Turn LEDs off
      ledsOn = false;
    } else {
      lightUpLEDs(numLEDs); // Turn LEDs on
      ledsOn = true;
    }
  }
  
  Serial.print("Distance: ");
  Serial.println(distance); // Print distance
  delay(50); //some buffer to measure distance
}

// Function to light up a specific number of LEDs
void lightUpLEDs(int numLEDs) {
  ring.clear(); // Clear all pixels
  uint32_t color = ring.Color(red, green, blue);
  for (int i = 0; i < numLEDs; i++) {
    ring.setPixelColor(i, color); // Set color
  }
  ring.show(); // Update the ring
}
