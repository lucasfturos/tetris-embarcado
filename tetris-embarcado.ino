#include "lib/Adafruit_GFX.h"
#include "lib/Adafruit_SSD1306.h"

#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialize the OLED display
  display.clearDisplay(); // Clear the display buffer
}

void loop() {
  display.clearDisplay(); // Clear the display buffer
  display.setTextSize(1); // Set the text size
  display.setTextColor(WHITE); // Set the text color
  display.setCursor(0, 0); // Set the text position
  display.println("Muito Lindo!"); // Display the text
  display.display(); // Show the text on the OLED display
}