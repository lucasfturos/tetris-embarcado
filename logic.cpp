#include "tetris.hpp"

void TetrisEmbarcado::moveToDown() {
    // Variável que pega os eventos do teclado.
    uint8_t flags{events()};
    // Movimento normal das peças
    for (uint8_t i{0}; i < squares; ++i) {
        ++z[i].y;
        delay(50);

        // Ao precionar o botão dash a peça move mais rápido
        if (flags == 4) {
            digitalWrite(13, LOW);
            ++z[i].y;
            delay(1);
        }
    }

    // Verifica se atingiu o limite máximo
    if (maxLimit()) {
        for (uint8_t i{0}; i < squares; ++i) {
            board[z[i].y - 1][z[i].x] = true;
        }

        // Verifica se houve algum preenchimento de linhas
        checkLines();

        // Gera uma nova peça
        spawPiece();
        // Checa colisão no topo do tabuleiro
        checkGameOver();
    }
}

// Função que gira a peça
void TetrisEmbarcado::setRotate() {
    if (rotate) {
        digitalWrite(13, LOW);
        Point p = z[1];
        for (uint8_t i{0}; i < squares; ++i) {
            int x = z[i].y - p.y;
            int y = z[i].x - p.x;

            z[i].x = p.x - x;
            z[i].y = p.y + y;
        }

        if (maxLimit()) {
            for (uint8_t i{0}; i < squares; ++i) {
                z[i] = k[i];
            }
        }
    }
}

// Função que move a peça para a esqueda ou direita
void TetrisEmbarcado::changePosition() {
    uint8_t flags{events()}; // Variável que pega os eventos do teclado.
    if (flags == 2 || flags == 3) {
        digitalWrite(13, LOW);
        for (uint8_t i{0}; i < squares; ++i) {
            k[i] = z[i];
            z[i].x += dirx;
        }

        if (maxLimit()) {
            for (uint8_t i{0}; i < squares; ++i) {
                z[i] = k[i];
            }
        }
    }
}

// Função que checa as linhas do tabuleiro
void TetrisEmbarcado::checkLines() {
    bool line_cleared = false;
    for (int8_t i{lines - 2}; i >= 1; --i) {
        bool full_line = true;
        for (uint8_t j{1}; j < cols - 1; ++j) {
            if (!board[i][j]) {
                full_line = false;
                break;
            }
        }
        if (full_line) {
            line_cleared = true;
            removeLine(i);
        }
    }

    if (line_cleared) {
        score += 10;
        if (score >= 990) {
            gameOver();
        }
    }
}

// Função que remove as peças caso seja completa
void TetrisEmbarcado::removeLine(uint8_t line) {
    for (int8_t i{line}; i >= 2; --i) {
        for (uint8_t j{1}; j < cols - 1; ++j) {
            board[i][j] = board[i - 1][j];
        }
    }
    for (uint8_t j{1}; j < cols - 1; ++j) {
        board[1][j] = false;
    }
}

// Função que checa se as peças tocaram no topo do tabulei
// e retorna fim do jogo
void TetrisEmbarcado::checkGameOver() {
    for (uint8_t i{0}; i < squares; ++i) {
        if (z[i].y < 1 || board[z[i].y - 1][z[i].x]) {
            gameover = true;
            return;
        }
    }
}

// Função que gera novas peças
void TetrisEmbarcado::spawPiece() {
    uint8_t number{random(shapes)};
    const uint8_t startX{(cols - 2) / 2};
    const uint8_t startY{2};

    // Defini as posições da nova peça no topo do tabuleiro
    for (uint8_t i{0}; i < squares; ++i) {
        z[i].x = startX + forms[number][i] % 2;
        z[i].y = startY + forms[number][i] / 2;
    }
}
