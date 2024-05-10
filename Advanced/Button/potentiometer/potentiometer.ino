
// INPUT: Potentiometer should be connected to 5V and GND
int potPin = A3; // Potentiometer output connected to analog pin 3
int potVal = 0; // Variable to store the input from the potentiometer


void setup() {
  pinMode(potPin, InPUT);   // sets the pin as input
  Serial.begin(9600);
}

// Main program
void loop(){
  potVal = analogRead(potPin);   // read the potentiometer value at the input pin
  Serial.println(potval);
  delay(200);
}