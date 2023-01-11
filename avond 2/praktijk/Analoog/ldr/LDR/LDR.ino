// cursus microprocessoren
// Riekus .Bennink
#include <arduino.h>
#define LDR A0

int waardeLDR;

void setup() {
  Serial.begin(9600);
}


void loop() {
   waardeLDR= analogRead(LDR);
   Serial.println(waardeLDR);
   delay(1000);
}
