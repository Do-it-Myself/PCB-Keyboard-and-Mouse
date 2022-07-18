/*Library*/
#include <Keyboard.h>
#include <Mouse.h>

/*Pins*/
#define X A0
#define Y A1
#define LEFT A2
#define RIGHT A3

#define SAFETY A5
#define LIGHTBULB 16

/*Variables*/
int shiftflag = 0;
int typecount = 0;
int casecount = 99;
int typelim = 50;

int range = 13;
int centre = (range - 1) /2;

/*Functions - keyboard*/ 
void type(char key) {
  if (typecount == 1) {
    Serial.println(typecount);
    typecount = typecount + 1;
    Keyboard.press(key);
    delay(150);
    Keyboard.releaseAll();
  }
  else if (typecount < typelim) {
    Serial.println(typecount);
    typecount = typecount + 1;
  }
}

void typeSpecial (byte key) {
  if (typecount == 1){
    Serial.println(typecount);
    typecount = typecount + 1;
    Keyboard.press(key);
    delay(150);
    Keyboard.releaseAll();
  }
  else if (typecount > typelim){
    Serial.println(typecount);
    typecount = typecount + 1;
    Keyboard.press(key);
    delay(75);
    Keyboard.releaseAll();
  }
  else {
    Serial.println(typecount);
    typecount = typecount + 1;
  }
}

void typeSymbol(char key) {
  if (typecount == typelim) {
    Serial.println(typecount);
    typecount = typecount + 1;
    Keyboard.press(0xB2);
    Keyboard.press(key);
    delay(150);
    Keyboard.releaseAll();
  }
  else if (typecount > typelim) {
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
      if (digitalRead(5) == 1) {
        type('1');
        typeSymbol('!');
        casecount = 0;
        break;
      }
      else if (digitalRead(6) == 1) {
        type('q');
        typeSymbol('~');
        casecount = 0;
        break;
      }
      else if (digitalRead(7) == 1) {
        type('a');
        typeSymbol('`');
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
        typeSymbol('^');
        casecount = 0;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('y');
        typeSymbol('|');
        casecount = 0;
        break;
      }
      else if (digitalRead(14) == 1) {
        type('h');
        typeSymbol('<');
        casecount = 0;
        break;
      }
      else if (digitalRead(15) == 1) {
        type(' ');
        casecount = 0;
        break;
      }
      else {
        if (casecount == 0) {
          casecount = 99;
          typecount = 0;
        }
        break;
      }
    case 1:
      if (digitalRead(5) == 1) {
        type('2');
        typeSymbol('@');
        casecount = 1;
        break;
      }
      else if (digitalRead(6) == 1) {
        type('w');
        typeSymbol('\"');
        casecount = 1;
        break;
      }
      else if (digitalRead(7) == 1) {
        type('s');
        typeSymbol('_');
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
        typeSymbol('&');
        casecount = 1;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('u');
        typeSymbol('{');
        casecount = 1;
        break;
      }
      else if (digitalRead(14) == 1) {
        type('j');
        typeSymbol('>');
        casecount = 1;
        break;
      }
      else if (digitalRead(15) == 1) {
        type('b');
        typeSymbol(',');
        casecount = 1;
        break;
      }
      else {
        if (casecount == 1) {
          casecount = 99;
          typecount = 0;
        }
        break;
      }  
    case 2:
      if (digitalRead(5) == 1) {
        type('3');
        typeSymbol('#');
        casecount = 2;
        break;
      } 
      else if (digitalRead(6) == 1) {
        type('e');
        typeSymbol('\'');
        casecount = 2;
        break; 
      }
      else if (digitalRead(7) == 1) {
        type('d');
        typeSymbol('-');
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
        typeSymbol('*');
        casecount = 2;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('i');
        typeSymbol('}');
        casecount = 2;
        break;
      }
      else if (digitalRead(14) == 1) {
        type('k');
        typeSymbol('\\');
        casecount = 2;
        break;
      }
      else if (digitalRead(15) == 1) {
        type('n');
        typeSymbol('.');
        casecount = 2;
        break;
      }
      else {
        if (casecount == 2) {
          casecount = 99;
          typecount = 0;
        }
        break;
      }
    case 3:
      if (digitalRead(5) == 1) {
        type('4');
        typeSymbol('$');
        casecount = 3;
        break;
      }
      else if (digitalRead(6) == 1) {
        type('r');
        typeSymbol(':');
        casecount = 3;
        break;
      }
      else if (digitalRead(7) == 1) {
        type('f');
        typeSymbol('+');
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
        typeSymbol('(');
        casecount = 3;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('o');
        typeSymbol('[');
        casecount = 3;
        break;
      }
      else if (digitalRead(14) == 1) {
        type('l');
        typeSymbol('/');
        casecount = 3;
        break;
      }
      else if (digitalRead(15) == 1) {
        type('m');
        typeSymbol('?');
        casecount = 3;
        break;
      }
      else {
        if (casecount == 3) {
          casecount = 99;
          typecount = 0;
        }
        break;
      }
    case 4:
      if (digitalRead(5) == 1) {
        type('5');
        typeSymbol('%');
        casecount = 4;
        break;
      }
      else if (digitalRead(6) == 1) {
        type('t');
        typeSymbol(';');
        casecount = 4;
        break;
      }
      else if (digitalRead(7) == 1) {
        type('g');
        typeSymbol('=');
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
        typeSymbol(')');
        casecount = 4;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('p');
        typeSymbol(']');
        casecount = 4;
        break;
      }
      else if (digitalRead(14) == 1) {
        typeSpecial(0xB2); // KEY_BACKSPACE
        casecount = 4;
        break;
      }
      else if (digitalRead(15) == 1) {
        typeSpecial(0xE0); // KEY_KP_ENTER
        casecount = 4;
        break;
      }
      else {
        if (casecount == 4) {
          casecount = 99;
          typecount = 0;
        }
        break;
      }         
  }
}

