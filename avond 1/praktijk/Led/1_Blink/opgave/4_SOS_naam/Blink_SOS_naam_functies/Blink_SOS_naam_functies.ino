/*
  Cursus micro processoren
  Riekus Bennink
  AV de Blasbaars
*/
#define PUNT_DELAY 100
#define STREEP_DELAY 300
#define PUNT punt();
#define STREEP streep();
// morse codes
#define S_MORSE PUNT PUNT PUNT
#define O_MORSE STREEP STREEP STREEP
#define R_MORSE PUNT STREEP PUNT
#define I_MORSE PUNT PUNT
#define E_MORSE PUNT
#define K_MORSE STREEP PUNT STREEP
#define U_MORSE PUNT PUNT STREEP

// end morse codes



void punt() {
  digitalWrite(LED_BUILTIN, HIGH);  // onsteek de led
  delay(PUNT_DELAY);                // wacht
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

void riekus(){
  R_MORSE;
  I_MORSE;
  E_MORSE;
  K_MORSE;
  U_MORSE;
  S_MORSE;
}

void setup() {
  // set digital pin LED_BUILTIN to output.
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  sos();
  delay(1000);  // wacht 1 sec en begin dan opnieuw
  riekus();
  delay(2000);  // wacht 2 sec en begin dan opnieuw

}
