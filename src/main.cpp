#include <Arduino.h>

// Motor R connections
#define ENA 7
#define IN1 10
#define IN2 11

// Motor L connections
#define ENB 6
#define IN3 12
#define IN4 13

// Motor R Encoder
#define ENC_R_CH_A 56
#define ENC_R_CH_B 57

// Motor L Encoder
#define ENC_L_CH_A 55
#define ENC_L_CH_B 54

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
long enc_r_count = 0;
long enc_l_count = 0;
const int SENSOR_SAMPLES=15;

// Declare Functions
void enc_r_isr();
void enc_l_isr();
void stop();
void forward();
float read_sensor(int sensor_pin);



void setup()
{
    Serial.begin(9600);
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
    
    
    // Turn off all motors
    stop();

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
    return (sensor_sum/SENSOR_SAMPLES)*(-0.12) + 86.9;
    
    // Uncomment the following line for raw data
    // return sensor_sum/SENSOR_SAMPLES;

    digitalWrite(L_GPIO1, LOW); // Turn off sensor
}

void forward()
{
    analogWrite(ENA, 255);
	analogWrite(ENB, 255);

	// Turn on motor A & B
	digitalWrite(IN1, HIGH);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, HIGH);
	digitalWrite(IN4, LOW);
	delay(2000);
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