#include <DueTimer.h>

const float encoder_counts_to_MM = 1324234234;

 float  error = 0;
 float error_sum = 0;
 float error_change = 0;
 float prev_error = 0;


void timerISR()
{
  //read all the sensors

  //calculate wheel speeds
  //check current encoder count, compare to prev. calculate speed
  SpeedControl();

}

void SpeedControl(float desired_speed)
{
   error = desired_speed - 100; // des speed - actual
   error_sum += error;

   error_change = error - prev_error;
   prev_error = error;


   motor_power = motor_model(desired_speed) + error*KP + error_sum*KI + error_change*KD;

}

int motor_model(float dspeed)
{
  if(dspeed > 0)
  {
    return dspeed*math + othermath;
  }
  if(dspeed < 0)
  {
    return -math
  }
  if(dspeed = 0)
  {
    return 0;
  }
}


void setup(){


Timer3.attachInterrupt(timerISR);
Timer3.start(50000); // Calls every 50ms
}

void loop()
{

  if(condition)
  {
    doStuff
  }
  if(otherState)
  {
     dootherstuff
  }
}



//encoder stuff

