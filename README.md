
# Automatic Plant Watering System using IoT and WiFi

## Project Overview
This project implements an **Automatic Plant Watering System** that uses an ESP8266 (or ESP32) microcontroller, soil moisture sensor, DC motor (for water pump), and a relay module. The system detects the moisture level of the soil and automatically waters the plant when the soil gets dry. It also connects to the internet via WiFi and uploads real-time data to an IoT platform (like ThingSpeak) for remote monitoring.

---

## How It Works
1. **Soil Moisture Sensor**:
    - The soil moisture sensor measures the water content in the soil. The sensor outputs an analog voltage that corresponds to the soil's moisture level. A lower value indicates dry soil, while a higher value indicates wet soil.

2. **ESP8266/ESP32 Microcontroller**:
    - The ESP8266/ESP32 reads the soil moisture level and makes decisions based on predefined thresholds. If the moisture is below a set threshold, it triggers the relay to turn on the water pump. The ESP also connects to WiFi, allowing data to be sent to an IoT platform.

3. **Relay Module**:
    - The relay acts as a switch for the water pump. When the moisture level drops below the threshold, the relay is activated, which powers the water pump. When the soil is sufficiently watered, the relay is deactivated, stopping the pump.

4. **DC Motor (Water Pump)**:
    - The water pump is controlled by the relay. It pumps water to the plant when needed. The motor is turned off automatically when the soil moisture reaches the required level.

5. **IoT Integration** (Optional):
    - Using an IoT platform like **ThingSpeak**, the system uploads real-time moisture data, allowing you to monitor and control the system remotely. You can also receive data alerts or manually control the water pump via the IoT dashboard.

---

## Project Workflow
1. **Initialization**:
    - The ESP8266/ESP32 connects to the WiFi network using the credentials provided.
    - It initializes the moisture sensor and relay, ready for operation.

2. **Soil Monitoring**:
    - The soil moisture sensor continuously reads the moisture level.
    - The microcontroller compares the moisture value with a predefined threshold.

3. **Decision Making**:
    - If the soil is dry (moisture level below threshold), the system turns on the water pump by activating the relay.
    - If the soil is sufficiently wet, the water pump remains off.

4. **Water Pump Activation**:
    - When the soil is dry, the relay activates the water pump, providing water to the plant until the moisture level rises.

5. **IoT Data Logging (Optional)**:
    - The sensor data is uploaded to an IoT platform like **ThingSpeak** for real-time monitoring and logging.
    - You can remotely check the moisture level and control the system from anywhere.

---

## Key Features
- **Automated Irrigation**: Waters the plant automatically when the soil moisture is low.
- **Energy and Water Efficiency**: Conserves water and energy by only activating the pump when necessary.
- **Remote Monitoring**: Real-time data is uploaded to the cloud, allowing remote access and monitoring via a smartphone or web dashboard.
- **Manual Control**: Users can manually control the pump remotely using an IoT platform.
- **Scalable**: The system can be scaled to monitor multiple plants with additional sensors and relays.

---

## Components Required
- **ESP8266/ESP32** (Microcontroller for processing and WiFi)
- **Soil Moisture Sensor**
- **Relay Module** (To control the water pump)
- **DC Motor** (Water pump)
- **Power Supply** (for ESP and motor)
- **Jumper Wires**

---

## Working Example
1. **Moisture Monitoring**:
    - If the moisture level is below a set threshold (e.g., 500), the system assumes the soil is dry and turns on the water pump.
   
2. **Water Pump Activation**:
    - The ESP8266/ESP32 triggers the relay, activating the water pump to water the plant.

3. **IoT Data Transmission** (Optional):
    - Real-time moisture data is uploaded to the IoT platform for monitoring.
    - You can check moisture levels and control the system from anywhere.

4. **Automatic Stop**:
    - The water pump turns off automatically when the soil moisture level reaches the threshold or after a certain time.

---

## Applications
- **Home Gardens**: Perfect for automating plant watering in home gardens.
- **Farms/Greenhouses**: Scalable to larger farms and greenhouses.
- **Urban Gardens**: Great for smart city projects where remote plant monitoring is essential.

---

## Advantages
- **Convenience**: No need to manually water plants.
- **IoT Integration**: Real-time monitoring and control through cloud platforms.
- **Water Conservation**: Uses water only when necessary.
- **Scalability**: Can be expanded to monitor and control multiple zones or plants.

---

## Code
You can find the Arduino code for this project in the `project-code.ino` file.

---



---

## Getting Started
1. **Clone the Repository**:
2. **Upload the Code**:
- Upload the `project-code.ino` file to your ESP8266/ESP32 using the Arduino IDE.
- Ensure the necessary libraries (`WiFi`, `ThingSpeak`, etc.) are installed.

3. **Circuit Setup**:
- Follow the circuit diagram in the `circuit_diagram.png` file to connect the soil moisture sensor, relay, and water pump to the ESP8266/ESP32.

4. **Monitor and Control**:
- Monitor real-time moisture levels via the IoT platform (optional).
- Adjust the threshold value in the code to suit your needs.

