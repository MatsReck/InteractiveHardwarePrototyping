
  unsigned long duration;
  const int button_pin = 2;  //Taster an Pin 2 anschließen
  const int redLED = 13;     //Lampe an Pin 13 anschließen

  void setup() {
    pinMode(button_pin, INPUT);   //Setze Taster-Pin als Eingang
    pinMode(redLED, OUTPUT);      //Setze LED-Pin als Ausgang
  }

  void loop() {
    if(digitalRead(button_pin) == HIGH) {
      //Wenn der taster gedrückt wird, starte Schalte die Lampe ein
      blinken(5000);
    }
  }

  void blinken(unsigned long duration) {
    digitalWrite(redLED, HIGH);   //Schalte die Lampe ein
    delay(duration);              //Warte für angegebene Dauer
    digitalWrite(redLED, LOW);    //Schalte die Lampe aus
  }




