// cursus microprocessoren
// Riekus .Bennink

#define RELAY_1 6
#define RELAY_2 7
int waarde;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  digitalWrite(RELAY_1, HIGH);
  digitalWrite(RELAY_2, HIGH);
}


void loop() {
  if (Serial.available()) {
    waarde = Serial.parseInt();
    switch (waarde) {
      case 1:
        digitalWrite(RELAY_1, LOW);
        break;
      case 2:
        digitalWrite(RELAY_1, HIGH);
        break;
      case 3:
        digitalWrite(RELAY_2, LOW);
        break;
      case 4:
        digitalWrite(RELAY_2, HIGH);
        break;
      default:
        digitalWrite(RELAY_2, HIGH);
        digitalWrite(RELAY_1, HIGH);
    }
  }
}
