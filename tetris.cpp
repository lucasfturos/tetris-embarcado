#include "tetris.hpp"

TetrisEmbarcado::TetrisEmbarcado() {
    display = Adafruit_SSD1306(lines, cols, &Wire, OLED_RESET);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
}

void TetrisEmbarcado::resetValues() {}

void TetrisEmbarcado::setScore() {}

void TetrisEmbarcado::run() {
    logo();
    events();
}
