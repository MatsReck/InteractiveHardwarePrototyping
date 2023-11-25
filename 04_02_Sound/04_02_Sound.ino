  

  const int button_pin = 2;

  void setup() {
    pinMode(button_pin, INPUT);
  }

  void loop() {

    if (digitalRead(button_pin) == HIGH) {
      tone(8, 300); // …spiele diesen Ton...
      delay(1000); //…und zwar für eine Sekunde...
      noTone(8); // Ton abschalten
    }
  } 