void shiftType (int PIN) {
  switch(PIN) {
    case 0:
      if (digitalRead(5) == 1) {
        type('1');
        typeSymbol('!');
        casecount = 0;
        break;
      }
      else if (digitalRead(6) == 1) {
        type('Q');
        typeSymbol('~');
        casecount = 0;
        break;
      }
      else if (digitalRead(7) == 1) {
        type('A');
        typeSymbol('`');
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
        typeSymbol('^');
        casecount = 0;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('Y');
        typeSymbol('|');
        casecount = 0;
        break;
      }
      else if (digitalRead(14) == 1) {
        type('H');
        typeSymbol('<');
        casecount = 0;
        break;
      }
      else if (digitalRead(15) == 1) {
        type(' ');
        casecount = 0;
        break;
      }
      else {
        if (casecount == 0) {
          casecount = 99;
          typecount = 0;
        }
        break;
      }
    case 1:
      if (digitalRead(5) == 1) {
        type('2');
        typeSymbol('@');
        casecount = 1;
        break;
      }
      else if (digitalRead(6) == 1) {
        type('W');
        typeSymbol('\"');
        casecount = 1;
        break;
      }
      else if (digitalRead(7) == 1) {
        type('S');
        typeSymbol('_');
        casecount = 1;
        break;
      }
      else if (digitalRead(8) == 1) {
        type('Z');
        casecount = 1;
        break;
      }
      else if (digitalRead(9) == 1) {
        type('7');
        typeSymbol('&');
        casecount = 1;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('U');
        typeSymbol('{');
        casecount = 1;
        break;
      }
      else if (digitalRead(14) == 1) {
        type('J');
        typeSymbol('>');
        casecount = 1;
        break;
      }
      else if (digitalRead(15) == 1) {
        type('B');
        typeSymbol(',');
        casecount = 1;
        break;
      }
      else {
        if (casecount == 1) {
          casecount = 99;
          typecount = 0;
        }
        break;
      }  
    case 2:
      if (digitalRead(5) == 1) {
        type('3');
        typeSymbol('#');
        casecount = 2;
        break;
      } 
      else if (digitalRead(6) == 1) {
        type('E');
        typeSymbol('\'');
        casecount = 2;
        break; 
      }
      else if (digitalRead(7) == 1) {
        type('A');
        typeSymbol('-');
        casecount = 2;
        break;
      }
      else if (digitalRead(8) == 1) {
        type('X');
        casecount = 2;
        break;
      }
      else if (digitalRead(9) == 1) {
        type('8');
        typeSymbol('*');
        casecount = 2;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('I');
        typeSymbol('}');
        casecount = 2;
        break;
      }
      else if (digitalRead(14) == 1) {
        type('K');
        typeSymbol('\\');
        casecount = 2;
        break;
      }
      else if (digitalRead(15) == 1) {
        type('N');
        typeSymbol('.');
        casecount = 2;
        break;
      }
      else {
        if (casecount == 2) {
          casecount = 99;
          typecount = 0;
        }
        break;
      }
    case 3:
      if (digitalRead(5) == 1) {
        type('4');
        typeSymbol('$');
        casecount = 3;
        break;
      }
      else if (digitalRead(6) == 1) {
        type('R');
        typeSymbol(':');
        casecount = 3;
        break;
      }
      else if (digitalRead(7) == 1) {
        type('F');
        typeSymbol('+');
        casecount = 3;
        break;
      }
      else if (digitalRead(8) == 1) {
        type('C');
        casecount = 3;
        break;
      }
      else if (digitalRead(9) == 1) {
        type('9');
        typeSymbol('(');
        casecount = 3;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('O');
        typeSymbol('[');
        casecount = 3;
        break;
      }
      else if (digitalRead(14) == 1) {
        type('L');
        typeSymbol('/');
        casecount = 3;
        break;
      }
      else if (digitalRead(15) == 1) {
        type('M');
        typeSymbol('?');
        casecount = 3;
        break;
      }
      else {
        if (casecount == 3) {
          casecount = 99;
          typecount = 0;
        }
        break;
      }
    case 4:
      if (digitalRead(5) == 1) {
        type('5');
        typeSymbol('%');
        casecount = 4;
        break;
      }
      else if (digitalRead(6) == 1) {
        type('T');
        typeSymbol(';');
        casecount = 4;
        break;
      }
      else if (digitalRead(7) == 1) {
        type('G');
        typeSymbol('=');
        casecount = 4;
        break;
      }
      else if (digitalRead(8) == 1) {
        type('V');
        casecount = 4;
        break;
      }
      else if (digitalRead(9) == 1) {
        type('0');
        typeSymbol(')');
        casecount = 4;
        break;
      }
      else if (digitalRead(10) == 1) {
        type('P');
        typeSymbol(']');
        casecount = 4;
        break;
      }
      else if (digitalRead(14) == 1) {
        typeSpecial(0xB2); // KEY_BACKSPACE
        casecount = 4;
        break;
      }
      else if (digitalRead(15) == 1) {
        typeSpecial(0xE0); // KEY_KP_ENTER
        casecount = 4;
        break;
      }
      else {
        if (casecount == 4) {
          casecount = 99;
          typecount = 0;
        }
        break;
      }         
  }
}

