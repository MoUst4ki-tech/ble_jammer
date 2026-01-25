# 📡 BLE Jammer

**Author:** [moust4ki](https://github.com/moust4ki)  
**Version:** 1.0.0

A portable ESP32-based tool utilizing dual NRF24L01 modules to scan and interact with the 2.4GHz spectrum. Features an OLED display for real-time feedback and a 3-button navigation interface.

> ⚠️ **DISCLAIMER:** This project is for **educational purposes and hardware testing only**. Jamming wireless networks is illegal in most countries. The author is not responsible for any misuse of this software.

---

## 🛠 Hardware Required

| Component | Quantity | Description |
|-----------|:--------:|-------------|
| **ESP32** | 1 | Development Board (WROOM-32 recommended) |
| **NRF24L01** | 2 | 2.4GHz Transceiver modules (PA+LNA recommended for range) |
| **OLED Display** | 1 | 0.96" I2C SSD1306 (128x64 pixels) |
| **Push Buttons** | 3 | 4-pin tactile switches |
| **Wires** | - | Jumper wires |
| **Capacitors** | 2 | 10µF or 100µF (Essential for NRF24 stability) |

---
###### FOR TEST AND ONLY FOR TEST ######
## 🔌 Wiring / Pinout

### 1. OLED Display (I2C)
| OLED Pin | ESP32 Pin |
|:--------:|:---------:|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

### 2. Control Buttons
| Button | ESP32 Pin | Mode |
|:------:|:---------:|:----:|
| BTN 1 (Left) | GPIO 19 | INPUT_PULLUP |
| BTN 2 (Center)| GPIO 18 | INPUT_PULLUP |
| BTN 3 (Right) | GPIO 17 | INPUT_PULLUP |

### 3. Dual NRF24L01 Modules (SPI)
*Note: Both modules share MOSI, MISO, and SCK. Only CSN and CE differ.*

| NRF24 Pin | ESP32 Pin | Note |
|:---:|:---:|:---|
| **VCC** | 3.3V | **DO NOT USE 5V** |
| **GND** | GND | Add Capacitor here |
| **MOSI** | GPIO 23 | Shared |
| **MISO** | GPIO 19 | Shared |
| **SCK** | GPIO 18 | Shared |
| **CE** (Radio 1) | GPIO 4 | |
| **CSN** (Radio 1)| GPIO 5 | |
| **CE** (Radio 2) | GPIO 2 | (Example - Check code) |
| **CSN** (Radio 2)| GPIO 15 | (Example - Check code) |

---

**⚠️ IMPORTANT:** Use this wiring for `Test_boutton_ecran_antenne`, `Teste_dual_antenne`, and the final application.
*Changes were made to avoid conflict between Buttons and NRF24 SPI bus.*

### A. OLED Display (I2C)
| OLED Pin | ESP32 Pin |
|:--------:|:---------:|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

### B. Control Buttons (New Pins)
| Button | ESP32 Pin | Function |
|:------:|:---------:|:--------:|
| **BTN UP** | **GPIO 32** | Up / Left |
| **BTN DOWN** | **GPIO 33** | Down / Right |
| **BTN OK** | **GPIO 27** | Enter / Validate |

### C. Dual NRF24L01 Modules (SPI)
*Note: Both modules share MOSI, MISO, and SCK. Only CSN and CE differ.*

| NRF24 Pin | ESP32 Pin | Note |
|:---:|:---:|:---|
| **VCC** | 3.3V | **DO NOT USE 5V** (Add Capacitor!) |
| **GND** | GND | (Add Capacitor!) |
| **MOSI** | GPIO 23 | Shared |
| **MISO** | GPIO 19 | Shared |
| **SCK** | GPIO 18 | Shared |
| | | |
| **RADIO 1** (CE) | **GPIO 13** | |
| **RADIO 1** (CSN)| **GPIO 14** | |
| | | |
| **RADIO 2** (CE) | **GPIO 25** | |
| **RADIO 2** (CSN)| **GPIO 26** | |
## 📂 Project Structure

```text
.
├── README.md
└── test
    ├── Test_antenne
    │   ├── Test_antenne.ino
    │   └── Teste_dual_antenne.ino
    ├── Test_boutton_ecran
    │   └── Test_boutton_ecran.ino
    └── Test_boutton_ecran_antenne
        └── Test_boutton_ecran_antenne.ino
