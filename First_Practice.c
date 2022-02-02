#include <kipr/wombat.h>

int main()
{
    int forward(int rmotor, int lmotor){
      mav(0, lmotor);
      mav(2, lmotor);
      return 0;
    }
        
    enable_servos();
    set_servo_position(0,1500);
    disable_servos();
    ao();
    mav(0,1500);
    mav(2,1500);
    msleep(5000);
    ao();
    mav(0,1500);
    msleep(1675);
    ao();
    mav(0,1500);
    mav(2,1500);
    msleep(5000);
    ao();
    return 0;
}
