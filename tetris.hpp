#pragma once

#include "constante.hpp"

// Classe principal do jogo
class TetrisEmbarcado {
private:
  // Declaração de variáveis privadas.
  // Dimenções do tabuleiro
  uint8_t lines{ 125 }, cols{ 62 };
  uint8_t dirx;  // Variável que faz o movimento do jogo.
  // Limite do score é 255
  uint8_t score{ 0 };      // Variável da pontuação do jogo.
  uint8_t flags;           // Variável que pega os eventos do teclado.
  bool rotate{ false };    // Variável que detecta a ação do teclado de girar a peça.
  bool gameover{ false };  // Variável que controla se o jogo continua ou para.
  // float timercount;

  // Declaração da variável do display
  Adafruit_SSD1306 display;

  // Struct que define os pontos cartesianos x e y.
  // Os vetores são para definir a orientação das peças.
  struct Point {
    uint8_t x, y;
  } z[squares], k[squares];

protected:
  // Declaração das funções protegidas.
  uint8_t events();

  void logicMenu();
  void moveToDown();
  void setRotate();
  void resetValues();
  void changePosition();
  bool maxLimit();
  void setScore();
  void draw_ui();
  void draw_gameover();
  void draw_game();
  void logo();

public:
  // Declaração das funções publicas.
  void setup();
  void loop();
};