#include "tetris.hpp"

void TetrisEmbarcado::draw_ui() {
}

void TetrisEmbarcado::draw() {
  for (uint8_t i{ 0 }; i < display.width() - 1; ++i) {
    for (uint8_t j{ 0 }; j < display.height() - 1; ++j) {
      for (uint8_t k{ 0 }; k < squares; ++k) {
        if (j == z[k].y && i == z[k].x) {
          display.drawBitmap(z[k].x, z[k].y, bitmap_Bloco, 5, 5, 1);
        }
      }
    }
  }
  display.display();
}

bool TetrisEmbarcado::maxLimit() {
  for (uint8_t i{ 0 }; i < squares; ++i) {
    if (z[i].x < 1 || z[i].x >= display.width() - 2 || z[i].y >= display.height() - 2 || z[i].y < 1) {
      return true;
    }
  }
  return false;
}