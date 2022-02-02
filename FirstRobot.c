#include <kipr/wombat.h>

int main()
{
    printf("Hello Kelly\n");
    enable_servos(0);
    enable_servos(1);
    set_servo_position(0, 600);
    msleep(1000);
    set_servo_position(1, 2047);
    msleep(2000);
    motor(0,92);
    motor(2, 99);
    msleep(4000);
    ao();
	set_servo_position(0, 1400);
    msleep(5000);
	set_servo_position(1, 1200);
	msleep(2000);
    motor(0,92);
    motor(2, 100);
    msleep(1000);
    set_servo_position(1, 1800);
    msleep(5000);
    set_servo_position(0, 500);
    msleep(2000);
    disable_servos();
    ao();
    motor(0, 100);
    msleep(3200);
    ao();
    motor(0, 92);
    motor(2, 100);
    msleep(9000);
    motor(0, 92);
    motor(2,92);
    ao();
    motor(0,100);
    msleep(3200);
    return 0;
}
