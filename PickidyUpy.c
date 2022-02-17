#include <stdio.h>
#include <kipr/wombat.h>
void distance(int dis) {
  while (analog(0) < dis) {
    motor(0, 50);
    motor(3, 50);
  }  
  ao();
}  
void moveStraight(int a, int b, int time) {
  motor(0, a);
  motor(3, b);
  msleep(time);
  ao();
}  
void pickUp() {
  enable_servos();
  set_servo_position(3, 900);
  moveStraight(25, 25, 2435);
  set_servo_position(3, 1900);
  msleep(1000);
  set_servo_position(0, 1024);
}  
int main()
{
    enable_servos();
    set_servo_position(3, 2000);
    msleep(200);
    set_servo_position(0, 1950);
    msleep(1000);
    disable_servos();
    msleep(1000);
    distance(3590);
    msleep(200);
    pickUp();
    msleep(200);
    return 0;
}
 
