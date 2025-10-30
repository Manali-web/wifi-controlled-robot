// WiFi Control Car using NodeMCU
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Pin Definitions
#define ENA   14 // Enable/speed motors Right (GPIO14 - D5)
#define ENB   12 // Enable/speed motors Left (GPIO12 - D6)
#define IN_1  15 // L298N in1 motors Right (GPIO15 - D8)
#define IN_2  13 // L298N in2 motors Right (GPIO13 - D7)
#define IN_3  2  // L298N in3 motors Left  (GPIO2  - D4)
#define IN_4  0  // L298N in4 motors Left  (GPIO0  - D3)

// WiFi Configuration
const char* ssid = "NodeMCU_Car"; // WiFi SSID
const char* password = "12345678"; // WiFi Password

ESP8266WebServer server(80); // Web server on port 80

// Variables
String command;           // Stores the received command
int speedCar = 800;       // Motor speed (400 - 1023)
int speed_Coeff = 3;      // Speed coefficient for turning

void setup() {
  // Set pin modes
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);

  // Initialize Serial Monitor
  Serial.begin(115200);

  // Set up WiFi in Access Point mode
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  // Set up web server routes
  server.on("/", HTTP_handleRoot);
  server.onNotFound(HTTP_handleRoot);
  server.begin();
  Serial.println("Web server started.");
}

// Motor Control Functions
void goAhead() {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedCar);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCar);
}

void goBack() {
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);
  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}

void goRight() {
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCar);
}

void goLeft() {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedCar);
  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}

void stopRobot() {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, 0);
}

// Handle HTTP Requests
void HTTP_handleRoot() {
  if (server.hasArg("State")) {
    command = server.arg("State");
    Serial.println("Received Command: " + command);

    // Process Command
    if (command == "F") goAhead();
    else if (command == "B") goBack();
    else if (command == "L") goLeft();
    else if (command == "R") goRight();
    else if (command == "S") stopRobot();
    else if (command == "0") speedCar = 400;
    else if (command == "1") speedCar = 470;
    else if (command == "2") speedCar = 540;
    else if (command == "3") speedCar = 610;
    else if (command == "4") speedCar = 680;
    else if (command == "5") speedCar = 750;
    else if (command == "6") speedCar = 820;
    else if (command == "7") speedCar = 890;
    else if (command == "8") speedCar = 960;
    else if (command == "9") speedCar = 1023;
    else stopRobot(); // Default to stop for unknown commands
  }

  // Send response
  server.send(200, "text/html", "<h1>NodeMCU Car</h1><p>Command received.</p>");
}

void loop() {
  server.handleClient(); // Handle incoming web requests
}

