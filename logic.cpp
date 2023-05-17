#include "tetris.hpp"

void TetrisEmbarcado::moveToDown() {
  // Variável que pega os eventos do teclado.
  uint8_t flags = events();

  // Movimento normal das peças
  for (uint8_t i = 0; i < squares; ++i) {
    k[i] = z[i];
    ++z[i].y;
    delay(90);
  }

  // Ao precionar o botão dash a peça move mais rápido
  if (flags == 5) {
    for (auto i = 0; i < squares; ++i) {
      ++z[i].y;
      delay(50);
    }
  }

  // Verifica se atingiu o limite máximo
  if (maxLimit()) {
    uint8_t number = rand() % shapes;

    // Reverte as alterações nas posições da peça atual
    for (uint8_t i = 0; i < squares; ++i) {
      --z[i].y;
    }

    // Marca as posições da peça atual no tabuleiro
    for (uint8_t i = 0; i < squares; ++i) {
      board[z[i].x][z[i].y] = true;
    }

    // Verificar se houve algum preenchimento completo de linhas
    checkLines();

    // Gerar uma nova peça
    generatePiece();
  }
}

void TetrisEmbarcado::checkLines() {
  for (uint8_t y = lines - 1; y >= 0; --y) {
    bool lineComplete = true;
    for (uint8_t x = 0; x < cols; ++x) {
      if (!board[x][y]) {
        lineComplete = false;
        break;
      }
    }
    if (lineComplete) {
      // Remove a linha completa
      for (uint8_t i = y; i > 0; --i) {
        for (uint8_t x = 0; x < cols; ++x) {
          board[x][i] = board[x][i - 1];
        }
      }
      for (uint8_t x = 0; x < cols; ++x) {
        board[x][0] = false;
      }
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
// Função que gera novas peças
void TetrisEmbarcado::generatePiece() {
  uint8_t number = rand() % shapes;

  // Defini as posições da nova peça no topo do tabuleiro
  for (uint8_t i{ 0 }; i < squares; ++i) {
    z[i].x = (cols - 3) / 2 + forms[number][i] % 2;
    z[i].y = forms[number][i] / 2;
  }

  // Verifica se a nova peça já está em uma posição ocupada no tabuleiro
  if (maxLimit()) {
    generatePiece();
  }
}

// Função que calcula os pontos do jogador.
void TetrisEmbarcado::setScore() {
  // score++;
}