#pragma once

// Motor R connections
#define ENA 7
#define IN1 10
#define IN2 11

// Motor L connections
#define ENB 6
#define IN3 12
#define IN4 13


// Encoder R Connections
#define ENC_R_CH_A 55
#define ENC_R_CH_B 54

// Encoder L Connections
#define ENC_L_CH_A 56
#define ENC_L_CH_B 57



class Motors
{
    public:
        Motors();
        void stop();
        void drive(int speed);
        void drive(int speed, uint32_t duration);

        void turn_left();
        void turn_right();


    private:
        uint8_t _speed;

        void left_motor_fwd(uint8_t speed);
        void right_motor_fwd(uint8_t speed);
        void left_motor_rev(uint8_t speed);
        void right_motor_rev(uint8_t speed);
};


// class Encoders
// {
//     public:
//         Encoders();
//         void getTicks();
//         void printTicks();
//         static void enc_r_isr();
//         static void enc_l_isr();

//     private:
//         long enc_r_count = 0;
//         long enc_l_count = 0;

// };