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
const uint8_t KEY_RIGHT{ 3 };
const uint8_t KEY_DASH{ 4 };
const uint8_t KEY_LEFT{ 5 };
const uint8_t KEY_ROTATE{ 6 };

// Setup das peças
const uint8_t squares{ 4 };
const uint8_t shapes{ 7 };

// Interface gráfica do jogo
#include "ui/logo_game.hpp"
// 'Bloco', 5x5px
const unsigned char bitmap_Bloco[] PROGMEM = { 248, 248, 248, 248, 248 };