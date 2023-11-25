

  #include "pitches.h"

  //Noten für 
  int melody[] = {

    NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
    NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
    NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4,
    NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4,
    NOTE_G4, NOTE_C4
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {

    8, 8, 16, 16, 8, 8, 16, 16,
    8, 8, 16, 16, 8, 8, 16, 16,
    8, 8, 16, 16, 8, 8, 16, 16,
    8, 8, 16, 16, 8, 8, 16, 16,
    4, 4
  };


  void setup() {
    pinMode (8,OUTPUT);
  }

  void loop() {
  
    playSong();   //Spiele den Song ab
    delay(5000);  //Warte 5 Sekunden bevor er erneut abgespielt wird

  }

  void playSong() {
    int size = sizeof(durations) / sizeof(int); 
	  for (int note = 0; note < size; note++) { 
	    
	    int duration = 1000 / durations[note]; 
	    tone(BUZZER_PIN, melody[note], duration); 
	    
      //Pause zwischen den Noten
	    int pauseBetweenNotes = duration * 1.30; 
	    delay(pauseBetweenNotes); 
	    
      //Stoppe den Ton
	    noTone(BUZZER_PIN); 
	 } 
  }


  