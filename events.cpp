#include "tetris.hpp"

// Função que pega os eventos do teclado
uint8_t TetrisEmbarcado::events() {
  // Definição do modo dos botões
  pinMode(KEY_START, INPUT);
  pinMode(KEY_RESTART, INPUT);
  pinMode(KEY_LEFT, INPUT);
  pinMode(KEY_RIGHT, INPUT);
  pinMode(KEY_DASH, INPUT);
  pinMode(KEY_ROTATE, INPUT);

  uint8_t flags = 0;  // Variável que pega os eventos do teclado.

  // Condição que pega o estado do botões e define na variável flags
  if (digitalRead(KEY_START) == HIGH) {
    return flags = 1;
  }
  if (digitalRead(KEY_RESTART) == HIGH) {
    return flags = 2;
  }
  if (digitalRead(KEY_LEFT) == HIGH) {
    return flags = 3;
  }
  if (digitalRead(KEY_RIGHT) == HIGH) {
    return flags = 4;
  }
  if (digitalRead(KEY_DASH) == HIGH) {
    return flags = 5;
  }
  if (digitalRead(KEY_ROTATE) == HIGH) {
    return flags = 6;
  }
  return flags;
}

// Função que define as ações do jogo
void TetrisEmbarcado::logicMenu() {
  uint8_t event = events();
  switch (event) {
    case 1:
      // digitalWrite(13, HIGH);
      // startgame = true;
      // gameover = false;
      break;
    case 2:
      // digitalWrite(13, LOW);
      // resetGame();
      // gameover = true;
      // startgame = false;
      break;
    case 3:
      digitalWrite(13, HIGH);
      --dirx;
      break;
    case 4:
      digitalWrite(13, HIGH);
      ++dirx;
      break;
    case 5:
      digitalWrite(13, HIGH);
      break;
    case 6:
      digitalWrite(13, HIGH);
      rotate = true;
      break;
      //   default:
      //     digitalWrite(13, LOW);
      //     logo();
      //     startgame = false;
      //     gameover = true;
      //     break;
  }
}

// Função que redefine os valores.
void TetrisEmbarcado::resetValues() {
  dirx = 0;
  rotate = false;
}

void TetrisEmbarcado::gameOver() {
  display.clearDisplay();
  drawGameover();
  gameover = true;
  digitalWrite(13, LOW);
}

// Função que calcula os pontos do jogador.
void TetrisEmbarcado::setScore() {
  // score++;
}