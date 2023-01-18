/*
  Microprocesor cursus
  Riekus Bennink
  Serial en Display
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Start Serial
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("wat is je naam?");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  if(Serial.available()){
    lcd.setCursor(0, 0);
    lcd.print("                ");  // print
    lcd.setCursor(0, 0);   // set de cursor lcd
    lcd.print("Hallo ");
    lcd.print(Serial.readString());
  }
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}

