  


  void setup() {
   
  }

  void loop() {
    
  // Der Lautsprecher an Pin 8 wird mit der Tonhöhe „100“ aktiviert
  tone(8, 100);
      
  // Pause für 1 Sekunde – Der Lautsprecher bleibt für diese Zeit aktiv.
  delay(1000); 

  // Der Lautsprecher an Pin 8 wird deaktiviert
  noTone(8); 
    
  }