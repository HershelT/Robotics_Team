#include <kipr/wombat.h>
void camUp(int amount) {
    int i;
	for (i = 1; i < amount; i++) {
    	camera_update();
    }
}
void cam(int num) {
    int x = 0;
    int n = 100;
    camUp(num);
    set_servo_position(0, x);
	while (get_object_count(0) < 1) 
    {
        if (x > 1950) {
        	n = -100;
        }
        if (x < 100) {
            n = 100;
        }    
        set_servo_position(0, x);
        x = x + n;
        msleep(100);
        camUp(num);
	}
}
void servoMove(char direction){
    if(direction == 'C') {
        int i = 950;
        for(i = 950; i<= 2000; i++){
            set_servo_position(0, i);
            msleep(1);
        }
    }
    if(direction == 'O'){
        int i = 850;
        for(i= 850; i>5; i--)
        {
            set_servo_position(0, i);
            msleep(1);
        }
    }   
}
void sweep() {
	camUp(3);
  	if (get_object_center_x(0,0) < 75)
    {
        motor_power(0, -15);
    }
    //servoMove('O');
    else if (get_object_center_x(0,0) > 85) 
    {
        motor_power(0, 15);
    }
    //servoMove('C');
    } else
    {
        printf("in the middle\n");
        ao();
        msleep(1500);
    }
    
} 
int main()
{    
    set_servo_position(0, 1024);
    camera_open();
    enable_servos();
   	cam(3);
	if (get_object_count(0) > 0)
    {
        while (get_object_count(0))
        }       
            sweep();
        }
    } else
    {
        cam(3)
    }
    sweep();
    
    
    
    return 0;
}

