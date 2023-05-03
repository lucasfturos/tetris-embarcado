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
    uint8_t events();

    void logicMenu();
    void moveToDown();
    void setRotate();
    void resetValues();
    void changePosition();
    bool maxLimit();
    void setScore();
    void draw_ui();
    void draw();
    void logo();

  public:
    void setup();
    void loop();
};