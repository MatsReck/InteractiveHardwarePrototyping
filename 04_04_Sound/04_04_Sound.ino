

  #include "pitches.h"

  void setup() {
    pinMode (8,OUTPUT);
  }

  void loop() {
    tone(8, NOTE_C4, 1000); //Note C4 für 1 Sekunde abspielen
    delay(1000); //für 1 Sekunde warten
    tone(8, NOTE_G3, 1000); //NoteG3 für 1 Sekunde abspielen
    delay(1000); //für 1 Sekunde warten
    tone(8, NOTE_A3, 1000); //NoteA3 für 1 Sekunde abspielen
    delay(1000); //für 1 Sekunde warten
    tone(8, NOTE_G3, 1000); //NoteG3 für 1 Sekunde abspielen
  }