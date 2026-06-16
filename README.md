Temperature Display and MQTT Monitoring System
📌 Project Overview

This project is an IoT embedded system that reads temperature data from a DHT11 sensor using Arduino Uno, displays it on a 16×2 LCD, sends the data via serial communication to a PC, and publishes it to an MQTT broker hosted on a VPS. A web dashboard subscribes to the MQTT topic and displays real-time temperature updates.

🏗️ System Architecture
flowchart LR

A[DHT11 Temperature Sensor] --> B[Arduino Uno]

B --> C[16x2 LCD Display]

B --> D[Serial Communication USB 9600]

D --> E[PC Script (pc_mqtt.py)]

E --> F[MQTT Broker on VPS]

F --> G[MQTT Topic: iot/temperature]

F --> H[WebSocket Port 9001]

H --> I[HTML Dashboard (index.html)]

I --> J[Live Temperature Display])
⚙️ Hardware Components
Arduino Uno
DHT11 Temperature Sensor
16×2 LCD Display
Jumper wires
USB cable
💻 Software Components
Arduino IDE
Python 3
Paho MQTT Library
Serial Library (pyserial)
MQTT Broker (VPS)
HTML + JavaScript (MQTT.js)
📡 Communication Details
🔌 Serial Communication
Between: Arduino Uno ↔ PC
Baud Rate: 9600
Purpose: Transfer temperature readings from Arduino to PC
🌐 MQTT Communication
Broker: VPS / broker.benax.rw
Topic: iot/temperature
Protocol: MQTT over TCP / WebSockets (for dashboard)
🔧 Features
Real-time temperature reading using DHT11 sensor
LCD display with scrolling name on first row
Temperature display on second row of LCD
Serial transmission from Arduino to PC
MQTT publishing to remote broker
Real-time web dashboard visualization
📁 Project Structure
TemperatureDisplay/
│
├── Temperature/
│   ├── arduino/
│   │   └── temperature_lcd.ino
│   │
│   ├── pc/
│   │   └── pc_mqtt.py
│   │
│   ├── dashboard/
│   │   └── index.html
│   │
│   ├── screenshots/
│       ├── page.png
│       ├── page(2).png
│       ├── serial monitor.png
│
├── README.md
🚀 How It Works
Arduino reads temperature from DHT11 sensor.
Data is displayed on LCD:
Row 1: Candidate name (scrolling if long)
Row 2: Temperature value
Arduino sends temperature data via serial to PC.
Python script reads serial data and publishes it to MQTT broker.
Web dashboard subscribes to MQTT topic and displays live updates.
🧪 Sample Serial Output
Temperature: 25.60 C
Temperature: 26.10 C
Temperature: 26.30 C
🌍 Dashboard Access
http://157.173.101.159:8089/dashboard/dashboard.html

📌 MQTT Topic Used
iot/temperature
👨‍💻 Author

Ikirezi Unejumutima Honorine
