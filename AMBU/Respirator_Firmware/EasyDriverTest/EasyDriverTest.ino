#include <AccelStepper.h>

int motor_step_pin = 9;
int motor_dir_pin = 8;
// Define a stepper and the pins it will use
AccelStepper stepper(AccelStepper::DRIVER, motor_step_pin, motor_dir_pin);



void setup() {
  // put your setup code here, to run once:
  stepper.setMaxSpeed(30000);
  stepper.setAcceleration(30000);

stepper.setCurrentPosition(0);
    stepper.moveTo(-3200);
}

void loop() {
  // put your main code here, to run repeatedly:
    
  
    stepper.run();

}
