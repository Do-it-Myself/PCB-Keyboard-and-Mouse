/*Library*/
#include <Keyboard.h>

/*Pins*/
#define SAFETY A5

/*Variables*/
int shiftflag = 0;

/*Functions*/ 
void type(char key) {
  Keyboard.press(key);
  delay(150);
  Keyboard.releaseAll();
}

void typeSpecial (byte key) {
  Keyboard.press(key);
  Keyboard.releaseAll(); 
}

void shift() {
  if (shiftflag == 0) {
    shiftflag = 1;
  }
  else {
    shiftflag = 0;
  }
}

void noShiftType (int PIN) {
  switch(PIN) {
    case 0:
      if (digitalRead(5) == 1) {
        type('1');
        break;
      }
      else if (digitalRead(6) == 1) {
        type('q');
        break;
      }
      else if (digitalRead(7) == 1) {
        type('a');
        break;
      }
      else if (digitalRead(8) == 1) {
        shift();
        break;
      }
      else if (digitalRead(9) == 1) {
        type('6');
        break;
      }
      else if (digitalRead(10) == 1) {
        type('y');
        break;
      }
      else if (digitalRead(11) == 1) {
        type('h');
        break;
      }
      else if (digitalRead(12) == 1) {
        type(' ');
        break;
      }  
    case 1:
      if (digitalRead(5) == 1) {
        type('2');
        break;
      }
      else if (digitalRead(6) == 1) {
        type('w');
        break;
      }
      else if (digitalRead(7) == 1) {
        type('s');
        break;
      }
      else if (digitalRead(8) == 1) {
        type('z');
        break;
      }
      else if (digitalRead(9) == 1) {
        type('7');
        break;
      }
      else if (digitalRead(10) == 1) {
        type('u');
        break;
      }
      else if (digitalRead(11) == 1) {
        type('j');
        break;
      }
      else if (digitalRead(12) == 1) {
        type('b');
        break;
      }
    case 2:
      if (digitalRead(5) == 1) {
        type('3');
        break;
      } 
      else if (digitalRead(6) == 1) {
        type('e');
        break; 
      }
      else if (digitalRead(7) == 1) {
        type('a');
        break;
      }
      else if (digitalRead(8) == 1) {
        type('x');
        break;
      }
      else if (digitalRead(9) == 1) {
        type('8');
        break;
      }
      else if (digitalRead(10) == 1) {
        type('i');
        break;
      }
      else if (digitalRead(11) == 1) {
        type('k');
        break;
      }
      else if (digitalRead(12) == 1) {
        type('n');
        break;
      }
    case 3:
      if (digitalRead(5) == 1) {
        type('4');
        break;
      }
      else if (digitalRead(6) == 1) {
        type('r');
        break;
      }
      else if (digitalRead(7) == 1) {
        type('f');
        break;
      }
      else if (digitalRead(8) == 1) {
        type('c');
        break;
      }
      else if (digitalRead(9) == 1) {
        type('9');
        break;
      }
      else if (digitalRead(10) == 1) {
        type('o');
        break;
      }
      else if (digitalRead(11) == 1) {
        type('l');
        break;
      }
      else if (digitalRead(12) == 1) {
        type('m');
        break;
      }
    case 4:
      if (digitalRead(5) == 1) {
        type('5');
        break;
      }
      else if (digitalRead(6) == 1) {
        type('t');
        break;
      }
      else if (digitalRead(7) == 1) {
        type('g');
        break;
      }
      else if (digitalRead(8) == 1) {
        type('v');
        break;
      }
      else if (digitalRead(9) == 1) {
        type('0');
        break;
      }
      else if (digitalRead(10) == 1) {
        type('p');
        break;
      }
      else if (digitalRead(11) == 1) {
        typeSpecial(0xB2); // KEY_BACKSPACE
        break;
      }
      else if (digitalRead(12) == 1) {
        typeSpecial(0xE0); // KEY_KP_ENTER
        break;
      }
               
  }
}

void output (int PIN) {
  switch(PIN) {
    case 0: 
      digitalWrite(0, HIGH);
      digitalWrite(1, LOW);
      noShiftType(0);
      break;
    case 1:
      digitalWrite(0, LOW);
      digitalWrite(1, HIGH);
      noShiftType(1);
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
  Serial.println("Typing...");
  
  output(0);
  output(1);
  output(2);
  output(3);
  output(4);


}
