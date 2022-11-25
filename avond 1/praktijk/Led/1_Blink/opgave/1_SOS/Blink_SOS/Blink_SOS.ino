/*
  Morse SOS
  Cursus micro processoren
  Riekus Bennink
*/


void setup() {
  // set digital pin LED_BUILTIN to output.
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  //punt 1
  digitalWrite(LED_BUILTIN, HIGH);  // onsteek de led
  delay(100);                       // wacht
  digitalWrite(LED_BUILTIN, LOW);   // doof the led
  delay(100);
  //punt 2
  digitalWrite(LED_BUILTIN, HIGH);  // onsteek de led
  delay(100);                       // wacht
  digitalWrite(LED_BUILTIN, LOW);   // doof the led
  delay(100);
  // punt 3
  digitalWrite(LED_BUILTIN, HIGH);  // onsteek de led
  delay(100);                       // wacht
  digitalWrite(LED_BUILTIN, LOW);   // doof the led
  delay(100);
  // streep 1
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  //streep 2
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  //streep 3
 digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  //punt 1
  digitalWrite(LED_BUILTIN, HIGH);  // onsteek de led
  delay(100);                       // wacht
  digitalWrite(LED_BUILTIN, LOW);   // doof the led
  delay(100);
  //punt 2
  digitalWrite(LED_BUILTIN, HIGH);  // onsteek de led
  delay(100);                       // wacht
  digitalWrite(LED_BUILTIN, LOW);   // doof the led
  delay(100);
  //punt 3
  digitalWrite(LED_BUILTIN, HIGH);  // onsteek de led
  delay(100);                       // wacht
  digitalWrite(LED_BUILTIN, LOW);   // doof the led
  delay(100);

  delay(2000);  // wacht 2 sec en begin dan opnieuw
}
