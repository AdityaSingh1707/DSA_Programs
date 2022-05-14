// To sort positive and negative integers of the array using Counting Sort... 

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int *csort(int *arr, int size);
int main()
{
    int *ans, size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int arr[size], i, j=0;
    ans = (int *)malloc(size * sizeof(int));
    printf("Enter the elements of array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Display the elements of array: ");
    for(i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    ans = csort(arr, size);
    printf("\nDisplay the elements of array: ");
    for(i=0; i<size; i++)
    {
        printf("%d ", ans[i]);
    }
}
int *csort(int *arr, int size)
{
    int *res = (int *)malloc(size * sizeof(int));
    int len, i, j=0, max = INT_MIN, min = INT_MAX;
    for(i=0; i<size; i++)
    {
        if(max<arr[i])
            max = arr[i];
        if(min>arr[i])
            min = arr[i];
    }
    if(min<0)
        len = max-min+1;
    else
        len = max+1;
    int index[len];
    for(i=0; i<len; i++)
    {
        index[i] = 0;
    }
    for(i=0; i<size; i++)
    {
        if(arr[i]==min)
            arr[i] = 0;
        else if(arr[i]>min)
            arr[i] = arr[i] - min;
    }
    for(i=0; i<size; i++)
    {
        index[arr[i]]++;
    }
    for (i = 0; i < len; i++)
    {
        while (index[i] != 0)
        {
            res[j++] = i+min;
            index[i]--;
        }
    }
    return res;
}
