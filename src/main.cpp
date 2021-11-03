#include <Arduino.h>
#include <Servo.h>
#include "maze_bot.h"
#include <DueTimer.h>
#include <Encoder.h>

Encoder leftWheel(ENC_R_CH_A, ENC_R_CH_B);
Encoder rightWheel(ENC_L_CH_A, ENC_L_CH_B);

void handler_isr()
{
    if (read_sensor(FL_SENSOR, FL_GPIO1) <= COLLISION_DIST && read_sensor(L_SENSOR, L_GPIO1) > 10)
    {
        turn_right();
    }
    else if(read_sensor(FL_SENSOR, FL_GPIO1) <= COLLISION_DIST)
    {
        stop();
    }
    else
    {
        follow_wall();

    }

    // long newLeft, newRight;
    // newLeft = leftWheel.read();
    // newRight = rightWheel.read();

    // if (newLeft != positionLeft || newRight != positionRight) 
    // {
    //     // Serial.print("Left = " + String(newLeft) + ", Right = " + String(newRight) + "\n");
    //     positionLeft = newLeft;
    //     positionRight = newRight;
    // }

}

void encoder_isr()
{
    positionLeft = leftWheel.read();
    positionRight = rightWheel.read();
    Serial.println(String(String(positionLeft) + " " + String(positionRight)));
    
}

void setup()
{
    // Encoder Setup
    pinMode(ENC_R_CH_A, INPUT_PULLUP);
    pinMode(ENC_R_CH_B, INPUT_PULLUP);
    
    pinMode(ENC_L_CH_A, INPUT_PULLUP);
    pinMode(ENC_L_CH_B, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(ENC_R_CH_A), enc_r_isr, CHANGE); 
    attachInterrupt(digitalPinToInterrupt(ENC_L_CH_A), enc_l_isr, CHANGE); 

    // Motors Setup
    pinMode(ENA, OUTPUT);
	pinMode(ENB, OUTPUT);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);

    // Distance Sensors Setup
    pinMode(L_SENSOR, INPUT); // Left Sensor
    pinMode(L_GPIO1, OUTPUT); // Enable Pin
    
    pinMode(FL_SENSOR, INPUT); // Front Left Sensor
    pinMode(FL_GPIO1, OUTPUT); // Enable Pin

    pinMode(FR_SENSOR, INPUT); // Front Right Sensor
    pinMode(FR_GPIO1, OUTPUT); // Enable Pin

    pinMode(R_SENSOR, OUTPUT); // Right Sensor
    pinMode(R_GPIO1, OUTPUT); // Enable Pin
    
    Serial.begin(9600);

    // Attach Servo 
    // servo.attach(SERVO);
    
    // When program starts, turn off all motors 
    stop();

    // Encoder counts
    leftWheel.write(0);
    rightWheel.write(0);

    Timer8.attachInterrupt(handler_isr);
	Timer8.start(50000); // Calls every 50ms
    
    // Timer7.attachInterrupt(encoder_isr);
    // Timer7.start(25000);


}

void loop()
{    
    positionLeft = leftWheel.read();
    positionRight = rightWheel.read();
    Serial.println(String(String(positionLeft) + " " + String(positionRight)));
}
