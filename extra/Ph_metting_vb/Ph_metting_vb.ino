//Ph meting en EEPROM gebruik
//Riekus Bennink
// AV de glasbaars

// We hebben de EEPROM library nodig
#include <EEPROM.h>
//voor het filteren van de analoge (A0) waarden gebruiken een kalmanfilter
#include <SimpleKalmanFilter.h>

// dit is omdat dit makkelijk is
#include <arduino-timer.h>

auto _Timer = timer_create_default();  // hier maken we een timer
//SimpleKalmanFilter(e_mea, e_est, q);
//e_mea: Measurement Uncertainty
// e_est: Estimation Uncertainty
//q: Process Noise

SimpleKalmanFilter analogeWaardeGefilterd(2, 2, 0.01);
float _GefilterdAnalogeWaarde = 0.0;

struct DATA {  // hier defineren een data structuur
  float cal4 = 292.0;
  float cal7 = 512.0;
};

DATA _Data;  // dit is nu het type  DATA
float _PhWaarde = 0.0;

void slaDataOp() {
  Serial.println("Data wordt opgeslagen in de EEPROM");
  Serial.println("cal4 :" + String(_Data.cal4));
  Serial.println("cal7 :" + String(_Data.cal7));
  EEPROM.put(1, _Data);
  EEPROM.write(0, 1);  // we schrijven hier de waarde 1 op adres 0 , zodat we weten dat we wat opgeslagen hebben
}

void leesData() {
  if (EEPROM.read(0) == 1) {  //als de waarde op adres 0 een 1 dan hebben we data op geslagen
    EEPROM.get(1, _Data);
    Serial.println("Data is gelezen uit de EEPROM");
    Serial.println("cal4 :" + String(_Data.cal4));
    Serial.println("cal7 :" + String(_Data.cal7));
  } else{
    slaDataOp();
  }
}

void resetEEPROM(){
   EEPROM.write(0, 0);
}

bool flterDeAnalogeWaarde(void *) {
  _GefilterdAnalogeWaarde = analogeWaardeGefilterd.updateEstimate(analogRead(A0));
  return true;
}

bool berekenDePh() {
  float a = (7.00 - 4.00) / (_Data.cal7 - _Data.cal4);  // richtingscoefficient
  _PhWaarde = a * _GefilterdAnalogeWaarde;
  Serial.println("pH :" + String(_PhWaarde, 2));
}

void setup() {
  Serial.begin(9600);
  // Lees data uit EEPROM
  leesData();
  //hier definieren we de timers
  _Timer.every(300, flterDeAnalogeWaarde);  // elke 300 ms wordt de waarde van de analoge ingang gemeten en gefilterd
  _Timer.every(3000, berekenDePh);          // elke 3 seconde bereken de Ph
}

void loop() {
  _Timer.tick();  // dit is voor de auto timer
  if (Serial.available()) {
    /*
     0) is Kalibreren 7,00 
     1) is kalibreren 4.00
     2) is rest EEPROM
     getallen groter als 2 wordt gezien als testwaarde van A0
    */
    int _user = Serial.parseInt();  //
    switch (_user) {
      case 0:
        // de waarde van de gefilterde waarde is de kalibratie waarde 7.00 (pen staat +/- 2 minuten in 7.00)
        Serial.println("Kalibratie 7 einde");
        _Data.cal7 = _GefilterdAnalogeWaarde;
        Serial.println("cal7 :" + String(_Data.cal7));
        slaDataOp();
        break;
      case 1:
        // de waarde van de gefilterde waarde is de kalibratie waarde 4.00 (pen staat +/- 2 minuten in 4.00)
         Serial.println("Kalibratie 4 einde");
        _Data.cal4 = _GefilterdAnalogeWaarde;
        Serial.println("cal4 :" + String(_Data.cal4));
        slaDataOp();
        break;
      case 2:
       // reset EEPROM
       Serial.println("Reset EEPROM indicatie");
       resetEEPROM();
      break;  
      default:
        // dit de test waarde voor de analoge ingang A0
        _GefilterdAnalogeWaarde = float(_user);
         if(berekenDePh()){
          Serial.println("********* PH : " + String(_PhWaarde, 2) + " *************");
         }
    }
  }
}