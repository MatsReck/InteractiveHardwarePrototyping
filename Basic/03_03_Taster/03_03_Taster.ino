
  const int buttonBlinken = 2;   //Taster an Pin 2 anschließen
  const int buttonLeuchten = 3;  //Taster an Pin 3 anschließen
  const int redLED = 13;         //Lampe an Pin 13 anschließen

  void setup() {
    pinMode(2, INPUT);     //Setze Taster-Pin als Eingang
    pinMode(3, INPUT);     //Setze Taster-Pin als Eingang
    pinMode(13, OUTPUT);   //Setze LED-Pin als Ausgang
  }

  void loop() {
    if(digitalRead(buttonBlinken) == HIGH) {
      blinken();
    }

    if(digitalRead(buttonLeuchten) == HIGH) {
      leuchten();
    }
  }

  void blinken() {
    for (int i = 0; i < 5; i++) {
    digitalWrite(redLED, HIGH);
    delay(500);
    digitalWrite(redLED, LOW);
    delay(500);
    }
  }

  void leuchten() {
    digitalWrite(redLED, HIGH);
    delay(5000);
    digitalWrite(redLED, LOW);
  }
    





