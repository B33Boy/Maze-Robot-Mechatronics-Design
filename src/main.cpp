#include <Arduino.h>
#include <Servo.h>
#include "maze_bot.h"
#include <DueTimer.h>

void handler_isr()
{
    follow_wall();
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

    Timer8.attachInterrupt(handler_isr);
	Timer8.start(50000); // Calls every 50ms
    

}

void loop()
{
    // float l_sensor = read_sensor(L_SENSOR,  L_GPIO1);
    // float r_sensor = read_sensor(R_SENSOR,  R_GPIO1);
    // float fl_sensor = read_sensor(FL_SENSOR,  FL_GPIO1);
    // float fr_sensor = read_sensor(FR_SENSOR,  FR_GPIO1);
    // Serial.println("l_sensor:" + String(l_sensor)  + " fl_sensor:" + String(fl_sensor) + " fr_sensor:" + String(fr_sensor) + " r_sensor:" + String(r_sensor) );    
    // Serial.println("r_sensor" + String(r_sensor));
    // delay(250);

    // Serial.println(String(obstacle_left()) + " " + String(obstacle_forward()) + " " + String(obstacle_right()));
    
    // follow_wall();
    // forward();
    // delay(50);

    // stop();
    // delay(4000);

}

