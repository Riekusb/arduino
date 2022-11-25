// cursus microprocesoren
// Riekus Bennink

#define LED 9

int dimValue =255;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  dimValue --;
  analogWrite(LED,  dimValue);
  delay(100);
  // put your main code here, to run repeatedly:

}
