#include <string.h>
#include <Servo.h>


// Declare struct
  struct MessageValue {
  String message;
  String value;
  };


// Declare function that parse message format
  struct MessageValue getMessage(String inputtedStr) {
  struct MessageValue result;

  char charArr[50];
  inputtedStr.toCharArray(charArr, 50);
  char* ptr = strtok(charArr, "||");
  result.message = String(ptr);
  ptr = strtok(NULL, "||");

  if (ptr == NULL) {
    result.value = String("");
    return result;
  }

  result.value = String(ptr);

  return result;
}

// Declare MessageValue struct's instance
struct MessageValue receivedData;


//Variables
const int ledPin = 16;    // the number of the LED pin
const int buttonPin = 12;  // the number of the pushbutton pin

int curButtonState = 0;
int lastButtonState = 0;
int counter = 0;


void setup() {

  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  // Setup Serial Monitor
  Serial.begin(9600);
}

void loop() {

  //Do something with recieved data from ProtoPie Connect
  while (Serial.available() > 0) { // Take out strings until Serial is empty
      String receivedString = Serial.readStringUntil('\0'); // From 1.9.0 version, We can use '\0' as delimiter in Arduino Serial
      receivedData = getMessage(receivedString);
    }

    if (receivedData.message.equals("LIGHT_ON")) {
      digitalWrite(ledPin, HIGH);
    }
    else if (receivedData.message.equals("LIGHT_OFF")) {
      digitalWrite(ledPin, LOW);
    }
  
  //Send something to ProtoPie Connect
  curButtonState = digitalRead(buttonPin);
  if (curButtonState != lastButtonState) { 
      lastButtonState = curButtonState;
    
  if (curButtonState == HIGH) {
    counter ++; 
    
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
