#include "tetris.hpp"

// Inicializar todos os campos do tabuleiro como vazios
void TetrisEmbarcado::initBoard() {
  for (uint8_t i{ 0 }; i < lines; ++i) {
    for (uint8_t j{ 0 }; j < cols; ++j) {
      board[i][j] = false;
    }
  }
}

// Função que desenha o tabuleiro do jogo
void TetrisEmbarcado::drawUI() {
  uint8_t x0{ 1 }, y0{ 1 }, x1{ display.width() - 2 }, y1{ display.height() - 2 };
  display.setCursor(3, 0);
  display.setTextColor(1);
  display.setTextSize(1);
  display.println("Score:" + String(score));
  // Desenha a linha horizontal no final da tela
  display.drawLine(x0, y1, x1, y1, 1);
  // Desenha as linhas verticais da tela
  display.drawLine(x0, y0, x0, y1, 1);
  display.drawLine(x1, y0, x1, y1, 1);
}

// Função que desenha as peças do jogo
void TetrisEmbarcado::drawGame() {
  // Inicializar a matriz board
  display.clearDisplay();
  drawUI();
  for (uint8_t i{ 0 }; i < lines - 1; ++i) {
    for (uint8_t j{ 0 }; j < cols - 1; ++j) {
      if (board[i][j]) {
        display.drawBitmap(i * 5, j * 5, bitmap_Bloco, 4, 4, 1);
      }
    }
  }
  for (uint8_t i{ 0 }; i < squares; ++i) {
    uint8_t x = z[i].x;
    uint8_t y = z[i].y;
    display.drawBitmap(x * 5, y * 5, bitmap_Bloco, 4, 4, 1);
  }
  display.display();
}

void TetrisEmbarcado::drawGameover() {
  uint8_t x0{ 2 }, y0{ 2 };
  uint8_t x1{ display.width() - 3 }, y1{ display.height() - 3 };
  display.setCursor(5, 56);
  display.setTextColor(1);
  display.setTextSize(1);
  display.println("Game Over");
  display.setCursor(5, 67);
  display.setTextColor(1);
  display.setTextSize(1);
  display.println("Score:" + String(score));
  // Desenha a linha horizontal da tela
  for (int i = 0; i < 1; ++i) {
    display.drawLine(x0, y1 + i, x1, y1 + i, 1);
    display.drawLine(x0, y0 - i, x1, y0 - i, 1);
  }

  // Desenha as linhas verticais da tela
  for (int i = 0; i < 1; ++i) {
    display.drawLine(x0 - i, y0, x0 - i, y1, 1);
    display.drawLine(x1 + i, y0, x1 + i, y1, 1);
  }

  display.display();
}

// Função que desenha a tela inicial do jogo
void TetrisEmbarcado::logo() {
  display.clearDisplay();
  display.drawBitmap(0, 0, bitmap_tela_inicial, height, width, 1);
  display.display();
}

void TetrisEmbarcado::resetGame() {
  logo();       // Exibe a tela inicial
  delay(2000);  // Aguarda 2 segundos

  score = 0;        // Reinicia a pontuação
  gameover = true;  // Reinicia o estado do jogo

  initBoard();
  spawPiece();
}

// Função que define os limites do tabuleiro
bool TetrisEmbarcado::maxLimit() {
  for (uint8_t i{ 0 }; i < squares; ++i) {
    if (z[i].x < 1 || z[i].y < 1 || z[i].x >= cols + 2 || z[i].y >= lines + 5 || board[z[i].x][z[i].y]) {
      return true;
    }
  }
  return false;
}