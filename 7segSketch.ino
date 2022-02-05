using namespace std;


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
int btn = 13;


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
  pinMode(btn, INPUT);

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
  int flashTime = 1;
  int actualTime = 249 - (.18 + .18);
  bool done = false;
  int theNums[] = {&zero, &one, &two, &three, &four, &five, &six, &seven, &eight, &nine};



  if (digitalRead(btn) == HIGH) {
    delay(500);


    for (int x = 0; x < 10; x++) {        // Thousands
      //actualTime -= 1;
      for (int i = 0; i < 10; i++) {      // Hundreds
        actualTime -= .9;
        for (int j = 0; j < 6; j++) {     // Tens
          //actualTime -= .9;
          
          for (int k = 0; k < 10; k++) {  // Ones

            if (digitalRead(btn) == HIGH) {
                delay(5000);
            }
            doCount(theNums[k], theNums[j], theNums[i], theNums[x],flashTime, actualTime);
          }
        }
      }
    }
  }
}




// *******************************************
// Helper functions
// *******************************************


int doCount(int (*ones)(int, int), int (*tens)(int, int),int (*hundreds)(int, int), int (*thousands)(int, int),int theFlashTime, int theActualTime) {

  int cnt = 0;
  while (cnt < theActualTime) {
    ones(D4, theFlashTime);
    tens(D3, theFlashTime);
    hundreds(D2, theFlashTime);
    thousands(D1, theFlashTime);
    cnt++;
  }
  cnt = 0;
}

void zero(int theD, int d) {
 
  digitalWrite(theD, LOW);

  // Pull high to engage the letter
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, LOW);

  delay(d);
  digitalWrite(theD, HIGH);
}

void one(int theD, int d) {
  
  digitalWrite(theD, LOW);

  // Pull high to engage the letter
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);

  delay(d);
  digitalWrite(theD, HIGH);
}

void two(int theD, int d) {
  
  digitalWrite(theD, LOW);

  // Pull high to engage the letter
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
 
  delay(d);
  digitalWrite(theD, HIGH);
}

void three(int theD, int d) {

  digitalWrite(theD, LOW);

  
  // Pull high to engage the letter
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);

  delay(d);
  digitalWrite(theD, HIGH);
}

void four(int theD, int d) {

  digitalWrite(theD, LOW);


  // Pull high to engage the letter
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  
  delay(d);
  digitalWrite(theD, HIGH);
  
}

void five(int theD, int d) {

  digitalWrite(theD, LOW);


  // Pull high to engage the letter
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);

  delay(d);
  digitalWrite(theD, HIGH);
}

void six(int theD, int d) {

  digitalWrite(theD, LOW);


  // Pull high to engage the letter
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);

  delay(d);
  digitalWrite(theD, HIGH);
}

void seven(int theD, int d) {

  digitalWrite(theD, LOW);


  // Pull high to engage the letter
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);

  delay(d);
  digitalWrite(theD, HIGH);
}

void eight(int theD, int d) {

  digitalWrite(theD, LOW);

  // Pull high to engage the letter
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);

  delay(d);
  digitalWrite(theD, HIGH);
}

void nine(int theD, int d) {

  digitalWrite(theD, LOW);


  // Pull high to engage the letter
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);

  delay(d);
  digitalWrite(theD, HIGH);
}
