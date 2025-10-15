
    # 🤖 HEXAPOD-ROBOT


### 🦿 Overview
A **six-legged hexapod robot** with **18° of freedom**, designed for dynamic locomotion, terrain adaptability, and autonomous control. Each leg is powered by **three servo motors** to enable complex, multi-axis movements for walking, turning, and balancing.
<p align="center">
  <img src="https://raw.githubusercontent.com/pratik001010/HEXAPOD-ROBOT/main/hexapod.jpg"
       alt="Hexapod Robot"
       width="450"
       height="220"
       style="object-fit: cover; border-radius: 10px;"/>
</p>

This project demonstrates **bio-inspired robotics** and explores **inverse kinematics**, **wireless control**, and **embedded motion algorithms** using Arduino.

---


### ⚙️ System Architecture

| Module | Microcontroller | Communication | Description |
|---------|-----------------|----------------|--------------|
| **Hexapod Body** | Arduino Mega 2560 | nRF24L01 (2.4 GHz RF Transceiver) | Central control system managing all 18 servo motors, handling inverse kinematics and gait algorithms. |
| **Remote Controller** | Arduino Nano | nRF24L01 | Compact handheld controller with dual joysticks for directional and mode control. |
| **Input Interface** | Joystick + Switches | Analog Input | Provides intuitive, manual control over movement, orientation, and gait mode. |

---
### 🔋 Key Features
- 18° of freedom for smooth, stable locomotion  
- Modular servo-driven leg mechanism  
- Real-time **wireless control** using nRF24L01 (2.4 GHz)  
- Dual-mode operation: **Manual (Joystick)** & **Autonomous**  
- Inverse kinematics-based gait generation  
- Terrain adaptability and balance correction  
- Arduino-based motion sequencing and control loop

---

### 🧠 Working Principle
The hexapod’s walking behavior is based on **tripod gait**, where three legs stay in contact with the ground while the other three move forward.  
Inverse kinematics equations compute joint angles for each servo in real time, ensuring synchronized, stable motion across uneven terrain.

<p align="center">
  <img src="https://raw.githubusercontent.com/pratik001010/HEXAPOD-ROBOT/92eed9dbe64f1565c79fcdbdf96f9d4a69235687/HEXAPOD1.jpg"
       alt="Hexapod Robot Side View"
       width="420"
       height="210"
       style="object-fit: cover; border-radius: 10px;"/>
</p>

Wireless data from the **remote (Arduino Nano)** is transmitted via **nRF24L01** to the **hexapod (Arduino Mega)**, which interprets the joystick input and adjusts leg positions accordingly.

---

### 🧰 Components Used
| Component | Quantity | Function |
|------------|-----------|-----------|
| Arduino Mega 2560 | 1 | Main controller for hexapod body |
| Arduino Nano | 1 | Remote controller unit |
| nRF24L01 (2.4 GHz RF module) | 2 | Wireless data transmission |
| Joystick Module | 2 | Directional and motion control |
| MG90S / SG90 Servo Motors | 18 | Leg actuation (3 per leg) |
| Li-Po Battery Pack | 1 | Power supply for servos and logic |
| Custom 3D-Printed / Acrylic Frame | 1 | Robot chassis |
| Power Distribution Board | 1 | Servo and controller power management |

---
### 🧮 Control Logic
1. **Joystick Input:**  
   Captures analog signals for forward/backward, rotation, and lateral movement.  
2. **Data Encoding:**  
   Arduino Nano transmits control packets via nRF24L01.  
3. **Wireless Reception:**  
   Arduino Mega receives and decodes control data.  
4. **Motion Computation:**  
   Inverse kinematics algorithms compute servo angles for each leg.  
5. **Execution:**  
   Servo commands are sent simultaneously to all legs, creating smooth, stable motion.

---
### 🧩 Future Improvements
- Add **IMU (MPU6050)** for balance feedback  
- Integrate **ultrasonic sensors** for obstacle avoidance  
- Implement **autonomous path planning**  
- Explore **Raspberry Pi vision module** for object detection and navigation  
- Optimize servo energy management via PID-based gait control  

---

**Pratik Khadka**  
