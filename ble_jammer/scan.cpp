#include "libs.h"

void executerScanHybride() {
  if (!scanTermine) {
    afficherEntete("-- Scanner --");
    ecranOLED.setCursor(0, 25);
    ecranOLED.println("Recherche...");
    ecranOLED.display();
    
    totalTrouve = 0;

    BLEScanResults *foundDevices = pBLEScan->start(SCAN_TIME, false);
    for (int i = 0; i < foundDevices->getCount() && totalTrouve < 15; i++) {
      BLEAdvertisedDevice d = foundDevices->getDevice(i);
      String nom = d.haveName() ? d.getName().c_str() : d.getAddress().toString().c_str();
      nomsTrouves[totalTrouve] = "[B] " + nom.substring(0, 16);
      totalTrouve++;
    }
    pBLEScan->clearResults(); 
    BTScanResults* btDeviceList = SerialBT.discover(SCAN_TIME * 1000);
    if (btDeviceList) {
      for (int i = 0; i < btDeviceList->getCount() && totalTrouve < 15; i++) {
        BTAdvertisedDevice* d = btDeviceList->getDevice(i);
        String nom = (d->getName().length() > 0) ? d->getName().c_str() : d->getAddress().toString().c_str();
        nomsTrouves[totalTrouve] = "[C] " + nom.substring(0, 16);
        totalTrouve++;
      }
    }
    
    scanTermine = true;
    if(totalTrouve == 0) nomsTrouves[0] = "Aucun signal";
  }

  afficherEntete("-- Resultats --");
  for (int i = 0; i < 4; i++) {
    int idx = i + indexSousMenu;
    if (idx < totalTrouve) {
      ecranOLED.setCursor(0, 16 + (i * 12));
      ecranOLED.println(nomsTrouves[idx]); 
    }
  }
}