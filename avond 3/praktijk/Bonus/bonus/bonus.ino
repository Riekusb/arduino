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
#include <DallasTemperature.h>

#define RELAY_1 11
#define RELAY_2 12
ace_time::LocalDateTime ldt;

/*
The LCD circuit:
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
 */
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
// Menu callback function
// In this example all menu items use the same callback.

// define keys
#define NUM_KEYS 5
#define Key_Pin 0  // LCD key pad analog pin
int adc_key_val[5] = { 50, 200, 400, 600, 800 };
int adc_key_in;
int key = -1;
int oldkey = -1;
//Data wire is plugged into port 13 on the Arduino
#define ONE_WIRE_BUS 13

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

float temperature;

void displayTemperatuur(){
  lcd.setCursor(0,1);
  lcd.print(temperature,1);
  lcd.print((char)223);  
}

enum DISPLAY_STATUS {
  DISPLAY_KLOK,
  DISPLAY_MENU,
  WAIT,

};

DISPLAY_STATUS displayStatus = DISPLAY_KLOK;
// Menu variables



using ace_time::acetime_t;
using ace_time::TimeZone;
using ace_time::LocalDateTime;
using ace_time::clock::DS3231Clock;
using ace_time::zonedb::kZoneBufSizeEurope_Berlin;

using WireInterface = ace_wire::TwoWireInterface<TwoWire>;
WireInterface wireInterface(Wire);
DS3231Clock<WireInterface> dsClock(wireInterface);
String message;



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

String commandoString;

String extraNul(byte getal) {
  if (getal < 10) {
    return "0" + String(getal);
  } else {
    return String(getal);
  }
}

void diplayBerichtOpLcd(byte regel, byte kolom, const String bericht) {
  lcd.setCursor(kolom, regel);
  lcd.print(bericht);
}

float getTemperatuur() {
}

void displayklok() {
  acetime_t now = dsClock.getNow();
  ldt = LocalDateTime::forEpochSeconds(now);
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
  diplayBerichtOpLcd(0, 0, "Aquarium");
  diplayBerichtOpLcd(1, 4, "Arduino");
  delay(5000);
  // start I2C
  Wire.begin();
  wireInterface.begin();
  dsClock.setup();
  if (EEPROM.read(0) == 48) {
    Serial.println("EEPROM data beschikbaar");
    // er is data beschikbaar
    relaisPcb = EEPROM.get(1, relaisPcb);
  } else {
    Serial.println("Eerste keer opstarten");
    // eerst keer op starten
    EEPROM.put(1, relaisPcb);
    EEPROM.write(0, 48);
  }
  // defineer de relais pinnen
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  digitalWrite(RELAY_1, HIGH);
  digitalWrite(RELAY_2, HIGH);
  // Start up the library
  sensors.begin(); // ds1820;
}

void storeRelais() {
  EEPROM.put(1, relaisPcb);
}


void serialPrintHelp() {
  Serial.println("***************");
  Serial.println("Commando's");
  Serial.println("klok yyyy:dd:mm:uur:min; vb klok 2022:22:12:15:40;");
  Serial.println("rx aan:uur:min;  bv r1 aan:08:10");
  Serial.println("rx uit:uur:min; bv r2 uit:22:15");
  Serial.println("status: print scahkelstanden R1 en R2 : vb status;");
  Serial.println("***************");
}
String getPart() {
  // zoek de dubbele punt
  int dubbelepunt = commandoString.indexOf(':');
  // Haal het deel op
  String part = commandoString.substring(0, dubbelepunt);
  // verwijder het part uit de commando string;
  commandoString = commandoString.substring(dubbelepunt + 1, commandoString.length());

  return part;
}

void checkRelais() {
  int time = ldt.hour() * 100 + ldt.minute();
  //Serial.println("time :" + String(time));
  int relaisAanTijd = relaisPcb.relais1Aan.Uur * 100 + relaisPcb.relais1Aan.Minuten;
  //Serial.println("r1 AAN :" + String(relaisAanTijd));
  int relaisUitTijd = relaisPcb.relais1Uit.Uur * 100 + relaisPcb.relais1Uit.Minuten;
 // Serial.println("r1 uit :" + String(relaisUitTijd));

  if (time >= relaisAanTijd && time < relaisUitTijd) {
    digitalWrite(RELAY_1, LOW);
  } else {
    digitalWrite(RELAY_1, HIGH);
  }
  relaisAanTijd = relaisPcb.relais2Aan.Uur * 100 + relaisPcb.relais2Aan.Minuten;
  //Serial.println("r2 AAN :" + String(relaisAanTijd));

  relaisUitTijd = relaisPcb.relais2Uit.Uur * 100 + relaisPcb.relais2Uit.Minuten;
 // Serial.println("r2 uit :" + String(relaisUitTijd));
  if (time >= relaisAanTijd && time <= relaisUitTijd) {
    digitalWrite(RELAY_2, LOW);
  } else {
    digitalWrite(RELAY_2, HIGH);
  }
}

