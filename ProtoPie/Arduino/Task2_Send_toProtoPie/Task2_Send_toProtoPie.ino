
//Variables
int ledPin = 12;  // the number of the LED pin
int potiPin = A2;
int sensorwert = 0;

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(potiPin, INPUT);
  // initialize the LED pin as an output
  // Setup Serial Monitor
}

void loop() {

  //Send something to ProtoPie Connect
  sensorwert = analogRead(potiPin);
  sensorwert = map(sensorwert, 0, 1023, 0, 100);
  Serial.print("opacityvalue||");
  Serial.println(sensorwert);


  delay(5);
}
