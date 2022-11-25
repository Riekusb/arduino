// cursus microprocesoren
// Riekus Bennink

#define LED 9

int dimValue =255;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if(Serial.available()){
    dimValue = Serial.parseInt() % 256;
  }
  analogWrite(LED,  dimValue);
  delay(100);
  // put your main code here, to run repeatedly:

}
