// To sort an array of positive integers using Counting Sort.... 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int *countSort(int *arr, int size);

int main()
{
    int size, *ans;
    printf("Enter the size of the array:\n");
    scanf("%d", &size);
    int arr[size], i;
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Display the elements of the array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    ans = countSort(arr, size);
    printf("\nSorted array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
int *countSort(int *arr, int size)
{
    int *res = (int *)malloc(size * sizeof(int));
    int i = 0, j = 0;
    int max = INT_MIN;
    for (i = 0; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    int index[max + 1];
    for (i = 0; i < max + 1; i++)
    {
        index[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        index[arr[i]]++;
    }
    for (i = 0; i < max + 1; i++)
    {
        while (index[i] != 0)
        {
            res[j++] = i;
            index[i]--;
        }
    }
    return res;
}
