#include <string.h>

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


//define variables


void setup() {

  // initialize the LED pin as an output

}

void loop() {

  while (Serial.available() > 0) { // Take out strings until Serial is empty
      String receivedString = Serial.readStringUntil('\0');
      receivedData = getMessage(receivedString);
    }

  //Do something with recieved message from ProtoPie Connect
  
}
