//cursus Microprocesoren
//Riekus Bennink

// We hebben een library nodig
#include <EEPROM.h>

struct DATA{  //definitie van een structuur/record
  int getal= 66;
  String naam ="Riekus";
};

DATA data;

void setup() {
  Serial.begin(9600);
  if(EEPROM.read(0)==13){// zomaar een getal om te testen of er wat gescherven is
      EEPROM.get(1, data);
       Serial.println(data.naam);
       Serial.println(data.getal);
  } else{
    EEPROM.put(1, data);
    EEPROM.write(0, 13);
  }

}

void loop() {

}
