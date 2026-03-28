# ☀️ Raspberry Pi Dual-Axis Solar Tracker

A hardware-software integrated embedded system developed in Python. Built as part of the engineering curriculum at **RWTH Aachen University**, this project is designed to maximize solar panel energy efficiency by dynamically tracking the strongest light source in real-time using a Raspberry Pi.

## 🚀 Key Technical Highlights

This project demonstrates strong proficiency in Linux-based embedded systems, hardware communication protocols, and closed-loop control algorithms:

* **SPI Communication & ADC Integration:** Since Raspberry Pi lacks native analog inputs, the system integrates an **MCP3008 10-bit Analog-to-Digital Converter (ADC)**. Communication between the Pi and the ADC is handled via the hardware **SPI (Serial Peripheral Interface)** bus using the `spidev` library.
* **Software PWM Control:** Manages dual-axis actuation (Pan and Tilt) by generating Software Pulse Width Modulation (PWM) signals via the `RPi.GPIO` library to control two independent servo motors.
* **Algorithmic Sensor Processing:** Processes real-time 10-bit analog feedback from 4 Light Dependent Resistors (LDRs). The algorithm calculates spatial averages (Top, Bottom, Left, Right) to determine the precise differential light vector.
* **Jitter Prevention (Hysteresis):** Implemented a programmatic tolerance threshold (`tol = 50`) to filter out minor ambient light fluctuations. This prevents mechanical jittering and extends the lifespan of the servos.
* **Hardware Safety Bounds:** Hardcoded operational limits (e.g., `servovLimitHigh = 120`, `servovLimitLow = 10`) to prevent physical stalling, over-rotation, and potential hardware damage to the tracking mount.

## 📂 System Architecture

* **Input Stage:** 4x LDRs connected to the channels (CH0-CH3) of the MCP3008 ADC.
* **Processing Stage:** Raspberry Pi running the Python control loop, querying the ADC via SPI, calculating intensity differentials, and mapping them to PWM duty cycles.
* **Output Stage:** 2x Servo motors (connected to GPIO 17 and GPIO 27) executing the positional corrections.

## 🛠️ Technologies & Hardware

* **Language:** Python 3
* **Libraries:** `RPi.GPIO`, `spidev`, `time`
* **Hardware:** Raspberry Pi, MCP3008 (SPI ADC), 2x Servo Motors, 4x Photoresistors (LDRs).
* **Protocols & Concepts:** SPI Bus, ADC Conversion, PWM, Embedded Linux, Mechatronics.

## ⚙️ How to Run

1. **Hardware Setup:**
   * Wire the MCP3008 to the Raspberry Pi's SPI pins (MOSI, MISO, SCLK, CE0).
   * Connect 4 LDRs to CH0, CH1, CH2, and CH3 on the MCP3008.
   * Connect the Vertical Servo to `GPIO 17` (Pin 11) and Horizontal Servo to `GPIO 27` (Pin 13).
2. **Software Dependencies:** Ensure SPI is enabled via `raspi-config` and install the required Python package:
   ```bash
   sudo apt-get install python3-spidev
