# ☀️ STM32 Nucleo Dual-Axis Solar Tracker

A hardware-software integrated embedded system developed in **C/C++** using the **STM32 CubeIDE** and HAL framework. Built as part of the engineering curriculum at **RWTH Aachen University**, this project is designed to maximize solar panel energy efficiency by dynamically tracking the strongest light source in real-time using an industrial-grade STM32 microcontroller.

## 🚀 Key Technical Highlights

This project demonstrates strong proficiency in bare-metal embedded development, register-level configuration via HAL, and closed-loop control algorithms:

* **Microcontroller Integration:** Implemented on an **STM32F429ZI** (ARM Cortex-M4) Nucleo board, utilizing its advanced peripherals for efficient power management and real-time processing.
* **Internal ADC & Sensor Processing:** Leveraged the STM32's native **12-bit Analog-to-Digital Converter (ADC)** to simultaneously sample raw data from 4 Light Dependent Resistors (LDRs) via specific GPIO pins.
* **Hardware PWM Control:** Generated precise Hardware Pulse Width Modulation (PWM) signals using the STM32's advanced-control timers to actuate dual-axis servo motors (Pan and Tilt) with high angular resolution.
* **Algorithmic Differential Tracking:** Developed a spatial differential algorithm that calculates the average intensity of sensor quadrants (Top, Bottom, Left, Right) to determine the optimal light vector.
* **Hysteresis & Hardware Safety:** Programs a mechanical tolerance threshold (`tol = 50`) and hardcoded operational angular limits to filter ambient noise, prevent actuator jitter, and protect the tracking mount from physical stalling.

## 📂 System Architecture

* **Input Stage:** 4x LDRs connected directly to the STM32's Internal ADC channels.
* **Processing Stage:** STM32F429ZI MCU executing the C/C++ control loop, querying the internal ADC via HAL, calculating intensity differentials, and updating PWM duty cycles.
* **Output Stage:** 2x Servo motors executing positional corrections based on hardware PWM signals.

## 🛠️ Technologies & Hardware

* **Language:** C/C++
* **Development Environment:** STM32CubeIDE (CubeMX configuration)
* **Framework:** STM32 HAL (Hardware Abstraction Layer)
* **Hardware:** STM32 Nucleo-F429ZI Board, Servo Motors, Photoresistors (LDRs), Custom Mount.
* **Concepts:** Embedded C, ADC Conversion, Hardware PWM, Timer Configuration, Control Systems, Mechatronics.

## ⚙️ How to Build and Run

1. **Hardware Setup:** Consult the provided block diagram to connect the LDRs to the ADC pins and Servos to the specific Timer-capable PWM pins on the Nucleo-F429ZI.
2. **Software Setup:** Open the project in **STM32CubeIDE**.
3. **Generate & Compile:** Generate the initialization code via CubeMX (if changes are needed) and build the project using the integrated GCC compiler.
4. **Flash & Run:** Connect the Nucleo board via USB (ST-Link) and flash the `.bin`/`.elf` file directly to the microcontroller.

---
*Developed by Mehmet Akif Ulutas - Computer Engineering @ RWTH Aachen University*
