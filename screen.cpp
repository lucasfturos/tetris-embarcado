#include "tetris.hpp"

void TetrisEmbarcado::clear() {}

void TetrisEmbarcado::draw() {
    display.fillRect(2, -2, lines/2,  cols/ 2, SSD1306_INVERSE);
    display.display();
}

bool TetrisEmbarcado::maxLimit() {}
