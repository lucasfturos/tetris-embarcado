#include "tetris.hpp"

void TetrisEmbarcado::moveToDown() {
  // Variável que pega os eventos do teclado.
  uint8_t flags{ events() };

  // Movimento normal das peças
  for (uint8_t i{ 0 }; i < squares; ++i) {
    //  k[i] = z[i];
    ++z[i].y;
    delay(50);

    // Ao precionar o botão dash a peça move mais rápido
    if (flags == 5) {
      digitalWrite(13, LOW);
      ++z[i].y;
      delay(1);
    }
  }

  // Verifica se atingiu o limite máximo
  if (maxLimit()) {
    for (uint8_t i{ 0 }; i < squares; ++i) {
      board[z[i].x][z[i].y - 1] = true;
    }

    // Verifica se houve algum preenchimento de linhas
    checkLines();

    // Gera uma nova peça
    spawPiece();
  }
}

// Função que gira a peça
void TetrisEmbarcado::setRotate() {
  if (rotate) {
    digitalWrite(13, LOW);
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
  }
}

// Função que move a peça para a esqueda ou direita
void TetrisEmbarcado::changePosition() {
  uint8_t flags{ events() };  // Variável que pega os eventos do teclado.
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

// Função que checa as linhas do tabuleiro
void TetrisEmbarcado::checkLines() {
  for (uint8_t y = 0; y < lines + 5; ++y) {
    bool lineComplete = true;

    for (uint8_t x = 1; x <= cols + 1; ++x) {
      if (!board[x][y]) {
        lineComplete = false;
        break;
      }
    }

    if (lineComplete) {
      removeLine(y);
      ++score;
    }
  }
}

// Função que remove as peças caso seja completa
void TetrisEmbarcado::removeLine(uint8_t line) {
  for (uint8_t y = line + 5; y > 0; --y) {
    for (uint8_t x = 4; x <= cols + 1; ++x) {
      board[x][y] = board[x][y - 1];
    }
  }

  for (uint8_t x = 1; x <= cols; ++x) {
    board[x][0] = false;
  }
}

// Função que gera novas peças
void TetrisEmbarcado::spawPiece() {
  uint8_t number{ random(shapes) };
  const uint8_t startX{ (cols - 3) / 2 };
  const uint8_t startY{ 0 };

  // Defini as posições da nova peça no topo do tabuleiro
  for (uint8_t i = 0; i < squares; ++i) {
    z[i].x = startX + forms[number][i] % 2;
    z[i].y = startY + forms[number][i] / 2;
  }
}