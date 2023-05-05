#pragma once

#include <Wire.h>
#include <Arduino.h>
#include <avr/pgmspace.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Display
const uint8_t lines{ 128 }, cols{ 64 };
const uint8_t OLED_RESET{ -1 };

// Botões
const uint8_t KEY_START{ 2 };
const uint8_t KEY_RESTART{ 3 };
const uint8_t KEY_LEFT{ 4 };
const uint8_t KEY_RIGHT{ 5 };
const uint8_t KEY_DASH{ 6 };
const uint8_t KEY_ROTATE{ 7 };

// Objetos do jogo
#include "./ui/borda_tabuleiro.hpp"
#include "./ui/logo_game.hpp"
// 'Bloco', 5x5px
const unsigned char bitmap_Bloco[] PROGMEM = { 0xf8, 0xf8, 0xf8, 0xf8, 0xf8 };