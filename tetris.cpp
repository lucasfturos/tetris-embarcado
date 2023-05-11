#include "tetris.hpp"

// Função que redefine os valores.
void TetrisEmbarcado::resetValues() {
  dirx = 0;
  rotate = false;
}

// Função principal onde define o tamanho da tela e velocidade
// de comunicação.
void TetrisEmbarcado::setup() {
  Serial.begin(9600);
  display = Adafruit_SSD1306(width, height, &Wire, OLED_RESET);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  //logo();
}

// Função loop do jogo, pega as ações do jogador e atualiza
// os movimentos em tempo de execução. Também faz o desenho
// da interface.
void TetrisEmbarcado::loop() {
  while (true) {
    draw_game();
    // logicMenu();
    // if (!gameover) {
    //   changePosition();
    //moveToDown();
    //   resetValues();
    //   setRotate();
    //   setScore();
    // }
  }
}