#include <Arduino.h>
#include "maze_bot.h"


Motors motors; 

void setup()
{
     // Stops both motors

}

void loop()
{
    motors.drive(-100);   
    delay(2000);

    motors.drive(100);
    delay(2000); 


     
    motors.stop();   
}






















// using maze_bot::Motors;


// Motors m(enA, in1, in2, in3, in4, enB);

// void setup()
// {
//     m.setSpeed(100);
//     Serial.begin(250000);
// }

// void loop()
// {
//     Serial.println("Working");
//     m.forward();
//     delay(3000);
    
//     //exit(0);
// }






// #include <Arduino.h>

// // Motor A connections
// #define enA 7
// #define in1 10
// #define in2 11

// // Motor B connections
// #define enB 6
// #define in3 12
// #define in4 13

// void directionControl();
// void speedControl();


// void setup() {
// 	// Set all the motor control pins to outputs
// 	pinMode(enA, OUTPUT);
// 	pinMode(enB, OUTPUT);
// 	pinMode(in1, OUTPUT);
// 	pinMode(in2, OUTPUT);
// 	pinMode(in3, OUTPUT);
// 	pinMode(in4, OUTPUT);
	
// 	// Turn off motors - Initial state
// 	digitalWrite(in1, LOW);
// 	digitalWrite(in2, LOW);
// 	digitalWrite(in3, LOW);
// 	digitalWrite(in4, LOW);
// }

// void loop() {
// 	directionControl();
// 	delay(1000);
// 	speedControl();
// 	delay(1000);
// }

// // This function lets you control spinning direction of motors
// void directionControl() {
// 	// Set motors to maximum speed
// 	// For PWM maximum possible values are 0 to 255
// 	analogWrite(enA, 255);
// 	analogWrite(enB, 255);

// 	// Turn on motor A & B
// 	digitalWrite(in1, HIGH);
// 	digitalWrite(in2, LOW);
// 	digitalWrite(in3, HIGH);
// 	digitalWrite(in4, LOW);
// 	delay(2000);
	
// 	// Now change motor directions
// 	digitalWrite(in1, LOW);
// 	digitalWrite(in2, HIGH);
// 	digitalWrite(in3, LOW);
// 	digitalWrite(in4, HIGH);
// 	delay(2000);
	
// 	// Turn off motors
// 	digitalWrite(in1, LOW);
// 	digitalWrite(in2, LOW);
// 	digitalWrite(in3, LOW);
// 	digitalWrite(in4, LOW);
// }

// // This function lets you control speed of the motors
// void speedControl() {
// 	// Turn on motors
// 	digitalWrite(in1, LOW);
// 	digitalWrite(in2, HIGH);
// 	digitalWrite(in3, LOW);
// 	digitalWrite(in4, HIGH);
	
// 	// Accelerate from zero to maximum speed
// 	for (int i = 0; i < 256; i++) {
// 		analogWrite(enA, i);
// 		analogWrite(enB, i);
// 		delay(20);
// 	}
	
// 	// Decelerate from maximum speed to zero
// 	for (int i = 255; i >= 0; --i) {
// 		analogWrite(enA, i);
// 		analogWrite(enB, i);
// 		delay(20);
// 	}
	
// 	// Now turn off motors
// 	digitalWrite(in1, LOW);
// 	digitalWrite(in2, LOW);
// 	digitalWrite(in3, LOW);
// 	digitalWrite(in4, LOW);
// }