// 2. Program to Add Two Distances (in inch-feet system) using Structures.
#include <stdio.h>
typedef struct
{
    int feet;
    float inch;

} Dist;
int main()
{
    Dist d1, d2, result;
    printf("Enter Distance1 (in feet-inch system): \n");
    printf("Enter feet (dist1): ");
    scanf("%d", &d1.feet);
    printf("Enter inches (dist1): ");
    scanf("%f", &d1.inch);
    printf("Enter Distance2 (in feet-inch system): \n");
    printf("Enter feet (dist2): ");
    scanf("%d", &d2.feet);
    printf("Enter inches  (dist2): ");
    scanf("%f", &d2.inch);
    result.feet = d1.feet + d2.feet;
    result.inch = d1.inch + d2.inch;
    while (result.inch >= 12.0)
    {
        result.inch = result.inch - 12.0;
        ++result.feet;
    }
    printf("\nSum of Distances %d\'%.1f\" + %d\'%.1f\" = %d\'%.1f\"", d1.feet, d1.inch, d2.feet, d2.inch, result.feet, result.inch);
    return 0;
}
