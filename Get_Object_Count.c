#include <kipr/wombat.h>

int main()
{
    camera_open();
    camera_update();
    if (get_object_count(0) > 0) {
        if (get_object_area(0,0) > 40) {
            printf("%d\n", get_object_center_x(0,0));

        }
    }
    camera_close();
    return 0;
}
