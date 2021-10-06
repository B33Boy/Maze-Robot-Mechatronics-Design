// #include <Arduino.h>
// #include "maze_bot.h"




// Encoders::Encoders()
// {
//     pinMode(ENC_R_CH_A, INPUT_PULLUP);
//     pinMode(ENC_R_CH_B, INPUT_PULLUP);
    
//     pinMode(ENC_L_CH_A, INPUT_PULLUP);
//     pinMode(ENC_L_CH_B, INPUT_PULLUP);

 
    
//     attachInterrupt(digitalPinToInterrupt(ENC_R_CH_A), enc_r_callback, CHANGE); // Rising For Method 1
//     attachInterrupt(digitalPinToInterrupt(ENC_L_CH_A), enc_l_callback, CHANGE); // Rising FOr Method 1

//     // void setupEncoder();
// }


// void Encoders::getTicks()
// {
    
// }


// // void setupEncoder()
// // {
// //     attachInterrupt(digitalPinToInterrupt(ENC_R_CH_A), enc_r_isr, CHANGE); // Rising For Method 1
// //     attachInterrupt(digitalPinToInterrupt(ENC_L_CH_A), enc_l_isr, CHANGE); // Rising FOr Method 1
// // }

// void enc_r_callback()
// {   
//     enc_r_isr();   
// }

// static void Encoder::enc_r_isr()
// {
//     if (digitalRead(ENC_R_CH_A) == HIGH)
//     {
//         if (digitalRead(ENC_R_CH_B) == HIGH)
//         {
//             enc_r_count++;
//         }
//         else
//         {
//             enc_r_count--;
//         }
        
//     }
//     else
//     {
//         if (digitalRead(ENC_R_CH_B) == HIGH)
//         {
//             enc_r_count--;
//         }
//         else
//         {
//             enc_r_count++;
//         }
//     }
// }


// void enc_l_isr()
// {
//     if (digitalRead(ENC_L_CH_A) == HIGH)
//     {
//         if (digitalRead(ENC_L_CH_B) == HIGH)
//         {
//             enc_l_count++;
//         }
//         else
//         {
//             enc_l_count--;
//         }
        
//     }
//     else
//     {
//         if (digitalRead(ENC_L_CH_B) == HIGH)
//         {
//             enc_l_count--;
//         }
//         else
//         {
//             enc_l_count++;
//         }
//     }
// }