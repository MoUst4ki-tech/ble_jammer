#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RF24.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
#define BTN_UP    32
#define BTN_DOWN  33
#define BTN_OK    27
#define R1_CE     13
#define R1_CSN    14
#define R2_CE     25
#define R2_CSN    26
RF24 radio1(R1_CE, R1_CSN);
RF24 radio2(R2_CE, R2_CSN);

bool r1_status = false;
bool r2_status = false;

void setup() {
  Serial.begin(115200);
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_OK, INPUT_PULLUP);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("ERREUR: Ecran OLED non trouvé ! Vérifiez SDA/SCL."));
    for(;;);
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Test Hardware...");
  display.display();
  delay(500);
  r1_status = radio1.begin();
  r2_status = radio2.begin();
  if(r1_status) {
    radio1.setPALevel(RF24_PA_LOW);
  }
  if(r2_status) {
    radio2.setPALevel(RF24_PA_LOW);
  }
}

void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("RADIO 1 (13/14): ");
  if(r1_status) display.println("OK");
  else          display.println("ERR");
  display.print("RADIO 2 (25/26): ");
  if(r2_status) display.println("OK");
  else          display.println("ERR");
  display.drawLine(0, 20, 128, 20, SSD1306_WHITE);
  display.setCursor(0, 25);
  display.println("TEST BOUTONS:");
  display.setCursor(0, 38);
  display.print("BTN UP (32):   ");
  if(digitalRead(BTN_UP) == LOW) display.print("ON  [X]");
  else                           display.print("OFF [ ]");
  display.setCursor(0, 48);
  display.print("BTN DWN (33):  ");
  if(digitalRead(BTN_DOWN) == LOW) display.print("ON  [X]");
  else                             display.print("OFF [ ]");
  display.setCursor(0, 58);
  display.print("BTN OK  (27):  ");
  if(digitalRead(BTN_OK) == LOW) display.print("ON  [X]");
  else                           display.print("OFF [ ]");
  display.display();
  delay(50);
}