#include "libs.h"

#define R1_CE     13
#define R1_CSN    14
#define R2_CE     25
#define R2_CSN    26

RF24 radio1(R1_CE, R1_CSN);
RF24 radio2(R2_CE, R2_CSN);

bool radiosInit = false;
bool r1_ok = false;
bool r2_ok = false;

void executerTestHardware() {
  if (!radiosInit) {
    r1_ok = radio1.begin();
    r2_ok = radio2.begin();
    if(r1_ok) {
        radio1.setPALevel(RF24_PA_LOW);
        radio1.setDataRate(RF24_250KBPS);
    }
    if(r2_ok) {
        radio2.setPALevel(RF24_PA_LOW);
        radio2.setDataRate(RF24_250KBPS);
    }
    radiosInit = true;
  }
  ecranOLED.clearDisplay(); 
  ecranOLED.setTextSize(1);
  ecranOLED.setTextColor(WHITE);
  ecranOLED.setCursor(0, 0);
  ecranOLED.print("NRF24 #1: ");
  ecranOLED.println(r1_ok ? "OK" : "ERR");
  ecranOLED.setCursor(0, 9);
  ecranOLED.print("NRF24 #2: ");
  ecranOLED.println(r2_ok ? "OK" : "ERR");
  ecranOLED.setCursor(0, 20);
  ecranOLED.print("OLED :   [ON]");
  ecranOLED.setCursor(0, 30);
  ecranOLED.print("UP   :   ");
  ecranOLED.println(digitalRead(PIN_BTN_UP) == LOW ? "[ON]" : "[  ]");
  ecranOLED.setCursor(0, 40);
  ecranOLED.print("DOWN :   ");
  ecranOLED.println(digitalRead(PIN_BTN_DOWN) == LOW ? "[ON]" : "[  ]");
  ecranOLED.setCursor(0, 50);
  ecranOLED.print("OK   :   ");
  ecranOLED.println(digitalRead(PIN_BTN_OK) == LOW ? "[ON]" : "[  ]");
  ecranOLED.display();
}