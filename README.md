# ARM-project
Smart CAN Bus Vehicle Diagnostics and Monitoring System

A real-time embedded automotive monitoring system built using LPC2129 (ARM7) microcontrollers and CAN Bus communication. The project demonstrates ECU-to-ECU communication by monitoring multiple vehicle parameters through distributed sensor nodes.

🚀 Features
Dual LPC2129-based ECU architecture
CAN Bus communication using MCP2551 transceivers
Real-time sensor monitoring
UART-based live data display
Fault detection using predefined threshold values
ADC interfacing for analog sensors
Embedded C implementation using Keil µVision
🛠 Hardware Used
LPC2129 ARM7 Microcontrollers (2 ECUs)
MCP2551 CAN Transceivers
IR Sensor
Vibration Sensor
LM35 Temperature Sensor
Voltage Sensor
Potentiometer
UART Terminal (PC)

📌 Working
ECU1 monitors the IR sensor and vibration sensor.
ECU2 monitors the LM35 temperature sensor, voltage sensor, and potentiometer.
Both ECUs exchange sensor data over the CAN Bus.
The system detects abnormal conditions such as obstacle detection, excessive vibration, high temperature, and abnormal voltage levels.
The processed data and fault status are displayed on the UART terminal for real-time diagnostics.

💻 Software & Tools
Embedded C
Keil µVision
Flash Magic
CAN Protocol
UART Communication

🎯 Applications
Automotive diagnostics
Vehicle health monitoring
CAN Bus communication learning
Embedded systems education
Industrial monitoring systems
