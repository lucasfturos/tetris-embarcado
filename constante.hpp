#pragma once

#include <Wire.h>
#include <Arduino.h>
#include <avr/pgmspace.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// Display
const uint8_t lines{ 128 }, cols{ 32 };
const uint8_t OLED_RESET{ -1 };

// Botões
const uint8_t KEY_ROTATE{};
const uint8_t KEY_LEFT{};
const uint8_t KEY_RIGHT{};
const uint8_t KEY_DASH{};
const uint8_t KEY_START{};
const uint8_t KEY_RESET{ 3 };

// Setup Tetris
const uint8_t squares{ 4 };
const uint8_t shapes{ 7 };
const uint8_t forms[shapes][squares] PROGMEM = {
  { 1, 3, 5, 7 },  // I
  { 2, 4, 5, 7 },  // Z
  { 3, 5, 4, 6 },  // S
  { 3, 5, 4, 7 },  // T
  { 2, 3, 5, 7 },  // L
  { 3, 5, 7, 6 },  // J
  { 2, 3, 4, 5 },  // O
};