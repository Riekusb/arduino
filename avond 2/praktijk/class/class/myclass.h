#ifndef _MYCLASS_
#define _MYCLASS_

class MyClass {
  public:  // dit betekent dat je de functies buiten de class  kan bereiken.
  MyClass(int getal1,int getal2);   //constructor
  ~MyClass();  //destructor
  int som();
  int trekAf();
  int vermenigvuldig();
  float delen();
  String publicFuntie();


  private: // alles wat hier onder wordt gedefinieerd kun je allen in de class gebruiken
  int _getal_1;
  int _getal_2;
  String privateFunctie();
};  // vergeet niet deze punt comma

MyClass::MyClass(int getal1,int getal2) {
  _getal_1=getal1;
  _getal_2=getal2;
};

MyClass::~MyClass() {};

int MyClass::som(){
   return _getal_1 + _getal_2;
}
int MyClass::trekAf(){
   return _getal_1 -_getal_2;
}
int MyClass::vermenigvuldig(){
    return _getal_1 * _getal_2;
}
float MyClass::delen(){
  return float(_getal_1) / _getal_2;
}

String MyClass::privateFunctie(){
  return "Private Functie";
}

String MyClass::publicFuntie(){
  return privateFunctie();
}

#endif