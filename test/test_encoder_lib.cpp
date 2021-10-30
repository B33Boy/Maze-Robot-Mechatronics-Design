
#include <Encoder.h>
#include <Arduino.h>



#define ENC_R_CH_A 55
#define ENC_R_CH_B 54

#define ENC_L_CH_A 56
#define ENC_L_CH_B 57




// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder knobLeft(ENC_R_CH_A, ENC_R_CH_B);
Encoder knobRight(ENC_L_CH_A, ENC_L_CH_B);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
  Serial.println("Encoder Test:");
    // Encoder Setup
    pinMode(ENC_R_CH_A, INPUT_PULLUP);
    pinMode(ENC_R_CH_B, INPUT_PULLUP);
    
    pinMode(ENC_L_CH_A, INPUT_PULLUP);
    pinMode(ENC_L_CH_B, INPUT_PULLUP);

  knobLeft.write(0);
  knobRight.write(0);
}

long positionLeft  = -999;
long positionRight = -999;

long enc_r_count = 0;
long enc_l_count = 0;

void loop() 
{

  long newLeft, newRight;
  newLeft = knobLeft.read();
  newRight = knobRight.read();

  if (newLeft != positionLeft || newRight != positionRight) 
  {
    Serial.print("Left = ");
    Serial.print(newLeft);
    Serial.print(", Right = ");
    Serial.print(newRight);
    Serial.println();
    positionLeft = newLeft;
    positionRight = newRight;
  }

//   enc_r_count = knobLeft.read();
//   enc_l_count = knobRight.read();


  
 
//   Serial.println(String(enc_r_count) + " | " + String(enc_l_count));
  delay(50);
}