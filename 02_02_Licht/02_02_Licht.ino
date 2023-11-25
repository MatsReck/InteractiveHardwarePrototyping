

  const int redLED = 13;         //Rote LED an Pin 13
  const int yellowLED = 12;      //Gelbe LED an Pin 12
  const int greenLED = 11;       //Grüne LED an Pin 11

  void setup() {
    pinMode(13, OUTPUT);        //rot   
    pinMode(12, OUTPUT);        //gelb
    pinMode(11, OUTPUT);        //grün
  }

  void loop() {
    //Phase 1: Rotes Licht
    redLight();
    delay(1500);    

    //Phase 2: Gelbes und rotes Licht
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    delay(700); 

    //Phase 3: Grünes Licht
    greenLight();
    delay(1500); 

    //Phase 4: Grünes Licht blinkt
    for (int i = 0; i < 5; i++) {
      digitalWrite(11, LOW);
      delay(300);
      digitalWrite(11, HIGH);
      delay(300);
    }

    //Phase 5: Gelbes Licht
    yellowLight();
    delay(700); 
                  
  }


  void redLight() {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  }

  void yellowLight() {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
  }

  void greenLight() {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
  }


