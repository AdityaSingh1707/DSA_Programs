// Stack Implementation by Array....

#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    int *arr, tos, size;
} Stack;

void init(Stack *pts, int size);
int isEmpty(const Stack *pts);
int isFull(const Stack *pts);
int push(Stack *pts, int data);
int pop(Stack *pts, int *data);
int peek(const Stack *pts);

int main()
{
    int size, data;
    char ch, dump;
    Stack S;
    do
    {
        printf("\nPress A : To Initialize the Stack.\n");
        printf("Press B : To Push an element into the Stack.\n");
        printf("Press C : To Pop out topmost element from the Stack.\n");
        printf("Press D : To check whether the Stack is Empty or Not?\n");
        printf("Press E : To check whether the Stack is Full or Not?\n");
        printf("Press F : To display the topmost element of the Stack.\n");
        printf("Press X : Close the program.\n");
        printf("Enter your Choice :\n");
        scanf("%c%c", &ch, &dump);

        switch (ch)
        {
        case 'A':
            printf("Enter the Size of the Stack : \n");
            scanf("%d%c", &size, &dump);
            init(&S, size);
            printf("Succesfully Initailized.\n");
            break;
        case 'B':
            if (isFull(&S) == 1)
            {
                printf("Stack Overflow! Stack is Full.\n");
                break;
            }
            else
            {
                printf("Enter the element to be pushed into the Stack :\n");
                scanf("%d%c", &data, &dump);
                push(&S, data);
                printf("Successfully Pushed.\n");
                break;
            }
        case 'C':
            if (pop(&S, &data) == 1)
                printf("Successfully Poped.\nThe poped element from the Stack :%d\n", data);
            else
                printf("Stack UnderFlow! Stack is empty.\n");
            break;
        case 'D':
            if (isEmpty(&S) == 1)
                printf("Stack is Empty.\n");
            else
                printf("Stack is not Empty.\n");
            break;
        case 'E':
            if (isFull(&S) == 1)
                printf("Stack is Full.\n");
            else
                printf("Stack is not Full.\n");
            break;
        case 'F':
            if (isEmpty(&S) == 1)
                printf("Stack is Empty.\n");
            else
                printf("The topmost element of the Stack = %d\n", peek(&S));
            break;
        case 'X':
            printf("Program Closed.\n");
            break;
        default:
            printf("INVALID CHOICE...\nTry Again...\n");
            break;
        }
    } while (ch != 'X');

    return 0;
}

void init(Stack *pts, int size)
{
    pts->arr = (int *)malloc(size * sizeof(int));
    pts->size = size;
    pts->tos = -1;
}

int isEmpty(const Stack *pts)
{
    if (pts->tos == -1)
        return 1;
    return 0;
}

int isFull(const Stack *pts)
{
    if (pts->tos == pts->size - 1)
        return 1;
    return 0;
}

int push(Stack *pts, int data)
{
    if (isFull(pts) == 1)
        return 0;
    pts->tos++;
    pts->arr[pts->tos] = data;
    return 1;
}

int pop(Stack *pts, int *data)
{
    if (isEmpty(pts) == 1)
        return 0;
    *data = pts->arr[pts->tos];
    pts->tos--;
    return 1;
}
int peek(const Stack *pts)
{
    return pts->arr[pts->tos];
}
