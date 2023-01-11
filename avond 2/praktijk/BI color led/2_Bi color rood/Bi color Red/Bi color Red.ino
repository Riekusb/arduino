// microprocessor cursus
// Riekus Bennink

# define BLUE_PIN 6
# define RED_PIN 7
#define DELAY  1000

void rood(){
 digitalWrite(RED_PIN, HIGH);
 digitalWrite(BLUE_PIN,LOW);
}


void uit(){
 digitalWrite(RED_PIN, LOW);
 digitalWrite(BLUE_PIN,LOW);
}

void setup() {
 pinMode(BLUE_PIN,OUTPUT);
 pinMode(RED_PIN,OUTPUT);
 digitalWrite(RED_PIN, LOW);
 digitalWrite(BLUE_PIN,HIGH );
}

void loop() {
  // put your main code here, to run repeatedly:
rood();
  delay(DELAY);
  uit();
  delay(DELAY);
}
