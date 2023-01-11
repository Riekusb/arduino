// microprocessor cursus
// Riekus Bennink

# define BLUE_PIN 6
# define RED_PIN 7
#define DELAY  1000

void blauw(){
 digitalWrite(RED_PIN, LOW);
 digitalWrite(BLUE_PIN,HIGH);
}

void rood(){
 digitalWrite(RED_PIN, HIGH);
 digitalWrite(BLUE_PIN,LOW);
}



void setup() {
 pinMode(BLUE_PIN,OUTPUT);
 pinMode(RED_PIN,OUTPUT);
 
}

void loop() {
  blauw();
  delay(DELAY);
  rood();
  delay(DELAY);


}
