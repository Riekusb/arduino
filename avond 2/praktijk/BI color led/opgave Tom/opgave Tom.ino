// microprocessor cursus
// Riekus Bennink
/*
 Serial commando's
 0 -> Rood branden
 1 -> Blauw branden
 2 -> Rood knipperen
 3 -> Blauw kniperen
 4 -> Rood en Blauw knipperen om en om
*/

#define BLUE_PIN 6
#define RED_PIN 7

#define DELAY 1000

int serialOntvangeCommando = 5;  //elk ander nummer dan 0,1,2,3,4)

void blauw() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
}

void rood() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
}

void LedUit() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
}


void setup() {
  Serial.begin(9600);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

void handleCommand() {
  switch (serialOntvangeCommando) {
    case 0:
      rood();
      break;
    case 1:
      blauw();
      break;
    case 2:
      rood();
      delay(DELAY);
      LedUit();
      delay(DELAY);
      break;
    case 3:
      blauw();
      delay(DELAY);
      LedUit();
      delay(DELAY);
      break;
    case 4:
      blauw();
      delay(DELAY);
      rood();
      delay(DELAY);
      break;
    default:
      LedUit();
  }
}

void loop() {
  if(Serial.available()>0){
    delay(100);
    serialOntvangeCommando = Serial.parseInt();
  }
  handleCommand();
}
