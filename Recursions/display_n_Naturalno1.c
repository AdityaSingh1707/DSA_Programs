// Display n number of natural number in Reverse Order. (Using Recursion)

#include<stdio.h>
void func(int n)
{
    if(n==0)
        return;
    else
    {
        func(n-1);
        printf("%d ", n);
    }
}
int main()
{
    int n;
    printf("Enter the value of n:\n");
    scanf("%d", &n);
    func(n);
    return 0;
}
