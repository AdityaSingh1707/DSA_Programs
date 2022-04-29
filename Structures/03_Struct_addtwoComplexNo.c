// 3. Program to Add Two Complex Numbers by Passing Structure to a Function.
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    float real;
    float imaginary;
} Complex;
Complex add(Complex c1, Complex c2);
int main()
{
    Complex c1, c2, res;
    printf("Enter Complex_No1: \n");
    printf("Enter real part of Complex_No1: ");
    scanf("%f", &c1.real);
    printf("Enter imaginary part of Complex_No1: ");
    scanf("%f", &c1.imaginary);
    printf("Enter Complex_No2: \n");
    printf("Enter real part of Complex_No2: ");
    scanf("%f", &c2.real);
    printf("Enter imaginary part of Complex_No2: ");
    scanf("%f", &c2.imaginary);
    res = add(c1, c2);
    printf("\nSum of two complex numbers %.1f + i(%.1f) + %.1f + i(%.1f) = %.1f + i(%.1f)\n", c1.real, c1.imaginary, c2.real, c2.imaginary, res.real, res.imaginary);
    return 0;
}
Complex add(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imaginary = c1.imaginary + c2.imaginary;
    return temp;
}
