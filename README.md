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
- a high-efficiency buck (step-down) regulator that can handle up to 3A output current.
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

- TC4427: We've selected the TC4427 motor driver for its fast switching capabilities, ensuring precise control over the motor's speed and direction.
- ZXMHC3F38148: This motor driver complements the TC4427, offering additional motor control options and enhancing overall performance.

### User Interface

- HC-05 Bluetooth Module: The HC-05 module facilitates wireless communication with the micromouse, enabling remote debugging and configuration adjustments.

### Battery
Our micromouse project relies on a series configuration of two Li-ion 3.7V batteries, meticulously chosen to strike a harmonious balance between weight, size, and power supply capability. we opted for 500mAh batteries for debugging purposes.

## PCB Design

The PCB design is set at dimensions of 98mm by 74mm. This deliberate size choice allows for possible future expansion, including diagonal runs or extra components. The design maintains compatibility with the micromouse challenge's limitations. Furthermore, this sizing aligns with the cost-effective PCB manufacturing boundary of 100mm by 100mm provided by JLCPCB. 
**Design Files** could be viewed [here](./PCB/).

Understand the design bettery by looking at the [schematic](./PCB/Design/schematic.pdf) and [layout](./PCB/Design/layout.pdf).

### Design Considerations
1. **Overlay Labels**: Ensured clear overlay labels, including indicators for the positive side of batteries, components placed within the compact size constraints, and proper naming of SWD interface pins and motor pins.
2. **Ground Separation**: Maintained the separation of motor ground, analog ground, and main ground until the battery terminal. This seperation is also upheld during the copper pouring process. The isolation of motor ground addresses potential signal noise that could impact microcontroller performance. Furthermore, AGND was designated as a noise-free ground for components like the gyroscope and IR receiver, which is particularly sensitive to ground noise.
3. **Trace Widths**: To accommodate high current flow, we implemented a trace width of 30mil. For tracks originating from the microcontroller, an 11mil width was chosen, while a width of 15mil was used for most tracks. Notably, the trace widths for high current paths were tailored for connections involving the battery, motor ground, and motor drivers to the motor header. Clearance values were chosen in accordance with manufacturer capablities.
4. **Copper Pours**: Deliberate copper pours were employed to enhance thermal conductivity, especially for high current paths and integrated circuits. The chosen nets for copper pours encompass battery positive voltage, motor ground, 3V3 STM32 supply, analog ground for the gyroscope, and general ground connections. The selection of pour areas was made with meticulous attention to detail, ensuring optimal performance and functionality.
5. **Symmetric Component Placement**: Our design emphasizes symmetrical placement of components, taking into account the inherent symmetry of the mouse body. This approach extends to the distribution of component placements, ensuring uniform weight distribution across the micromouse.
6. **IR Sensor Guidelines**: To ensure precise alignment of IR sensors, we incorporated accurately aligned guide lines corresponding to specific angular measurements. This meticulous approach guarantees the optimal positioning and performance of the IR sensors. We accomadate two IR configurations by having an extra pad and guideline.

### Design Flow
1. Finishing the Placements and Outer Shape

<img src="./images/placement.jfif" alt="Image Description" style="width:300px; height:auto;">

2. Routing the Design using Different Widths - Keep a rule of thumb!

<div style="display: flex; justify-content: space-between;">
  <img src="./images/top_route.jfif" alt="Top Track" style="width: 30%;">
  <img src="./images/bottom_route.jfif" alt="Bottom Track" style="width: 27%;">
  <img src="./images/route.jfif" alt="Tracks" style="width: 30%;">
</div>

3. Filling Copper in our Design.

<div style="display: flex; justify-content: space-between;">
  <img src="./images/top_pour.jfif" alt="Top Pour" style="width: 30%;">
  <img src="./images/bottom_pour.jfif" alt="Bottom Pour" style="width: 28%;">
</div>
<br>
Here is the complete PCB in a 3D view.
<br>
<img src="./images/3d_layout.jfif" alt="Image Description" style="width:400px; height:auto;">

## Soldering
1. **Power Circuit** : We begin by soldering the power circuit components. Once completed, we use test points to verify the voltage output, comparing it with the expected values.

2. **Main Controller** : Next, we move on to soldering the microcontroller and establish a connection to upload the code. This step allows us to verify the basic functionality of the microcontroller.

3. **Passive Components** : After confirming the proper functioning of the microcontroller, we proceed to solder all other components to complete the circuit. This step ensures that all elements of the project are integrated seamlessly.

***Note***: We paid special attention to soldering the gyroscope, adhering to its footprint specifications to ensure precise and reliable connections. Infact we confirmed the connections from microcontroller end.

<div style="display: flex;">
    <img src="./images/after_power.jpg" alt="After Power Circuit" style="Height: 200px; padding: 5px;">
    <img src="./images/after_power2.jpg" alt="Image 2" style="Height: 200px; padding: 5px;">
    <img src="./images/after_microcontroller.jpg" alt="Image 3" style="Height: 200px; padding: 5px;">
    <img src="./images/pcb_working.gif" alt="Image 5" style="Height: 200px; padding: 5px;">
    <img src="./images/soldered.jpg" alt="Image 4" style="Height: 200px; padding: 5px;">
</div>


## Firmware

## Achievements
We are proud to announce that our project achieved remarkable success at SLIIT Robofest 2023. We secured the prestigious position of 2nd runners up.

<div style="display: flex;">
    <img src="./images/team2.jpg" alt="After Power Circuit" style="Height: 200px; padding: 5px;">
    <img src="./images/team3.jpg" alt="Image 2" style="Height: 200px; padding: 5px;">
</div>

**Search Run**<br>
<img src="./images/search_run.gif" alt="Image Description" style="width:500px; height:auto;">


## Basic Tests
1. **TEST 1:** Going straight with the help of encoder<br>
    <img src="./images/straight_run.gif" alt="Image Description" style="width:500px; height:auto;">
2. **TEST 2:** Aligning the robot normal to a wall in front on a specified distance.<br>
    <img src="./images/front_align.gif" alt="Image Description" style="width:500px; height:auto;">
3. **TEST 3:** Compass nature using gyroscope reading.<br>
    <img src="./images/point_direction.gif" alt="Image Description" style="width:500px; height:auto;">


Feel free to [contact us](mailto:shansanjithofficial@gmail.com). 


## Limitations
1. Keeping the wheels outside the chasis makes it harder for the mice to recover when the wheel hits wall.
2. Period between updates of parameters is limited by the SPI communication speed of gyroscope in our implementation. Using analog gyroscope is advantageous.


## References
1. [STM32-ST Link V2 for programming STM32 microcontrollers.](https://www.robotics-university.com/2016/05/mini-st-linkv2-programming-tool-for-stm8-and-stm32.html)
2. [Interfacing HC-06 bluetooth module via USART communication.](https://www.etechnophiles.com/hc06-pinout-specifications-datasheet/)
3. [Interfacing OLED display via SPI communication.](https://github.com/lamik/OLED_SSD1306_STM32_HAL)

