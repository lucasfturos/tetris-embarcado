#include "tetris.hpp"

void TetrisEmbarcado::events() {
    pinMode(KEY_START, INPUT);
    pinMode(KEY_LEFT, INPUT_PULLUP);
    pinMode(KEY_RIGHT, INPUT_PULLUP);
    pinMode(KEY_DASH, INPUT_PULLUP);
    pinMode(KEY_ROTATE, INPUT_PULLUP);
    uint8_t stateButtonStart = digitalRead(KEY_START);
    uint8_t stateButtonLeft = digitalRead(KEY_LEFT);
    uint8_t stateButtonRight = digitalRead(KEY_RIGHT);
    uint8_t stateButtonDash = digitalRead(KEY_DASH);
    uint8_t stateButtonRotate = digitalRead(KEY_ROTATE);

    if (stateButtonStart == HIGH) {
        display.clearDisplay();
        digitalWrite(13, HIGH);
        draw();
    } else if (stateButtonStart == LOW) {
        logo();
        digitalWrite(13, LOW);
    }

    if (stateButtonLeft == LOW) {
        flags = 1;
    } else if (stateButtonRight == LOW) {
        flags = 2;
    } else if (stateButtonDash == LOW) {
        flags = 3;
    } else if (stateButtonRotate == LOW) {
        flags = 4;
    }
}

void TetrisEmbarcado::moveToDown() {
    if (flags == 3) {
        digitalWrite(13, HIGH);
    }
    for (auto i{0}; i < squares; ++i) {
        k[i] = z[i];
        z[i].y += 2;
    }

    if (maxLimit()) {
        int number = rand() % shapes;
        for (auto i{0}; i < squares; ++i) {
            z[i].x = forms[number][i] % 2;
            z[i].y = forms[number][i] / 2;
        }
    }
}

void TetrisEmbarcado::setRotate() {
    if (flags == 4) {
        digitalWrite(13, HIGH);
        Point p = z[1];
        for (auto i{0}; i < squares; ++i) {
            int x = z[i].y - p.y;
            int y = z[i].x - p.x;

            z[i].x = p.x - x;
            z[i].y = p.y + y;
        }

        if (maxLimit()) {
            for (auto i{0}; i < squares; ++i) {
                z[i] = k[i];
            }
        }
    }
}

void TetrisEmbarcado::changePosition() {}
