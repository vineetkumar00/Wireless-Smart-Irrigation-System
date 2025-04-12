#include <ESP8266WiFi.h>  // Use <WiFi.h> if you're using ESP32
#include <ThingSpeak.h>   // For sending data to ThingSpeak (optional for IoT functionality)

// WiFi credentials
const char* ssid = "Your_SSID";           // Replace with your WiFi SSID
const char* password = "Your_PASSWORD";   // Replace with your WiFi password

// ThingSpeak credentials
unsigned long myChannelNumber = YOUR_CHANNEL_NUMBER;   // Replace with your ThingSpeak Channel ID
const char* myWriteAPIKey = "YOUR_API_KEY";            // Replace with your ThingSpeak API key

// Pin configurations
const int moisturePin = A0;         // Analog pin for soil moisture sensor
const int relayPin = D1;            // Digital pin to control relay module
const int motorPin = D2;            // Digital pin to control motor (via relay)

// Moisture level threshold
int threshold = 500;                // Threshold for dry soil; adjust based on calibration

// Variables for storing sensor data
int soilMoistureValue = 0;

WiFiClient client;

void setup() {
  // Initialize Serial monitor for debugging
  Serial.begin(115200);

  // Initialize pins
  pinMode(relayPin, OUTPUT);
  pinMode(motorPin, OUTPUT);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to WiFi");

  // Initialize ThingSpeak (optional for IoT)
  ThingSpeak.begin(client);
}

void loop() {
  // Read moisture sensor value
  soilMoistureValue = analogRead(moisturePin);
  Serial.print("Soil Moisture Level: ");
  Serial.println(soilMoistureValue);

  // Check if the soil moisture is below the threshold
  if (soilMoistureValue < threshold) {
    Serial.println("Soil is dry, turning on the water pump.");
    digitalWrite(relayPin, HIGH);  // Activate relay to turn on motor
    digitalWrite(motorPin, HIGH);  // Turn on the motor
  } else {
    Serial.println("Soil is moist, turning off the water pump.");
    digitalWrite(relayPin, LOW);   // Deactivate relay to turn off motor
    digitalWrite(motorPin, LOW);   // Turn off the motor
  }

  // Send data to ThingSpeak (optional)
  ThingSpeak.setField(1, soilMoistureValue);  // Send moisture data to field 1

  int responseCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (responseCode == 200) {
    Serial.println("Data sent to ThingSpeak successfully");
  } else {
    Serial.println("Problem sending data to ThingSpeak: " + String(responseCode));
  }

  // Wait 30 seconds before the next reading
  delay(30000);
}
