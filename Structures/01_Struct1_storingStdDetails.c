// 1. Program to Store Information of a Student Using Structure.
#include <stdio.h>
typedef struct StudentInfo
{
    char Name[50];
    char Stream[30];
    unsigned long int Roll_no;
} sInfo;
int main()
{
    char dump, d;
    int N, i;
    printf("Enter the number of students whose details are to be stored : \n");
    scanf("%d", &N);
    sInfo Details[N];
    for (i = 0; i < N; i++)
    {
        printf("Enter the roll number of student %d: \n", i + 1);
        scanf("%lu%c", &Details[i].Roll_no, &dump);
        printf("Enter the Name of student %d: \n", i + 1);
        fgets(Details[i].Name, 50, stdin);
        printf("Enter the Stream of student %d: \n", i + 1);
        fgets(Details[i].Stream, 30, stdin);
    }
    for (i = 0; i < N; i++)
    {
        printf("\nEnter the name of student %d: \n", i + 1);
        fprintf(stdout, "%s\n", Details[i].Name);
        printf("Enter the stream of student %d: \n", i + 1);
        fprintf(stdout, "%s\n", Details[i].Stream);
        printf("Enter the rollno of student %d: \n", i + 1);
        printf("%lu\n", Details[i].Roll_no);
    }
}
