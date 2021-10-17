// #include <Arduino.h>
// #include <Servo.h>

// // Motor R connections
// #define ENA 7
// #define IN1 10
// #define IN2 11

// // Motor L connections
// #define ENB 6
// #define IN3 12
// #define IN4 13

// // Motor R Encoder
// #define ENC_R_CH_A 56
// #define ENC_R_CH_B 57

// // Motor L Encoder
// #define ENC_L_CH_A 55
// #define ENC_L_CH_B 54

// // Sensors
// #define L_SENSOR A7
// #define FL_SENSOR A6
// #define FR_SENSOR A5
// #define R_SENSOR A4

// //Sensor GPIO1 Standby Pins
// #define L_GPIO1 A11
// #define FL_GPIO1 A10
// #define FR_GPIO1 A9
// #define R_GPIO1 A8

// // Servo Pin
// // #define SERVO 9

// // Global Variables
// long enc_r_count = 0;
// long enc_l_count = 0;
// const int SENSOR_SAMPLES=15;
// // Servo servo;

//  float error = 0;
//  float error_sum = 0;
//  float error_change = 0;
//  float prev_error = 0;

//  float KP = 2;
//  float KI = 0;
//  float KD = 0;

//  int fwd_vel = 100;
//  int turning_rate = 0;

//  const int CLICKS_PER_ROTATION = 12;
//  const float GEAR_RATIO = 210.5906;
//  const float WHEEL_DIAMETER = 6.0;
//  const int WHEEL_CIRCUMFERENCE = PI*WHEEL_DIAMETER;


// // Declare Functions
// void enc_r_isr();
// void enc_l_isr();
// void stop();
// void forward();
// void right();
// void left();
// float read_l_sensor();
// float read_fl_sensor();
// float read_fr_sensor();
// float read_r_sensor();
// void SpeedControl(float desired_speed);
// void sensor_handler_isr();

// void setup()
// {
//     Serial.begin(9600);
//     // Encoder Setup
//     pinMode(ENC_R_CH_A, INPUT_PULLUP);
//     pinMode(ENC_R_CH_B, INPUT_PULLUP);
    
//     pinMode(ENC_L_CH_A, INPUT_PULLUP);
//     pinMode(ENC_L_CH_B, INPUT_PULLUP);

//     attachInterrupt(digitalPinToInterrupt(ENC_R_CH_A), enc_r_isr, CHANGE); 
//     attachInterrupt(digitalPinToInterrupt(ENC_L_CH_A), enc_l_isr, CHANGE); 

//     // Motors Setup
//     pinMode(ENA, OUTPUT);
// 	pinMode(ENB, OUTPUT);
// 	pinMode(IN1, OUTPUT);
// 	pinMode(IN2, OUTPUT);
// 	pinMode(IN3, OUTPUT);
// 	pinMode(IN4, OUTPUT);

//     // Distance Sensors Setup
//     pinMode(L_SENSOR, INPUT); // Left Sensor
//     pinMode(L_GPIO1, OUTPUT); // Enable Pin
    
//     pinMode(FL_SENSOR, INPUT); // Front Left Sensor
//     pinMode(FL_GPIO1, OUTPUT); // Enable Pin

//     pinMode(FR_SENSOR, INPUT); // Front Right Sensor
//     pinMode(FR_GPIO1, OUTPUT); // Enable Pin

//     pinMode(R_SENSOR, OUTPUT); // Right Sensor
//     pinMode(R_GPIO1, OUTPUT); // Enable Pin
    

//     // Attach Servo 
//     // servo.attach(SERVO);
    
//     // Turn off all motors
//     stop();

// 	// Timer3.attachInterrupt(sensor_handler_isr);
// 	// Timer3.start(50000); // Calls every 50ms

// }

// void sensor_handler_isr()
// {
//     float l_sensor = read_l_sensor();
//     float fl_sensor = read_fl_sensor();
//     // float fr_sensor = read_fr_sensor();
//     float r_sensor = read_r_sensor();


//     if (fl_sensor > 10)
//     {
//         forward();
//     }
//     else if (fl_sensor < 10 && r_sensor > 10)
//     {
//         right();
//     }
// }  


// void loop()
// {

//     // if (fr_sensor < 10.0)
//     // {
//     //     stop();
//     //     left();
//     //     delay(700);
//     // }
//     // else
//     // {
//     //     forward();
//     //     delay(50);
//     // }

//     stop();
//     forward();
//     delay(1000);

//     right();
//     delay(700);



//     // stop();
//     // right();
//     // delay(700);

//     // stop();
//     // left();
//     // delay(700);

//     // stop();
//     // delay(3000);

// }


// // void SpeedControl(float desired_speed)
// // {
// //    error = desired_speed - fwd_vel; // des speed - actual
// //    error_sum += error;

// //    error_change = error - prev_error;
// //    prev_error = error;


// //    int motor_power = motor_model(desired_speed) + error*KP + error_sum*KI + error_change*KD;

// // }

// // void motor_model(int speed)
// // {
// //     if (speed > 0)
// //     {
// //         left_motor_fwd(abs(speed));
// //         right_motor_fwd(abs(speed));
// //     }
// //     else
// //     {
// //         left_motor_rev(abs(speed));
// //         right_motor_rev(abs(speed));
// //     }
// // } 




// // //PID
// // const double desiredState = (double) 20;
// // const double KP = 2;
// // const double KI = 0;
// // const double KD = 0;

// // double kiTotal = 0.0;
// // double priorError = 0.0;
// // long prevTime = ;

// // void loop()
// // {
// //     // double error = desiredState - read_l_sensor();
// //     // double proportional = kp * error;
// //     // kiTotal += error;
// //     // double integral = ki * kiTotal;

