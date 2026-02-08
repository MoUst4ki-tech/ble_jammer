#include "libs.h"

void afficherEntete(const char* titre) {
  ecranOLED.setCursor(20, 0);
  ecranOLED.setTextColor(SSD1306_WHITE);
  ecranOLED.setTextSize(1);
  ecranOLED.println(titre);
  ecranOLED.drawLine(0, 10, 128, 10, SSD1306_WHITE);
}

void afficherMenu(int sel) {
  ecranOLED.setTextSize(1);
  ecranOLED.setTextColor(SSD1306_WHITE);
  ecranOLED.setCursor(30, 0);
  ecranOLED.println(F(" -- MENU --"));
  ecranOLED.drawLine(0, 10, 128, 10, SSD1306_WHITE);
  
  const char* options[] = {"Scanner", "Jammer", "Infos", "Test HW"};
  
  for (int i = 0; i < 4; i++) {
    int y = 18 + (i * 12);
    if (i == sel) {
      ecranOLED.fillRect(0, y - 2, 128, 12, SSD1306_WHITE);
      ecranOLED.setTextColor(SSD1306_BLACK);
    } else {
      ecranOLED.setTextColor(SSD1306_WHITE);
    }
    ecranOLED.setCursor(5, y);
    ecranOLED.println(options[i]);
  }
}