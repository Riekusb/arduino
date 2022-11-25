// microprocesor cursus
// Riekus Bennink

#define SCHAKELAAR 7

bool ingedrukt = false;

void setup() {
  Serial.begin(9600);
  pinMode(SCHAKELAAR, INPUT_PULLUP);
 
}

void loop() {
  
  while (digitalRead(SCHAKELAAR) == LOW) {
    ingedrukt = true;
    delay(50);
  }

  if (ingedrukt) {
    Serial.println("Ingedrukt");
    ingedrukt = false;
  }
}
