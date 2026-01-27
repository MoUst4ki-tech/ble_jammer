#include "menu.h"

void afficherMenu(Adafruit_SSD1306 &ecran, int sel) {
  ecran.setTextSize(1);
  ecran.setTextColor(SSD1306_WHITE);
  ecran.setCursor(30, 0);
  ecran.println(F("-- MENU --"));
  ecran.drawLine(0, 10, 128, 10, SSD1306_WHITE);
  
  const char* options[] = {"Scanner", "Jammer", "Informations"};
  
  for (int i = 0; i < 3; i++) {
    int y = 18 + (i * 12);
    if (i == sel) {
      ecran.fillRect(0, y - 2, 128, 12, SSD1306_WHITE);
      ecran.setTextColor(SSD1306_BLACK);
    } else {
      ecran.setTextColor(SSD1306_WHITE);
    }
    ecran.setCursor(5, y);
    ecran.println(options[i]);
  }
}
void afficherInfos(Adafruit_SSD1306 &ecran) {
  ecran.setTextSize(1);
  ecran.setTextColor(SSD1306_WHITE);
  ecran.setCursor(10, 0);
  ecran.println(F("-- Informations --"));
  ecran.drawLine(0, 10, 128, 10, SSD1306_WHITE);
  ecran.setCursor(0, 16);
  ecran.println(F("Version: 1.0.4"));
  ecran.println(F("User: Moust4ki"));
  ecran.println(F("Hardware: ESP32"));
  ecran.setCursor(0, 45);
  ecran.println(F("Statut: Operationnel"));
  ecran.print(F("Uptime: ")); 
  ecran.print(millis() / 1000);
  ecran.println(F("s"));
}