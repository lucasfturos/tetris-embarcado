#include "tetris.hpp"

// Chamada do constructor da classe
TetrisEmbarcado::TetrisEmbarcado() {
  initBoard();
  spawPiece();
}

// Chamada do destructor
TetrisEmbarcado::~TetrisEmbarcado() {
  // Libera memória do tabuleiro
  for (uint8_t i = 0; i < lines + 5; ++i) {
    delete[] board[i];
  }
  delete[] board;
}

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
  logicMenu();
  if (!gameover /*&& startgame*/) {
    // Jogo em andamento
    drawGame();
    changePosition();
    moveToDown();
    setRotate();
    resetValues();
    setScore();
  } else {
    // Jogo encerrado
    resetGame();
  }
}