// microprocesor cursus
// Riekus Bennink

#define SCHAKELAAR 7
#define LED 2

bool ingedrukt = false;

void setup() {
  Serial.begin(9600);
  pinMode(SCHAKELAAR, INPUT_PULLUP);
  pinMode(LED,OUTPUT);
}

void loop() {
  digitalWrite(LED, LOW);
  while (digitalRead(SCHAKELAAR) == LOW) {
    digitalWrite(LED, HIGH);
    ingedrukt = true;
    delay(50);
  }

  if (ingedrukt) {
    Serial.println("Ingedrukt");
    ingedrukt = false;
  }
}
