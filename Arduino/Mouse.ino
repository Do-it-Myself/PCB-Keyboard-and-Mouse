/*Library*/
#include <Mouse.h>

/*Pins*/
#define X A0
#define Y A1
#define LEFT A2
#define RIGHT A3

#define SAFETY A5

/*Variables*/
int range = 13;
int centre = (range - 1) /2;

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

void setup() {
  Serial.begin(9600);

  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);

  Mouse.begin();

  /* Delete when merge*/
  pinMode(SAFETY, OUTPUT);

}

void loop() {
  /* Delete when merge*/
  while (digitalRead(SAFETY) != 1) {
  Serial.println("Safety");  
  }

  while (analogRead(X) > 1000 && analogRead(Y) > 1000) {
  Serial.println("Exceeded XY");
  }
  
  Serial.print("readAxis X: ");
  Serial.println(readAxis(X));
  Serial.print("readAxis Y: ");
  Serial.println(readAxis(Y));

  Serial.println(analogRead(X));
  Serial.println(analogRead(Y));
  Serial.println(digitalRead(LEFT));
  Serial.println(digitalRead(RIGHT));
  Serial.println(" ");
  leftClick();
  rightClick();
  moveCursor();

}
