#include <kipr/wombat.h>
int distance;
int isRunning;

int main()
{
    enable_servos();
    isRunning = 1;
    distance = analog(0);
    servoMove('O');


    while (isRunning == 1) {

        while (analog(1) < 4000) {
            driveForward(500, 1);
        }
        driveForward(500, 1500);
        while (analog(1) < 4000) {
            drive(-1000, 1000, 1);
        }
        ao();
    }
    isRunning = 0;
    ao();

    msleep(2000);
    isRunning = 0;
}
disable_servos();

ao();

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

void drive(int left, int right, int delay) {

    mav(2, (-1 * left));
    mav(0, (-1 * right));
    msleep(delay);

}

void driveForward(int speed, int time) {
    drive(speed, speed, time);
}

void turn(char direction) {
    if (direction == 'L') {
        drive(-1000, 1000, 850);  
    }
}

void getOnLine(int darkness) {
    while (darkness < 4000) {
        drive(-1000, 1000, 1);
    }
}


