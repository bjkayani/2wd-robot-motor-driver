#include "constants.h"

void setup() {
  pinMode(left_motor_a, OUTPUT);
  pinMode(left_motor_b, OUTPUT);
  pinMode(right_motor_a, OUTPUT);
  pinMode(right_motor_b, OUTPUT);
  delay(2000);

}

void loop() {
}

void motor_stop(){
  motor_speed(0, 'r');
  motor_speed(0, 'l');  
}

void motor_reverse(int vel){
  motor_speed(-vel, 'r');
  motor_speed(-vel, 'l');
}

void motor_forward(int vel){
  motor_speed(vel, 'r');
  motor_speed(vel, 'l');
}

void motor_speed(int vel, char motor){
  
  if(vel > 0 && motor == 'l'){
    int pwm = map(vel, 0, 100, 0, 255);
    analogWrite(left_motor_a, pwm);
    digitalWrite(left_motor_b, 0); 
  }
  else if(vel < 0 && motor == 'l'){
    vel = abs(vel);
    int pwm = map(vel, 0, 100, 0, 255);
    analogWrite(left_motor_b, pwm);
    digitalWrite(left_motor_a, 0); 
  }
  else if(vel == 0 && motor == 'l'){
    digitalWrite(left_motor_a, 0); 
    digitalWrite(left_motor_b, 0); 
  }
  
  if(vel > 0 && motor == 'r'){
    int pwm = map(vel, 0, 100, 0, 255);
    analogWrite(right_motor_a, pwm);
    digitalWrite(right_motor_b, 0); 
  }
  else if(vel < 0 && motor == 'r'){
    vel = abs(vel);
    int pwm = map(vel, 0, 100, 0, 255);
    analogWrite(right_motor_b, pwm);
    digitalWrite(right_motor_a, 0); 
  }
  else if(vel == 0 && motor == 'r'){
    digitalWrite(right_motor_a, 0); 
    digitalWrite(right_motor_b, 0); 
  }
}
