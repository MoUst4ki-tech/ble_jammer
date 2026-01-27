#ifndef MENU_H
  #define MENU_H
  #include <Adafruit_SSD1306.h>

enum PageActuelle { SPLASH, MENU, OUTIL_1, OUTIL_2, OUTIL_3 };
void afficherMenu(Adafruit_SSD1306 &ecran, int sel);
void afficherInfos(Adafruit_SSD1306 &ecran);

#endif