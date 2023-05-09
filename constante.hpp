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
const unsigned char bitmap_Bloco[] PROGMEM = { 0xf8, 0xf8, 0xf8, 0xf8, 0xf8 };
const uint8_t forms[shapes][squares] = {
  { 1, 3, 5, 7 },  // I
  { 2, 4, 5, 7 },  // Z
  { 3, 5, 4, 6 },  // S
  { 3, 5, 4, 7 },  // T
  { 2, 3, 5, 7 },  // L
  { 3, 5, 7, 6 },  // J
  { 2, 3, 4, 5 },  // O
};