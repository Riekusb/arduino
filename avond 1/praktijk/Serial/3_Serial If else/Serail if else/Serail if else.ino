/* Cursus microprocessoren
Riekus Bennink
AV de Glasbaars
*/

void setup() {
  //Hier zetten we de baud rate van de USB/Com poort
  Serial.begin(9600);
  Serial.println("Ik heb een geheim getal onder de 10 ");
}

void loop() {
  // Als ik wat ontvangen heb dan ga ik dat terug zenden
  if (Serial.available()) {
    int ontvangen = Serial.parseInt(); // Wat ik heb ontvangen maak ik een integer
    if (ontvangen == 4 ) {
      // Als ik 4 heb ontvangen dan doe ik dit
      Serial.println("geraden !!!");
    } else {
      // anders doe ik dat
      Serial.println("Sorry niet geraden");
      Serial.println("Nog eens ");
    }
  }

  // wat moet ik nog meer doen
}

// Maak nu zelf een leuk welkomsbericht
// bv Hallo wat is je leuk dat je meedoet met de cursus