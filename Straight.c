#include <kipr/wombat.h>

int main()
{
    enable_servos();
    set_servo_position(0, 900);
    msleep(1000);
    enable_servos();
    set_servo_position(0, 1);
    msleep(500);
    motor(0, -75);
    motor(2, -75);
    msleep(5250);
    ao();
    motor(0, -95);
    motor(2, 60);
    msleep(3000);
    
    motor(0, -95);
    motor(2, -95);
    msleep(5000);
    
    return 0;
}
