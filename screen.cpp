#include "tetris.hpp"

// Função que desenha a interface do jogo
void TetrisEmbarcado::draw_ui() {
    display.setRotation(3);
    display.setCursor(3, 0);
    display.setTextColor(1);
    display.setTextSize(1);
    display.println("Score:" + String(score));
    display.setRotation(4);
    display.drawBitmap(0, 0, bitmap_Borda_Tabuleiro, lines, cols, 1);
}

// Função que desenha as peças do jogo
void TetrisEmbarcado::draw() {
    for (uint8_t i{0}; i < display.width() - 3; ++i) {
        for (uint8_t j{0}; j < display.height() - 3; ++j) {
            for (uint8_t k{0}; k < squares; ++k) {
                if (j == z[k].y && i == z[k].x) {
                    display.setRotation(3);
                    display.drawBitmap(z[k].x, z[k].y, bitmap_Bloco, 5, 5, 1);
                }
            }
        }
    }
    draw_ui();
    display.display();
}

// Função que define os limites do tabuleiro
bool TetrisEmbarcado::maxLimit() {
    for (uint8_t i{0}; i < squares; ++i) {
        if (z[i].x < 1 || z[i].x >= display.width() - 3 ||
            z[i].y >= display.height() - 3 || z[i].y < 1) {
            return true;
        }
    }
    return false;
}

// Função que desenha a tela inicial do jogo
void TetrisEmbarcado::logo() {
    display.clearDisplay();
    display.setRotation(3);
    display.drawBitmap(0, 0, bitmap_logo_tela_inicial, cols, lines, 1);
    display.display();
}
