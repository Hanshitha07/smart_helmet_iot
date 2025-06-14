# 🛠️ Smart Helmet for Mining and Construction Safety 🚧⛑️

This is my **first IoT project**, built by me and my teammate focusing on **worker safety in hazardous environments** like mining and construction zones.

## 🔍 Project Overview

The Smart Helmet is designed to:
- Continuously **monitor environmental conditions**
- **Detect hazardous gases, smoke, high temperature**
- **Warn users about nearby obstacles**
- **Display real-time data** on an LCD screen
- **Trigger alerts** using a buzzer

---

## 🧠 Technologies Used
- **Arduino UNO** (Coded using Arduino IDE)
- **C/C++** (Embedded programming)

---

## 🔌 Components & Sensors

| Component            | Purpose |
|----------------------|---------|
| 🔸 MQ-4 Sensor        | Detects Methane gas (CH₄) in the environment |
| 🔸 MQ-2 Sensor        | Detects Smoke and combustible gases |
| 🔸 DHT11 Sensor       | Monitors temperature & humidity |
| 🔸 Ultrasonic Sensor  | Detects obstacles in close proximity |
| 🔸 16x2 LCD Display   | Shows sensor data and warning messages |
| 🔸 Buzzer             | Sounds alerts when danger is detected |
| 🔸 Relay Module       | Can control external devices in future (e.g., fans, alarms) |

---

## 📷 How It Works

- Sensors constantly collect environmental data.
- If dangerous gas or smoke is detected, or if the temperature is too high, the buzzer alerts the user.
- The LCD shows live readings and any warning messages.
- The ultrasonic sensor ensures the user is warned about obstacles.

---

## 🚀 Getting Started

### Prerequisites:
- Arduino IDE installed
- Libraries:
  - `DHT.h`
  - `Adafruit_Sensor.h`
  - `LiquidCrystal.h`

### Uploading the Code:
1. Connect your Arduino UNO.
2. Open `smartHelmet.ino` in Arduino IDE.
3. Install necessary libraries.
4. Upload and monitor using Serial Monitor.

---

## 💡 Future Improvements
- Add GPS tracking for location-based alerts
- Send real-time data to a cloud dashboard (using ESP32/Wi-Fi module)
- Helmet impact detection and emergency SMS

![smarthelmet1](https://github.com/user-attachments/assets/d120c5af-d744-4acf-bf6b-d7d8453f7dbe)
![smarthelmet3](https://github.com/user-attachments/assets/5efba420-d63b-4ae2-9781-d251f469b86e)


