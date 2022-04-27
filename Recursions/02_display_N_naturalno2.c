// Display n number of natural numbers in descending order. (Using Recursion)
#include<stdio.h>
void func(int n)
{
    if(n==0)
        return;
    else
    {
        printf("%d ", n);
        func(n-1);
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