// //     // float derivative = kd * (error - priorError);
// //     // previousError = error;

// //     // float pidResult  = proportional + integral + derivative;



// //     // Serial.println((String)enc_l_count + "  " +  (String)enc_r_count);
// //     // Serial.println();
// //     // delay(50);

// //     // float l_sensor = read_sensor(L_SENSOR, L_GPIO1);
// //     // float fl_sensor = read_sensor(FL_SENSOR,  FL_GPIO1);
// //     // float fr_sensor = read_sensor(FR_SENSOR,  FR_GPIO1);
// //     // float r_sensor = read_sensor(R_SENSOR,  R_GPIO1);
// //     // Serial.println(r_sensor);
// //     // delay(250);

    
// //    error = desired_speed - 100; // des speed - actual
// //    error_sum += error;

// //    error_change = error - prev_error;
// //    prev_error = error;


// //    motor_power = motor_model(desired_speed) + error*KP + 
// //    error_sum*KI + error_change*KD;
    

// // }





// float read_l_sensor()
// {
//     digitalWrite(L_GPIO1, HIGH); // Turn on sensor
//     unsigned int sensor_sum = 0;
//     for (int i=0; i<SENSOR_SAMPLES; i++)
//     {
//         sensor_sum += analogRead(L_SENSOR);
//     }

//     digitalWrite(L_GPIO1, LOW); // Turn off sensor
//     //L
//     return (sensor_sum/SENSOR_SAMPLES)*(-0.12) + 86.9;
    
// }

// float read_fl_sensor()
// {
//     digitalWrite(FL_GPIO1, HIGH); // Turn on sensor
//     unsigned int sensor_sum = 0;
//     for (int i=0; i<SENSOR_SAMPLES; i++)
//     {
//         sensor_sum += analogRead(FL_SENSOR);
//     }

//     digitalWrite(FL_GPIO1, LOW);
//     //FL
//     return (sensor_sum/SENSOR_SAMPLES)*(-0.0978) + 71.7;
//      // Turn off sensor
// }

// float read_fr_sensor()
// {
    
//     // digitalWrite(FR_GPIO1, HIGH); // Turn on sensor
//     unsigned int sensor_sum = 0;
//     for (int i=0; i<SENSOR_SAMPLES; i++)
//     {
//         sensor_sum += analogRead(FR_SENSOR);
//     }

//     // digitalWrite(FR_GPIO1, LOW); // Turn off sensor
//     //FR
//     return (sensor_sum/SENSOR_SAMPLES)*(-0.0979) + 71.5;
    
// }

// float read_r_sensor()
// {
//     digitalWrite(R_GPIO1, HIGH); // Turn on sensor
//     unsigned int sensor_sum = 0;
//     for (int i=0; i<SENSOR_SAMPLES; i++)
//     {
//         sensor_sum += analogRead(R_SENSOR);
//     }

//     digitalWrite(R_GPIO1, LOW); // Turn off sensor
//     //R
//     return (sensor_sum/SENSOR_SAMPLES)*(-0.116) + 81;
    
// }

// void forward()
// {
//     analogWrite(ENA, 100);
// 	analogWrite(ENB, 100);

// 	// Turn on motor A & B
// 	digitalWrite(IN1, HIGH);
// 	digitalWrite(IN2, LOW);
// 	digitalWrite(IN3, LOW);
// 	digitalWrite(IN4, HIGH);
	
// }

// void right()
// {
//     analogWrite(ENA, 100);
// 	analogWrite(ENB, 100);

// 	// Turn on motor A & B
// 	digitalWrite(IN1, HIGH);
// 	digitalWrite(IN2, LOW);
// 	digitalWrite(IN3, HIGH);
// 	digitalWrite(IN4, LOW);
// }


// void left()
// {
//     analogWrite(ENA, 100);
// 	analogWrite(ENB, 100);

// 	digitalWrite(IN1, LOW);
// 	digitalWrite(IN2, HIGH);
// 	digitalWrite(IN3, LOW);
// 	digitalWrite(IN4, HIGH);
// }

// void stop()
// {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);
//   analogWrite(ENA, 0);

//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, LOW);
//   analogWrite(ENB, 0);
// }

// void enc_r_isr()
// {
//     if (digitalRead(ENC_R_CH_A) == HIGH)
//     {
//         if (digitalRead(ENC_R_CH_B) == HIGH)
//         {
//             enc_r_count++;
//         }
//         else
//         {
//             enc_r_count--;
//         }
        
//     }
//     else
//     {
//         if (digitalRead(ENC_R_CH_B) == HIGH)
//         {
//             enc_r_count--;
//         }
//         else
//         {
//             enc_r_count++;
//         }
//     }
// }


// void enc_l_isr()
// {
//     if (digitalRead(ENC_L_CH_A) == HIGH)
//     {
//         if (digitalRead(ENC_L_CH_B) == HIGH)
//         {
//             enc_l_count++;
//         }
//         else
//         {
//             enc_l_count--;
//         }
        
//     }
//     else
//     {
//         if (digitalRead(ENC_L_CH_B) == HIGH)
//         {
//             enc_l_count--;
//         }
//         else
//         {
//             enc_l_count++;
//         }
//     }
// }

// // void grab()
// // {
// //     for (int angle = 80; angle < 130; angle++)
// //     {
// //         servo.write(angle);
// //         Serial.println(angle);
// //         delay(25);
// //     }
// //     delay(500);
// //     for(int angle = 130;  angle > 80; angle--)
// //     {
// //         servo.write(angle);
// //         Serial.println(angle);
// //         delay(25);
// //     }
// // }