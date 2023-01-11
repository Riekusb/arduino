//cursus Microprocesoren
//Riekus Bennink
// AV de glasbaars

// We hebben de EEPROM library nodig
#include <EEPROM.h>

int getal =0;


void slaDataOp() {
  Serial.println("Data wordt opgeslagen in de EEPROM");
  EEPROM.put(1, getal);
  EEPROM.write(0, 1);
}

int leesData() {
  int waarde;
  if (EEPROM.read(0) == 1) {
    EEPROM.get(1, waarde);
  }
 return waarde;
}

void setup() {
  Serial.begin(9600);
  Serial.println(" Test EEPROM");
  getal=leesData();
  Serial.println(getal);


}

void loop() {
  if (Serial.available()) {
    getal = Serial.parseInt();
    slaDataOp();
  }
}
