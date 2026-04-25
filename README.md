# WiFi Controlled Robot 🤖

An IoT-based robotics project using NodeMCU (ESP8266) to control a 4-wheel robot via a local web server.

## 🚀 Key Features
* **Web Control:** Real-time movement control through a mobile-responsive web UI.
* **Low Latency:** Optimized socket communication for instant response.
* **Dual Power:** Separated logic and motor power supply to prevent noise.

## 🛠️ Hardware Components
* **Microcontroller:** NodeMCU ESP8266
* **Motor Driver:** L298N Dual H-Bridge
* **Chassis:** 4-Wheel Robot Kit
* **Battery:** 7.4V Li-ion

## 🔌 Circuitry
> [!TIP]
> **Insert your Circuit Diagram or Proteus Screenshot here!**

## 💻 Software Setup
1. Clone this repo: `git clone https://github.com/Manali-web/wifi-controlled-robot.git`
2. Open the `.ino` file in **Arduino IDE**.
3. Install the ESP8266 Board Manager.
4. Update your WiFi credentials in the code:
   ```cpp
   const char* ssid = "YOUR_WIFI_NAME";
   const char* password = "YOUR_PASSWORD";
   ## 🔍 How to Find the IP Address
After uploading the code to your NodeMCU:
1. Keep the NodeMCU connected to your computer.
2. In the Arduino IDE, go to **Tools > Serial Monitor**.
3. Set the baud rate to **115200**.
4. Press the **RST (Reset)** button on the NodeMCU.
5. The IP address will be printed on the screen once it connects to your WiFi. 
6. Type this IP into your web browser to control the robot.
