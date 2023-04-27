#include "Adafruit_SSD1306.h"
#include "tetris.hpp"

TetrisEmbarcado::TetrisEmbarcado(uint8_t width, uint8_t height, Adafruit_SSD1306 display) {
  this->lines = width;
  this->cols = height;
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize the OLED display
  display.clearDisplay();
  uint8_t color = 1;
  for (int16_t i = 0; i < display.height() / 2; i += 3) {
    // alternate colors
    display.fillRect(i, i, display.width() - 2, display.height() - 2, color % 2);
    display.display();
    color++;
  }
}

void TetrisEmbarcado::resetValues() {}

void TetrisEmbarcado::setScore() {}

void TetrisEmbarcado::run() {}