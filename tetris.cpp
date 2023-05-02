#include "tetris.hpp"

void TetrisEmbarcado::resetValues() {}

void TetrisEmbarcado::setScore() {}

void TetrisEmbarcado::setup() {
    Serial.begin(9600);
    display = Adafruit_SSD1306(lines, cols, &Wire, OLED_RESET);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
}

void TetrisEmbarcado::loop() {
    // int number = rand() % shapes;
    // for (auto i{ 0 }; i < squares; ++i) {
    //   z[i].x = forms[number][i] % 2;
    //   z[i].y = forms[number][i] / 2;
    // }
    events();
    moveToDown();
    // setRotate();
    // display.display();
}
