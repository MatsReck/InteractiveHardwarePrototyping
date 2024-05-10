  
  const int button_pin = 2;  //Taster an Pin 2 anschließen
  const int redLED = 13;     //Lampe an Pin 13 anschließen

  void setup() {
    pinMode(button_pin, INPUT);   //Setze Taster-Pin als Eingang
    pinMode(redLED, OUTPUT);      //Setze LED-Pin als Ausgang
  }

  void loop() {
    if(digitalRead(button_pin) == HIGH) {
      //Wenn der taster gedrückt wird, ...
      digitalWrite(redLED, HIGH);
      //...schalte die Lampe ein.
    }

    if(digitalRead(button_pin) == LOW) {
      //Wenn der taster gedrückt wird, ...
      digitalWrite(redLED, LOW);
      //...schalte die Lampe ein.
    }
  }
