/*
  Microprocesor cursus
  Riekus Bennink
  Bonus
*/

// include the library code:
#include <Arduino.h>
#include <AceTime.h>       // TimeZone, LocalDateTime
#include <AceTimeClock.h>  // DS3231Clock
#include <AceWire.h>       // TwoWireInterface
#include <Wire.h>          // TwoWire, Wire
#include <LiquidCrystal.h>
#include <EEPROM.h>

#define SELECT_SWITCH 719
#define LEFT_SWITCH 478
#define UP_SWITCH 130
#define DOWN_SWITCH 306
#define RIGHT_SWITCH 0
#define DELTA_VALUE 30



using ace_time::acetime_t;
using ace_time::TimeZone;
using ace_time::LocalDateTime;
using ace_time::clock::DS3231Clock;
using ace_time::zonedb::kZoneBufSizeEurope_Berlin;

using WireInterface = ace_wire::TwoWireInterface<TwoWire>;
WireInterface wireInterface(Wire);
DS3231Clock<WireInterface> dsClock(wireInterface);

enum SCHAKELAAR{
    NIKS,
    SELECT,
    OMHOOG,
    OMLAAG,
    LINKS,
    RECHTS
};

struct ACTION_REGEL_UIT {
  byte Uur = 22;
  byte Minuten = 15;
};

struct ACTION_REGEL_AAN {
  byte Uur = 10;
  byte Minuten = 20;
};

struct RELAIS_TIME {
  ACTION_REGEL_AAN relais1Aan;
  ACTION_REGEL_UIT relais1Uit;
  ACTION_REGEL_AAN relais2Aan;
  ACTION_REGEL_UIT relais2Uit;
};

RELAIS_TIME relaisPcb;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte uur = 0;
byte minuten = 0;
byte sec = 0;
SCHAKELAAR schakelaarIngedrukt = NIKS;

String extraNul(byte getal) {
  if (getal < 10) {
    return "0" + String(getal);
  } else {
    return String(getal);
  }
}

void diplayBerichtOpLcd(byte regel,byte kolom,const String bericht){
  lcd.setCursor(kolom, regel);
  lcd.print(bericht);
}

void displayklok() {
  acetime_t now = dsClock.getNow();
  LocalDateTime ldt = LocalDateTime::forEpochSeconds(now);
  lcd.setCursor(0, 0);
  lcd.print(extraNul(ldt.hour()));
  lcd.print(":");
  lcd.print(extraNul(ldt.minute()));
  lcd.print(":");
  lcd.print(extraNul(ldt.second()));
}

void start_up() {  // deze functie wordt alleen in de set up aangelopen
  // start het lcd met het aantal karakters en regels
  lcd.begin(16, 2);
  // laat een welkomsbericht zien
  diplayBerichtOpLcd(0, 0,"Aquarium");
  diplayBerichtOpLcd(1, 4 , "Arduino");
  delay(5000);
  // start I2C
  Wire.begin();
  wireInterface.begin();
  dsClock.setup();
  if (EEPROM.read(0) == "48") {
    // er is data beschikbaar
    relaisPcb = EEPROM.get(1, relaisPcb);
  } else {
    // eerst keer op starten
    EEPROM.put(1, relaisPcb);
    EEPROM.write(0, 48);
  }
}

bool bepaalSchakelaarValue(int value ,int grens){
  int ondergrens = grens - DELTA_VALUE;
  int bovengrens = grens + DELTA_VALUE;
  return value > ondergrens && value < bovengrens;
}

bool welkeSchakelaarIngedrukt(int waardeA0) {
  if (bepaalSchakelaarValue(waardeA0, SELECT_SWITCH)) {
    schakelaarIngedrukt= SELECT;
    return true;
  } else if (bepaalSchakelaarValue(waardeA0,LEFT_SWITCH)) {
    schakelaarIngedrukt=LINKS;
    return true;
  } else if (bepaalSchakelaarValue(waardeA0,UP_SWITCH)) {
    schakelaarIngedrukt=OMHOOG;
    return true;
  } else if (bepaalSchakelaarValue(waardeA0,DOWN_SWITCH)) {
    schakelaarIngedrukt=OMLAAG;
    return true;
  } else if (bepaalSchakelaarValue(waardeA0,RIGHT_SWITCH)) {
    schakelaarIngedrukt=RECHTS;
    return true;
  }
  schakelaarIngedrukt=NIKS;
  return false;
}



void setup() {
  // Start Serial
  Serial.begin(9600);
  // run de start up
  start_up();
  // maak het display schoon
  lcd.clear();
}

void loop() {
  if (millis() % 1000 == 0) {
    displayklok();
  }
  if(welkeSchakelaarIngedrukt(analogRead(A0))){

  }
}
