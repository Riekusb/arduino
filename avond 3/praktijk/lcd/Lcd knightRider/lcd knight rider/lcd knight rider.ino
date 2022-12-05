/*
  Microprocesor cursus
  Riekus Bennink
  Klok
*/

// include the library code:
#include <LiquidCrystal.h>

int oldRow = 0;
int oldKol = 0;
int kolCounter = 0;
bool rechts = false;

// zie lcd shield data
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void ShowKnightRider(int row, int kol) {
  // als eerste delete de oude waarde
  lcd.setCursor(oldKol, oldRow);
  lcd.print(" ");
  // print nu het chacter .
  lcd.setCursor(kol, row);
  lcd.print(".");
  // bewaar de nieuwe waarde
  oldKol = kol;
  oldRow = row;
}

void nightRider() {
  ShowKnightRider(1, kolCounter);
  if (rechts) {
    kolCounter++;
    if (kolCounter > 15) {
      rechts = false;
    }
  } else {
    kolCounter--;
    if (kolCounter < 0) {
      rechts = true;
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
  nightRider();
  delay(100);
}
