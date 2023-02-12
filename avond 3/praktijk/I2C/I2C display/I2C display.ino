// Aansturing I2C Display
// Gebruik library van Frank Brabander
// Cursus Microprocessoren Av de Glasbaars
//
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 4);  // set the LCD address to 0x27 for a 16 chars and 4line display

void setMyCursor(int row,int col){ // error in library 
   if( row <1){
     lcd.setCursor(col, row);
   }else{
     lcd.setCursor(col-4, row);
   }
}

void setup() {
  lcd.init();  // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  setMyCursor(0, 0);
  lcd.print("Regel 1");
  setMyCursor(1,0);
  lcd.print("Regel 2");
  setMyCursor(2, 0);
  lcd.print("Regel 3");
  setMyCursor(3, 0);
  lcd.print("Regel 4");
}


void loop() {
}