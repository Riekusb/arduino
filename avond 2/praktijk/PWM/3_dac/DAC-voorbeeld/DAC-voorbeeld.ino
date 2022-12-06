//cursus Microprocesoren
//Riekus Bennink

#define PWM 3

int counter = 0;
int input;
void setup() {
  Serial.begin(9600);
  pinMode(PWM, OUTPUT);
  
}

void loop() {
  analogWrite(PWM,counter);
  Serial.print("PWM waarde :");
  Serial.print(counter); 
  Serial.print(" --> ");
  Serial.print("input waarde :");
  input =analogRead(A0);
  Serial.println(input);
  counter=(counter+5)%254;
  delay(1000);
  
}
