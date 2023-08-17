#include "Wire.h"
#include "Adafruit_PWMServoDriver.h"
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define MIN_PULSE_WIDTH 600
#define MAX_PULSE_WIDTH 2600
#define FREQUENCY 50


void setup() {
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  Serial.begin(9600);
  zero();
}

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 270, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}

void loop() {
  if (Serial.available()){
    char data = Serial.read();
    if ( data == '0') {
      Serial.println("zero");
      zero();
    }
    else if (data == '1'){
      zero_up();
      Serial.println("zero up");
      
    }
    else if (data == '2'){
      parado();
      Serial.println("parado");
    }
    else if (data == '3'){
      acostado();
      Serial.println("acostado");
    }
    else if (data == '4'){
      zero_down();
      Serial.println("zero down");
    }
    else if (data == '5'){
      sentado();
      Serial.println("sentado");
      uint16_t  getpwm = pwm.getPWM(0);
      Serial.println(getpwm);
    }
  }
  //delay(5000);
  //parado();
  //pwm.setPWM(0, 0, pulseWidth(0));
  delay(20);
}
//Minimos

// UP
//
//FDER 270 -- 180
//FIZQ 0 -- 90
//ADER  0 -- 90
//AIZQ  270 -- 180


//-------------
// Mid

//FDER 0 -- 90 Inicial
//FIZQ 270 -- 180 Inicial
//ADER 0 -- 90 Inicial
//AIZQ 270 -- 180 Inicial


//-------------------
// Down
//FIZQ 0
//FDER 270
//AIZQ 0
//ADER 270
void parado(){
  //Parado
  //Up
  pwm.setPWM(2, 0, pulseWidth(100)); //FIZQ 
  pwm.setPWM(6, 0, pulseWidth(180)); //FDER
  pwm.setPWM(10, 0, pulseWidth(170)); //AIZQ
  pwm.setPWM(14, 0, pulseWidth(100)); //ADER

  ///////////////MID
  pwm.setPWM(9, 0, pulseWidth(150)); //AIZQ
  pwm.setPWM(13, 0, pulseWidth(120)); //ADER
  pwm.setPWM(1, 0, pulseWidth(150)); //FIZQ 
  pwm.setPWM(5, 0, pulseWidth(130)); //FDER
  

  ////////////DOWN
  pwm.setPWM(8, 0, pulseWidth(90)); //AIZQ
  pwm.setPWM(12, 0, pulseWidth(180)); //ADER
  delay(200);
  pwm.setPWM(0, 0, pulseWidth(80)); //FIZQ
  pwm.setPWM(4, 0, pulseWidth(180)); //FDER
  
  

  
}

void sentado(){
  //Parado
  //Up
  pwm.setPWM(2, 0, pulseWidth(100)); //FIZQ 
  pwm.setPWM(6, 0, pulseWidth(180)); //FDER
  pwm.setPWM(10, 0, pulseWidth(170)); //AIZQ
  pwm.setPWM(14, 0, pulseWidth(100)); //ADER

  ///////////////MID
  pwm.setPWM(1, 0, pulseWidth(140)); //FIZQ 
  pwm.setPWM(5, 0, pulseWidth(140)); //FDER
  pwm.setPWM(9, 0, pulseWidth(180)); //AIZQ
  pwm.setPWM(13, 0, pulseWidth(90)); //ADER
  ////////////DOWN
  pwm.setPWM(0, 0, pulseWidth(120)); //FIZQ
  pwm.setPWM(4, 0, pulseWidth(150)); //FDER
  pwm.setPWM(8, 0, pulseWidth(55)); //AIZQ
  pwm.setPWM(12, 0, pulseWidth(215)); //ADER
}
// Mid

//FDER 0 -- 90 Inicial
//FIZQ 270 -- 180 Inicial
//ADER 0 -- 90 Inicial
//AIZQ 270 -- 180 Inicial


//-------------------
// Down
//FIZQ 0
//FDER 270
//AIZQ 0
//ADER 270

