# IoT Color Sorting System (Arduino & Node-RED)

## Overview

This project implements an **IoT-based automatic color sorting system** combining **embedded systems**, **automation**, and **real-time data visualization**.
The system detects object colors, sorts them automatically using actuators, and displays sorting statistics on a **Node-RED dashboard**.

---

## Project Objectives

* Automate object sorting based on color
* Process sensor data in real time using an embedded system
* Control mechanical actuators for physical sorting
* Visualize sorting data through an IoT dashboard
* Study an industrial-oriented supervision solution (PLCnext / Proficloud) 

---

## System Architecture

1. Color detection using a sensor
2. Data processing on Arduino
3. Mechanical actuation for sorting
4. Serial data transmission
5. Real-time visualization via Node-RED 

---

## Hardware Components

* Arduino board
* TCS230 color sensor
* Nema 17HS4401S stepper motor
* DRV8825 stepper motor driver
* Three servo motors
* 2200 µF / 16 V capacitor
* External power supply (12V/2A) and (5V/2A)

---

## Software & Tools

* Arduino IDE (C/C++)
* Node-RED
* Node-RED Dashboard
* PLCnext Engineer (study)
* Proficloud (study) 

---

## System Operation

### Color Detection

The **TCS230** sensor measures RGB light intensity using a matrix of photodiodes.
The output is a frequency proportional to the detected light intensity. 

### Data Processing

* RGB frequency measurement
* Noise reduction using averaging
* Dominant color detection
* Object counting per color
* Serial transmission of results 

### Actuation

* A **Nema 17 stepper motor**, driven by the **DRV8825**, ensures object movement
* **Servo motors** direct objects according to the detected color 

---

## Data Visualization (Node-RED)

Data received from Arduino are processed in Node-RED using:

* `serial in`
* `csv`
* `change`
* `gauge`

The dashboard displays the number of detected objects for each color in real time. 

---

## Industrial Visualization Study

An industrial visualization architecture was studied using:

* PLCnext
* OPC UA communication
* Proficloud platform

This setup enables real-time industrial-level monitoring of sorting data. 

---

## Challenges Encountered

* Insufficient motor torque, requiring a Nema 17 motor
* Driver incompatibility, leading to the use of DRV8825
* Electrical instability due to an undersized capacitor
* Connection issues between PLCnext and Proficloud 

---

## Conclusion

This project delivers a **functional IoT-based color sorting prototype**, integrating sensing, processing, actuation, and visualization.
It demonstrates practical implementation of **embedded systems**, **automation**, and **IoT supervision** concepts. 

---

[To access the repository of the project](https://najmechorouk.github.io/IoT-Color-Sorting-System/)
