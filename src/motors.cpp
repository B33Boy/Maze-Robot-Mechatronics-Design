#include <Arduino.h>
#include "maze_bot.h"


Motors::Motors()
{
	pinMode(ENA, OUTPUT);
	pinMode(ENB, OUTPUT);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);

    stop();

}

void Motors::stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
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
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);
}

void Motors::right_motor_fwd(uint8_t speed)
{
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  analogWrite(ENB, speed);
}

void Motors::left_motor_rev(uint8_t speed)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speed);
}

void Motors::right_motor_rev(uint8_t speed)
{
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  analogWrite(ENB, speed);
}