void acostado(){
  //Acostado
  //UP
  pwm.setPWM(2, 0, pulseWidth(100)); //FIZQ 
  pwm.setPWM(6, 0, pulseWidth(180)); //FDER
  pwm.setPWM(10, 0, pulseWidth(170)); //AIZQ
  pwm.setPWM(14, 0, pulseWidth(100)); //ADER

  ///////////////MID
  pwm.setPWM(1, 0, pulseWidth(180)); //FIZQ 
  pwm.setPWM(5, 0, pulseWidth(100)); //FDER
  pwm.setPWM(9, 0, pulseWidth(180)); //AIZQ
  pwm.setPWM(13, 0, pulseWidth(90)); //ADER
  ////////////DOWN
  
  pwm.setPWM(0, 0, pulseWidth(50)); //FIZQ
  pwm.setPWM(4, 0, pulseWidth(210)); //FDER
  pwm.setPWM(8, 0, pulseWidth(50)); //AIZQ
  pwm.setPWM(12, 0, pulseWidth(220)); //ADER
  
  
}

void zero_up(){
  pwm.setPWM(2, 0, pulseWidth(100)); //FIZQ 
  pwm.setPWM(6, 0, pulseWidth(180)); //FDER
  pwm.setPWM(10, 0, pulseWidth(170)); //AIZQ
  pwm.setPWM(14, 0, pulseWidth(100)); //ADER

  ///////////////MID
  pwm.setPWM(1, 0, pulseWidth(180)); //FIZQ 
  pwm.setPWM(5, 0, pulseWidth(100)); //FDER
  pwm.setPWM(9, 0, pulseWidth(180)); //AIZQ
  pwm.setPWM(13, 0, pulseWidth(90)); //ADER
  ////////////DOWN
  up(0,0,50); //FIZQ
  down(4,270,210); //FDER
  up(8,0,50); //AIZQ
  down(12,270,220); //ADER
}

void zero_down(){
  pwm.setPWM(2, 0, pulseWidth(100)); //FIZQ 
  pwm.setPWM(6, 0, pulseWidth(180)); //FDER
  pwm.setPWM(10, 0, pulseWidth(170)); //AIZQ
  pwm.setPWM(14, 0, pulseWidth(100)); //ADER

  ///////////////MID
  pwm.setPWM(1, 0, pulseWidth(180)); //FIZQ 
  pwm.setPWM(5, 0, pulseWidth(100)); //FDER
  pwm.setPWM(9, 0, pulseWidth(180)); //AIZQ
  pwm.setPWM(13, 0, pulseWidth(90)); //ADER
  ////////////DOWN
  down(8,50,0); //AIZQ
  up(12,220,270); //ADER
  down(0,50,0); //FIZQ
  up(4,210,270); //FDER
  
}

void zero(){
  pwm.setPWM(2, 0, pulseWidth(100)); //FIZQ 
  pwm.setPWM(6, 0, pulseWidth(180)); //FDER
  pwm.setPWM(10, 0, pulseWidth(170)); //AIZQ
  pwm.setPWM(14, 0, pulseWidth(100)); //ADER

  ///////////////MID
  pwm.setPWM(1, 0, pulseWidth(180)); //FIZQ 
  pwm.setPWM(5, 0, pulseWidth(100)); //FDER
  pwm.setPWM(9, 0, pulseWidth(180)); //AIZQ
  pwm.setPWM(13, 0, pulseWidth(90)); //ADER
  ////////////DOWN
  pwm.setPWM(0, 0, pulseWidth(0)); //FIZQ
  pwm.setPWM(4, 0, pulseWidth(270)); //FDER
  pwm.setPWM(8, 0, pulseWidth(0)); //AIZQ
  pwm.setPWM(12, 0, pulseWidth(270)); //ADER
}

void up(int canal, int angle_0, int angle_1){
  int aj;
  if (angle_0 < angle_1){
    for (int ang = angle_0; ang <= angle_1; ang++) {
    pwm.setPWM(canal, 0, pulseWidth(ang));
    delay(20);
    }
  }
}

void down(int canal, int angle_0, int angle_1){
  if (angle_0>angle_1){
    for (int ang = angle_0; ang >= angle_1; ang--) {
    pwm.setPWM(canal, 0, pulseWidth(ang));
    delay(10);
    }
  }
}