#include "tetris.hpp"

// Função principal onde define o tamanho da tela e velocidade
// de comunicação.
void TetrisEmbarcado::setup() {
  Serial.begin(115000);
  display = Adafruit_SSD1306(width, height, &Wire, OLED_RESET);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

// Função loop do jogo, pega as ações do jogador e atualiza
// os movimentos em tempo de execução. Também faz o desenho
// da interface.
void TetrisEmbarcado::loop() {
  // while (!gameover) {
  draw_game();
  // logicMenu();
  // if (!gameover) {
  //   changePosition();
  //   moveToDown();
  //   resetValues();
  //   setRotate();
  //   setScore();
  // }
  // }
}