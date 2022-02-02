#include <kipr/wombat.h>

int main()
{
	while (1 == 1) {
        
        enable_servos();
        set_servo_position(1, 1000);
        set_servo_position(0, 1490);
        camera_open();
        camera_update();
        while (analog(1) < 2400){
            while (get_object_count(0) < 1){
                mav(2,1000);
                camera_update();
            }
            ao();
            printf("object count %d/f", get_object_count(0));
            camera_update();
            if(get_object_area(0,0) < 1850){
                mav(2,1250);
                mav(0,1240);
                camera_update();
                if (get_object_center_x(0,0) > 85){
                    mav(0,200);
                    camera_update();
                    ao();
                }
                else if (get_object_center_x(0,0) < 75){
                    mav(2,200);
                    camera_update();
                }
            }
            ao();
            msleep(1000);
            printf("     first x reading: %d/n", get_object_center_x(0,0));
            if (get_object_center_x(0,0) > 85){
                mav(0,200);
                camera_update();
                ao();
            }

            else if (get_object_center_x(0,0) < 75){
                mav(2,200);
                camera_update();
            }
            ao();
            printf("     second x reading: %d/n", get_object_center_x(0,0));
            camera_update();
            while (analog(1) < 2400){
                mav(2,500);
                mav(0,500);
                camera_update();
            }
        }    
        ao();
        mav(2,100);
        mav(0,100);
        msleep(750);    
        ao();
        set_servo_position(1,1500);
        msleep(1500);
        set_servo_position(0,500);
        ao();
    }
    return 0;
}
