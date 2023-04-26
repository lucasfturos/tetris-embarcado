#pragma once

#include <avr/pgmspace.h>

uint8_t lines, cols;

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

struct Point {
  uint8_t x, y;
} z[squares], k[squares];