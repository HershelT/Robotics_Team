#include <kipr/wombat.h>

int main()
{
    int forward(int rmotor, int lmotor, int time){
		mav(0, lmotor);
    	mav(2, rmotor);	
        msleep(time);
    	return 0;
	}
    forward(1500,1500, 7000);
    return 0;
}
