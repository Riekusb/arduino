/*
  Microprocesor cursus
  Riekus Bennink
  Klok
*/

// include the library code:
#include <LiquidCrystal.h>

#define SELECT_SWITCH 719
#define LEFT_SWITCH 478
#define UP_SWITCH 130
#define DOWN_SWITCH 306
#define RIGHT_SWITCH 0
#define DELTA_VALUE 30


// zie lcd shield data
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String extraNul(byte getal) {
  if (getal < 10) {
    return "0" + String(getal);
  } else {
    return String(getal);
  }
}

void lcdMessage(int value) {
  lcd.setCursor(0, 0);
  lcd.print("          ");
  lcd.setCursor(0, 0);
  switch (value) {
    case 0:
      lcd.print("Select");
      break;
    case 1:
      lcd.print("Left");
      break;
    case 2:
      lcd.print("Up");
      break;
    case 3:
      lcd.print("Down");
      break;
    case 4:
      lcd.print("Right");
      break;
  }
}

bool bepaalSchakelaarValue(int value ,int grens){
  int ondergrens = grens - DELTA_VALUE;
  int bovengrens = grens + DELTA_VALUE;
  return value > ondergrens && value < bovengrens;
}

bool welkeSchakelaarIngedrukt(int waardeA0) {
  if (bepaalSchakelaarValue(waardeA0, SELECT_SWITCH)) {
    lcdMessage(0);
    return true;
  } else if (bepaalSchakelaarValue(waardeA0,LEFT_SWITCH)) {
    // Left schakelaar
    lcdMessage(1);
    return true;
  } else if (bepaalSchakelaarValue(waardeA0,UP_SWITCH)) {
    // Up schakelaar
    lcdMessage(2);
    return true;
  } else if (bepaalSchakelaarValue(waardeA0,DOWN_SWITCH)) {
    // Down schakelaar
    lcdMessage(3);
    return true;
  } else if (bepaalSchakelaarValue(waardeA0,RIGHT_SWITCH)) {
    // right schakelaar
    lcdMessage(4);
    return true;
  }
  return false;
}


void setup() {
  // Start Serial
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  if (welkeSchakelaarIngedrukt(analogRead(A0))) {
    // doe wat
  }
  
}
