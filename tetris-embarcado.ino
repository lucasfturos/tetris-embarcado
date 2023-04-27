#include "tetris.hpp"

Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  TetrisEmbarcado::TetrisEmbarcado(display.width(), display.height(), display);
}

void loop() {
}

void logo() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(15, 10);
  display.println("TETRIS EMBARCADO");
  display.setCursor(15, 20);
  display.println("By. Lucas Turos");
  display.display();
}
