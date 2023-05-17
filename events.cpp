#include "tetris.hpp"

// Função que pega os eventos do teclado
uint8_t TetrisEmbarcado::events() {
  // Definição do modo dos botões
  pinMode(KEY_START, INPUT);
  pinMode(KEY_RESTART, INPUT);
  pinMode(KEY_LEFT, INPUT);
  pinMode(KEY_RIGHT, INPUT);
  pinMode(KEY_DASH, INPUT_PULLUP);
  pinMode(KEY_ROTATE, INPUT_PULLUP);

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
      if (score > 254) {
        display.clearDisplay();
        draw_gameover();
        gameover = true;
        digitalWrite(13, LOW);
      }
      break;
    case 2:
      display.clearDisplay();
      digitalWrite(13, LOW);
      logo();
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
      delay(20);
      digitalWrite(13, LOW);
      break;
    case 6:
      rotate = true;
      break;
  }
}

// Função que move a peça para baixo mais rápido
void TetrisEmbarcado::moveToDown() {
  uint8_t flags = events();  // Variável que pega os eventos do teclado.
  if (flags == 5) {
    for (auto i{ 0 }; i < squares; ++i) {
      ++z[i].y;
      delay(50);
    }
  }
  for (uint8_t i{ 0 }; i < squares; ++i) {
    k[i] = z[i];
    ++z[i].y;
    delay(90);
  }

  if (maxLimit()) {
    uint8_t number = rand() % shapes;
    for (uint8_t i = 0; i < squares; ++i) {
      z[i].x = (cols - 3) / 2 + forms[number][i] % 2;
      z[i].y = forms[number][i] / 2;
    }
  }
}

// Função que gira a peça
void TetrisEmbarcado::setRotate() {
  if (rotate) {
    digitalWrite(13, HIGH);
    Point p = z[1];
    for (uint8_t i{ 0 }; i < squares; ++i) {
      int x = z[i].y - p.y;
      int y = z[i].x - p.x;

      z[i].x = p.x - x;
      z[i].y = p.y + y;
    }

    if (maxLimit()) {
      for (uint8_t i{ 0 }; i < squares; ++i) {
        z[i] = k[i];
      }
    }
    rotate = false;
  }
}

// Função que move a peça para a esqueda ou direita
void TetrisEmbarcado::changePosition() {
  uint8_t flags = events();  // Variável que pega os eventos do teclado.

  if (flags == 3 || flags == 4) {
    digitalWrite(13, LOW);
    for (uint8_t i{ 0 }; i < squares; ++i) {
      k[i] = z[i];
      z[i].x += dirx;
    }

    if (maxLimit()) {
      for (uint8_t i{ 0 }; i < squares; ++i) {
        z[i] = k[i];
      }
    }
  }
}

// Função que redefine os valores.
void TetrisEmbarcado::resetValues() {
  dirx = 0;
}
