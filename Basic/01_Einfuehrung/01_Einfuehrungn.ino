  
  const int redLED = 13; //Definiere den Pin, an dem die LED angeschlossen ist

  void setup() {
    pinMode(redLED, OUTPUT); //Setze den LED-Pin als Ausgang

  }

  void loop() {
    digitalWrite(redLED, HIGH); //Schalte die LED ein
    delay(1000); //Warte für eine Sekunde
    digitalWrite(redLED, LOW); //Schalte die LED aus
    delay(1000); //Warte für eine Sekunde
  }

