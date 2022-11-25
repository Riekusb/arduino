/* Cursus microprocessoren
Riekus Bennink
intro tot Serial
*/

void setup() {
  //Hier zetten we de baud rate van de USB/Com poort
  Serial.begin(9600);
  Serial.println("Hallo wat is je naam?");
}

void loop() {
  // Als ik wat ontvangen heb dan ga ik dat terug zenden
  if (Serial.available()) {
    Serial.print("Hoi ");
    Serial.println(Serial.readString());
    Serial.println("wat leuk dat je mee doet!");
  }
}
