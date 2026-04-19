# Basic-Obstacle-Avoidance-Robot
# Obstacle Avoidance Robot 🤖

An Arduino-based autonomous robot that detects obstacles using an ultrasonic sensor and avoids collisions through intelligent movement control. The robot continuously scans the path ahead, makes real-time decisions, and navigates without manual input.

## 🚀 Features

* Real-time obstacle detection using HC-SR04 sensor
* Autonomous forward, reverse, left, and right movement
* Smart path selection for obstacle avoidance
* Simple and low-cost hardware design
* Beginner-friendly robotics project

## 🛠️ Components Used

* Arduino Uno / Nano
* HC-SR04 Ultrasonic Sensor
* L298N Motor Driver Module
* DC Motors with Robot Chassis
* Wheels
* Battery Pack
* Jumper Wires

## ⚙️ How It Works

1. The ultrasonic sensor measures the distance in front of the robot.
2. If the path is clear, the robot moves forward.
3. When an obstacle is detected, the robot stops and reverses slightly.
4. It scans alternate directions and turns toward the clearer path.
5. The process repeats continuously for autonomous navigation.

## 📂 Project Structure

* `obstacle_avoidance.ino` – Main Arduino source code
* `README.md` – Project documentation

## 🔧 Applications

* Robotics learning projects
* Arduino workshops
* Basic autonomous vehicles
* STEM demonstrations

## 🔮 Future Improvements

* Bluetooth / Wi-Fi manual control
* LiDAR or IR sensor integration
* Path memory and mapping
* Advanced obstacle detection algorithms

## 🙌 Credits

Implemented and customized as a hands-on robotics workshop demonstration using publicly available reference concepts for educational purposes.

