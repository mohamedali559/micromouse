# Momentum Micromouse Project

Welcome to the repository for the Momentum Micromouse project developed for IEEE Victories 3 by the MicroSauraus team.

In this project, we present our efforts to design and build a micromouse robot capable of navigating a maze autonomously.

This README file provides an overview of the design details starting from the rough sketch.

<div style="display: flex;">
    <img src="https://github.com/user-attachments/assets/a3dcaf06-35f1-4eba-b373-7a1086af5753" alt="After Power Circuit" style="Height: 300px; padding: 10px;">
    <img src="https://github.com/user-attachments/assets/a702d02c-65c8-454d-bf29-d570bcb35345" alt="After Power Circuit" style="Height: 300px; padding: 10px;">
    <img src="https://github.com/user-attachments/assets/6daad120-ade1-4d14-880a-48fb4a05f945" alt="After Power Circuit" style="Height: 300px; padding: 10px;">
</div>

## Component Selection

### Microcontroller: STM32F401RCT6

When developing high-speed micro mice, the choice of microcontroller plays a critical role. It's essential to opt for a high-performance microcontroller that also offers sufficient memory capabilities. In our project, we have carefully considered these factors and selected the STM32F401RCT6 microcontroller from the STM32 variations. This microcontroller , which is known for it's high performance. 

The STM32F405 microcontroller stands out due to its potent ARM Cortex-M4 core, generous Flash and RAM resources, and efficient implementation of intricate algorithms for maze-solving and motion control. With up to 15 communication interfaces, two 12-bit DACs, three 12-bit ADCs, and ample EEPROM support, the STM32F405 offers a comprehensive set of features that align well with our project's requirements.

While the ESP32 also presents itself as a viable option with its wireless communication capabilities, which could prove advantageous during debugging, we prioritized the STM32F405 due to its suitability in terms of size requirements. This careful consideration ensures that our micro mouse project maintains the balance between performance and form factor.

### Programming Tool: ST-Link V2
The SWD (Serial Wire Debug) mode of the ST-Link V2 provides an efficient method for debugging and programming microcontroller. With SWD, we can access real-time debugging information, set breakpoints, and upload firmware seamlessly, reducing development time and ensuring precise control over our micromouse's behavior.


### Voltage Regulator: LM2596S
a high-efficiency buck (step-down) regulator that can handle up to 3A output current.
It accepts an input voltage of about 4–40V and provides an adjustable output of 1.25–35V via a potentiometer.

### Infrared Components: SFH4545 (IR Emitter) and TEFT4300 (IR Receiver)
- SFH4545: The SFH4545 IR emitter stands as our choice for its efficient and focused infrared emission. With a narrow half angle of 5 degrees, it significantly improves the accuracy of our distance measurement and obstacle detection systems. 
- TEFT4300: The TEFT4300 IR Receiver is selected for its sensitivity and reliability in detecting the emitted infrared signals, enabling precise distance measurements.

### Gyroscope: MPU6050 IMU
Elevated sensitivity enables the detection of minute angular velocity changes, a pivotal feature for meticulous motion tracking demands. With minimal power consumption, it seamlessly aligns with battery-powered applications, ensuring extended operational endurance. Its compact form factor further enhances its adaptability, effortlessly integrating into various devices and augmenting the efficiency of our micromouse's design.


### Motor: DC Motor GA25-370 with Encoder 2kg 280RPM

The N20-500RPM motor, paired with a gear box of ratio 30:1, strikes a balance between speed and torque. This combination provides the necessary power to propel the robot through the maze while maintaining control, maneuverability and a low stall current of 0.6A. 7PPR compatible encoder provides 28 Counts Per Revolution(CPR). Compatible D-hole rubber wheel with 32mm diameter and 3mm apecture is selected.
$$\texttt{Speed}_{max}= \frac{500\times 2\pi}{60}\cdot 0.016=0.83ms^{-1}$$
$$\texttt{Accuracy} = \frac{2\pi\times 0.016}{30\times 28}= 1.196\times10^{-4}m/count=0.12mm/count $$

### Motor Drivers: L298

a dual H-bridge driver capable of controlling two DC motors or one stepper motor.
It supports motor supply voltages up to 46V and can deliver up to 2A per channel.

### User Interface

HC-05 Bluetooth Module: The HC-05 module facilitates wireless communication with the micromouse, enabling remote debugging and configuration adjustments.

### Battery
Our micromouse project relies on a series configuration of three Li-ion 3.7V batteries, meticulously chosen to strike a harmonious balance between weight, size, and power supply capability. we opted for 500mAh batteries for debugging purposes.

### Simulation
We used a virtual platform calles "MMS" designed to emulate Micromouse maze-solving challenges.
It allows testing and refining navigation algorithms without the need for physical hardware.
<img src="https://github.com/user-attachments/assets/45ba97fa-236d-4db0-a1c5-3bfe1796e22b" style="Height: 400px; padding: 10px;">


## Achievements
Thrilled to share that we secured 2nd place in the third edition of the Victories competition, proudly organized by IEEE MSB!

<div style="display: flex;">
    <img src="https://github.com/user-attachments/assets/7c161231-2880-48d7-bfd4-6001e322d98b" alt="Winners" style="Height: 800px; padding: 10px;">
</div>




Feel free to [contact us](mailto:mohamedalim559@gmail.com). 
