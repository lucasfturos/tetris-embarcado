#include "tetris.hpp"

uint8_t TetrisEmbarcado::events() {
  pinMode(KEY_START, INPUT);
  pinMode(KEY_RESTART, INPUT);
  pinMode(KEY_LEFT, INPUT);
  pinMode(KEY_RIGHT, INPUT);
  pinMode(KEY_DASH, INPUT_PULLUP);
  pinMode(KEY_ROTATE, INPUT_PULLUP);
  uint8_t stateButtonStart = digitalRead(KEY_START);
  uint8_t stateButtonRestart = digitalRead(KEY_RESTART);
  uint8_t stateButtonLeft = digitalRead(KEY_LEFT);
  uint8_t stateButtonRight = digitalRead(KEY_RIGHT);
  uint8_t stateButtonDash = digitalRead(KEY_DASH);
  uint8_t stateButtonRotate = digitalRead(KEY_ROTATE);

  if (stateButtonStart == HIGH) {
    return flags = 1;
  }
  if (stateButtonRestart == HIGH) {
    return flags = 2;
  }
  if (stateButtonLeft == HIGH) {
    return flags = 3;
  }
  if (stateButtonRight == HIGH) {
    return flags = 4;
  }  if (stateButtonDash == LOW) {
    return flags = 5;
  }
  if (stateButtonRotate == LOW) {
    return flags = 6;
  }
}

void TetrisEmbarcado::logicMenu() {
  display.clearDisplay();
  switch (events()) {
    case 1:
      display.clearDisplay();
      digitalWrite(13, HIGH);
      draw();
      break;
    case 2:
      display.clearDisplay();
      logo();
      digitalWrite(13, LOW);
      break;
    case 3:
      --dirx;
      break;
    case 4:
      ++dirx;
      break;
    default:
      display.clearDisplay();
      logo();
      digitalWrite(13, LOW);
      break;
  }
}

void TetrisEmbarcado::moveToDown() {
  if (flags == 5) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }
  for (auto i{ 0 }; i < squares; ++i) {
    //k[i] = z[i];
    z[i].y += 2;
  }

  if (maxLimit()) {
    int number = rand() % shapes;
    for (auto i{ 0 }; i < squares; ++i) {
      z[i].x = forms[number][i] % 2;
      z[i].y = forms[number][i] / 2;
    }
  }
}

void TetrisEmbarcado::setRotate() {
  if (flags == 6) {
    digitalWrite(13, HIGH);
    Point p = z[1];
    for (auto i{ 0 }; i < squares; ++i) {
      int x = z[i].y - p.y;
      int y = z[i].x - p.x;

      z[i].x = p.x - x;
      z[i].y = p.y + y;
    }

    if (maxLimit()) {
      for (auto i{ 0 }; i < squares; ++i) {
        z[i] = k[i];
      }
    }
  }
}

void TetrisEmbarcado::changePosition() {
  if (flags == 3 || flags == 4) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
    for (auto i{0}; i < squares; ++i) {
      k[i] = z[i];
      z[i].x += dirx;
    }

    if (maxLimit()) {
      for (auto i{0}; i < squares; ++i) {
        z[i] = k[i];
      }
    }
  }
}