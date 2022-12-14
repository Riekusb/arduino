//cursus Microprocesoren
//Riekus Bennink
#include "myclass.h"  

#define GETAL_1 7
#define GETAL_2 3

MyClass _myclass(GETAL_1,GETAL_2);

void setup() {
  Serial.begin(9600);

  Serial.print("De som is ");
  Serial.println(_myclass.som());

  Serial.print("De aftrekking  is ");
  Serial.println(_myclass.trekAf());


  Serial.print("De vermenigvuldiging is ");
  Serial.println(_myclass.vermenigvuldig());

  Serial.print("De deling is ");
  Serial.println(_myclass.delen());

  Serial.print("De deling (4 decimalen) is ");
  Serial.println(_myclass.delen(), 4);

  Serial.print("is groter ");
 
  Serial.println(_myclass.isgroter());
  
}

void loop() {
}
