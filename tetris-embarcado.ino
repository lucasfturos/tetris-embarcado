#include "constante.hpp"
#include "formas.hpp"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_RESET 4  
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize the OLED display
  display.clearDisplay();
}

void loop() {
  logo();
}

void logo() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(15, 10);
  display.println("TETRIS EMBARCADO");
  display.setCursor(15, 20);
  display.println("By. Lucas Turos");
  display.display();
}
