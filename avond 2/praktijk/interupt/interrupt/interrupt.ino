//cursus Microprocesoren
//Riekus Bennink

#define INTERRUPT_PIN 3

bool werk = false;

void interruptProgramma(){
  werk=true;  //Dit is het interrupt programma. Houd dit zo kort mogelijk!
}

void werk_actie(){
  Serial.println("Dit ga ik doen na een interrupt !!");
}

void setup() {
  Serial.begin(9600);
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN),interruptProgramma ,LOW );
}
void loop() {
    if(werk){
     werk_actie();
     werk= false;
  }else{
    Serial.println("Dit het hoofd programma");
  }
  delay(1000);
}
