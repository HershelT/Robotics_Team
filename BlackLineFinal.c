#include <kipr/wombat.h>
#include </home/root/Documents/KISS/Default User/Final_project/include/functions.h>
int main()
{
    analog(0);
    turn('L');
    while (analog(0) > 4000) {
        motor(0, 60);
        msleep(200);
        motor(2, 60);
        msleep(200);
        ao();
    }
    return 0;
}
