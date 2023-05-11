#include "tetris.hpp"

// Função que desenha a interface do jogo
void TetrisEmbarcado::draw_ui() {
  display.setRotation(3);
  display.setCursor(3, 0);
  display.setTextColor(1);
  display.setTextSize(1);
  display.println("Score:" + String(score));
  display.setRotation(4);
  display.drawBitmap(0, 0, bitmap_Borda_Tabuleiro, width, height, 1);
}

// Função que desenha as peças do jogo
void TetrisEmbarcado::draw_game() {
  display.setRotation(3);
  for (uint8_t i{ 0 }; i < squares; ++i) {
    z[i].x = forms[5][i] % 2;
    z[i].y = forms[5][i]/ 2;
  }
  for (uint8_t i{ 0 }; i < squares; i++) {
    display.drawBitmap(z[i].x, z[i].y, bitmap_Bloco, 5, 5, 1);
  }
  //draw_ui();
  display.display();
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

// Função que calcula os pontos do jogador.
void TetrisEmbarcado::setScore() {
  //score++;
}

// Função que define os limites do tabuleiro
bool TetrisEmbarcado::maxLimit() {
  for (uint8_t i{ 0 }; i < squares; ++i) {
    if (z[i].x < 1 || z[i].x >= cols || z[i].y >= lines - 1 || z[i].y < 1) {
      return true;
    }
  }
  return false;
}