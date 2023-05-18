#pragma once

#include "constante.hpp"

// Classe principal do jogo
class TetrisEmbarcado {
private:
  // Declaração de variáveis privadas.
  // Dimenções do tabuleiro
  static constexpr uint8_t lines{ 20 }, cols{ 10 };
  // Matriz tabuleiro
  bool board[lines][cols];

  uint8_t dirx;  // Variável que faz o movimento do jogo.
  // Limite do score é 255
  uint8_t score{ 0 };      // Variável da pontuação do jogo.
  bool rotate{ false };    // Variável que detecta a ação do teclado de girar a peça.
  bool startgame{false};          // Variável para controlar o início do jogo
  bool gameover{ false };  // Variável que controla se o jogo continua ou para.
  // float timercount;

  // Declaração da variável do display
  Adafruit_SSD1306 display;

  // Struct que define os pontos cartesianos x e y.
  // Os vetores são para definir a orientação das peças.
  struct Point {
    uint8_t x, y;
  } z[squares], k[squares];

  /*
    Configuração das peças
    0 1
    2 3
    4 5
    6 7

    |-----------------------------------------------------|
    |    1|       |       |       |       |       |       |
    |I = 3|Z = 2  |S =   3|T =   3|L = 2 3|J =   3|O = 2 3|
    |    5|    4 5|    4 5|    4 5|      5|      5|    4 5|
    |    7|      7|    6  |      7|      7|    6 7|       |
    |-----------------------------------------------------|
    */

  const uint8_t forms[shapes][squares] = {
    { 1, 3, 5, 7 },  // I
    { 2, 4, 5, 7 },  // Z
    { 3, 5, 4, 6 },  // S
    { 3, 5, 7, 4 },  // T
    { 2, 3, 5, 7 },  // L
    { 3, 5, 7, 6 },  // J
    { 2, 4, 3, 5 },  // O
  };

protected:
  // Declaração das funções protegidas.

  // Eventos do jogo
  void logicMenu();
  void moveToDown();
  void setRotate();
  void resetValues();
  void changePosition();
  bool maxLimit();
  void spawPiece();
  void gameOver();
  void checkLines();
  void removeLine(uint8_t line);

  uint8_t events();
  // Interface do jogo
  void setScore();
  void draw_ui();
  void draw_gameover();
  void draw_game();
  void logo();
  void initBoard();
  void resetGame();

public:
  // Declaração das funções publicas.
  TetrisEmbarcado();
  ~TetrisEmbarcado();

  void setup();
  void loop();
};
