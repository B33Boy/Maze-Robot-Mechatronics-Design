#include <Arduino.h>
#include <Servo.h>
#include "maze_bot.h"
#include <DueTimer.h>
#include <Encoder.h>
// #include <stack> 


// Path: 1 = right, 0 = ignore, -1 = left
int path [11] = {-1, -1, 1, 1, 1, 1, 1, 1, -1, 0, -1};
int i = 0;

boolean specialCase()
{
    // Basically if its not a wall 
    Serial.println(String(read_sensor(L_SENSOR, L_GPIO1)) + " | " + String(read_sensor(FL_SENSOR, FL_GPIO1)) + " | " + String(read_sensor(FR_SENSOR, FR_GPIO1)));
    if (read_sensor(L_SENSOR, L_SENSOR) > 20 || read_sensor(FR_SENSOR, FR_GPIO1) > 20)
    {
        return true;
    }

    return false;
}

void wastereads()
{
    for (int i =0; i< 10; i++)
    {
        Serial.println(String(read_sensor(L_SENSOR, L_GPIO1)) + " | " + String(read_sensor(FL_SENSOR, FL_GPIO1)) + " | " + String(read_sensor(FR_SENSOR, FR_GPIO1)));
    }
    Serial.println("FUCKKKKKKKKKK");
    
}

void handler_isr()
{
    // Serial.print("Left = " + String(get_leftWheel()) + ", Right = " + String(get_rightWheel()) + "\n");
    // Serial.println(String(read_sensor(L_SENSOR, L_GPIO1)) + " " + String(read_sensor(FL_SENSOR, FL_GPIO1)) + " " + String(read_sensor(FR_SENSOR, FR_GPIO1)));
    // if (read_sensor(L_SENSOR, L_GPIO1) > 15 && read_sensor(FL_SENSOR, FL_GPIO1) < 12 && read_sensor(FR_SENSOR, FR_GPIO1) < 12) 
    // {
    //     turn_left();
    // }
    // else if(read_sensor(FL_SENSOR, FL_GPIO1) <= COLLISION_DIST)
    // {
    //     stop();
    // }
    
    // Serial.println(String(read_sensor(L_SENSOR, L_GPIO1)) + " | " + String(read_sensor(FL_SENSOR, FL_GPIO1)) + " | " + String(read_sensor(FR_SENSOR, FR_GPIO1)));
    

    if (specialCase())
    {
        Serial.println("Special Case");
        // Timer.stop();
        if (path[i] == 0)
        {   
            Serial.println("GAP");
            drive_forward();
            i++;
        }
        else if (path[i] == -1)
        {   
            Serial.println("LEFT OPEN");
            turn_left();
            i++;
        }
        else if (path[i] == 1)
        {   
            Serial.println("RIGHT OPEN");
            turn_right();
            i++;
        }
        // Timer.start(50000);
    }
    else 
    {
        follow_wall_dual();
        
    }




    // if(read_sensor(FL_SENSOR, FL_GPIO1) <= COLLISION_DIST)
    // {
    //     stop();
    //     delay(5000);
    // }
    // else 
    // {
    //     follow_wall_dual();
    // }   


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

// void encoder_isr()
// {
//     positionLeft = leftWheel.read();
//     positionRight = rightWheel.read();
//     Serial.println(String(String(positionLeft) + " " + String(positionRight)));
    
// }

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

    // // Encoder counts
    // leftWheel.write(0);
    // rightWheel.write(0);
    reset_encoders();

//    Timer8.attachInterrupt(handler_isr);
//    Timer8.start(50000); // Calls every 50ms
    delay(2000);
    wastereads();
}



void loop()
{   
    Serial.println(String(read_sensor(L_SENSOR, L_GPIO1)) + " | " + String(read_sensor(FL_SENSOR, FL_GPIO1)) + " | " + String(read_sensor(FR_SENSOR, FR_GPIO1)));

    if (specialCase())
    {
        Serial.println("Special Case");
        // Timer.stop();
        if (path[i] == 0)
        {   
            Serial.println("GAP");
            drive_forward();
            i++;
        }
        else if (path[i] == -1)
        {   
            Serial.println("LEFT OPEN");
            turn_left();
            i++;
        }
        else if (path[i] == 1)
        {   
            Serial.println("RIGHT OPEN");
            turn_right();
            i++;
        }
        // Timer.start(50000);
    }
    else 
    {
        follow_wall_dual();
        
    }
}
