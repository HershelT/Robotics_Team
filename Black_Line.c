#include <kipr/wombat.h>
void straight(int num, int wait) {
	motor(0, num);
    motor(2, num);
    msleep(wait);
}

int main()
{
    int bob = analog(1);
    while (bob < 3000) {
        bob = analog(1);
        motor(0, -50);
        motor(2, -50);
    }
	msleep(100);
    ao();
    bob = analog(1);
    motor(0, -75);
    msleep(2000);
    straight(60, 19000);
    




return 0;
}
