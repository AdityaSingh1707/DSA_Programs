// 6. Program to Store Data in Structures Dynamically
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int marks;
    char grades[2];
} Info;
int main()
{
    Info *Details, temp;
    int size, i;
    printf("Enter the no of Students: ");
    scanf("%d", &size);
    char dump;
    Details = (Info *)malloc(sizeof(Info));
    for (i = 0; i < size; i++)
    {
        printf("Details of Student %d\n", i + 1);
        printf("Enter the marks of student %d: \n", i + 1);
        scanf("%d%c", &temp.marks, &dump);
        printf("Enter the grades of student %d: \n", i + 1);
        fgets(temp.grades, 5, stdin);
        Details[i] = temp;
    }
    for (i = 0; i < size; i++)
    {
        printf("Details of Student %d\n", i + 1);
        printf("The Marks of student %d: \n", i + 1);
        printf("%d\n", Details[i].marks);
        printf("The Grades of student %d: \n", i + 1);
        printf("%s\n", Details[i].grades);
    }
    return 0;
}
