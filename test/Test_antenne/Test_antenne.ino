#include <SPI.h>
#include <RF24.h>
#define CE_PIN  4
#define CSN_PIN 5

RF24 radio(CE_PIN, CSN_PIN);

const int num_channels = 126;
uint8_t values[num_channels];

void setup() {
  Serial.begin(9600);
  if (!radio.begin()) {
    Serial.println(F("\nERREUR CRITIQUE : NRF24 non detecte !"));
    Serial.println(F("Verifiez : 1. Cablage (MISO/MOSI) 2. Alimentation 3.3V"));
    while (1);
  }
  Serial.println(F("\nNRF24 Detecte avec succes ! Demarrage du scanner..."));
  radio.setAutoAck(false); 
  radio.startListening();  
  radio.stopListening();   
  radio.printDetails();  
  Serial.println(F("Canal  | Activite detectee"));
}

void loop() {
  memset(values, 0, sizeof(values));
  int i = 0;
  while (i < num_channels) {
    radio.setChannel(i);
    radio.startListening();
    delayMicroseconds(128);
    radio.stopListening();
    if (radio.testCarrier()) {
      values[i]++;
    }
    i++;
  }
  int j = 0;
  while (j < num_channels) {
    if (values[j] > 0) {
      Serial.print("*");
    } else {
      Serial.print("-");
    }
    if(j == 63) Serial.println(""); 
    j++;
  }
  Serial.println("");
}