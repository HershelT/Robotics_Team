#include <kipr/wombat.h>

int main()
{
    camera_open();
    enable_servos();
    int slide = 1;
    set_servo_position(1, 1000);
    set_servo_position(0, 1490);
    camera_update();
    while(get_object_count(0) < 1 ){
        mav(2,700);
        mav(0,-700);
        camera_update();
    }
    ao();
    msleep(700);
    camera_update();
    while(slide > 0){
        slide = get_object_count(0);
        camera_update();
        if (get_object_center_x(0,0) > 85){
            motor (0,70);
            camera_update();
        }
        else if(get_object_center_x(0,0) < 75){
            motor (2,70);
            camera_update();
        }
        else {
            ao();
        }
    }
    return 0;
}
