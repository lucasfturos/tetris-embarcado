#pragma once

#include "constante.hpp"

class TetrisEmbarcado {
private:
  uint8_t dirx, score, flags;
  bool rotate, gameover;
  float timercount;

  Adafruit_SSD1306 display;

  struct Point {
    uint8_t x, y;
  } z[squares], k[squares];

protected:
  void events();
  void moveToDown();
  void setRotate();
  void resetValues();
  void changePosition();
  bool maxLimit();
  void setScore();
  void clear();
  void draw();
  void logo();

public:
  void setup();
  void loop();
};
