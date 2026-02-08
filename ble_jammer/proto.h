#ifndef PROTO_H
#define PROTO_H

#include "include.h"


#define PIN_BTN_UP   33
#define PIN_BTN_DOWN 32
#define PIN_BTN_OK   27
#define SCAN_TIME    5


enum PageActuelle { SPLASH, MENU, OUTIL_1, OUTIL_2, OUTIL_3, OUTIL_4 };


extern Adafruit_SSD1306 ecranOLED;
extern BluetoothSerial SerialBT;
extern BLEScan* pBLEScan;
extern String nomsTrouves[];
extern int totalTrouve;
extern bool scanTermine;
extern int indexSousMenu;
void afficherMenu(int sel);
void afficherInfos();
void afficherEntete(const char* titre);
void executerScanHybride();
void executerTestHardware();

#endif