#include <Arduino.h>
#include <Servo.h>

int servoPin = 9;
Servo servo;
int angle = 0;  // servo position in degrees

void setup() {
    servo.attach(servoPin);
    Serial.begin(9600);
}

void loop() {

    // scan from 0 to 180 degrees
    for(angle = 0; angle < 180; angle++) {
        servo.write(angle);
        Serial.println(angle);
        delay(1000);
    }
    
    // now scan back from 180 to 0 degrees
    for(angle = 180; angle > 0; angle--) {
        servo.write(angle);
        Serial.println(angle);
        delay(1000);
    }
}