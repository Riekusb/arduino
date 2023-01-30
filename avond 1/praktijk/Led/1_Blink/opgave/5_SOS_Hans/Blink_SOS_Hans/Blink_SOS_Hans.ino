/*
  Cursus micro processoren
  Riekus Bennink
  AV de Blasbaars
*/
#define PUNT_DELAY 200
#define STREEP_DELAY 400
#define MORSE_WORD_DELAY 500
#define LETTER_DELAY 100

#define PUNT punt();
#define STREEP streep();


// morse codes
#define A_MORSE PUNT STREEP
#define B_MORSE STREEP PUNT PUNT PUNT
#define C_MORSE STREEP PUNT STREEP PUNT
#define D_MORSE STREEP PUNT PUNT
#define E_MORSE PUNT
#define F_MORSE PUNT PUNT STREEP PUNT
#define G_MORSE STREEP STREEP PUNT
#define H_MORSE PUNT PUNT PUNT PUNT
#define I_MORSE PUNT PUNT
#define J_MORSE PUNT STREEP STREEP STREEP
#define K_MORSE STREEP PUNT STREEP
#define L_MORSE PUNT STREEP PUNT PUNT
#define M_MORSE STREEP STREEP
#define N_MORSE STREEP PUNT
#define O_MORSE STREEP STREEP STREEP
#define P_MORSE PUNT STREEP STREEP PUNT
#define Q_MORSE STREEP STREEP PUNT STREEP
#define R_MORSE PUNT STREEP PUNT
#define S_MORSE PUNT PUNT PUNT
#define O_MORSE STREEP STREEP STREEP
#define T_MORSE STREEP
#define U_MORSE PUNT PUNT STREEP
#define V_MORSE PUNT PUNT PUNT STREEP
#define W_MORSE PUNT STREEP STREEP
#define X_MORSE STREEP PUNT PUNT STREEP
#define Y_MORSE STREEP PUNT STREEP STREEP
#define Z_MORSE STREEP STREEP PUNT PUNT

#define MORSE_1 PUNT STREEP STREEP STREEP STREEP
#define MORSE_2 PUNT PUNT STREEP STREEP STREEP
#define MORSE_3 PUNT PUNT PUNT STREEP STREEP
#define MORSE_4 PUNT PUNT PUNT PUNT STREEP
#define MORSE_5 PUNT PUNT PUNT PUNT PUNT
#define MORSE_6 STREEP PUNT PUNT PUNT PUNT
#define MORSE_7 STREEP STREEP PUNT PUNT PUNT
#define MORSE_8 STREEP STREEP STREEP PUNT PUNT
#define MORSE_9 STREEP STREEP STREEP STREEP PUNT
#define MORSE_0 STREEP STREEP STREEP STREEP STREEP

// end morse codes

String serialReceivedData="";

void punt() {
  digitalWrite(LED_BUILTIN, HIGH);  // onsteek de led
  delay(PUNT_DELAY);                // wacht
  digitalWrite(LED_BUILTIN, LOW);   // doof the led
  delay(PUNT_DELAY);
}

void streep() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(STREEP_DELAY);
  digitalWrite(LED_BUILTIN, LOW);
  delay(STREEP_DELAY);
}

void blinkChar(char letter) {
  switch (letter) {
    case 'a':
A_MORSE
      break;
    case 'b':
B_MORSE
      break;
    case 'c':
C_MORSE
      break;
    case 'd':
D_MORSE
      break;
    case 'e':
E_MORSE
      break;
    case 'f':
F_MORSE
      break;
    case 'g':
G_MORSE
      break;
    case 'h':
H_MORSE
      break;
    case 'i':
I_MORSE
      break;
    case 'j':
J_MORSE
      break;
    case 'k':
K_MORSE
      break;
    case 'l':
L_MORSE
      break;
    case 'm':
M_MORSE
      break;
    case 'n':
N_MORSE
      break;
    case 'o':
O_MORSE
      break;
    case 'p':
P_MORSE
      break;
    case 'q':
Q_MORSE
      break;
    case 'r':
R_MORSE
      break;
    case 's':
S_MORSE
      break;
    case 't':
T_MORSE
      break;
    case 'u':
U_MORSE
      break;
    case 'v':
V_MORSE
      break;
    case 'w':
W_MORSE
      break;
    case 'x':
X_MORSE
      break;
    case 'y':
Y_MORSE
      break;
    case 'z':

Z_MORSE
      break;
    case '1':
MORSE_1
      break;
    case '2':
MORSE_2
      break;
    case '3':
MORSE_3
      break;
    case '4':
MORSE_4
      break;
    case '5':
MORSE_5
      break;
    case '6':
MORSE_6
      break;
    case '7':
MORSE_7
      break;
    case '8':
MORSE_8
      break;
    case '9':
MORSE_9
      break;
    case '0':
MORSE_0
      break;
  }
  delay(LETTER_DELAY);
}

void sos() {
  blinkChar('s');
  blinkChar('o');
  blinkChar('s');
  delay(MORSE_WORD_DELAY);
}

void riekus() {
  blinkChar('r');
  blinkChar('i');
  blinkChar('e');
  blinkChar('k');
  blinkChar('u');
  blinkChar('s');
  delay(MORSE_WORD_DELAY);
}

void setup() {
  Serial.begin(9600);
  
  // set digital pin LED_BUILTIN to output.
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  if(Serial.available()){
    serialReceivedData=Serial.readString();
    for (int i=0; i<serialReceivedData.length(); i++) {
       blinkChar(serialReceivedData.charAt(i));
    }
  }
  
 
}
