#define ENC_R_CH_A 55
#define ENC_R_CH_B 54

#define ENC_L_CH_A 56
#define ENC_L_CH_B 57

#include <Arduino.h>

long enc_r_count = 0;
long enc_l_count = 0;


// Declare Functions
void enc_r_isr();
void enc_l_isr();

void setup()
{
    pinMode(ENC_R_CH_A, INPUT_PULLUP);
    pinMode(ENC_R_CH_B, INPUT_PULLUP);
    
    pinMode(ENC_L_CH_A, INPUT_PULLUP);
    pinMode(ENC_L_CH_B, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(ENC_R_CH_A), enc_r_isr, CHANGE); // Rising For Method 1
    attachInterrupt(digitalPinToInterrupt(ENC_L_CH_A), enc_l_isr, CHANGE); // Rising FOr Method 1
    Serial.begin(9600);
    Serial.println("Initalizing");
}



void loop()
{
    //Serial.println((String)enc_r_count + "  " +  (String)enc_l_count);
    Serial.println(enc_r_count);
    Serial.println(enc_l_count);
    Serial.println();
    delay(50);

}

// Method 1. Standard, Interrupt is 
// void enc_r_isr()
// {
//     if (digitalRead(ENC_R_CH_B) == HIGH)
//     {
//         enc_r_count++;
//     }
//     else
//     {
//         enc_r_count--;
//     }
// }

// void enc_l_isr()
// {
//     if (digitalRead(ENC_L_CH_B) == HIGH)
//     {
//         enc_l_count++;
//     }
//     else
//     {
//         enc_l_count--;
//     }
// }


// Method 2. Double Resolution
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