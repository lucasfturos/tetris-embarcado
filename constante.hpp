#pragma once

#include <Wire.h>
#include <Arduino.h>
#include <avr/pgmspace.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// Display
constexpr uint8_t SCREEN_WIDTH{ 128 };
constexpr uint8_t SCREEN_HEIGHT{ 64 };
constexpr uint8_t OLED_RESET {4};

// Botões
constexpr uint8_t KEY_ROTATE{};
constexpr uint8_t KEY_LEFT{};
constexpr uint8_t KEY_RIGHT{};
constexpr uint8_t KEY_DASH{};
constexpr uint8_t KEY_START{};
constexpr uint8_t KEY_RESET{ 3 };

// Setup Tetris
constexpr uint8_t squares{ 4 };
constexpr uint8_t shapes{ 7 };
constexpr uint8_t forms[shapes][squares] PROGMEM = {
  { 1, 3, 5, 7 },  // I
  { 2, 4, 5, 7 },  // Z
  { 3, 5, 4, 6 },  // S
  { 3, 5, 4, 7 },  // T
  { 2, 3, 5, 7 },  // L
  { 3, 5, 7, 6 },  // J
  { 2, 3, 4, 5 },  // O
};