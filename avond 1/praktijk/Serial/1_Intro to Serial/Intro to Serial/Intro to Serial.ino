/* Cursus microprocessoren
Riekus Bennink
// intro tot Serial Hello World
*/
void setup() {
  // Dit wordt alleen uitgevoerd tijdes het opstarten
  //Hier zetten we de baud rate van de USB/Com poort
  Serial.begin(9600);
  Serial.println("Hello World!");
}

void loop() {
  // De code die hier staat wordt continue uitgevoerd
}