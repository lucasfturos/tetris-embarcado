#pragma once

#include "constante.hpp"

// Classe principal do jogo
class TetrisEmbarcado {
private:
  // Declaração de variáveis privadas.
  uint8_t dirx;  // Variável que faz o movimento do jogo.
  // Limite do score é 255
  uint8_t score{ 0 };      // Variável da pontuação do jogo.
  uint8_t flags;           // Variável que pega os eventos do teclado.
  bool rotate{ false };    // Variável que detecta a ação do teclado de girar a peça.
  bool gameover{ false };  // Variável que controla se o jogo continua ou para.
  // float timercount;

  // Declaração da variável do display
  Adafruit_SSD1306 display;

  // Setup das peças
  static const uint8_t squares{ 4 };
  static const uint8_t shapes{ 7 };

  // Struct que define os pontos cartesianos x e y.
  // Os vetores são para definir a orientação das peças.
  struct Point {
    uint8_t x, y;
  } z[squares], k[squares];

  // Matriz com a posição das peças.
  uint8_t forms[shapes][squares] = {
    { 1, 3, 5, 7 },  // I
    { 2, 4, 5, 7 },  // Z
    { 3, 5, 4, 6 },  // S
    { 3, 5, 4, 7 },  // T
    { 2, 3, 5, 7 },  // L
    { 3, 5, 7, 6 },  // J
    { 2, 3, 4, 5 },  // O
  };

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
  void draw();
  void logo();

public:
  // Declaração das funções publicas.
  void setup();
  void loop();
};
