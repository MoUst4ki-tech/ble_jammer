#include <Wire.h>
#include <Adafruit_GFX.h>    
#include <Adafruit_SSD1306.h>
#include "images.h"
#include "menu.h"

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
const int OLED_ADDR = 0x3C;
const int PIN_BTN_1 = 33;
const int PIN_BTN_2 = 32;
const int PIN_BTN_3 = 27;

Adafruit_SSD1306 ecranOLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
PageActuelle etat = SPLASH; 
int selection = 0;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_BTN_1, INPUT_PULLUP);
  pinMode(PIN_BTN_2, INPUT_PULLUP);
  pinMode(PIN_BTN_3, INPUT_PULLUP);

  if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    for(;;);
  }
  ecranOLED.clearDisplay();
  ecranOLED.drawBitmap(0, 0, logo_moust4ki, 128, 64, WHITE);
  ecranOLED.display(); 
  delay(3000);
  etat = MENU;
}

void loop() {
  if (digitalRead(PIN_BTN_1) == LOW) {
    if(etat == MENU) {
      selection = (selection <= 0) ? 2 : selection - 1;
    } else {
      etat = MENU;
    }
    delay(200); 
  }

  if (digitalRead(PIN_BTN_2) == LOW) {
    selection = (selection >= 2) ? 0 : selection + 1;
    delay(200);
  }
  if (digitalRead(PIN_BTN_3) == LOW) {
    if (selection == 0) etat = OUTIL_1;
    if (selection == 1) etat = OUTIL_2;
    if (selection == 2) etat = OUTIL_3;
    delay(200);
  }
  ecranOLED.clearDisplay();
  switch (etat) {
    case MENU:
      afficherMenu(ecranOLED, selection);
      break;
    case OUTIL_1:
      afficherEntete("-- Scanner --");
      break;
    case OUTIL_2:
      afficherEntete("-- Jammer --");
      break;
    case OUTIL_3:
      afficherInfos(ecranOLED);
      break;
  }
  ecranOLED.display();
}

void afficherEntete(const char* titre) {
  ecranOLED.setCursor(20, 0);
  ecranOLED.setTextColor(SSD1306_WHITE);
  ecranOLED.println(titre);
  ecranOLED.drawLine(0, 10, 128, 10, SSD1306_WHITE);
}