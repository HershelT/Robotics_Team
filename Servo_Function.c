#include <kipr/wombat.h>

int main()
{
    enable_servos();
    servoMove('O');
	ao();
    while (digital(0) == 0){
    	mav(0, -1000);
        mav(2, -1000);
        digital(0);
    }
    ao();
    servoMove('C');
    disable_servos();
    mav(0, 500);
    mav(2, -500);
    msleep(3000);
    ao();
    printf("Hello World\n");
    return 0;
} 

void servoMove(char direction){
 if(direction == 'O') {
     int i = 1974;
     for(i = 1974; i>=900; i--){
        set_servo_position(0, i);
        msleep(1);
     }
    }
	if(direction == 'C'){
        int i = 900;
        for(i= 900; i <= 1974; i++){
        set_servo_position(0, i);
        msleep(1);
     }
    } 
}
