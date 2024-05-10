#include <HCSR04.h>

int triggerPin = 13;
int echoPin = 12;

UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);  // Initialize sensor that uses digital pins 13 and 12.

void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    float distance = distanceSensor.measureDistanceCm()
    Serial.println(distance);
    delay(500);
}
