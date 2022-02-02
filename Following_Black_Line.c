#include <kipr/wombat.h>

int main()
{
    enable_servos();
    set_servo_position(1, 1000);
    set_servo_position(0, 1490);
    ao();
    while(1==1){
        while(analog(1) < 2800){
            if(analog(2) < 3000){
                mav(2,500);
                ao();
            }
            if(analog(2) > 3000){
                mav(2,1500);
                mav(0,1500);
                ao();
            }
        }
    }
    return 0;
}
