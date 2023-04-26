#include "constante.hpp"
#include "formas.hpp"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_RESET 4  
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize the OLED display
  display.clearDisplay();
  uint8_t color = 1;
  for (int16_t i = 0; i < display.height() / 2; i += 3) {
    // alternate colors
    display.fillRect(i, i, display.width() - 2, display.height() - 2, color % 2);
    display.display();
    color++;
  }
}

void loop() {
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
