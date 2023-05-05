#include "tetris.hpp"

// Função que redefine os valores.
void TetrisEmbarcado::resetValues() {
  dirx = 0;
}

// Função principal onde define o tamanho da tela e velocidade
// de comunicação.
void TetrisEmbarcado::setup() {
  Serial.begin(9600);
  display = Adafruit_SSD1306(width, height, &Wire, OLED_RESET);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

// Função loop do jogo, pega as ações do jogador e atualiza
// os movimentos em tempo de execução. Também faz o desenho
// da interface.
void TetrisEmbarcado::loop() {
  // uint8_t number = rand() % shapes;
  // for (uint8_t i{0}; i < squares; ++i) {
  //     z[i].x = forms[number][i] % 2;
  //     z[i].y = forms[number][i] / 2;
  // }
  while (true) {
    logicMenu();
    if (!gameover) {
      changePosition();
      moveToDown();
      resetValues();
      setRotate();
      setScore();
    }
  }
}
