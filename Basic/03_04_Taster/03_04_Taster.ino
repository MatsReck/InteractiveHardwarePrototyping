
  const int button_pin = 2;
  const int redLED = 13;

  int tasterStatus = 0;
  int LEDStatus = -1; //1 = an, -1 = aus


  void setup() {
    pinMode(button_pin, INPUT);
    pinMode(redLED, OUTPUT);
  }

  void loop() {
    //Wenn Taster gedrückt wird, ändert sich der LED Zustand
    tasterStatus = digitalRead(button_pin);
    
    if (tasterStatus == HIGH) {
      LEDStatus =-LEDStatus;
    }
    
    if(LEDStatus == 1) {
      digitalWrite(redLED, HIGH);
    }

    else {
      digitalWrite(redLED, LOW);
    }

      delay(200);
  }

