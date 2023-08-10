#include "Wire.h"
#include "Adafruit_PWMServoDriver.h"
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define MIN_PULSE_WIDTH 600
#define MAX_PULSE_WIDTH 2600
#define FREQUENCY 50

//Posiciones iniciales DOWN
#define PD0_FIZQ 30
#define PD0_FDER 240
#define PD0_ADER 240
#define PD0_AIZQ 30

#define PM0_FIZQ 270
#define PM0_FDER 0
#define PM0_ADER 0
#define PM0_AIZQ 270

#define PU0_FIZQ 90
#define PU0_FDER 175
#define PU0_ADER 100
#define PU0_AIZQ 185


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

  /*
  Parado
  pwm.setPWM(0, 0, pulseWidth(90)); //FIZQ 
  pwm.setPWM(4, 0, pulseWidth(175)); //FDER
  pwm.setPWM(8, 0, pulseWidth(185)); //AIZQ
  pwm.setPWM(12, 0, pulseWidth(100)); //ADER
  //pwm.setPWM(1, 0, pulseWidth(270));
  ///////////////
  pwm.setPWM(1, 0, pulseWidth(220)); //FIZQ 
  pwm.setPWM(5, 0, pulseWidth(60)); //FDER
  pwm.setPWM(9, 0, pulseWidth(240)); //AIZQ
  pwm.setPWM(13, 0, pulseWidth(30)); //ADER
  ////////////
  pwm.setPWM(2, 0, pulseWidth(120)); //FIZQ
  pwm.setPWM(6, 0, pulseWidth(140)); //FDER
  pwm.setPWM(10, 0, pulseWidth(120)); //AIZQ
  pwm.setPWM(14, 0, pulseWidth(140)); //ADER
  */  
  acostado();
  delay(5000);
  parado();
  delay(5000);
}

// UP
//
//FDER 270 -- 
//FIZQ 0 -- 
//ADER  0 --
//AIZQ  270 --


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
void parado(){
  //Parado
  //Up
  pwm.setPWM(0, 0, pulseWidth(90)); //FIZQ 
  pwm.setPWM(4, 0, pulseWidth(175)); //FDER
  pwm.setPWM(8, 0, pulseWidth(185)); //AIZQ
  pwm.setPWM(12, 0, pulseWidth(100)); //ADER

  ///////////////Mid
  pwm.setPWM(9, 0, pulseWidth(240)); //AIZQ
  pwm.setPWM(13, 0, pulseWidth(30)); //ADER
  pwm.setPWM(1, 0, pulseWidth(220)); //FIZQ 
  pwm.setPWM(5, 0, pulseWidth(60)); //FDER
  delay(500);

  ////////////DOWN
  pwm.setPWM(10, 0, pulseWidth(120)); //AIZQ
  pwm.setPWM(14, 0, pulseWidth(140)); //ADER
  pwm.setPWM(2, 0, pulseWidth(120)); //FIZQ
  pwm.setPWM(6, 0, pulseWidth(140)); //FDER
}
void acostado(){
  //Acostado
  //UP
  pwm.setPWM(0, 0, pulseWidth(90)); //FIZQ 
  pwm.setPWM(4, 0, pulseWidth(175)); //FDER
  pwm.setPWM(8, 0, pulseWidth(185)); //AIZQ
  pwm.setPWM(12, 0, pulseWidth(100)); //ADER

  ///////////////MID
  pwm.setPWM(1, 0, pulseWidth(270)); //FIZQ 
  pwm.setPWM(5, 0, pulseWidth(0)); //FDER
  pwm.setPWM(9, 0, pulseWidth(270)); //AIZQ
  pwm.setPWM(13, 0, pulseWidth(0)); //ADER
  delay(200);
  ////////////DOWN
  pwm.setPWM(2, 0, pulseWidth(30)); //FIZQ
  pwm.setPWM(6, 0, pulseWidth(240)); //FDER
  pwm.setPWM(10, 0, pulseWidth(30)); //AIZQ
  pwm.setPWM(14, 0, pulseWidth(240)); //ADER
}

void down(int angle){
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
void up(int angle){
  for (int ang = angle; ang >= 0; ang--) {
    pwm.setPWM(0, 0, pulseWidth(ang));
    delay(20);
  }
  delay(3000);
  for (int ang = 0; ang <= angle; ang++) {
    pwm.setPWM(0, 0, pulseWidth(ang));
    delay(20);
  }
  delay(3000);
}
