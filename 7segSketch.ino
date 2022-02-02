
// Digits 
int D1 = 2;
int D2 = 3; 
int D3 = 4;
int D4 = 5;

// Segments
int segA = 6;
int segB = 7;
int segC = 8;
int segD = 9;
int segE = 10;
int segF = 11;
int segG = 12;
int dot = 13;


void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(dot, OUTPUT);

  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  
  Serial.begin(9600);
}

// *******************************************
// Main function
// *******************************************
void loop() {
  count(D4, 1000);
  count(D3, 1000);
}




// *******************************************
// Helper functions
// *******************************************


boolean count(int theD, int t) {
  
  zero(theD);
  delay(t);
  one(theD);
  delay(t);
  two(theD);
  delay(t);
//  three();
//  delay(t);
//  four();
//  delay(t);
//  five();
//  delay(t);
//  six();
//  delay(t);
//  seven();
//  delay(t);
//  eight();
//  delay(t);
//  nine();
//  delay(t);
  return false;
}


void zero(int theD) {
  
  digitalWrite(theD, LOW); 
  
  // Pull high to engage the letter
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, LOW);
  digitalWrite(dot, LOW);
}

void one(int theD) {

  digitalWrite(theD, LOW);

  // Pull high to engage the letter
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(dot, LOW);
}

void two(int theD) {
  
  digitalWrite(theD, LOW);

  // Pull high to engage the letter
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(dot, LOW);
}

//void three() {
//  
//  // Pull high to engage the letter
//  digitalWrite(segA, HIGH);
//  digitalWrite(segB, HIGH);
//  digitalWrite(segC, HIGH);
//  digitalWrite(segD, HIGH);
//  digitalWrite(segE, LOW);
//  digitalWrite(segF, LOW);
//  digitalWrite(segG, HIGH);
//  digitalWrite(dot, LOW);
//}
//
//void four() {
//
//  // Pull high to engage the letter
//  digitalWrite(segA, LOW);
//  digitalWrite(segB, HIGH);
//  digitalWrite(segC, HIGH);
//  digitalWrite(segD, LOW);
//  digitalWrite(segE, LOW);
//  digitalWrite(segF, HIGH);
//  digitalWrite(segG, HIGH);
//  digitalWrite(dot, LOW);
//}
//
//void five() {
//
//  // Pull high to engage the letter
//  digitalWrite(segA, HIGH);
//  digitalWrite(segB, LOW);
//  digitalWrite(segC, HIGH);
//  digitalWrite(segD, HIGH);
//  digitalWrite(segE, LOW);
//  digitalWrite(segF, HIGH);
//  digitalWrite(segG, HIGH);
//  digitalWrite(dot, LOW);
//}
//
//void six() {
//
//  // Pull high to engage the letter
//  digitalWrite(segA, HIGH);
//  digitalWrite(segB, LOW);
//  digitalWrite(segC, HIGH);
//  digitalWrite(segD, HIGH);
//  digitalWrite(segE, HIGH);
//  digitalWrite(segF, HIGH);
//  digitalWrite(segG, HIGH);
//  digitalWrite(dot, LOW);
//}
//
//void seven() {
//
//  // Pull high to engage the letter
//  digitalWrite(segA, HIGH);
//  digitalWrite(segB, HIGH);
//  digitalWrite(segC, HIGH);
//  digitalWrite(segD, LOW);
//  digitalWrite(segE, LOW);
//  digitalWrite(segF, LOW);
//  digitalWrite(segG, LOW);
//  digitalWrite(dot, LOW);
//}
//
//void eight() {
//
//  // Pull high to engage the letter
//  digitalWrite(segA, HIGH);
//  digitalWrite(segB, HIGH);
//  digitalWrite(segC, HIGH);
//  digitalWrite(segD, HIGH);
//  digitalWrite(segE, HIGH);
//  digitalWrite(segF, HIGH);
//  digitalWrite(segG, HIGH);
//  digitalWrite(dot, LOW);
//}
//
//void nine() {
//
//  // Pull high to engage the letter
//  digitalWrite(segA, HIGH);
//  digitalWrite(segB, HIGH);
//  digitalWrite(segC, HIGH);
//  digitalWrite(segD, LOW);
//  digitalWrite(segE, LOW);
//  digitalWrite(segF, HIGH);
//  digitalWrite(segG, HIGH);
//  digitalWrite(dot, LOW);
//}
