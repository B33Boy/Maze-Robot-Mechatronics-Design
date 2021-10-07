#define ENC_R_CH_A 55
#define ENC_R_CH_B 54

#define ENC_L_CH_A 56
#define ENC_L_CH_B 57

#include <Arduino.h>

long enc_r_count = 0;
long enc_l_count = 0;


// Declare 
void enc_r_isr_a();
void enc_r_isr_b();

void enc_l_isr_a();
void enc_l_isr_b();

void setup()
{
    Serial.println("Initalizing");
    pinMode(ENC_R_CH_A, INPUT_PULLUP);
    pinMode(ENC_R_CH_B, INPUT_PULLUP);
    
    pinMode(ENC_L_CH_A, INPUT_PULLUP);
    pinMode(ENC_L_CH_B, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(ENC_R_CH_A), enc_r_isr_a, CHANGE); // Use RISING For Method 1
    attachInterrupt(digitalPinToInterrupt(ENC_R_CH_B), enc_l_isr_b, CHANGE); // Use RISING FOr Method 1

    attachInterrupt(digitalPinToInterrupt(ENC_L_CH_A), enc_r_isr_a, CHANGE); // Use RISING For Method 1
    attachInterrupt(digitalPinToInterrupt(ENC_L_CH_B), enc_l_isr_b, CHANGE); // Use RISING FOr Method 1

    Serial.begin(9600);
}



void loop()
{
    //Serial.println((String)enc_r_count + "  " +  (String)enc_l_count);
    Serial.println(enc_r_count);
    Serial.println(enc_l_count);
    Serial.println();
    delay(50);

}


// Method 3. Port Manipulation
void enc_r_isr_a()
{
    uint8_t portState = REG_PIOD_PDSR; //Register holds current state of pins

    enc_r_count = enc_r_count - 1 + ((portState & 0b00000010)^(portState & 0b00000001)<<1);
}

void enc_r_isr_b()
{
    uint8_t portState = REG_PIOD_PDSR; //Register holds current state of pins

    enc_r_count = enc_r_count - 1 + ((!(portState & 0b00000001)^((portState & 0b00000010)>>1))<<1);
}


void enc_l_isr_a()
{
    uint8_t portState = REG_PIOD_PDSR; //Register holds current state of pins

    enc_l_count = enc_l_count - 1 + ((portState & 0b00000010)^(portState & 0b00000001)<<1);
}

void enc_l_isr_b()
{
    uint8_t portState = REG_PIOD_PDSR; //Register holds current state of pins

    enc_l_count = enc_l_count - 1 + ((!(portState & 0b00000001)^((portState & 0b00000010)>>1))<<1);
}
