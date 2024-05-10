
  const int button_pin = 2;  //Taster an Pin 2 anschließen
  const int redLED = 10;     //Lampe an PWM Pin anschließen

  void setup() {
    pinMode(button_pin, INPUT);   //Setze Taster-Pin als Eingang
    pinMode(redLED, OUTPUT);      //Setze LED-Pin als Ausgang
  }

  void loop() {
    if(digitalRead(button_pin) == HIGH) {
      for (int helligkeit =1; helligkeit <= 255; helligkeit = helligkeit +5){
        analogWrite(redLED, helligkeit);
         delay(20);
      }
      for (int helligkeit =255; helligkeit >= 0; helligkeit = helligkeit -5){
        analogWrite(redLED, helligkeit);
       delay(20);
      }
    }
  }