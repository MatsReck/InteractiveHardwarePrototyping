
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

int ledPin = 12;  // the number of the LED pin

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  while (Serial.available() > 0) {                         // Take out strings until Serial is empty
    String receivedString = Serial.readStringUntil('\0');  // From 1.9.0 version, We can use '\0' as delimiter in Arduino Serial
    receivedData = getMessage(receivedString);
  }

  if (receivedData.message.equals("LED_ON")) {
    digitalWrite(ledPin, HIGH);
  }

  else if (receivedData.message.equals("LED_OFF")) {
    digitalWrite(ledPin, LOW);
  }
}
