#include "tetris.hpp"

void TetrisEmbarcado::draw_ui() {
}

void TetrisEmbarcado::draw() {
  for (auto i{ 0 }; i < display.width() - 1; ++i) {
    for (auto j{ 0 }; j < display.height() - 1; ++j) {
      for (auto k{ 0 }; k < squares; ++k) {
        if (j == z[k].y && i == z[k].x) {
          display.fillRect(z[k].x, z[k].y, 5, 5, 1);
        }
      }
    }
  }
  display.display();
}

bool TetrisEmbarcado::maxLimit() {
  for (auto i{ 0 }; i < squares; ++i) {
    if (z[i].x < 1 || z[i].x >= display.width() - 2 || z[i].y >= display.height() - 2 || z[i].y < 1) {
      return true;
    }
  }
  return false;
}