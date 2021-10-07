// #include <Arduino.h>
// #include "maze_bot.h"


// Motors motors; 

// void setup()
// {
//      // Stops both motors

// }

// void loop()
// {
//     motors.drive(-100);   
//     delay(2000);

//     motors.drive(100);
//     delay(2000); 


     
//     motors.stop();   
// }



#include <Arduino.h>
#include <Servo.h>

int servoPin = 9;
Servo servo;
int angle = 0;  // servo position in degrees

void setup() {
    
    servo.attach(servoPin);

    Serial.begin(96000);
}

void loop() {

    // scan from 0 to 180 degrees
    for(angle = 0; angle < 180; angle++) {
        servo.write(angle);
        Serial.println(angle);
        delay(50);
    }
    
    // now scan back from 180 to 0 degrees
    for(angle = 180; angle > 0; angle--) {
        servo.write(angle);
        Serial.println(angle);
        delay(50);
    }
}


















// // using maze_bot::Motors;


// // Motors m(enA, in1, in2, in3, in4, enB);

// // void setup()
// // {
// //     m.setSpeed(100);
// //     Serial.begin(250000);
// // }

// // void loop()
// // {
// //     Serial.println("Working");
// //     m.forward();
// //     delay(3000);
    
// //     //exit(0);
// // }






// // #include <Arduino.h>

// // // Motor A connections
// // #define enA 7
// // #define in1 10
// // #define in2 11

// // // Motor B connections
// // #define enB 6
// // #define in3 12
// // #define in4 13

// // void directionControl();
// // void speedControl();


// // void setup() {
// // 	// Set all the motor control pins to outputs
// // 	pinMode(enA, OUTPUT);
// // 	pinMode(enB, OUTPUT);
// // 	pinMode(in1, OUTPUT);
// // 	pinMode(in2, OUTPUT);
// // 	pinMode(in3, OUTPUT);
// // 	pinMode(in4, OUTPUT);
	
// // 	// Turn off motors - Initial state
// // 	digitalWrite(in1, LOW);
// // 	digitalWrite(in2, LOW);
// // 	digitalWrite(in3, LOW);
// // 	digitalWrite(in4, LOW);
// // }

// // void loop() {
// // 	directionControl();
// // 	delay(1000);
// // 	speedControl();
// // 	delay(1000);
// // }

// // // This function lets you control spinning direction of motors
// // void directionControl() {
// // 	// Set motors to maximum speed
// // 	// For PWM maximum possible values are 0 to 255
// // 	analogWrite(enA, 255);
// // 	analogWrite(enB, 255);

// // 	// Turn on motor A & B
// // 	digitalWrite(in1, HIGH);
// // 	digitalWrite(in2, LOW);
// // 	digitalWrite(in3, HIGH);
// // 	digitalWrite(in4, LOW);
// // 	delay(2000);
	
// // 	// Now change motor directions
// // 	digitalWrite(in1, LOW);
// // 	digitalWrite(in2, HIGH);
// // 	digitalWrite(in3, LOW);
// // 	digitalWrite(in4, HIGH);
// // 	delay(2000);
	
// // 	// Turn off motors
// // 	digitalWrite(in1, LOW);
// // 	digitalWrite(in2, LOW);
// // 	digitalWrite(in3, LOW);
// // 	digitalWrite(in4, LOW);
// // }

// // // This function lets you control speed of the motors
// // void speedControl() {
// // 	// Turn on motors
// // 	digitalWrite(in1, LOW);
// // 	digitalWrite(in2, HIGH);
// // 	digitalWrite(in3, LOW);
// // 	digitalWrite(in4, HIGH);
	
// // 	// Accelerate from zero to maximum speed
// // 	for (int i = 0; i < 256; i++) {
// // 		analogWrite(enA, i);
// // 		analogWrite(enB, i);
// // 		delay(20);
// // 	}
	
// // 	// Decelerate from maximum speed to zero
// // 	for (int i = 255; i >= 0; --i) {
// // 		analogWrite(enA, i);
// // 		analogWrite(enB, i);
// // 		delay(20);
// // 	}
	
// // 	// Now turn off motors
// // 	digitalWrite(in1, LOW);
// // 	digitalWrite(in2, LOW);
// // 	digitalWrite(in3, LOW);
// // 	digitalWrite(in4, LOW);
// // }

























// #include <Arduino.h>

// // Parameters
// const int drive_distance = 100;   // cm
// const int motor_power = 200;      // 0-255
// const int motor_offset = 3;       // Diff. when driving straight
// const int wheel_d = 60;           // Wheel diameter (mm)
// const float wheel_c = PI * wheel_d; // Wheel circumference (mm)
// const int counts_per_rev = 384;   // (4 pairs N-S) * (48:1 gearbox) * (2 falling/rising edges) = 384

// // Pins
// const int enc_l_pin = 56;          // Motor A
// const int enc_r_pin = 55;          // Motor B
// const int pwma_pin = 7;
// const int ain1_pin = 10;
// const int ain2_pin = 11;
// const int pwmb_pin = 6;
// const int bin1_pin = 13;
// const int bin2_pin = 12;
// // const int stby_pin = ;

