/*
  Morse SOS
  Cursus micro processoren
  Riekus Bennink
*/
#define PUNT 100
#define STREEP 300

void punt() {
  digitalWrite(LED_BUILTIN, HIGH);  // onsteek de led
  delay(PUNT);                       // wacht
  digitalWrite(LED_BUILTIN, LOW);   // doof the led
  delay(PUNT);
}

void streep() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(STREEP);
  digitalWrite(LED_BUILTIN, LOW);
  delay(STREEP);
}

void s(){
punt();punt();punt();
}

void o(){
  streep();streep(),streep();
}

void sos(){
  s();o();s();
}

void setup() {
  // set digital pin LED_BUILTIN to output.
  pinMode(LED_BUILTIN, OUTPUT);
}



void loop() {
  sos();
  delay(2000);  // wacht 2 sec en begin dan opnieuw
}
