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

/*
Configuração das formas
 0 1
 2 3
 4 5
 6 7
*/
const uint8_t forms[][squares] = {
  { 1 * 6, 3 * 6, 5 * 6, 7 * 6 },    // I
  { 2 * 1, 4 * 1, 5 * 1, 7 * 1 },    // Z
  { 3 * 6, 5 * 5, 4 * 6, 6 * 5 },    // S
  { 3 * 6, 5 * 6, 7 * 6, 4 },        // T
  { 2, 3 * 6, 5 * 6, 7 * 2 },        // L
  { 3 * 6, 5 * 6, 7 * 6, 6 * 12 },   // J
  { 2 * 6, 4 * 6, 3 + 12, 5 + 12 },  // O
};