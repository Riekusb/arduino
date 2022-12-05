/*
  Microprocesor cursus
  Riekus Bennink
  Klok
*/

// include the library code:
#include <LiquidCrystal.h>


#define RELAIS_1 11
#define RELAIS_2 12

#define UUR_1_ON 10
#define UUR_1_OF 22


// de Select shakelaar set de uren
// de Left schakelaar set de minuten
// de right schakelaar set de secondes op nul

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



byte uur = 0;
byte minuten = 0;
byte sec = 0;

String extraNul(byte getal) {
  if (getal < 10) {
    return "0" + String(getal);
  } else {
    return String(getal);
  }
}


void HandleRelais_1(){
  if(uur >= UUR_1_ON && uur <UUR_1_OF){
    digitalWrite(RELAIS_1, LOW );
  }else{
    digitalWrite(RELAIS_1, HIGH );
  }
}


void displayklok() {
  lcd.setCursor(0, 0);
  lcd.print(extraNul(uur));
  lcd.print(":");
  lcd.print(extraNul(minuten));
  lcd.print(":");
  lcd.print(extraNul(sec));
}


void berekenKlokWaarde() {
  sec++;
  if (sec > 59) {
    sec = 0;
    minuten++;
    if (minuten > 59) {
      minuten = 0;
      uur++;
      if (uur > 23) {
        uur = 0;
      }
    }
  }
}

bool isEenSchakelaarIngedrukt() {
  int waardeA0 = analogRead(A0);
  Serial.println(waardeA0);
  if (waardeA0 >= 500 && waardeA0 <= 750) {
    //select schakelaar
    uur = (uur + 1) % 24;
    return true;
  }
  if (waardeA0 >= 300 && waardeA0 <= 500) {
    // Left schakelaar
    minuten = (minuten + 1) % 60;
    return true;
  }
  if (waardeA0 >= 0 && waardeA0 <= 50) {
    // right schakelaar
    sec = 0;
    return true;
  }

  return false;
}


void setup() {
  // Start Serial
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // set digital poorten
  pinMode(RELAIS_1, OUTPUT);
  pinMode(RELAIS_2, OUTPUT);
  digitalWrite(RELAIS_1, HIGH);
  digitalWrite(RELAIS_2, HIGH);
}


void loop() {
  lcd.setCursor(0, 0);
  if (millis() % 1000 == 0) {
    if (!isEenSchakelaarIngedrukt()) {
      berekenKlokWaarde();
    }
    displayklok();
    HandleRelais_1();
  }

  // print the number of seconds since reset:
}
