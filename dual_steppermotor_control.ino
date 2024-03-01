#include <AccelStepper.h>

// Define the stepper motor connections
#define motorPin1  4
#define motorPin2  5
#define motorPin3  6
#define motorPin4  7
#define motorPin5  8
#define motorPin6  9
#define motorPin7  10
#define motorPin8  11

// Initialize the AccelStepper library
AccelStepper myStepper(AccelStepper::FULL4WIRE, motorPin1, motorPin2, motorPin3, motorPin4);
AccelStepper myStepper1(AccelStepper::FULL4WIRE, motorPin5, motorPin6, motorPin7, motorPin8);

void setup() {
  // Set the maximum speed and acceleration:
  myStepper.setMaxSpeed(1000);
  myStepper.setAcceleration(500);
  myStepper1.setMaxSpeed(1000);
  myStepper1.setAcceleration(500);
}

void loop() {
  int sensorReading = analogRead(A0);
  int motorSpeed = map(sensorReading, 0, 1023, 0, 1000)*0.5; // Adjust the range as needed

  int sensorReading1 = analogRead(A1);
  int motorSpeed1 = map(sensorReading1, 0, 1023, 0, 1000)*0.5; // Adjust the range as needed

  // Set the speeds based on the potentiometer
  myStepper.setSpeed(-motorSpeed);
  myStepper1.setSpeed(-motorSpeed1);

  // Move the stepper motors a small amount
  myStepper.runSpeed();
  myStepper1.runSpeed();
}