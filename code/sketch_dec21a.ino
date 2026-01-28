#include <Servo.h>

// -------------------- Broches --------------------
#define actio1_cont 9
#define actio2_cont 10
#define actio3_cont 11

#define S0 7
#define S1 6
#define S2 5
#define S3 4

#define dirPin 2
#define stepPin 3

#define colorPin 8

int compt1 =0;
int compt2 =0;
int compt3 =0;

// -------------------- Enum couleur --------------------
enum Color { RED, GREEN, BLUE, NONE };

// -------------------- Structure servo --------------------

Servo actio1; // 0=BLUE,1=RED,2=GREEN
Servo actio2;
Servo actio3;

// -------------------- Setup --------------------
void setup() {
  Serial.begin(9600);

  actio1.attach(9);
  actio1.write(165);

  actio2.attach(10);
  actio2.write(173);

  actio3.attach(11);
  actio3.write(130);

  // Pins capteur
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT); 
  pinMode(S3, OUTPUT);
  digitalWrite(S1,HIGH); 
  digitalWrite(S0,LOW);

  pinMode(colorPin, INPUT);

  // Pins moteur
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  digitalWrite(dirPin, LOW);
}

// -------------------- Lecture couleur --------------------
unsigned long lireCouleur(bool s2, bool s3, int n=5) {
  unsigned long sum = 0;
  for(int i=0; i<n; i++){
    digitalWrite(S2, s2);
    digitalWrite(S3, s3);
    delay(10); // stabilisation courte
    sum += pulseIn(colorPin, LOW, 30000);
  }
  return sum / n;
}

// -------------------- Détecter couleur dominante --------------------
Color detectColor() {
  unsigned long red = lireCouleur(LOW, LOW);
  unsigned long green = lireCouleur(HIGH, HIGH);
  unsigned long blue = lireCouleur(LOW, HIGH);

  if (red < green && red < blue) return RED;
  if (green < red && green < blue) return GREEN;
  if (blue < red && blue < green) return BLUE;
  return NONE;
}


// -------------------- Loop --------------------
// -------------------- Loop (Optimisée pour Node-RED) --------------------
void loop() {
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(500);

  Color c = detectColor();
  
  bool detection = false;

  if (c == RED) {
    actio3.write(25);
    ++compt3;
    detection = true;
  } 
  else if (c == GREEN) {
    actio2.write(83);
    ++compt2;
    detection = true;
  } 
  else if (c == BLUE) {
    actio1.write(75);
    ++compt1;
    detection = true;
  }

  // On envoie les données sur le port série uniquement lors d'une détection
  if (detection) {
    // Format : Bleu,Vert,Rouge (compt1, compt2, compt3)
    Serial.print(compt1);
    Serial.print(",");
    Serial.print(compt2);
    Serial.print(",");
    Serial.println(compt3); // println ajoute le caractère de fin de ligne (\n)
    
    delay(500); // Pause pour éviter les doubles détections immédiates
  }
}
