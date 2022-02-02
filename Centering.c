#include <kipr/wombat.h>

int main()
{
    camera_open();
    camera_update();
    while (get_object_count(0) < 1){
        mav(2,700);
        mav(0, -700);
        camera_update();
    }
    ao();
    camera_update();
    printf("inital object center: %d/n", get_object_center_x(0, 0));
    while (get_object_count(0) > 0) {
        if (get_object_center_x(0, 0) > 85) {
            motor(0, 40);
            camera_update();

        }

        else if (get_object_center_x(0, 0) < 75) {
            motor(2, 40);
            camera_update();

        }
        else {
            ao();
            motor(0,50);
        }
    }
    ao();

    camera_update();
    printf("final object center: %d/n", get_object_center_x(0,0));
    return 0;
}
