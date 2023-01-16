void setup() {
  // Deze code wordt 1 keer doorlopen
  Serial.begin(9600);
  Serial.println("Hallo ik ben de Arduino, en hoe heet jij? ");
}

void loop() {
  // Deze code wordt steeds doorlopen
  if (Serial.available()) {
    Serial.print("Hallo ");
    Serial.print(Serial.readString());
    Serial.println(" wat leuk dat je meedoet met de cursus.");
    Serial.println("Ik denk dat wij het goed met elkaar zullen hebben.");
    Serial.println("Als ik je programma begrijp dan zal ik het uitvoeren.");
  }
}
