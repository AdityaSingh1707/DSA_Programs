// Queue Implementation using Array...

#include <stdio.h>
#include <stdlib.h>
typedef struct st
{
    int rear, front, *arr, size;
} Queue;
void init(Queue *ptq, int size);
int isEmpty(Queue *ptq);
int isFull(Queue *ptq);
int enqueue(Queue *ptq, int data);
int dequeue(Queue *ptq, int *data);
int main()
{
    Queue Q;
    int data, size;
    char ch, dump;
    do
    {
        printf("\nPress A : To initialize a Queue.\n");
        printf("Press B : To check whether the Queue is Empty or Not?\n");
        printf("Press C : To check whether the Queue is Full or Not?\n");
        printf("Press D : To enqueue an element into the Queue.\n");
        printf("Press E : To dequeue an element from the Queue.\n");
        printf("Press X : To close the Program.\n");
        printf("Enter Your Choice : \n");
        scanf("%c%c", &ch, &dump);
        switch (ch)
        {
        case 'A':
            printf("Enter the size of the Queue :\n");
            scanf("%d%c", &size, &dump);
            init(&Q, size);
            printf("Successfully Initialized.\n");
            break;
        case 'B':
            if (isEmpty(&Q) == 1)
                printf("Queue is Empty.\n");
            else
                printf("Queue is not Empty.\n");
            break;
        case 'C':
            if (isFull(&Q) == 1)
                printf("Queue is Full.\n");
            else
                printf("Queue is not Full.\n");
            break;
        case 'D':
            printf("Enter the element to be enqueued into the Queue :\n");
            scanf("%d%c", &data, &dump);
            if (enqueue(&Q, data) == 1)
                printf("Successfully Enqueued.\n");
            else
                printf("Queue is Full.\n");
            break;
        case 'E':
            if (dequeue(&Q, &data) == 1)
            {
                printf("The element dequeued from the Queue is : %d\n", data);
                printf("Successfull Dequeued.\n");
            }
            else
                printf("Queue is Empty.\n");
            break;
        case 'X':
            printf("Program Closed.\n");
            break;
        default:
            printf("Invalid Choice! Please Try Again...\n");
            break;
        }
    } while (ch != 'X');

    return 0;
}
void init(Queue *ptq, int size)
{
    ptq->arr = (int *)malloc(sizeof(int));
    ptq->size = size;
    ptq->front = ptq->rear = -1;
}
int isEmpty(Queue *ptq)
{
    if (ptq->front == -1 && ptq->rear == -1)
        return 1;
    return 0;
}
int isFull(Queue *ptq)
{
    if ((ptq->front == 0 && ptq->rear == (ptq->size - 1)) || (ptq->front == ptq->rear + 1))
        return 1;
    return 0;
}
int dequeue(Queue *ptq, int *data)
{
    int tmp;
    if (isEmpty(ptq) == 1)
        return 0;
    else
    {
        *data = ptq->arr[ptq->front];
        if (ptq->front == ptq->rear)
            ptq->front = ptq->rear = -1;
        else if (ptq->front == ptq->size - 1)
            ptq->front = 0;
        else
            ptq->front++;
        return 1;
    }
}
int enqueue(Queue *ptq, int data)
{
    if (isFull(ptq) == 1)
        return 0;
    else
    {
        if (ptq->front == -1)
            ptq->front = 0;
        if (ptq->rear == ptq->size - 1)
            ptq->rear = 0;
        else
        {
            ++ptq->rear;
            ptq->arr[ptq->rear] = data;
            return 1;
        }
    }
}
