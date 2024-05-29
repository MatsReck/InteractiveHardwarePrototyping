/* ==================================================
----------- To get a Message From ProtoPie ---------
====================================================*/
// DO NOT CHANGE THIS - Just Copy & Paste it

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

/*====================================================*/


void setup() {
  // Initialize the Serial Connection
  Serial.begin(9600);
}

void loop() {

  // To read a message from ProtoPie
  while (Serial.available() > 0) {
    String receivedString = Serial.readStringUntil('\0');
    receivedData = getMessage(receivedString);
  }
  // Here is your received Data from ProtoPie
  String receivced_key = receivedData.message;
  int receivced_value = receivedData.value.toInt();

  

  // To send something to ProtoPie
  String send_key = "Helligkeit";
  int send_value = 200;
  Serial.println(String(send_key) + String(send_value));

  // Good-to-have
  delay(5);
}
