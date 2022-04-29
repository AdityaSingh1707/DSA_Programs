// 4. Program to Calculate Difference Between Two Time Periods
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int hours;
    int seconds;
    int minutes;
} Time;
Time *time_difference(Time t1, Time t2);
int main()
{
    Time t1, t2, *diff;
    printf("Enter the start time. \n");
    printf("Enter hours, minutes and seconds: ");
    scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);
    printf("Enter the stop time. \n");
    printf("Enter hours, minutes and seconds: ");
    scanf("%d %d %d", &t2.hours, &t2.minutes, &t2.seconds);
    diff = time_difference(t1, t2);
    printf("Difference Between two time periods will be = %d hours %d minutes %d seconds, %d:%d:%d.\n", diff->hours, diff->minutes, diff->seconds, diff->hours, diff->minutes, diff->seconds);
    return 0;
}
Time *time_difference(Time t1, Time t2)
{
    Time *temp;
    while (t2.seconds > t1.seconds)
    {
        --t1.minutes;
        t1.seconds += 60;
    }
    temp->seconds = t1.seconds - t2.seconds;
    while (t2.minutes > t1.minutes)
    {
        --t1.hours;
        t1.minutes += 60;
    }
    temp->minutes = t1.minutes - t2.minutes;
    temp->hours = t1.hours - t2.hours;
    return temp;
}