// // Globals
// volatile unsigned long enc_l = 0;
// volatile unsigned long enc_r = 0;


// //Function Declarations
// //-----------------------------------------------------------------------------------



// // void enableMotors(boolean en) {
// //   if ( en ) {
// //     digitalWrite(stby_pin, HIGH);
// //   } else {
// //     digitalWrite(stby_pin, LOW);
// //   }
// // }

// void drive(int power_a, int power_b) {

//   // Constrain power to between -255 and 255
//   power_a = constrain(power_a, -255, 255);
//   power_b = constrain(power_b, -255, 255);

//   // Left motor direction
//   if ( power_a < 0 ) {
//     digitalWrite(ain1_pin, LOW);
//     digitalWrite(ain2_pin, HIGH);
//   } else {
//     digitalWrite(ain1_pin, HIGH);
//     digitalWrite(ain2_pin, LOW);
//   }

//   // Right motor direction
//   if ( power_b < 0 ) {
//     digitalWrite(bin1_pin, LOW);
//     digitalWrite(bin2_pin, HIGH);
//   } else {
//     digitalWrite(bin1_pin, HIGH);
//     digitalWrite(bin2_pin, LOW);
//   }

//   // Set speed
//   analogWrite(pwma_pin, abs(power_a));
//   analogWrite(pwmb_pin, abs(power_b));
// }

// void brake() {
//   digitalWrite(ain1_pin, LOW);
//   digitalWrite(ain2_pin, LOW);
//   digitalWrite(bin1_pin, LOW);
//   digitalWrite(bin2_pin, LOW);
//   analogWrite(pwma_pin, 0);
//   analogWrite(pwmb_pin, 0);
// }

// void countLeft() {
//   enc_l++;
// }

// void countRight() {
//   enc_r++;
// }


// void driveStraight(float dist, int power) {

//   unsigned long num_ticks_l;
//   unsigned long num_ticks_r;

//   // Set initial motor power
//   int power_l = motor_power;
//   int power_r = motor_power;

//   // Used to determine which way to turn to adjust
//   unsigned long diff_l;
//   unsigned long diff_r;

//   // Reset encoder counts
//   enc_l = 0;
//   enc_r = 0;

//   // Remember previous encoder counts
//   unsigned long enc_l_prev = enc_l;
//   unsigned long enc_r_prev = enc_r;

//   // Calculate target number of ticks
//   float num_rev = (dist * 10) / wheel_c;  // Convert to mm
//   unsigned long target_count = num_rev * counts_per_rev;
  
//   // Debug
//   Serial.print("Driving for ");
//   Serial.print(dist);
//   Serial.print(" cm (");
//   Serial.print(target_count);
//   Serial.print(" ticks) at ");
//   Serial.print(power);
//   Serial.println(" motor power");

//   // Drive until one of the encoders reaches desired count
//   while ( (enc_l < target_count) && (enc_r < target_count) ) {

//     // Sample number of encoder ticks
//     num_ticks_l = enc_l;
//     num_ticks_r = enc_r;

//     // Print out current number of ticks
//     Serial.print(num_ticks_l);
//     Serial.print("\t");
//     Serial.println(num_ticks_r);

//     // Drive
//     drive(power_l, power_r);

//     // Number of ticks counted since last time
//     diff_l = num_ticks_l - enc_l_prev;
//     diff_r = num_ticks_r - enc_r_prev;

//     // Store current tick counter for next time
//     enc_l_prev = num_ticks_l;
//     enc_r_prev = num_ticks_r;

//     // If left is faster, slow it down and speed up right
//     if ( diff_l > diff_r ) {
//       power_l -= motor_offset;
//       power_r += motor_offset;
//     }

//     // If right is faster, slow it down and speed up left
//     if ( diff_l < diff_r ) {
//       power_l += motor_offset;
//       power_r -= motor_offset;
//     }

//     // Brief pause to let motors respond
//     delay(20);
//   }

//   // Brake
//   brake();
// }


// //------------------------------------------------------------------------------------

// void setup() {

//   // Debug
//   Serial.begin(250000);

//   // Set up pins
//   pinMode(enc_l_pin, INPUT_PULLUP);
//   pinMode(enc_r_pin, INPUT_PULLUP);
//   pinMode(pwma_pin, OUTPUT);
//   pinMode(ain1_pin, OUTPUT);
//   pinMode(ain2_pin, OUTPUT);
//   pinMode(pwmb_pin, OUTPUT);
//   pinMode(bin1_pin, OUTPUT);
//   pinMode(bin2_pin, OUTPUT);
// //   pinMode(stby_pin, OUTPUT);

//   // Set up interrupts
//   attachInterrupt(digitalPinToInterrupt(enc_l_pin), countLeft, CHANGE);
//   attachInterrupt(digitalPinToInterrupt(enc_r_pin), countRight, CHANGE);

//   // Drive straight
//   delay(5000);
// //   enableMotors(true);
//   driveStraight(drive_distance, motor_power);
  
// }

// void loop() {
//   // Do nothing
// }

