#include "tetris.hpp"

void TetrisEmbarcado::logo() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(15, 10);
  display.println("TETRIS EMBARCADO");
  display.setCursor(15, 20);
  display.println("By. Lucas Turos");
  display.display();
}