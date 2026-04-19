# Basic-Obstacle-Avoidance-Robot

# Obstacle Avoidance Robot

An Arduino-based autonomous robot that detects obstacles using an ultrasonic sensor and avoids collisions through intelligent movement control. The robot continuously scans the path ahead, makes real-time decisions, and navigates without manual input.

## Project Demo

Autonomous obstacle detection and navigation in real time.

<img src="demo.gif" width="450"/>

[▶ Watch Full Video](./Obstacle_Avoidance_Robot.mp4)

## Features

* Real-time obstacle detection using HC-SR04 sensor
* Autonomous forward, reverse, left, and right movement
* Smart path selection for obstacle avoidance
* Simple and low-cost hardware design
* Beginner-friendly robotics project

## Components Used

* Arduino Uno / Nano
* HC-SR04 Ultrasonic Sensor
* L298N Motor Driver Module
* DC Motors with Robot Chassis
* Wheels
* Battery Pack
* Jumper Wires

## How It Works

1. The ultrasonic sensor measures the distance in front of the robot.
2. If the path is clear, the robot moves forward.
3. When an obstacle is detected, the robot stops and reverses slightly.
4. It scans alternate directions and turns toward the clearer path.
5. The process repeats continuously for autonomous navigation.

## Project Structure

* `obstacle_avoidance.ino` – Main Arduino source code
* `README.md` – Project documentation

## Code Explanation

This Arduino program controls an autonomous obstacle avoidance robot using an ultrasonic sensor, servo motor, and L298N motor driver.

### 1. Libraries Used

* **NewPing.h** – Handles ultrasonic sensor distance measurement.
* **Servo.h** – Controls the servo motor rotation.

### 2. Pin Definitions

Motor pins are assigned for forward and backward movement of left and right motors:

* Left Motor Forward → Pin 2
* Left Motor Backward → Pin 3
* Right Motor Forward → Pin 4
* Right Motor Backward → Pin 5

Ultrasonic sensor pins:

* Trigger Pin → A1
* Echo Pin → A2

Servo motor is connected to Pin 8.

### 3. Global Variables

* `maximum_distance = 200` → Maximum sensing range in cm.
* `distance` → Stores measured distance.
* `goesForward` → Tracks whether robot is moving forward.

### 4. setup() Function

Runs once when powered on:

* Sets motor pins as outputs.
* Attaches servo motor to pin 8.
* Centers sensor at 115°.
* Reads initial distance values.

### 5. loop() Function

Runs continuously:

* If obstacle is within 20 cm:

  * Stop robot
  * Move backward briefly
  * Stop again
  * Scan right side
  * Scan left side
  * Compare distances
  * Turn toward clearer side

* If no obstacle:

  * Move forward.

* Updates distance after every cycle.

### 6. Direction Scanning Functions

#### `lookRight()`

Turns servo to right (50°), reads distance, then returns to center.

#### `lookLeft()`

Turns servo to left (170°), reads distance, then returns to center.

### 7. Sensor Reading

#### `readPing()`

Gets distance from ultrasonic sensor.

* If no object detected (`0 cm`), sets value to `250 cm`.

### 8. Movement Functions

#### `moveStop()`

Stops all motors.

#### `moveForward()`

Moves both motors forward.

#### `moveBackward()`

Moves both motors backward.

#### `turnRight()`

Left motor forward + right motor backward.

#### `turnLeft()`

Left motor backward + right motor forward.

### 9. Working Logic Summary

The robot continuously checks for obstacles. If blocked, it reverses, scans both sides, chooses the clearer route, and continues moving autonomously.

## Wiring Connections

### HC-SR04 Ultrasonic Sensor → Arduino Uno

| Sensor Pin | Arduino Pin |
| ---------- | ----------- |
| VCC        | 5V          |
| GND        | GND         |
| TRIG       | A1          |
| ECHO       | A2          |

### Servo Motor → Arduino Uno

| Servo Wire | Arduino Pin |
| ---------- | ----------- |
| Signal     | D8          |
| VCC        | 5V          |
| GND        | GND         |

### L298N Motor Driver → Arduino Uno

| L298N Pin | Arduino Pin |
| --------- | ----------- |
| IN1       | D2          |
| IN2       | D3          |
| IN3       | D4          |
| IN4       | D5          |

### DC Motors → L298N

| Motor       | Driver Output |
| ----------- | ------------- |
| Left Motor  | OUT1 & OUT2   |
| Right Motor | OUT3 & OUT4   |

### Power Supply

| Connection  | Description   |
| ----------- | ------------- |
| Battery +   | L298N 12V     |
| Battery -   | L298N GND     |
| Arduino GND | Common Ground |

> Ensure all grounds are connected together for proper operation.


## Applications

* Robotics learning projects
* Arduino workshops
* Basic autonomous vehicles
* STEM demonstrations

## Future Improvements

* Bluetooth / Wi-Fi manual control
* LiDAR or IR sensor integration
* Path memory and mapping
* Advanced obstacle detection algorithms

## Credits

Implemented and customized as a hands-on robotics workshop demonstration using publicly available reference concepts for educational purposes.