void voerCommandoStatusUit() {
  Serial.println("Schakel standen relais");
  Serial.println("Relais 1");
  Serial.print("   aan : " + String(relaisPcb.relais1Aan.Uur) + ":" + String(relaisPcb.relais1Aan.Minuten));
  Serial.println("   uit : " + String(relaisPcb.relais1Uit.Uur) + ":" + String(relaisPcb.relais1Uit.Minuten));
  Serial.println("Relais 2");
  Serial.print("   aan : " + String(relaisPcb.relais2Aan.Uur) + ":" + String(relaisPcb.relais2Aan.Minuten));
  Serial.println("   uit : " + String(relaisPcb.relais2Uit.Uur) + ":" + String(relaisPcb.relais2Uit.Minuten));
}
void voerCommandoKlokUit(const String commando) {
  commandoString = commando;
  Serial.println("Commando string :" + commandoString);
  String jaar = getPart();
  Serial.println("Jaar : " + jaar);
  String dag = getPart();
  Serial.println("Dag : " + dag);
  String maand = getPart();
  Serial.println("maand : " + maand);
  String uur = getPart();
  Serial.println("uur : " + uur);
  String minuten = getPart();
  Serial.println("minuten : " + minuten);
  // we zetten nu de klok
  LocalDateTime ldt = LocalDateTime::forComponents(jaar.toInt(), maand.toInt(), dag.toInt(), uur.toInt(), minuten.toInt(), 0);
  dsClock.setNow(ldt.toEpochSeconds());
}

void voerCommandoR1Uit(const String commando) {
  commandoString = commando;
  Serial.println("Commando string :" + commandoString);
  String actie = getPart();
  Serial.println("actie : " + actie);
  String uur = getPart();
  Serial.println("uur : " + uur);
  String minuten = getPart();
  Serial.println("minuten : " + minuten);
  if (strcmp(actie.c_str(), "aan") == 0) {
    relaisPcb.relais1Aan.Uur = uur.toInt();
    relaisPcb.relais1Aan.Minuten = minuten.toInt();
  } else {
    relaisPcb.relais1Uit.Uur = uur.toInt();
    relaisPcb.relais1Uit.Minuten = minuten.toInt();
  }
}

void voerCommandoR2Uit(const String commando) {
  commandoString = commando;
  Serial.println("Commando string :" + commandoString);
  String actie = getPart();
  Serial.println("actie : " + actie);
  String uur = getPart();
  Serial.println("uur : " + uur);
  String minuten = getPart();
  Serial.println("minuten : " + minuten);
  if (strcmp(actie.c_str(), "aan") == 0) {
    relaisPcb.relais2Aan.Uur = uur.toInt();
    relaisPcb.relais2Aan.Minuten = minuten.toInt();
  } else {
    relaisPcb.relais2Uit.Uur = uur.toInt();
    relaisPcb.relais2Uit.Minuten = minuten.toInt();
  }
}


bool handelCommandosAf() {
  // zoek naar de eerst spatie en haal het commando uit de string
  int indexSpatie = commandoString.indexOf(' ');
  String command = commandoString.substring(0, indexSpatie);
  Serial.println("Commando " + command + " ontvangen");
  if (strcmp(command.c_str(), "klok") == 0) {
    voerCommandoKlokUit(commandoString.substring(indexSpatie + 1, commandoString.length()));
    return true;
  } else if (strcmp(command.c_str(), "r1") == 0) {
    voerCommandoR1Uit(commandoString.substring(indexSpatie + 1, commandoString.length()));
    //de gewijzigde gevens opslaan in EEPROM
    storeRelais();
    return true;
  } else if (strcmp(command.c_str(), "r2") == 0) {
    voerCommandoR2Uit(commandoString.substring(indexSpatie + 1, commandoString.length()));
    //de gewijzigde gevens opslaan in EEPROM
    storeRelais();
    return true;
  } else if (strcmp(command.c_str(), "status") == 0) {
    voerCommandoStatusUit();
  } else
    return false;
}

void setup() {

  // Start Serial
  Serial.begin(9600);
  // run de start up
  start_up();
  // maak het display schoon
  lcd.clear();
  serialPrintHelp();
}

void loop() {
  if (millis() % 1000 == 0) {
    displayklok();
    checkRelais();
    sensors.requestTemperatures(); // Send the command to get temperatures
    temperature = sensors.getTempCByIndex(0);
    displayTemperatuur();
  }
  if (Serial.available()) {
    commandoString = Serial.readStringUntil(';');
    if (!handelCommandosAf()) {
      Serial.println("Fouten in het commando!");
    }
  }
}
