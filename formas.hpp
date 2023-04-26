#pragma once

#include <avr/pgmspace.h>

constexpr uint8_t squares{4};
constexpr uint8_t shapes{7};

constexpr uint8_t forms[shapes][squares] PROGMEM = {
  { 0B01000100, 0B01000100 },
  { 0B11000000, 0B01000100 },
  { 0B01100000, 0B01000100 },
  { 0B01100000, 0B00000110 },
  { 0B11000000, 0B00000110 },
  { 0B01000000, 0B00001110 },
  { 0B01100000, 0B00001100 }
};

struct form_shapes {
  uint8_t form[squares][squares];
  uint8_t lines;
  uint8_t cols;
};

struct Point {
  uint8_t x, y;
};