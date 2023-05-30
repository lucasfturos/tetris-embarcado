#pragma once

#include "constante.hpp"

// Classe principal do jogo
class TetrisEmbarcado {
  private:
    // Declaração de variáveis privadas.

    // Matriz tabuleiro
    bool board[lines][cols];

    uint8_t dirx;      // Variável que faz o movimento do jogo.
    uint16_t score{0}; // Variável da pontuação do jogo. Limite do score é 990.
    bool rotate{
        false}; // Variável que detecta a ação do teclado de girar a peça.
    bool start{false};    // Variável que controla o inicio do jogo
    bool gameover{false}; // Variável que controla se o jogo continua ou para.
    uint8_t flags{0};     // Variável que pega os eventos do teclado.

    // Declaração da variável do display
    Adafruit_SSD1306 display;

    // Struct que define os pontos cartesianos x e y.
    // Os vetores são para definir a orientação das peças.
    struct Point {
        uint8_t x, y;
    } z[squares], k[squares];

  protected:
    // Declaração das funções protegidas.

    // Eventos do jogo
    void gameOver();
    void logicMenu();
    void setRotate();
    void initBoard();
    void spawPiece();
    void checkLines();
    void moveToDown();
    void resetValues();
    void checkGameOver();
    void changePosition();
    void removeLine(uint8_t line);

    bool maxLimit();
    uint8_t events();

    // Interface do jogo
    void logo();
    void drawUI();
    void setScore();
    void drawGame();
    void resetGame();
    void drawGameover();

  public:
    // Declaração das funções publicas.
    ~TetrisEmbarcado();

    void setup();
    void loop();
};
