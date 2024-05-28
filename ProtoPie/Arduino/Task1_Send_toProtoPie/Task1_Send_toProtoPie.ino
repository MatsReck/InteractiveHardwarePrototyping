//Variables
int buttonPin = 12;  // the number of the pushbutton pin

// variables will change:
int curButtonState = 0;  // variable for reading the pushbutton status
int lastButtonState = 0;
int counter = 0;


void setup() {

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
}

void loop() {

  //Send something to ProtoPie Connect
  if (curButtonState != lastButtonState) {
    lastButtonState = curButtonState;

    if (curButtonState == HIGH) {
      counter++;

      if (counter == 1) {
        Serial.println("Display_ON");
      }

      if (counter == 2) {
        counter = 0;
        Serial.println("Display_OFF");
      }
    }
  }
}