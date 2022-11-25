/*
  Morse SOS
  Cursus micro processoren
  Riekus Bennink
*/
#define PUNT_DELAY 100
#define STREEP_DELAY 300
#define PUNT punt();
#define STREEP streep();
// morse codes
#define S_MORSE PUNT PUNT PUNT
#define O_MORSE  STREEP STREEP STREEP
// end morse codes



void punt() {
  digitalWrite(LED_BUILTIN, HIGH);  // onsteek de led
  delay(PUNT_DELAY);                       // wacht
  digitalWrite(LED_BUILTIN, LOW);   // doof the led
  delay(PUNT_DELAY);
}

void streep() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(STREEP_DELAY);
  digitalWrite(LED_BUILTIN, LOW);
  delay(STREEP_DELAY);
}

void sos(){
  S_MORSE;
  O_MORSE;
  S_MORSE;
}

void setup() {
  // set digital pin LED_BUILTIN to output.
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  sos();
  delay(1000);  // wacht 2 sec en begin dan opnieuw
}
