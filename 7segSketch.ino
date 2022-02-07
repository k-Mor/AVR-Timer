// Constants
int flashTime = 1;
int actualTime = 249;
int speedAdjustment = .9;
int del = 400;
int maxVal = 1023;
int maxCount = 10;
int minCount = 6;
int theNums[] = { &zero, &one, &two, &three, &four, &five, &six, &seven, &eight, &nine };

// Digits 
int D1 = 2;
int D2 = 3; 
int D3 = 4;
int D4 = 5;
int allDigits[] = { D1, D2, D3, D4 };

// Segments
int segA = 6;
int segB = 7;
int segC = 8;
int segD = 9;
int segE = 10;
int segF = 11;
int segG = 12;
int btn = 13;
int btn2 = A1;
int allSegments[] = { segA, segB, segC, segD, segE, segF, segG };

void setup() {
  
  for (int i = 0; i < 4; i++) {         // remove magic number
    pinMode(allDigits[i], OUTPUT);
    digitalWrite(allDigits[i], HIGH);
  }
  
  for (int i = 0; i < 7; i++) {         // remove magic number 
    pinMode(allSegments[i], OUTPUT);
}
  
  pinMode(btn, INPUT);
  Serial.begin(9600);
}

void loop() {

  stateOne:
  if (digitalRead(btn) == HIGH) {
    
    delay(del);

    for (int x = 0; x < maxCount; x++) {
      // Thousands
      for (int i = 0; i < maxCount; i++) {      // Hundreds
        actualTime -= speedAdjustment;
        
        for (int j = 0; j < minCount; j++) {     // Tens
          
          for (int k = 0; k < maxCount; k++) {  // Ones

            if (digitalRead(btn) == HIGH) {
                pause(btn, del);
            }

            // If the reset button is pressed, bo back to state 1
            if (analogRead(btn2) >= maxVal) { 
              goto stateOne;
            }
            
            showDigits(theNums[k], theNums[j], theNums[i], theNums[x],flashTime, actualTime);
          }
        }
      }
    }
  }
}

void pause(int theBtn, int theDel) {

    delay(theDel);
    while (digitalRead(theBtn) == LOW) { // While the button is not pressed
      delay(theDel);
    }
}


int showDigits(int (*ones)(int, int), int (*tens)(int, int),int (*hundreds)(int, int), int (*thousands)(int, int),int theFlashTime, int theActualTime) {

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
