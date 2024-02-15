#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper myStepper(STEPS, 4, 5, 6, 7);

// the previous reading from the analog input
int stepCount  = A0;
    

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
      //start stop
     
      
   
  }
}
