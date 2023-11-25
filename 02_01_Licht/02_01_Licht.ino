  
  const int blueLED = 13; //Blaue LED an Pin 13
  const int redLED = 12; //Rote LED an Pin 12

  void setup() {
    pinMode(blueLED, OUTPUT);
    pinMode(redLED, OUTPUT);

    //LEDs vor Start aus
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, LOW);
  }

  void loop() {
    
    digitalWrite(blueLED, HIGH); //Blaue LED leuchtet 1 Sekunde
    digitalWrite(redLED, LOW); //Rote LED ist 1 Sekunde aus
    delay(1000);
    digitalWrite(blueLED, LOW); //Blaue LED ist 1 Sekunde aus
    digitalWrite(redLED, HIGH); //Rote LED leuchtet 1 Sekunde
    delay(1000);

  }



