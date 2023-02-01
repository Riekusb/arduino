// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// kies hier je opgave (Maak 1 opgave een 1 de rest 0 )
#define OPGAVE_1 1
#define OPGAVE_2 0


#if OPGAVE_2
#define RELAY_1 7
#define AQUARIUM_TEMP 24  //temper atuur Aquarium
#define STAP 0.5    // voorkomt dat het relais staat te schakelen
#endif

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2


// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

/*
 * The setup function. We only start the sensors here
 */
void setup(void) {
  // start serial port
  Serial.begin(9600);
  if (Serial) {
    Serial.println("Dallas Temperature IC Control Library Demo");
  }

  #if OPGAVE_2
     pinMode(RELAY_1, OUTPUT);
     digitalWrite(RELAY_1, HIGH);
  #endif

  // Start up the library
  sensors.begin();
}

/*
 * Main function, get and show the temperature
 */
void loop(void) {
// call sensors.requestTemperatures() to issue a global temperature
// request to all devices on the bus
#if OPGAVE_1
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();  // Send the command to get temperatures
  Serial.println("DONE");
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if (tempC != DEVICE_DISCONNECTED_C) {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  } else {
    Serial.println("Error: Could not read temperature data");
  }
#endif

#if OPGAVE_2
  //alle print statements verwijderd
  sensors.requestTemperatures();  // Send the command to get temperatures

  float tempC = sensors.getTempCByIndex(0);
  if (tempC != DEVICE_DISCONNECTED_C) {
  //  Serial.println(tempC);  // debug regel
    // hebben hier een goede waarde van de sensor dus kunnen we testen
    if (tempC > AQUARIUM_TEMP) {
        // temperatuur aquarium bereikt
        digitalWrite(RELAY_1, HIGH);
    } else if (tempC < AQUARIUM_TEMP - STAP ){
        // temperatuur aquarium bereikt
        digitalWrite(RELAY_1, LOW);
    }
  }
 delay(1000);
#endif
}
