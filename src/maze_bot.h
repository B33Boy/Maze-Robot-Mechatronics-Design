#ifndef MAZE_BOT_H
#define MAZE_BOT_H

// Motor R connections
#define ENA 7
#define IN1 10
#define IN2 11

// Motor L connections
#define ENB 6
#define IN3 12
#define IN4 13

// Motor R Encoder
#define ENC_R_CH_A 5//56
#define ENC_R_CH_B 4//57

// Motor L Encoder
#define ENC_L_CH_A 2//55
#define ENC_L_CH_B 3//54

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


// PID
#define DESIRED_DIST 6
#define FWD_VEL 120
#define TURN_RATE 100

#define COLLISION_DIST 10
#define MAX_SPEED_DIFF 40
#define SPEED_CORRECTION 50

#define MIN_SPEED 100
#define MAX_SPEED 255

// // Left wall following
// #define KP 5
// #define KI 0
// #define KD 2

// Double wall following
#define KP 5
#define KI 0.05
#define KD 2

extern float error;
extern float error_sum;
extern float error_change;
extern float prev_error;

extern int speedL, speedR;

// Global Variables
extern long enc_r_count;
extern long enc_l_count;

extern long positionLeft; 
extern long positionRight; 

const int SENSOR_SAMPLES = 15;


// Declare Functions
float read_sensor(int sensor_pin, int GPIO1PIN);
void stop();
void drive(int speedL, int ldir, int speedR, int rdir);
void enc_r_isr();
void enc_l_isr();

void turn_right();
void turn_left();

bool obstacle_left();
bool obstacle_forward();
bool obstacle_right();

void follow_wall();
void speed_control(float motor_power);

#endif