#include <kipr/wombat.h>
#include "claw.h"
#include "movement.h"
#include "start.h"
#include "final run.h" 
#include "blackline.h"

void BlackLineB()
{
    create_drive_direct(80, 100);  

    //if either sensors see black then the robot goes forward
    int lcliffAmt = get_create_lcliff_amt();
    int rcliffAmt = get_create_rcliff_amt();

    while (lcliffAmt < 1500 && rcliffAmt < 1500) {
        msleep(10);
        lcliffAmt = get_create_lcliff_amt();
        rcliffAmt = get_create_rcliff_amt();
    }
    create_stop();
    msleep(1000);
    create_drive_direct(100, 100);
   while (lcliffAmt > 1500 && rcliffAmt > 1500) {
        msleep(10);
        lcliffAmt = get_create_lcliff_amt();
        rcliffAmt = get_create_rcliff_amt();
    }
    printf ("ABC left: %d, right %d\n", lcliffAmt, rcliffAmt);
    create_stop();
    msleep(2000);
}

void FollowBlack1()
{
    int lfcliffAmt = get_create_lfcliff_amt();
    int rfcliffAmt = get_create_rfcliff_amt();
    int lcliffAmt = get_create_lcliff_amt();
    int rcliffAmt = get_create_rcliff_amt();

    create_drive_direct(200, 200);
    while ((lfcliffAmt < 1500 || lcliffAmt < 1500) && (rcliffAmt < 1500 || rfcliffAmt < 1500)) 
    {
        msleep(10);
        lfcliffAmt = get_create_lfcliff_amt();
        rfcliffAmt = get_create_rfcliff_amt();
        lcliffAmt = get_create_lcliff_amt();
        rcliffAmt = get_create_rcliff_amt();
        printf ("leftF: %d, rightF: %d left: %d, right: %d\n", lfcliffAmt, rfcliffAmt, lcliffAmt, rcliffAmt);
    }
}
void turnblack()
{ 
    int lfcliffAmt = get_create_lfcliff_amt();
    int rfcliffAmt = get_create_rfcliff_amt();
    int lcliffAmt = get_create_lcliff_amt();
    int rcliffAmt = get_create_rcliff_amt();

    create_drive_direct(0, 100);
    while ((lfcliffAmt > 1500 || lcliffAmt > 1500) && (rcliffAmt > 1500 || rfcliffAmt > 1500)) 
    {
        msleep(10);
        lfcliffAmt = get_create_lfcliff_amt();
        rfcliffAmt = get_create_rfcliff_amt();
        lcliffAmt = get_create_lcliff_amt();
        rcliffAmt = get_create_rcliff_amt();
        printf ("leftF: %d, rightF: %d left: %d, right: %d\n", lfcliffAmt, rfcliffAmt, lcliffAmt, rcliffAmt);
    }
    create_stop();

}