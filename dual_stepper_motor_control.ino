#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200
#define STEPS2 200
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper myStepper(STEPS, 4, 5, 6, 7);
Stepper myStepper1(STEPS2, 8, 9, 10, 11);

// the previous reading from the analog input
int stepCount  = A0,
    stepCount2  = A1;
    

void setup()
{

}

void loop()
{

      // read the sensor value:
      int sensorReading = analogRead(A0);
      // map it to a range from 0 to 100:
      int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
      // set the motor speed:
      if (motorSpeed > 0) {
      myStepper.setSpeed(motorSpeed);
      // step 1/100 of a revolution:
      myStepper.step(STEPS / 100);

           // read the sensor value:
      int sensorReading1 = analogRead(A1);
      // map it to a range from 0 to 100:
      int motorSpeed1 = map(sensorReading1, 0, 1023, 0, 100);
      // set the motor speed:
      if (motorSpeed1 > 0) {
      myStepper1.setSpeed(motorSpeed1);
      // step 1/100 of a revolution:
      myStepper1.step(STEPS2 / 100);
     
      }
   
  }
}
