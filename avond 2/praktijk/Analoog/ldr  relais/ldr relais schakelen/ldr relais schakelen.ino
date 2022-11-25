// cursus microprocessoren
// Riekus .Bennink

#define RELAY_1 6
#define LDR A0
int waarde;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_1, OUTPUT);
  digitalWrite(RELAY_1, HIGH);
}


void loop() {
  if(analogRead(LDR)>50){
    digitalWrite(RELAY_1, LOW);
  } else{
    digitalWrite(RELAY_1, HIGH);
  }
 
}
