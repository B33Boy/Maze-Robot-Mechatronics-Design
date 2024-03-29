#include "maze_bot.h"
#include <Arduino.h>
#include <Encoder.h>


// Extern Variable Definitions
long enc_r_count = 0;
long enc_l_count = 0;
long positionLeft = -999;
long positionRight = -999;

float error = 0;
float error_sum = 0;
float error_change = 0;
float prev_error = 0;

int speedL, speedR = 0;

Encoder leftWheel(ENC_R_CH_A, ENC_R_CH_B);
Encoder rightWheel(ENC_L_CH_A, ENC_L_CH_B);


void reset_encoders()
{
    rightWheel.write(0);
    leftWheel.write(0);
}

float get_rightWheel()
{
    return rightWheel.read() * 0.00343; //+ 0.0591;
}

float get_leftWheel()
{
    return leftWheel.read() * 0.00335; //+ 1.11;
}


void turn_left()
{
    reset_encoders();
    // while (get_leftWheel() < (PI*0.25*DIST_BW_WHEELS - OFFSET_TURN))
    // {
    //     drive(60, 0,60, 1);
    // }

    while(get_leftWheel() < 15 && get_rightWheel() < 15)
    {
        drive(80, 1, 80, 1);
    }
    
    // while (get_rightWheel() < (PI*0.5*DIST_BW_WHEELS))
    // {
    //     drive(0, 1, 50, 1);
    // }
    stop();
    reset_encoders();

    while (abs(get_rightWheel()) < (PI*0.5*5 + OFFSET_TURN_LEFT))
    {
        drive(80, 0, 80, 1);
    }
    stop();

}

void turn_right()
{   
    reset_encoders();

    while(get_leftWheel() < 15 && get_rightWheel() < 15)
    {
        drive(80, 1, 80, 1);
    }

    stop();
    reset_encoders();
    

    while (abs(get_leftWheel()) < (PI*0.5*5 + OFFSET_TURN_RIGHT))
    {
        drive(80, 1, 80, 0);
    }
    stop();
}



void drive_forward()
{
    reset_encoders();
    while (get_rightWheel() < 20 && get_leftWheel() < 20)
    {
        drive(80, 1, 80, 1);
    }
    stop();
}


void follow_wall_dual()
{
    // // PID using left sensor
    // float left_dist = read_sensor(L_SENSOR, L_GPIO1);
    // error = DESIRED_DIST - left_dist;

    // PID using left and right sensor
    float left_dist = read_sensor(L_SENSOR, L_GPIO1);
    // float right_dist = read_sensor(FR_SENSOR, FR_GPIO1);
    
    // Desired distance = mid_dist
    float mid_dist = (read_sensor(L_SENSOR, L_GPIO1) + read_sensor(FR_SENSOR, FR_GPIO1))/2.0; // TODO: Change FR to R when sensor is fixed
    error = mid_dist - left_dist;

    error_sum += error;
    float motor_power = KP*error + KI*error_sum + KD*(error - prev_error);
    prev_error = error;

    // Serial.println("PID: " + String(motor_power) + " | " + String(left_dist));
    
    speed_control(motor_power);

 }

void speed_control(float motor_power)
{
    speedL = FWD_VEL + motor_power;
    speedR = FWD_VEL - motor_power;
    
    // Make sure speeds are within a range
    speedL = constrain(speedL, MIN_SPEED, MAX_SPEED);
    speedR = constrain(speedR, MIN_SPEED, MAX_SPEED);

    // Serial.println("SpeedL: " + String(speedL) + " SpeedR: " + String(speedR));
    
    drive(speedL, 1, speedR, 1);
}

bool space_left()
{
    float reading1 = read_sensor(L_SENSOR, L_GPIO1);
    delay(20);
    float reading2 = read_sensor(L_SENSOR, L_GPIO1);
    delay(20);
    float reading3 = read_sensor(L_SENSOR, L_GPIO1);
    delay(20);
    float reading4 = read_sensor(L_SENSOR, L_GPIO1);


    if (reading1 > 15 && reading2 > 15  && reading3 > 15  && reading4 > 15 )
    {
        return true;
    }
    return false;

}

bool space_right()
{
    float reading1 = read_sensor(FR_SENSOR, FR_GPIO1);
    delay(20);
    float reading2 = read_sensor(FR_SENSOR, FR_GPIO1);
    delay(20);
    float reading3 = read_sensor(FR_SENSOR, FR_GPIO1);
    delay(20);
    float reading4 = read_sensor(FR_SENSOR, FR_GPIO1);


    if (reading1 > SPACE_RIGHT && reading2 > SPACE_RIGHT  && reading3 > SPACE_RIGHT  && reading4 > SPACE_RIGHT )
    {
        return true;
    }
    return false;

}


bool obstacle_forward()
{
    float reading1 = read_sensor(FL_SENSOR, FL_GPIO1);
    delay(20);
    float reading2 = read_sensor(FL_SENSOR, FL_GPIO1);
    delay(20);
    float reading3 = read_sensor(FL_SENSOR, FL_GPIO1);
    delay(20);
    float reading4 = read_sensor(FL_SENSOR, FL_GPIO1);


    if (reading1 < COLLISION_DIST && reading2 < COLLISION_DIST  && reading3 < COLLISION_DIST  && reading4 < COLLISION_DIST )
    {
        return true;
    }
    return false;
}

void back_up()
{
    reset_encoders();
    while (get_rightWheel() > -20 && get_leftWheel() > -20)
    {
        drive(80, 0, 80, 0);
    }
    stop();
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

    // digitalWrite(GPIO1_PIN, LOW); // Turn off sensor
}
// dir1 = 0 ==> backward, dir1 = 1 ==> forward
void drive(int speedL, int ldir, int speedR, int rdir)
{
    analogWrite(ENA, speedL);
	analogWrite(ENB, speedR);

    if (rdir)
    {
        digitalWrite(IN1, HIGH);
    	digitalWrite(IN2, LOW);
    }
    else
    {
        digitalWrite(IN1, LOW);
    	digitalWrite(IN2, HIGH);
    }

    if (ldir)
    {
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    }
    else
    {
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    }
	

}

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
