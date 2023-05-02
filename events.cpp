#include "tetris.hpp"

void TetrisEmbarcado::events() {
  pinMode(KEY_START, INPUT_PULLUP);
  pinMode(KEY_LEFT, INPUT_PULLUP);
  pinMode(KEY_RIGHT, INPUT_PULLUP);
  pinMode(KEY_DASH, INPUT_PULLUP);
  pinMode(KEY_ROTATE, INPUT_PULLUP);
  uint8_t stateButtonStart = digitalRead(KEY_START);
  uint8_t stateButtonLeft = digitalRead(KEY_LEFT);
  uint8_t stateButtonRight = digitalRead(KEY_RIGHT);
  uint8_t stateButtonDash = digitalRead(KEY_DASH);
  uint8_t stateButtonRotate = digitalRead(KEY_ROTATE);

  if (stateButtonStart == LOW) {
    display.clearDisplay();
    digitalWrite(13, HIGH);
    draw();
  } else if (stateButtonStart == HIGH) {
    logo();
    digitalWrite(13, LOW);
  }

  if (stateButtonLeft == LOW) {
    flags = 1;
  } else if (stateButtonRight == LOW) {
    flags = 2;
  } else if (stateButtonDash == LOW) {
    flags = 3;
  } else if (stateButtonRotate == LOW) {
    flags = 4;
  }
}

void TetrisEmbarcado::moveToDown() {
  if (flags == 3) {
    digitalWrite(13, HIGH);
  }
}

void TetrisEmbarcado::setRotate() {
  if (flags == 4) {
    digitalWrite(13, HIGH);
  }
}

void TetrisEmbarcado::changePosition() {}