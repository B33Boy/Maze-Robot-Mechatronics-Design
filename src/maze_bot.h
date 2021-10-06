#pragma once

// Motor A connections
#define enA 7
#define in1 10
#define in2 11

// Motor B connections
#define enB 6
#define in3 12
#define in4 13



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