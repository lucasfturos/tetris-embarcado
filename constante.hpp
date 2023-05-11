#pragma once

#include <Wire.h>
#include <Arduino.h>
#include <avr/pgmspace.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Display
const uint8_t width{ 128 }, height{ 64 };
const uint8_t OLED_RESET{ -1 };

// Botões
const uint8_t KEY_START{ 2 };
const uint8_t KEY_RESTART{ 3 };
const uint8_t KEY_LEFT{ 4 };
const uint8_t KEY_RIGHT{ 5 };
const uint8_t KEY_DASH{ 6 };
const uint8_t KEY_ROTATE{ 7 };

// Setup das peças
const uint8_t squares{ 4 };
const uint8_t shapes{ 7 };

// Interface gráfica do jogo
#include "ui/logo_game.hpp"
#include "ui/game_over.hpp"
#include "ui/borda_tabuleiro.hpp"
// 'Bloco', 5x5px
const unsigned char bitmap_Bloco[] PROGMEM = { 248, 248, 248, 248, 248 };

const uint8_t I0[4]  = {
  B00000000,
  B00001111,
  B00000000,
  B00000000,
};
const uint8_t I1[4]  = {
  B00000010,
  B00000010,
  B00000010,
  B00000010,
};
const uint8_t I2[4]  = {
  B00000000,
  B00000000,
  B00001111,
  B00000000,
};
const uint8_t I3[4]  = {
  B00000100,
  B00000100,
  B00000100,
  B00000100,
};
const uint8_t J0[3]  = {
  B00000100,
  B00000111,
  B00000000,
};
const uint8_t J1[3]  = {
  B00000011,
  B00000010,
  B00000010,
};
const uint8_t J2[3]  = {
  B00000000,
  B00000111,
  B00000001,
};
const uint8_t J3[3]  = {
  B00000010,
  B00000010,
  B00000110,
};
const uint8_t L0[3]  = {
  B00000001,
  B00000111,
  B00000000,
};
const uint8_t L1[3]  = {
  B00000010,
  B00000010,
  B00000011,
};
const uint8_t L2[3]  = {
  B00000000,
  B00000111,
  B00000100,
};
const uint8_t L3[3]  = {
  B00000110,
  B00000010,
  B00000010,
};
const uint8_t O0[4]  = {
  B00000000,
  B00000110,
  B00000110,
  B00000000,
};
const uint8_t S0[3]  = {
  B00000011,
  B00000110,
  B00000000,
};
const uint8_t S1[3]  = {
  B00000010,
  B00000011,
  B00000001,
};
const uint8_t S2[3]  = {
  B00000000,
  B00000011,
  B00000110,
};
const uint8_t S3[3]  = {
  B00000100,
  B00000110,
  B00000010,
};
const uint8_t T0[3]  = {
  B00000010,
  B00000111,
  B00000000,
};
const uint8_t T1[3]  = {
  B00000010,
  B00000011,
  B00000010,
};
const uint8_t T2[3]  = {
  B00000000,
  B00000111,
  B00000010,
};
const uint8_t T3[3]  = {
  B00000010,
  B00000110,
  B00000010,
};
const uint8_t Z0[3]  = {
  B00000110,
  B00000011,
  B00000000,
};
const uint8_t Z1[3]  = {
  B00000001,
  B00000011,
  B00000010,
};
const uint8_t Z2[3]  = {
  B00000000,
  B00000110,
  B00000011,
};
const uint8_t Z3[3]  = {
  B00000010,
  B00000110,
  B00000100,
};

const uint8_t forms[shapes][squares] = {
  { I0, I1, I2, I3 },
  { J0, J1, J2, J3 },
  { L0, L1, L2, L3 },
  { O0, O0, O0, O0 },
  { S0, S1, S2, S3 },
  { T0, T1, T2, T3 },
  { Z0, Z1, Z2, Z3 },
};