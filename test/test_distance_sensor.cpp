#include <Arduino.h>

// Sensors
#define L_SENSOR A7
#define FL_SENSOR A6
#define FR_SENSOR A5
#define R_SENSOR A4

//Sensor GPIO1 Standby Pins
#define L_GPIO1 A11
#define FL_GPIO1 A10
#define FR_GPIO1 A9
#define R_GPIO1 A8



// Global Variables
const int SENSOR_SAMPLES=15;

// Declare Functions

float read_sensor(int sensor_pin);

void setup()
{
    // Distance Sensors Setup
    pinMode(L_SENSOR, INPUT); // Left Sensor
    pinMode(L_GPIO1, OUTPUT); // Enable Pin
    
    pinMode(FL_SENSOR, INPUT); // Front Left Sensor
    pinMode(FL_GPIO1, OUTPUT); // Enable Pin

    pinMode(FR_SENSOR, INPUT); // Front Right Sensor
    pinMode(FR_GPIO1, OUTPUT); // Enable Pin

    pinMode(R_SENSOR, OUTPUT); // Right Sensor
    pinMode(R_GPIO1, OUTPUT); // Enable Pin

}

void loop()
{
    
    // Serial.println((String)enc_l_count + "  " +  (String)enc_r_count);
    // Serial.println();
    // delay(50);

    float l_sensor = read_sensor(L_SENSOR);
    // float fr_sensor = read_sensor(FR_SENSOR);
    // float fr_sensor = read_sensor(FR_SENSOR);
    // float r_sensor = read_sensor(R_SENSOR);
    Serial.println(l_sensor);

}


float read_sensor(int sensor_pin)
{
    digitalWrite(L_GPIO1, HIGH); // Turn on sensor
    unsigned int sensor_sum = 0;
    for (int i=0; i<SENSOR_SAMPLES; i++)
    {
        sensor_sum += analogRead(sensor_pin);
    }
    return (sensor_sum/SENSOR_SAMPLES)*(-0.12) + 86.9; // m and b values obtained from data collected at x=40cm to 
    
    // Uncomment the following line for raw data
    // return sensor_sum/SENSOR_SAMPLES;

    digitalWrite(L_GPIO1, LOW); // Turn off sensor
}