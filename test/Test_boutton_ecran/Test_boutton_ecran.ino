#include <Wire.h>
#include <Adafruit_GFX.h>    
#include <Adafruit_SSD1306.h>

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
const int OLED_ADDR = 0x3C;
const int PIN_BTN_1 = 19;
const int PIN_BTN_2 = 18;
const int PIN_BTN_3 = 17;

Adafruit_SSD1306 ecranOLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  pinMode(PIN_BTN_1, INPUT_PULLUP);
  pinMode(PIN_BTN_2, INPUT_PULLUP);
  pinMode(PIN_BTN_3, INPUT_PULLUP);
  if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("Echec init OLED"));
    for(;;);
  }
  afficherMessage("Systeme", "Pret !");
  delay(1000);
  ecranOLED.clearDisplay();
  ecranOLED.display();
}

void loop() {
  if (digitalRead(PIN_BTN_1) == LOW) {
    gestionBouton("BOUTON 1", "Pin 19 active");
  }
  else if (digitalRead(PIN_BTN_2) == LOW) {
    gestionBouton("BOUTON 2", "Pin 18 active");
  }
  else if (digitalRead(PIN_BTN_3) == LOW) {
    gestionBouton("BOUTON 3", "Pin 17 active");
  }
}

void gestionBouton(String titre, String sousTitre) {
  afficherMessage(titre, sousTitre);
  delay(200);
}

void afficherMessage(String ligne1, String ligne2) {
  ecranOLED.clearDisplay();
  ecranOLED.setCursor(0, 0);
  ecranOLED.setTextColor(SSD1306_WHITE);
  ecranOLED.println(ligne1);
  ecranOLED.println(ligne2);
  ecranOLED.setTextSize(1);
  ecranOLED.display();
}