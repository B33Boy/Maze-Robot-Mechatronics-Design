#include <Arduino.h>
#include "maze_bot.h"


Motors::Motors()
{
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

    stop();

}

void Motors::stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}

void Motors::drive(int speed)
{
    if (speed > 0)
    {
        left_motor_fwd(abs(speed));
        right_motor_fwd(abs(speed));
    }
    else
    {
        left_motor_rev(abs(speed));
        right_motor_rev(abs(speed));
    }
} 

void Motors::drive(int speed, uint32_t duration)
{
    if (speed > 0)
    {
        left_motor_fwd(abs(speed));
        right_motor_fwd(abs(speed));
    }
    else
    {   
        left_motor_rev(abs(speed));
        right_motor_rev(abs(speed));
    }
    delay(duration);
    stop();
} 

void Motors::turn_left()
{

}

void Motors::turn_right()
{
    
}





void Motors::left_motor_fwd(uint8_t speed)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);
}

void Motors::right_motor_fwd(uint8_t speed)
{
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  analogWrite(enB, speed);
}

void Motors::left_motor_rev(uint8_t speed)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speed);
}

void Motors::right_motor_rev(uint8_t speed)
{
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
  analogWrite(enB, speed);
}