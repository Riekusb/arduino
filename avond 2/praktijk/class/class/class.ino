//cursus Microprocesoren
//Riekus Bennink
#include "myclass.h"  

#define GETAL_1 7
#define GETAL_2 3

MyClass _myclass(GETAL_2,GETAL_1);

void setup() {
  Serial.begin(9600);

  Serial.print("De som is ");
  Serial.println(_myclass.som());

  Serial.print("Het verschil  is ");
  Serial.println(_myclass.trekAf());


  Serial.print("Het product is ");
  Serial.println(_myclass.vermenigvuldig());

  Serial.print("De deling is ");
  Serial.println(_myclass.delen());

  Serial.print("De deling (4 decimalen) is ");
  Serial.println(_myclass.delen(), 4);

  //Serial.println(_myclass.privateFunctie()); // fout melding
  Serial.println(_myclass.publicFuntie());
  
}

void loop() {
}
