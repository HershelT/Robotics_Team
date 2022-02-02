#include <kipr/wombat.h>

int main()
{
    
    enable_servos();
    set_servo_position(1, 1000);
    set_servo_position(0, 1290);
    msleep(300);
    camera_open();
    int ballPos = get_object_center_x(0, 0);
    while (ballPos > -1) {
        camera_open();
        get_object_count(0);
        ballPos = get_object_center_x(0, 0);
        camera_update();
        set_servo_position(1, 1600);
        set_servo_position(0, 235);
        ballPos = get_object_center_x(0, 0);
    }

    ao();
    mav(0, 1410);
    mav(2, 1450);


	return 0;
}
