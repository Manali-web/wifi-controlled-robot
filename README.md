# wifi-controlled-robot
Wi-Fi controlled robot using NodeMCU and L298N motor driver
# 🤖 Wi-Fi Controlled Robot using ESP8266 & L298N Motor Driver

Overview
This project is a Wi-Fi-based robot car built using the **ESP8266 NodeMCU** microcontroller and the **L298N motor driver**.  
The robot can be controlled wirelessly through a smartphone or laptop connected to the same Wi-Fi network.  
It demonstrates the use of **IoT and embedded systems** in basic robotic control applications.

Components Used
| Component | Description |
|------------|-------------|
| ESP8266 (NodeMCU) | Main controller board with built-in Wi-Fi |
| L298N Motor Driver | Dual H-bridge motor driver to control motor direction |
| DC Gear Motors (2x) | Used for movement and steering |
| Robot Chassis | Frame to hold motors, wheels, and electronics |
| Wheels (2x) | Connected to DC motors |
| Power Supply | 9V/12V battery |
| Jumper Wires | For circuit connections |

Circuit Connections
| NodeMCU Pin | L298N Pin | Function |
|--------------|-----------|----------|
| D1 (GPIO5) | IN1 | Motor A direction |
| D2 (GPIO4) | IN2 | Motor A direction |
| D3 (GPIO0) | IN3 | Motor B direction |
| D4 (GPIO2) | IN4 | Motor B direction |
| VIN | 12V | Power input to motor driver |
| GND | GND | Common ground |

Note: Connect the enable pins (ENA & ENB) of L298N to 5V for constant speed or to PWM pins for speed control.

Working Principle
- The NodeMCU creates a simple "web server" that hosts a control page (Forward, Backward, Left, Right, Stop buttons).  
- When you press a button, it sends an HTTP request to the NodeMCU.  
- Based on the command received, specific GPIO pins are triggered to drive the motors through the L298N module.

Control Interface
You can control the robot through any device (mobile or laptop) by typing the NodeMCU’s IP address (shown in the serial monitor) in a web browser.  
Example: `192.168.4.1`

Future Improvements
- Add **camera module (ESP32-CAM)** for live streaming  
- Implement **speed control** using PWM signals  
- Add **obstacle detection** using ultrasonic sensors  
- Create a **custom Android app** for control  

Learning Outcomes
- Wi-Fi communication using ESP8266  
- Controlling motors via L298N driver  
- Designing a web interface for real-time robot control  
- Understanding basic IoT-based robotics  

Developed By
Manali Yadav  
B.Tech in Electronics & Communication (AKTU University)  
Passionate about Embedded Systems, IoT & Robotics  
