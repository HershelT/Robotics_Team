#include <kipr/wombat.h>
#include "/home/root/Documents/KISS/Benny Grey/functions/src/main.c"
int init_servo_position;

void servoMove(char direction){
    if(direction == 'O') {
        int i = init_servo_position;
        for(i = init_servo_position; i>=900; i--){
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
    ao();

}

void driveForward(int speed, int time) {
    drive(speed, speed, time);
    ao();
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

void gradualTurn(char direction, int speed_init, int time) {
    if (direction == 'L') {
        int i = time;
        int right = speed_init;
        for(i=time; i>0; i--){
            right += 10;
            drive(speed_init, right, 10);
        }
    }
    if (direction == 'R') {
        int i = time;
        int left = speed_init;
        for(i=time; i>0; i--){
            left += 10;
            drive(left, speed_init, 140);
        }
    }
}

int main()
{
    init_servo_position = 900;
    enable_servos();
    servoMove('O');
    ao();
    driveForward(1000, 1700);
    gradualTurn('L', 1000, 450);
    drive(-600, -600, 1000);
    drive(200,0,500);
    driveForward(1000, 2000);
    printf("Hello World\n");
    return 0;
}

