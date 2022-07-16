#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    int *arr, rear, size;
} MinHeap;

MinHeap *init(int size);
int isEmpty_MinHeap(MinHeap *ptr);
int isFull_MinHeap(MinHeap *ptr);
void enqueue(MinHeap *ptr, int value);
int dequeue(MinHeap *ptr);
void preorder(MinHeap *pth, int rp);
void inorder(MinHeap *pth, int rp);
void postorder(MinHeap *pth, int rp);
void swap(int *a, int *b);
void levelorder(MinHeap *pth);
void heapify(MinHeap *pth);

int main()
{
    MinHeap *minH = init(7);

    enqueue(minH, 63);
    enqueue(minH, 17);
    enqueue(minH, 86);
    enqueue(minH, 95);
    enqueue(minH, 42);
    enqueue(minH, 31);
    enqueue(minH, 20);

    printf("\n");
    preorder(minH, 0);
    printf("\n");
    inorder(minH, 0);
    printf("\n");
    postorder(minH, 0);
    printf("\n");
    levelorder(minH);
    printf("\n");
    // printf("Deleting items :--\n");
    // for(int i=0; i<minH->size; i++)
    // {
    //     printf("%d ", dequeue(minH));
    // }
    // printf("\n");
    heapify(minH);
    printf("MinHeap to MaxHeap (Using Heapify!):\n");
    preorder(minH, 0);
    printf("\n");
    inorder(minH, 0);
    printf("\n");
    postorder(minH, 0);
    printf("\n");
    levelorder(minH);
    printf("\n");
    return 0;
}

MinHeap *init(int size)
{
    MinHeap *tmp = (MinHeap *)malloc(sizeof(MinHeap));
    tmp->arr = (int *)malloc(size * sizeof(MinHeap));
    tmp->rear = -1;
    tmp->size = size;
    return tmp;
}
int isFull_MinHeap(MinHeap *ptr)
{
    return (ptr->rear == ptr->size - 1);
}
int isEmpty_MinHeap(MinHeap *ptr)
{
    return (ptr->rear == -1);
}
void enqueue(MinHeap *ptr, int value)
{
    int child, parent;
    if (isFull_MinHeap(ptr) == 1)
        return;
    else
    {
        ptr->arr[++ptr->rear] = value;
        child = ptr->rear;
        while (child != 0)
        {
            parent = (child - 1) / 2;
            if (ptr->arr[parent] > ptr->arr[child])
            {
                swap(&ptr->arr[parent], &ptr->arr[child]);
                child = parent;
            }
            else
                break;
        }
    }
}
int dequeue(MinHeap *ptr)
{
    int tmp, child, parent;
    if (isEmpty_MinHeap(ptr) == 1)
        return 0;
    else
    {
        tmp = ptr->arr[0];
        ptr->arr[0] = ptr->arr[ptr->rear--];
        parent = 0;
        do
        {
            child = 2 * parent + 1;
            if (child > ptr->rear)
                break;
            if (child < ptr->rear && ptr->arr[child] > ptr->arr[child + 1])
                ++child;
            if (ptr->arr[parent] > ptr->arr[child])
            {
                swap(&ptr->arr[parent], &ptr->arr[child]);
                parent = child;
            }
            else
                break;
        } while (child < ptr->rear);
        return tmp;
    }
}
void preorder(MinHeap *pth, int rp)
{
    if (pth->size < 0)
        return;
    if (rp <= pth->size - 1)
    {
        printf("%d ", pth->arr[rp]);
        preorder(pth, 2 * rp + 1);
        preorder(pth, 2 * rp + 2);
    }
}
void inorder(MinHeap *pth, int rp)
{
    if (pth->size < 0)
        return;
    if (rp <= pth->size - 1)
    {
        inorder(pth, 2 * rp + 1);
        printf("%d ", pth->arr[rp]);
        inorder(pth, 2 * rp + 2);
    }
}
void postorder(MinHeap *pth, int rp)
{
    if (pth->size < 0)
        return;
    if (rp <= pth->size - 1)
    {
        postorder(pth, 2 * rp + 1);
        postorder(pth, 2 * rp + 2);
        printf("%d ", pth->arr[rp]);
    }
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void levelorder(MinHeap *pth)
{
    int i = 0;
    for (i = 0; i < pth->size; ++i)
    {
        printf("%d ", pth->arr[i]);
    }
}
void heapify(MinHeap *pth)
{
    int i, child, parent;
    for (i = pth->size - 1; i >= 0; --i)
    {
        parent = i;
        do
        {
            child = 2 * parent + 1;
            if (child > pth->size - 1)
                break;
            if (child <= pth->size - 1 && pth->arr[child] < pth->arr[child + 1])
                ++child;
            if (pth->arr[parent] < pth->arr[child])
            {
                swap(&pth->arr[parent], &pth->arr[child]);
                parent = child;
            }
            else
                break;
        } while (child <= pth->size - 1);
    }
}
