int touchSensorL;
int touchSensorR;
#include <kipr/wombat.h>

int main()
{
    	
   wait_for_light(1);
   shut_down_in(120);
    touchSensorL = digital(1);
    touchSensorR = digital(0); 
    while(touchSensorL == 0 || touchSensorR == 0)
    {
        touchSensorL = digital(1);
        touchSensorR = digital(0);
        mav(0, -1400);
        mav(2, -1410); 
    }
    ao();


    motor(0,0);
    motor(2, 0);
    msleep(1000);
    mav(0, 1400);
    mav(2, 1410); 
    msleep(2000);
    motor(0, 50);
    motor(2, 100); 
    motor(0, -50);
    motor(2, -100);
    motor(0, 80);
    motor(2, 100); 
    motor(0, -80);
    motor(2, -100);
    mav(0, 1400);
    mav(2, 1410); 
    msleep(1000);
    mav(0, -1400);
    mav(2, -1410); 
	msleep(6000);
    	
    ao();

    return(0);
}
