#pragma once

#include <Wire.h>
#include <Arduino.h>
#include <avr/pgmspace.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Dimenções do tabuleiro
const int lines{ 25 };
const int cols{ 10 };

// Display
const uint8_t width{ 128 }, height{ 64 };
const uint8_t OLED_RESET{ 4 };

// Botões
const uint8_t KEY_START{ 2 };
const uint8_t KEY_RIGHT{ 3 };
const uint8_t KEY_DASH{ 4 };
const uint8_t KEY_LEFT{ 5 };
const uint8_t KEY_ROTATE{ 6 };

// Setup das peças
const uint8_t squares{ 4 };
const uint8_t shapes{ 7 };

/*
    Configuração das peças
    0 1
    2 3
    4 5
    6 7

    |-----------------------------------------------------|
    |    1|       |       |       |       |       |       |
    |I = 3|Z = 2  |S =   3|T =   3|L = 2 3|J =   3|O = 2 3|
    |    5|    4 5|    4 5|    4 5|      5|      5|    4 5|
    |    7|      7|    6  |      7|      7|    6 7|       |
    |-----------------------------------------------------|
    */

const uint8_t forms[shapes][squares] = {
  { 1, 3, 5, 7 },  // I
  { 2, 4, 5, 7 },  // Z
  { 3, 5, 4, 6 },  // S
  { 3, 5, 7, 4 },  // T
  { 2, 3, 5, 7 },  // L
  { 3, 5, 7, 6 },  // J
  { 2, 4, 3, 5 },  // O
};

// Interface gráfica do jogo
#include "ui/logo_game.hpp"
// 'Bloco', 5x5px
const unsigned char bitmap_Bloco[] PROGMEM = { 248, 248, 248, 248, 248 };
const unsigned char bloco_Vazio[] PROGMEM = { 0, 0, 0, 0, 0 };