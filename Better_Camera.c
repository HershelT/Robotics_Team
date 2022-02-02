#include <kipr/wombat.h>

int main()
{
    camera_open();
    
    camera_update();
    if (get_object_count(0) > 0) {
        while (get_object_area(0, 0) > 0) {
            camera_update();
            if (get_object_count(0) > 0) {
            	if (get_object_center_x(0, 0) > 85) {
                    motor(0, 40);
                }
                else if (get_object_center_x(0, 0) < 75) {
                    motor(2, 40);
                }
                else {
                    ao();
                    mav(0, 1450);
                    mav(2, 1470);
                    msleep(3000);
                }
            }
            printf("%d\n", get_object_center_x(0, 0));
            printf("%d\n", get_object_area(0, 0));
        


        }    
    }
    camera_close();

    return 0;
}
