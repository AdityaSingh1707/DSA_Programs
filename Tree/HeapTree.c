#include<stdio.h>
#include<stdlib.h>
#define ITEM int

typedef struct st
{
    ITEM *arr;
    int tos, size;
}Stack;

typedef struct pq
{
    ITEM *arr;
    int rear, size;
}PQ;

PQ* init_PQ(int size);
int isEmpty_PQ(PQ *pth);
int isFull_PQ(PQ *pth);
void enqueue(PQ *pth, ITEM value);
ITEM dequeue(PQ *ptr);
void heapify(int arr[], int size);
void heapsort(int arr[], int size);
void preorder(PQ *pth, int rp);
void inorder(PQ *pth, int rp);
void postorder(PQ *pth, int rp);
void swap(int *a, int *b);
void levelorder(PQ *pth);

int main()
{
    PQ *heap;
    heap = init_PQ(9);
    enqueue(heap, 22);
    enqueue(heap, 75);
    enqueue(heap, 96);
    enqueue(heap, 41);
    enqueue(heap, 23);
    enqueue(heap, 12);
    enqueue(heap, 1);
    enqueue(heap, 2);
    enqueue(heap, 56);
    // printf("\n");
    // preorder(heap, 0);
    // printf("\n");
    // inorder(heap, 0);
    // printf("\n");
    // postorder(heap, 0);
    // printf("\n");
    // levelorder(heap);
    // printf("\n");
    int arr[9];
    for(int i = 0; i<9; i++)
    {
        scanf("%d", &arr[i]);
    }
    // for(i = 0; i < heap->size; i++)
    // {
    //     printf("%d ", dequeue(heap));
    // }
    // printf("\n");
    // heapify(heap->arr, heap->size);
    heapsort(arr, 9);
    for(int i=0; i<9; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // preorder(heap, 0);
    // printf("\n");
    // inorder(heap, 0);
    // printf("\n");
    // postorder(heap, 0);
    // printf("\n");
    // levelorder(heap);
    // printf("\n");
    return 0;
}

PQ *init_PQ(int size)
{
    PQ *pth = (PQ *)malloc(sizeof(PQ));
    pth->arr = (ITEM *)malloc(size * sizeof(ITEM));
    pth->size = size;
    pth->rear = -1;
    return pth;
}
int isEmpty_PQ(PQ *pth)
{
    if(pth->rear == -1)
        return 1;
    return 0;
}
int isFull_PQ(PQ *pth)
{
    if(pth->rear == pth->size-1)
        return 1;
    return 0;
}
void enqueue(PQ *pth, ITEM value)
{
    int child, parent;
    if(isFull_PQ(pth) == 1)
        return;
    else
    {
        pth->arr[++pth->rear] = value;
        child = pth->rear;

        while(child != 0)
        {
            parent = (child-1)/2;
            if(pth->arr[parent] < pth->arr[child])
            {
                swap(&(pth->arr[parent]), &(pth->arr[child]));
                child = parent;
            }
            else
                break;
        }
    }
}
ITEM dequeue(PQ *ptr)
{
    int temp = 0, parent, child;
    if(isEmpty_PQ(ptr) == 1)
        return 0;
    else
    {
        temp = ptr->arr[0];
        ptr->arr[0] = ptr->arr[ptr->rear--]; 
        parent = 0;

        do
        {
            child = 2*parent+1;
            if(child > ptr->rear)
                break;
            if(child < ptr->rear && ptr->arr[child] < ptr->arr[child+1])
                ++child;
            if(ptr->arr[parent] < ptr->arr[child])
            {
                swap(&ptr->arr[parent], &ptr->arr[child]);
                parent = child;    
            }
            else
                break;
        } while (child <= ptr->rear);
        return temp;
    }
}
void heapify(int arr[], int size)
{
    int i, parent, child;
    for(i = size-1; i >= 0; i--)
    {
        parent = i;
        do
        {
            child = 2*parent + 1;
            if(child > size-1)
                break;
            if(child < size-1 && arr[child] < arr[child+1])
                ++child;
            if(arr[parent] < arr[child])
            {
                swap(&arr[parent], &arr[child]);
                parent = child;
            }
            else
                break;
        }while(child <= size-1);
    }
}
void preorder(PQ *pth, int rp)
{
    if(pth->size < 0)
        return;
    if(rp <= pth->size-1)
    {
        printf("%d ", pth->arr[rp]);
        preorder(pth, 2*rp+1);
        preorder(pth, 2*rp+2);
    }
}
void inorder(PQ *pth, int rp)
{
    if(pth->size < 0)
        return;
    if(rp <= pth->size-1)
    {
        inorder(pth, 2*rp+1);
        printf("%d ", pth->arr[rp]);
        inorder(pth, 2*rp+2);
    }
}
void postorder(PQ *pth, int rp)
{
    if(pth->size < 0)
        return;
    if(rp <= pth->size-1)
    {
        postorder(pth, 2*rp+1);
        postorder(pth, 2*rp+2);
        printf("%d ", pth->arr[rp]);
    }
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void levelorder(PQ *pth)
{
    int i = 0;
    for(i = 0; i < pth->size; ++i)
    {
        printf("%d ", pth->arr[i]);
    }
}
