#include "maze_bot.h"
#include <Arduino.h>


// Extern Variable Definitions
long enc_r_count = 0;
long enc_l_count = 0;

float error = 0;
float error_sum = 0;
float error_change = 0;
float prev_error = 0;

int speedL, speedR = 0;

void follow_wall()
{
    float left_dist = read_sensor(L_SENSOR, L_GPIO1);
  
    error = DESIRED_DIST - left_dist;
    error_sum += error;
    int pid = KP*error + KI*error_sum + KD*(error - prev_error);
    prev_error = error;

    Serial.println("PID: " + String(pid) + " | " + String(left_dist));

    //  Make sure PID value does not exceed bounds
    if(pid < -SPEED_CORRECTION){
        pid = -SPEED_CORRECTION;
    }
    if(pid > SPEED_CORRECTION){
        pid = SPEED_CORRECTION;
    }

    if (error > 0)
    {
        speedL = FWD_VEL + pid;
        speedR = FWD_VEL - pid;
    }
    else
    {
        speedL = FWD_VEL - pid;
        speedR = FWD_VEL + pid;
    }

    Serial.println("SpeedL: " + String(speedL) + " SpeedR: " + String(speedR));
    
    analogWrite(ENA, speedL);
	analogWrite(ENB, speedR);

    digitalWrite(IN1, HIGH);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, HIGH);

    delay(50);
}

bool obstacle_left()
{
    float reading1 = read_sensor(L_SENSOR, L_GPIO1);
    // delay(10);
    float reading2 = read_sensor(L_SENSOR, L_GPIO1);

    if (reading1 < COLLISION_DIST && reading2 < COLLISION_DIST)
    {
        return true;
    }
    return false;
}

bool obstacle_forward()
{
    float reading1 = read_sensor(FL_SENSOR, FL_GPIO1);
    // delay(10);
    float reading2 = read_sensor(FL_SENSOR, FL_GPIO1);


    if (reading1 < COLLISION_DIST && reading2 < COLLISION_DIST)
    {
        return true;
    }
    return false;
}

bool obstacle_right()
{
    float reading1 = read_sensor(FR_SENSOR, FR_GPIO1);
    // delay(10);
    float reading2 = read_sensor(FR_SENSOR, FR_GPIO1);


    if (reading1 < COLLISION_DIST && reading2 < COLLISION_DIST)
    {
        return true;
    }
    return false;
}

float read_sensor(int SENSOR_PIN, int GPIO1_PIN)
{
    digitalWrite(GPIO1_PIN, HIGH); // Turn on sensor
    
    unsigned int sensor_sum = 0;
    for (int i=0; i<SENSOR_SAMPLES; i++)
    {
        sensor_sum += analogRead(SENSOR_PIN);
    }

    switch(SENSOR_PIN) 
    {
        case A7:
            return (sensor_sum/SENSOR_SAMPLES)*(-0.12) + 86.9;
        case A6:
            return (sensor_sum/SENSOR_SAMPLES)*(-0.0978) + 71.7;
        case A5:
            return (sensor_sum/SENSOR_SAMPLES)*(-0.0979) + 71.5;
        case A4:
            return (sensor_sum/SENSOR_SAMPLES)*(-0.116) + 81;
        default:
            return 0;
    }

    digitalWrite(GPIO1_PIN, LOW); // Turn off sensor
}

void forward()
{
    analogWrite(ENA, 100);
	analogWrite(ENB, 100);

	// Turn on motor A & B
	digitalWrite(IN1, HIGH);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, HIGH);
	
}

// void lmotor(int speed, int dir)
// {
//     analogWrite(ENA, speed);
//     digitalWrite(IN1, HIGH);
// 	digitalWrite(IN2, LOW);
// }


void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

void enc_r_isr()
{
    if (digitalRead(ENC_R_CH_A) == HIGH)
    {
        if (digitalRead(ENC_R_CH_B) == HIGH)
        {
            enc_r_count++;
        }
        else
        {
            enc_r_count--;
        }
        
    }
    else
    {
        if (digitalRead(ENC_R_CH_B) == HIGH)
        {
            enc_r_count--;
        }
        else
        {
            enc_r_count++;
        }
    }
}

void enc_l_isr()
{
    if (digitalRead(ENC_L_CH_A) == HIGH)
    {
        if (digitalRead(ENC_L_CH_B) == HIGH)
        {
            enc_l_count++;
        }
        else
        {
            enc_l_count--;
        }
        
    }
    else
    {
        if (digitalRead(ENC_L_CH_B) == HIGH)
        {
            enc_l_count--;
        }
        else
        {
            enc_l_count++;
        }
    }
}
