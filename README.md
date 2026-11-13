Smart Retractable Safety Knife 🔪
​An intelligent, sensor-driven utility knife designed to eliminate workplace lacerations.
​Unlike traditional spring-loaded knives that cause ergonomic fatigue, or fixed blades that cause injuries, this prototype uses micro-sensors to detect active cutting and user grip, instantly retracting the blade when a slip or drop occurs.
​🚀 The Problem with Existing Models
​Fixed Blades: High risk of severe lacerations if the knife slips or is left open.
​Manual Spring-Loaded Knives: Require constant thumb pressure to keep the blade out, leading to Repetitive Strain Injuries (RSI) and user fatigue over long shifts.
​Inertial Retraction Knives: Often jam or require a sudden jerky movement to trigger, slowing down workers.
​💡 Our Solution
​This project introduces a Smart Auto-Retraction Mechanism:
​1. Capacitive Touch: Detects if the user's hand is actively gripping the handle.
​2. Force Sensitive Resistor (FSR): Detects if the blade is currently applying pressure to a material.
​3. Fail-Safe Solenoid: If the knife slips (pressure drops) OR the user drops the knife (grip lost), a microcontroller triggers an instant blade retraction in milliseconds.
​🛠️ Hardware Requirements (Prototype)
​ESP32 or Arduino Nano
​Force Sensitive Resistor (FSR)
​Capacitive Touch Sensor (TTP223)
​5V Micro Push-Pull Solenoid (for blade retraction)
​3.7V LiPo Battery
​3D Printed Housing
​💻 Repository Structure
​/firmware/smart_knife_firmware.ino - The core microcontroller logic for sensor polling and actuator triggering.
​/cad/ - 3D models for the knife housing (Placeholder).
​/schematics/ - Circuit wiring diagrams (Placeholder).
​⚙️ How to Run the Code
​1. Open smart_knife_firmware.ino in the Arduino IDE.
​2. Select your board (e.g., Arduino Nano).
​3. Connect the FSR to analog pin A0, Touch Sensor to Digital Pin 2, and Solenoid control via MOSFET to Digital Pin 9.
​4. Upload and open the Serial Monitor (115200 baud) to view real-time safety triggers.