void output (int PIN) {
  switch(PIN) {
    case 0: 
      digitalWrite(0, HIGH);
      digitalWrite(4, LOW);
      if (shiftflag) {
        shiftType(0);
      }
      else {
        noShiftType(0);
      }
      break;
    case 1:
      Serial.print("output: ");
      Serial.println(1);
      digitalWrite(1, HIGH);
      digitalWrite(0, LOW);
      if (shiftflag) {
        shiftType(1);
      }
      else {
        noShiftType(1);
      }
      break;
      break;
    case 2:
      Serial.print("output: ");
      Serial.println(2);
      digitalWrite(2, HIGH);
      digitalWrite(1, LOW);
      if (shiftflag) {
        shiftType(2);
      }
      else {
        noShiftType(2);
      }
      break;
      break;
    case 3:
      Serial.print("output: ");
      Serial.println(3);
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW);
      if (shiftflag) {
        shiftType(3);
      }
      else {
        noShiftType(3);
      }
      break;
      break;
    case 4:
      Serial.print("output: ");
      Serial.println(4);
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      if (shiftflag) {
        shiftType(4);
      }
      else {
        noShiftType(4);
      }
      break;
      break;
  }
}

/* Functions - mouse*/
int readAxis(int axis) {
  int reading = analogRead(axis);
  reading = map(reading, 0, 1023, 0, range);
  int distance = reading - centre;
  
  if (abs(distance) == 1) {
    distance = 0;
  }

  return distance;
}

void leftClick() {
  if (digitalRead(LEFT) == 1) {
    Mouse.press(MOUSE_LEFT);
  }
  else {
    Mouse.release(MOUSE_LEFT);
  }
}

void rightClick() {
  if (digitalRead(RIGHT) == 1) {
    Mouse.press(MOUSE_RIGHT);
  }
  else {
    Mouse.release(MOUSE_RIGHT);
  }
}

void moveCursor() {
  Mouse.move(-readAxis(Y), readAxis(X), 0);
  delay(5);
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
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(SAFETY, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);

  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);

  Mouse.begin();

}

void loop() {
  while (digitalRead(SAFETY) != 1) {
  Serial.println("Safety");  
  }

  while (analogRead(X) > 1000 && analogRead(Y) > 1000) {
  Serial.println("Exceeded XY");
  }

  output(0);
  output(1);
  output(2);
  output(3);
  output(4);
  leftClick();
  rightClick();
  moveCursor();
}
