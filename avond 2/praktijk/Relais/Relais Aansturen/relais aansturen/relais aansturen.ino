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
  digitalWrite(RELAY_1,LOW);
  delay(1000);
  digitalWrite(RELAY_2,LOW);
  delay(1000);
  digitalWrite(RELAY_1, HIGH);
  digitalWrite(RELAY_2, HIGH);
  delay(2000);
 
}
