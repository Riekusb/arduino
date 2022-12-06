//cursus Microprocesoren
//Riekus Bennink

#define PWM 3

// De DAC kan maximaal 5 V 
// De PWM voor 5 V is 255 -> 5V/255 per stap
// De Analoog converter met 1024 stappen -> 5V/1024 per stap

int counter = 0;
int input;
void setup() {
  Serial.begin(9600);
  pinMode(PWM, OUTPUT);
  
}

void loop() {
  analogWrite(PWM,counter);
  Serial.print("PWM waarde :");
  Serial.print(float(counter)*5/255); 
  Serial.print(" Volt");
  Serial.print(" --> ");
  Serial.print("input waarde :");
  input =analogRead(A0);
  
  Serial.print(float(input)*5/1024);
  Serial.println(" Volt");
  counter=(counter+5)%254;
  delay(1000);
  
}
