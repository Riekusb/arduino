/* Cursus microprocessoren
Riekus Bennink
 intro tot Serial
*/

void setup() {
  //Hier zetten we de baud rate van de USB/Com poort
  Serial.begin(115200);

  Serial.println("Hallo hoe heet je?");
}

void loop() {
  // Als ik wat ontvangen heb dan ga ik dat terug zenden
  if (Serial.available()) {
    Serial.println(Serial.readString());
  }

  // Wat moet ik mog meer doen
}

