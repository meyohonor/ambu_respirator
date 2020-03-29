#include <AccelStepper.h>

int motor_step_pin = 9;
int motor_dir_pin = 8;
// Define a stepper and the pins it will use
AccelStepper stepper(AccelStepper::DRIVER, motor_step_pin, motor_dir_pin);

/*  HARDWARE PARAMS */
int microstepping_factor = 8;
float motor_steps_revolution = 200 * microstepping_factor; //NEMA17 ticks 1,8º per step, 200 steps per revolution
float thread_ratio = 1.25; //a normal M8 threaded rod (not helix) is about 1,25mm linear per revolution
int target_position_mm = 150; //this our final position is in mm, depends on how long your screw is

/* SOFTWARE PARAMS*/
int max_speed = 30000;
int max_accel = 30000;
int breath_pause_msec = 500; //time between the end if the last cycle and the next


/* CALCULATED PARAMS  */
float revolutions_to_target = target_position_mm*thread_ratio; //number of revolutions needed to target
int target_position_steps = revolutions_to_target*motor_steps_revolution; //this position is en steps 

bool first = true;

void setup()
{ 
  stepper.setMaxSpeed(max_speed);
  stepper.setAcceleration(max_accel);
}

void loop()
{
  
  if (first){
  first = false;
  stepper.setCurrentPosition(-target_position_steps);
  }
  
  if (stepper.distanceToGo() == 0)
  {
    delay(breath_pause_msec);
    target_position_steps = -target_position_steps;
    stepper.moveTo(target_position_steps);
  }
  
  stepper.run();
}
