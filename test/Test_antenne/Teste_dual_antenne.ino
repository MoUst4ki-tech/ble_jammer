#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

#define CE_PIN_1  13
#define CSN_PIN_1 14
#define CE_PIN_2  25
#define CSN_PIN_2 26

RF24 radio1(CE_PIN_1, CSN_PIN_1);
RF24 radio2(CE_PIN_2, CSN_PIN_2);

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println(F("\n--- TEST HARDWARE : DUAL NRF24 ---"));
  Serial.print(F("Initialisation Radio 1 (CE=4, CSN=5)... "));
  if (radio1.begin()) {
    Serial.println(F("OK ! (Connectee)"));
    radio1.setPALevel(RF24_PA_LOW);
    radio1.printDetails();
  } else {
    Serial.println(F("ERREUR ! (Non detectee)"));
    Serial.println(F(" -> Verifiez les fils CE(4) et CSN(5) de la premiere antenne."));
  }
  Serial.println(F("-----------------------------------"));
  Serial.print(F("Initialisation Radio 2 (CE=25, CSN=26)... "));
  if (radio2.begin()) {
    Serial.println(F("OK ! (Connectee)"));
    radio2.setPALevel(RF24_PA_LOW);
  } else {
    Serial.println(F("ERREUR ! (Non detectee)"));
    Serial.println(F(" -> Verifiez les fils CE(25) et CSN(26) de la deuxieme antenne."));
  }
  Serial.println(F("-----------------------------------"));
  if (radio1.isChipConnected() && radio2.isChipConnected()) {
    Serial.println(F("SUCCES TOTAL : Les deux antennes sont operationnelles !"));
  } else {
    Serial.println(F("ATTENTION : Au moins une antenne a un probleme."));
    Serial.println(F("Conseil : Verifiez que MISO/MOSI/SCK sont bien relies aux DEUX antennes."));
  }
}
void loop() {
}