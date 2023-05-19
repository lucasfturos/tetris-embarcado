#include "tetris.hpp"

// Inicializar todos os campos do tabuleiro como vazios
void TetrisEmbarcado::initBoard() {
  for (uint8_t i{ 0 }; i < lines; ++i) {
    for (uint8_t j{ 0 }; j < cols; ++j) {
      board[i][j] = false;
    }
  }
}

// Função que desenha a interface do jogo
void TetrisEmbarcado::drawUI() {
  display.setCursor(3, 0);
  display.setTextColor(1);
  display.setTextSize(1);
  display.println("Score:" + String(score));
  display.setRotation(4);
  display.drawBitmap(0, 0, bitmap_Borda_Tabuleiro, width, height, 1);
  display.display();
}

// Função que desenha as peças do jogo
void TetrisEmbarcado::drawGame() {
  // Inicializar a matriz board
  display.clearDisplay();
  display.setRotation(3);

  for (uint8_t i{ 0 }; i < squares; ++i) {
    uint8_t x = z[i].x;
    uint8_t y = z[i].y;
    display.drawBitmap(4 + x * 5, y * 5, bitmap_Bloco, 4, 4, 1);
  }

  for (uint8_t i{ 0 }; i < lines; ++i) {
    for (uint8_t j{ 0 }; j < cols; ++j) {
      if (board[i][j]) {
        display.drawBitmap(4 + i * 5, j * 5, bitmap_Bloco, 4, 4, 1);
      }
    }
  }
  drawUI();
}

void TetrisEmbarcado::drawGameover() {
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
  logo();       // Exibe a tela inicial
  delay(2000);  // Aguarda 2 segundos

  score = 0;         // Reinicia a pontuação
  gameover = false;  // Reinicia o estado do jogo

  initBoard();
  spawPiece();
}

// Função que define os limites do tabuleiro
bool TetrisEmbarcado::maxLimit() {
  for (uint8_t i{ 0 }; i < squares; ++i) {
    if (z[i].x < 1 || z[i].y < 1 || z[i].x >= cols + 1 || z[i].y >= lines + 5 || board[z[i].x][z[i].y]) {
      return true;
    }
  }
  return false;
}