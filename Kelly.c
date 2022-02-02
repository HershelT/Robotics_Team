#include <kipr/wombat.h>

int main()
{
    int distance = 0;
    int leverT = 0;
    enable_servos();
    set_servo_position(1, 1000);
    set_servo_position(0, 1490);
    while (1 == 1) {
        ao();
        distance = 0;
        leverT = 0;
        camera_open();
        msleep(1500);
        enable_servos();
        set_servo_position(1, 1000);
   	    set_servo_position(0, 1490);
        get_object_count(0);
        get_object_center_x(0, 0);
        camera_update();
        while (get_object_count(0) < 1) {
            motor(0, 70);
            camera_update();
        }
        if (get_object_count(0) > 0) {
            ao();
            
            while (get_object_area(0, 0) > 0) {
                camera_update();
                printf("%d/n", get_object_center_x(0, 0));
                if (get_object_count(0) > 0) {
                    if (get_object_center_x(0, 0) > 85) {
                        motor(0, 40);

                    }
                    else if (get_object_center_x(0, 0) < 75) {
                        motor(2, 40);

                    }
                    else {
                        ao();
                        
                        enable_servos();
                        while (distance < 2400) {
                            distance = analog(1);
                            mav(0, 1480);
                            mav(2, 1490);    
                        }  
                        ao();
                        enable_servos();
                        set_servo_position(1, 700);
                        set_servo_position(0,1470);
                        msleep(500);
                        mav(0, 1480);
                        mav(2, 1490);
                        msleep(300);
                        set_servo_position(1, 1980);
                        msleep(1200);
                        set_servo_position(1, 1980);
                        msleep(500);
                        set_servo_position(0, 365);
                        msleep(500);
                        ao();
                        motor(0, 100);
                        msleep(3300);
                        while (leverT == 0) {
                            leverT = digital(2);
                            mav(0, 1400);
                            mav(2, 1410);
                        }
                        ao();
                        enable_servos();
                        enable_servos();
                        msleep(500);
                        mav(0, -1400);
                        mav(2, -1410);
                        msleep(350);
                        set_servo_position(0, 590);
                        msleep(500);
                        set_servo_position(1, 1115);
                        distance = 0;
                        leverT = 0;
                        ao();
                        msleep(1500);
                        break;
                    }
                    printf("%d/n", get_object_center_x(0, 0));
                }
            }

        }
    }    
    camera_close();
    return 0;    
}



