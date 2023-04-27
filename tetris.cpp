#include "tetris.hpp"

TetrisEmbarcado::TetrisEmbarcado() {
  display = Adafruit_SSD1306(OLED_RESET);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void TetrisEmbarcado::resetValues() {}

void TetrisEmbarcado::setScore() {}

void TetrisEmbarcado::run() {
  logo();
  delay(1000);
  display.clearDisplay();
  uint8_t color = 1;
  for (int16_t i = 0; i < cols / 2; i += 3) {
    display.fillRect(i, i, lines - 2, cols - 2, color % 2);
    display.display();
    color++;
  }
}