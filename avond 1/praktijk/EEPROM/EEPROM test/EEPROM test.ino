//cursus Microprocesoren
//Riekus Bennink

// We hebben een library nodig
#include <EEPROM.h>

bool gelezen = false;
String data="";

void setup() {
  Serial.begin(9600);
  EEPROM.get(0, data);
  // Als de data niet gelijk is aan ""
  if (strcmp("", data.c_str())!=0) {
    // ik moest iets onthouden
    Serial.println(data);
  } else {
    // ik hoef niks te onthouden
    Serial.println("niks");
    EEPROM.put(0, data);
  }
}

void loop() {

  if (Serial.available()) {
    data = Serial.readString();
    Serial.println(data);
    EEPROM.put(0,data);
  
  }
  delay(100);
}
