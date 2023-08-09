#include "Wire.h"
#include "Adafruit_PWMServoDriver.h"
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define MIN_PULSE_WIDTH 600
#define MAX_PULSE_WIDTH 2600
#define FREQUENCY 50

//Posiciones iniciales DOWN
#define PD0_FIZQ 0
#define PD0_FDER 270
#define PD0_ADER 270
#define PD0_AIZQ 0

void setup() {
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 270, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}

void loop() {
  pwm.setPWM(0, 0, pulseWidth(0));
  pwm.setPWM(1, 0, pulseWidth(270));
  delay(3000);
  //pwm.setPWM(0, 0, pulseWidth(270));
  //delay(3000);
  //left_down(270);
}

// UP

//FDER 270 -- 
//FIZQ  -- 
//ADER  -- 
//AIZQ  -- 


//-------------
// Mid

//FDER 0 -- 
//FIZQ 270 -- 
//ADER 0 -- 
//AIZQ 270 -- 


//-------------------
// Down
//FIZQ 0
//FDER 270
//AIZQ 0
//ADER 270

void  left_down(int angle){
  for (int ang = 0; ang <= angle; ang++) {
    pwm.setPWM(0, 0, pulseWidth(ang));
    delay(20);
  }
  delay(3000);
  for (int ang = angle; ang >= 0; ang--) {
    pwm.setPWM(0, 0, pulseWidth(ang));
    delay(20);
  }
  delay(3000);
}