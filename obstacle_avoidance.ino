#include <NewPing.h>   // Library for ultrasonic sensor
#include <Servo.h>     // Library for servo motor

// Motor control pins
const int LeftMotorForward  = 2;
const int LeftMotorBackward = 3;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;

// Ultrasonic sensor pins
#define trig_pin A1
#define echo_pin A2

#define maximum_distance 200

boolean goesForward = false;
int distance = 100;

// Create sensor and servo objects
NewPing sonar(trig_pin, echo_pin, maximum_distance);
Servo servo_motor;

void setup() {
  // Set motor pins as outputs
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);

  // Attach servo to pin 8
  servo_motor.attach(8);

  // Set sensor to center position
  servo_motor.write(115);
  delay(2000);

  // Initial distance readings
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
  int distanceRight = 0;
  int distanceLeft = 0;

  delay(50);

  // If obstacle detected
  if (distance <= 20) {
    moveStop();
    delay(300);

    moveBackward();
    delay(400);

    moveStop();
    delay(300);

    // Scan both directions
    distanceRight = lookRight();
    delay(300);

    distanceLeft = lookLeft();
    delay(300);

    // Turn toward clearer path
    if (distanceRight >= distanceLeft) {
      turnRight();
    } else {
      turnLeft();
    }

    moveStop();
  } else {
    moveForward();
  }

  // Update distance reading
  distance = readPing();
}

// Check distance on right side
int lookRight() {
  servo_motor.write(50);
  delay(500);

  int distance = readPing();

  delay(100);
  servo_motor.write(115);

  return distance;
}

// Check distance on left side
int lookLeft() {
  servo_motor.write(170);
  delay(500);

  int distance = readPing();

  delay(100);
  servo_motor.write(115);

  return distance;
}

// Read distance from ultrasonic sensor
int readPing() {
  delay(70);

  int cm = sonar.ping_cm();

  if (cm == 0) {
    cm = 250;
  }

  return cm;
}

// Stop all motors
void moveStop() {
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

// Move robot forward
void moveForward() {
  if (!goesForward) {
    goesForward = true;

    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);

    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
  }
}

// Move robot backward
void moveBackward() {
  goesForward = false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
}

// Turn robot right
void turnRight() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);

  delay(500);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

// Turn robot left
void turnLeft() {
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(500);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

