#include "libs.h"

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
const int OLED_ADDR = 0x3C;
Adafruit_SSD1306 ecranOLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
BluetoothSerial SerialBT;
BLEScan* pBLEScan = NULL; 
PageActuelle etat = SPLASH; 
int selection = 0;
String nomsTrouves[15];
int totalTrouve = 0;
bool scanTermine = false;
int indexSousMenu = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(PIN_BTN_UP, INPUT_PULLUP);
  pinMode(PIN_BTN_DOWN, INPUT_PULLUP);
  pinMode(PIN_BTN_OK, INPUT_PULLUP);

  if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("Erreur OLED"));
    for(;;);
  }
  
  ecranOLED.clearDisplay();
  ecranOLED.drawBitmap(0, 0, logo_moust4ki, 128, 64, WHITE);
  ecranOLED.display(); 
  delay(2000);
  
  etat = MENU;
  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setActiveScan(true);
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);
  SerialBT.begin("ESP32_Moust4ki");
}

void loop() {
  if (digitalRead(PIN_BTN_UP) == LOW) {
    if (etat == MENU) selection = (selection <= 0) ? 3 : selection - 1;
    else if (etat == OUTIL_1 && scanTermine) indexSousMenu = (indexSousMenu <= 0) ? 0 : indexSousMenu - 1;
    delay(150); 
  }
  

  if (digitalRead(PIN_BTN_DOWN) == LOW) {
    if (etat == MENU) selection = (selection >= 3) ? 0 : selection + 1;
    else if (etat == OUTIL_1 && scanTermine) {
      int maxScroll = (totalTrouve > 4) ? totalTrouve - 4 : 0; 
      indexSousMenu = (indexSousMenu >= maxScroll) ? maxScroll : indexSousMenu + 1;
    }
    delay(150);
  }
  
  if (digitalRead(PIN_BTN_OK) == LOW) {
    if (etat == MENU) {
      if (selection == 0) etat = OUTIL_1;
      if (selection == 1) etat = OUTIL_2;
      if (selection == 2) etat = OUTIL_3;
      if (selection == 3) etat = OUTIL_4;
      indexSousMenu = 0;
      scanTermine = false;
    } else {
      etat = MENU;
      scanTermine = false;
      pBLEScan->stop();
    }
    delay(200);
  }

  ecranOLED.clearDisplay();
  
  switch (etat) {
    case MENU:
      afficherMenu(selection);
      break;
    case OUTIL_1:
      executerScanHybride();
      break;
    case OUTIL_2:
      afficherEntete(" -- Jammer --");
      ecranOLED.setCursor(0,25);
      ecranOLED.println("Comming soon...");
      break;
    case OUTIL_3:
      afficherInfos();
      break;
    case OUTIL_4:
      executerTestHardware();
      break;
  }
  ecranOLED.display();
}