#include "tetris.hpp"

// Inicializar todos os campos do tabuleiro como vazios
void TetrisEmbarcado::initBoard() {
    for (uint8_t i{0}; i < lines; ++i) {
        for (uint8_t j{0}; j < cols; ++j) {
            board[i][j] = false;
        }
    }
}

// Função que desenha a interface do jogo
void TetrisEmbarcado::draw_ui() {
    display.setCursor(3, 0);
    display.setTextColor(1);
    display.setTextSize(1);
    display.println("Score:" + String(score));
    display.setRotation(4);
    display.drawBitmap(0, 0, bitmap_Borda_Tabuleiro, width, height, 1);
    display.display();
}

// Função que desenha as peças do jogo
void TetrisEmbarcado::draw_game() {
    // Inicializar a matriz board
    initBoard();
    display.clearDisplay();
    display.setRotation(3);

    for (uint8_t k{0}; k < squares; ++k) {
        uint8_t x = z[k].x;
        uint8_t y = z[k].y;
        display.drawBitmap(4 + x * 5, y * 5, bitmap_Bloco, 4, 4, 1);
    }
    draw_ui();
}

void TetrisEmbarcado::draw_gameover() {
    display.clearDisplay();
    display.setRotation(3);
    display.setCursor(5, 67);
    display.setTextColor(1);
    display.setTextSize(1);
    display.println("Score:" + String(score));
    display.drawBitmap(0, 0, bitmap_GameOver, height, width, 1);
    display.display();
}

// Função que desenha a tela inicial do jogo
void TetrisEmbarcado::logo() {
    display.clearDisplay();
    display.setRotation(3);
    display.drawBitmap(0, 0, bitmap_tela_inicial, height, width, 1);
    display.display();
}

void TetrisEmbarcado::resetGame() {
    logo();      // Exibe a tela inicial
    delay(2000); // Aguarda 2 segundos

    score = 0;        // Reinicia a pontuação
    gameover = false; // Reinicia o estado do jogo

    // Restaurar o tabuleiro para vazio
    for (uint8_t x = 1; x <= cols; ++x) {
        for (uint8_t y = 1; y <= lines; ++y) {
            board[x][y] = false;
        }
    }

    // Reiniciar o jogo
    generatePiece();
}

// Função que define os limites do tabuleiro
bool TetrisEmbarcado::maxLimit() {
    for (uint8_t i{0}; i < squares; ++i) {
        if (z[i].x < 0 || z[i].y < 0 || z[i].x >= cols + 1 ||
            z[i].y >= lines + 5 || board[z[i].x][z[i].y] ||
            board[z[i].x][z[i].y + 1]) {
            return true;
        }
    }
    return false;
}