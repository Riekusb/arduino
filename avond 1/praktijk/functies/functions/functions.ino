//cursus Microprocesoren
//Riekus Bennink
//AV de Glasbaars

#define GETAL_1 7
#define GETAL_2 3

int som(int x, int y) {
  return x + y;
}

int trekAf(int x, int y) {
  return x - y;
}

int vermenigvuldig(int x, int y) {
  return x * y;
}

int delen_fout(int x, int y) {
  return x / y;
}

float delen(int x, int y) {
  return float(x) / (y);
}

bool isgroter(int x, int y) {
  return x > y;
}

void setup() {
  Serial.begin(9600);

  Serial.print("De som is ");
  Serial.println(som(GETAL_1, GETAL_2));

  Serial.print("De aftrekking  is ");
  Serial.println(trekAf(GETAL_1, GETAL_2));


  Serial.print("De vermenigvuldiging is ");
  Serial.println(vermenigvuldig(GETAL_1, GETAL_2));

  Serial.print("De deling tussen 2 integers is ");
  Serial.println(delen_fout(GETAL_1, GETAL_2));

  Serial.print("De deling is ");
  Serial.println(delen(GETAL_1, GETAL_2));

  Serial.print("De deling (4 decimalen) is ");
  Serial.println(delen(GETAL_1, GETAL_2), 4);

  Serial.print("is groter ");
 
  Serial.println(isgroter(GETAL_1, GETAL_2));
  
}

void loop() {
}
