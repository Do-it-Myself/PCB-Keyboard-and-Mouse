/*Library*/
#include <Keyboard.h>

/*Pins*/
#define SAFETY 13
#define LIGHTBULB A0

/*Variables*/
int shiftflag = 0;
int typecount = 0;
int casecount = 99;

/*Functions*/ 
void type(char key) {
  if (typecount == 1) {
    Serial.println(typecount);
    typecount = typecount + 1;
    Keyboard.press(key);
    delay(150);
    Keyboard.releaseAll();
  }
  else {
    Serial.println(typecount);
    typecount = typecount + 1;
  }
}

void typeSpecial (byte key) {
  if (typecount == 1) {
    Serial.println(typecount);
    typecount = typecount + 1;
    Keyboard.press(key);
    delay(150);
    Keyboard.releaseAll();
  }
  else {
    Serial.println(typecount);
    typecount = typecount + 1;
  }
}

void shift() {
  if (typecount == 1) {
    Serial.println(typecount);
    typecount = typecount + 1;
    
    if (shiftflag == 0) {
      shiftflag = 1;
      digitalWrite(LIGHTBULB, HIGH);
    }
    else {
      shiftflag = 0;
      digitalWrite(LIGHTBULB, LOW);
    }
  }
  else {
    Serial.println(typecount);
    typecount = typecount + 1;
  }
}

void noShiftType (int PIN) {
  switch(PIN) {
    case 0:
      Serial.print("noShiftType: ");
      Serial.println(0);
      if (digitalRead(5) == 1) {
        type('1');
        casecount = 0;
        break;
      }
      else if (digitalRead(6) == 1) {
        type('q');
        casecount = 0;
        break;
      }
      else if (digitalRead(7) == 1) {
        type('a');
        casecount = 0;
        break;
      }
      else if (digitalRead(8) == 1) {
        shift();
        casecount = 0;
        break;
      }
      else if (digitalRead(9) == 1) {
        type('6');
        casecount = 0;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('y');
        casecount = 0;
        break;
      }
      else if (digitalRead(11) == 1) {
        type('h');
        casecount = 0;
        break;
      }
      else if (digitalRead(12) == 1) {
        type(' ');
        casecount = 0;
        break;
      }
      else {
        Serial.print("(outside if) casecount: ");
          Serial.println(casecount);
        if (casecount == 0) {
          Serial.print("casecount: ");
          Serial.println(casecount);
          casecount = 99;
          typecount = 0;
          Serial.println("reset0");
        }
        break;
      }
    case 1:
      Serial.print("noShiftType: ");
      Serial.println(1);
      if (digitalRead(5) == 1) {
        type('2');
        casecount = 1;
        break;
      }
      else if (digitalRead(6) == 1) {
        type('w');
        casecount = 1;
        break;
      }
      else if (digitalRead(7) == 1) {
        type('s');
        casecount = 1;
        break;
      }
      else if (digitalRead(8) == 1) {
        type('z');
        casecount = 1;
        break;
      }
      else if (digitalRead(9) == 1) {
        type('7');
        casecount = 1;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('u');
        casecount = 1;
        break;
      }
      else if (digitalRead(11) == 1) {
        type('j');
        casecount = 1;
        break;
      }
      else if (digitalRead(12) == 1) {
        type('b');
        casecount = 1;
        break;
      }
      else {
        if (casecount == 1) {
          Serial.print("casecount: ");
          Serial.println(casecount);
          casecount = 99;
          typecount = 0;
          Serial.println("reset1");
        }
        break;
      }  
    case 2:
      Serial.print("noShiftType: ");
      Serial.println(2);
      if (digitalRead(5) == 1) {
        type('3');
        casecount = 2;
        break;
      } 
      else if (digitalRead(6) == 1) {
        type('e');
        casecount = 2;
        break; 
      }
      else if (digitalRead(7) == 1) {
        type('a');
        casecount = 2;
        break;
      }
      else if (digitalRead(8) == 1) {
        type('x');
        casecount = 2;
        break;
      }
      else if (digitalRead(9) == 1) {
        type('8');
        casecount = 2;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('i');
        casecount = 2;
        break;
      }
      else if (digitalRead(11) == 1) {
        type('k');
        casecount = 2;
        break;
      }
      else if (digitalRead(12) == 1) {
        type('n');
        casecount = 2;
        break;
      }
      else {
        if (casecount == 2) {
          Serial.print("casecount: ");
          Serial.println(casecount);
          casecount = 99;
          typecount = 0;
          Serial.println("reset2");
        }
        break;
      }
    case 3:
      Serial.print("noShiftType: ");
      Serial.println(3);
      if (digitalRead(5) == 1) {
        type('4');
        casecount = 3;
        break;
      }
      else if (digitalRead(6) == 1) {
        type('r');
        casecount = 3;
        break;
      }
      else if (digitalRead(7) == 1) {
        type('f');
        casecount = 3;
        break;
      }
      else if (digitalRead(8) == 1) {
        type('c');
        casecount = 3;
        break;
      }
      else if (digitalRead(9) == 1) {
        type('9');
        casecount = 3;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('o');
        casecount = 3;
        break;
      }
      else if (digitalRead(11) == 1) {
        type('l');
        casecount = 3;
        break;
      }
      else if (digitalRead(12) == 1) {
        type('m');
        casecount = 3;
        break;
      }
      else {
        if (casecount == 3) {
          Serial.print("casecount: ");
          Serial.println(casecount);
          casecount = 99;
          typecount = 0;
          Serial.println("reset3");
        }
        break;
      }
    case 4:
      Serial.print("noShiftType: ");
      Serial.println(4);
      if (digitalRead(5) == 1) {
        type('5');
        casecount = 4;
        break;
      }
      else if (digitalRead(6) == 1) {
        type('t');
        casecount = 4;
        break;
      }
      else if (digitalRead(7) == 1) {
        type('g');
        casecount = 4;
        break;
      }
      else if (digitalRead(8) == 1) {
        type('v');
        casecount = 4;
        break;
      }
      else if (digitalRead(9) == 1) {
        type('0');
        casecount = 4;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('p');
        casecount = 4;
        break;
      }
      else if (digitalRead(11) == 1) {
        typeSpecial(0xB2); // KEY_BACKSPACE
        casecount = 4;
        break;
      }
      else if (digitalRead(12) == 1) {
        typeSpecial(0xE0); // KEY_KP_ENTER
        casecount = 4;
        break;
      }
      else {
        if (casecount == 4) {
          Serial.print("casecount: ");
          Serial.println(casecount);
          casecount = 99;
          typecount = 0;
          Serial.println("reset4");
        }
        break;
      }         
  }
}

void output (int PIN) {
  switch(PIN) {
    case 0: 
      Serial.print("output: ");
      Serial.println(0);
      digitalWrite(0, HIGH);
      digitalWrite(4, LOW);
      noShiftType(0);
      break;
    case 1:
      Serial.print("output: ");
      Serial.println(1);
      digitalWrite(1, HIGH);
      digitalWrite(0, LOW);
      noShiftType(1);
      break;
    case 2:
      Serial.print("output: ");
      Serial.println(2);
      digitalWrite(2, HIGH);
      digitalWrite(1, LOW);
      noShiftType(2);
      break;
    case 3:
      Serial.print("output: ");
      Serial.println(3);
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW);
      noShiftType(3);
      break;
    case 4:
      Serial.print("output: ");
      Serial.println(4);
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      noShiftType(4);
      break;
  }
}

/* Main program */
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
  output(0);
  output(1);
  output(2);
  output(3);
  output(4);


}
