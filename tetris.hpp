#pragma once

#include "constante.hpp"

class TetrisEmbarcado {
private:
  struct Point {
    uint8_t x, y;
  } z[squares], k[squares];

  uint8_t lines, cols;
  uint8_t diry, score;
  bool rotate, gameover;
  float timercount;


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

public:
  TetrisEmbarcado(uint8_t, uint8_t, Adafruit_SSD1306);
  void run();
};
