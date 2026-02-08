#include "libs.h"

void afficherInfos() {
  afficherEntete("  -- Info --");
  ecranOLED.setTextSize(1);
  ecranOLED.setTextColor(SSD1306_WHITE);
  ecranOLED.setCursor(0, 16);
  ecranOLED.println(F("Version: 1.0.9"));
  ecranOLED.println(F("User:    Moust4ki"));
  ecranOLED.println(F("HW:      ESP32"));
  ecranOLED.setCursor(0, 45);
  ecranOLED.println(F("Status:  Ready"));
  ecranOLED.print(F("Uptime:    ")); 
  ecranOLED.print(millis() / 1000);
  ecranOLED.println(F("s"));
}