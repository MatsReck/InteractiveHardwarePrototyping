
  const int button_pin = 2;  //Taster an Pin 2 anschließen
  const int redLED = 13;     //Lampe an Pin 13 anschließen

  void setup() {
    pinMode(button_pin, INPUT);   //Setze Taster-Pin als Eingang
    pinMode(redLED, OUTPUT);      //Setze LED-Pin als Ausgang
  }

  void loop() {
    if(digitalRead(button_pin) == HIGH) {
      blinken(); 
    }
  }

  void blinken() {
    digitalWrite(redLED, HIGH);   //Schalte die Lampe ein
    delay(random(500,5000));      //Zufällige Zeit zwischen 0,5 und 5 Sekunden
    digitalWrite(redLED, LOW);    //Schalte die Lampe aus
  }




