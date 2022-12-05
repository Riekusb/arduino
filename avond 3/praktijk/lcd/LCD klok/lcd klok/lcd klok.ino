/*
  Microprocesor cursus
  Riekus Bennink
  Klok
*/

// include the library code:
#include <LiquidCrystal.h>

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


void setup() {
  // Start Serial
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  if (millis() % 1000 == 0) {
    berekenKlokWaarde();
    displayklok();
  }

  // print the number of seconds since reset:
}
