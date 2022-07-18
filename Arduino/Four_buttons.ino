/*Library*/
#include <Keyboard.h>

/*Pins*/
#define SAFETY 13

void type(char key){
  Keyboard.press(key);
  delay(150);
  Keyboard.releaseAll();
}

void columnWrite (int PIN) {
  switch(PIN) {
    case 0:
      digitalWrite(0, HIGH);
      digitalWrite(1, LOW);
      break;
    case 1:
      digitalWrite(0, LOW);
      digitalWrite(1, HIGH);
      break;
  }
}

void noShift (int PIN) {
  switch(PIN) {
    case 0:
      if (digitalRead(6) == 1) {
        type('q');
        break;
      }
      else if (digitalRead(7) == 1) {
        type ('a');
        break;
      }
    case 1:
      if (digitalRead(6) == 1) {
        type ('w');
        break;
      }
      else if (digitalRead(7) == 1) {
        type ('s');
        break;
      }
  }
}

void setup() {
  /* Serial begin */
  Serial.begin(9600);
  
  /* Pin Mode */
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(SAFETY, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);

}

void loop() {
  while (digitalRead(SAFETY) != 1) {
  }

  Serial.println(digitalRead(5));
  Serial.println(digitalRead(6));
  Serial.println("");


  columnWrite(0);
  noShift(0);
  
  columnWrite(1);
  noShift(1);
}
