// Aansturing I2C Display
// Gebruik library van Frank Brabander
// Cursus Microprocessoren Av de Glasbaars
//
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 4);  // set the LCD address to 0x27 for a 16 chars and 4line display

void set1604Cursor(int row, int col) {  // error in library
  if (row < 1) {
    lcd.setCursor(col, row);
  } else {
    lcd.setCursor(col - 4, row);
  }
}

void setup() {
  lcd.init();  // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  set1604Cursor(0, 0);
  lcd.print("Regel 1");
  set1604Cursor(1, 0);
  lcd.print("Regel 2");
  set1604Cursor(2, 0);
  lcd.print("Regel 3");
  set1604Cursor(3, 0);
  lcd.print("Regel 4");
  delay(5000);
  lcd.clear();
  
  set1604Cursor(0, 0);
  lcd.print("Ma-10-02 10:56");
  set1604Cursor(1,0);
  lcd.print("PH  6,80");
  set1604Cursor(2, 0);
  lcd.print("Temp  25,7 C");
 set1604Cursor(3, 0);
  lcd.print("Licht 80%");



}


void loop() {
}