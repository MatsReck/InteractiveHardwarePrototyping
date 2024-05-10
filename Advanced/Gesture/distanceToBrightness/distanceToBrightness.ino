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
int green = 100;
int blue = 50;

void setup() {
  ring.begin(); // Initialize the ring
  ring.show();  // Initialize all pixels to 'off'
  Serial.begin(9600); // Initialize serial connection to print values from sensor
}

void loop() {
  float distance = distanceSensor.measureDistanceCm(); // Measure distance in centimeters
  int brightness = map((int)distance, 0, 200, 0, 255); // Map distance to brightness values (0-255)
  brightness = constrain(brightness, 0, 255); // Ensure brightness stays within bounds

  setBrightness(brightness); // Set brightness of all LEDs based on distance
  
  Serial.println(distance); // Print distance
  delay(500); // Delay between measurements
}

// Function to set the brightness of all pixels with a specified color
void setBrightness(int brightness) {
  uint32_t color = ring.Color(red * brightness / 255, green * brightness / 255, blue * brightness / 255); // Scale color components based on brightness
  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, color); // Set each pixel to the calculated color
  }
  ring.show(); // Update the ring to new settings
}
