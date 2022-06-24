// Queue implementation using Linked List...

#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
    struct st *next;
    int data;
}Node;

void init(Node **front, Node **rear);
Node *createNode(int value);
int isEmpty(Node *Head);
void enqueue(Node **front, Node **rear, int value);
void dequeue(Node **front, Node **rear, int *data);

int main()
{
    int data;
    char ch, dump;
    Node *front, *rear;
    do
    {
        printf("\nPress A : To initialize a Queue.\n");
        printf("Press B : To check whether the Queue is Empty or Not?\n");
        printf("Press C : To enqueue an element into the Queue.\n");
        printf("Press D : To dequeue an element from the Queue.\n");
        printf("Press E : To display first inserted element.\n");
        printf("Press X : To close the Program.\n");
        printf("Enter Your Choice : \n");
        scanf("%c%c", &ch, &dump);
        switch (ch)
        {
        case 'A':
            init(&front, &rear);
            printf("Successfully Initialized.\n");
            break;
        case 'B':
            if(front == NULL && rear == NULL)
                printf("Queue is empty.\n");
            else
                printf("Queue is not empty.\n");
            break;
        case 'C': 
            printf("Enter the element to be enqueued into the Queue :\n");
            scanf("%d%c", &data, &dump);
            enqueue(&front, &rear, data);
            printf("Successfully Enqueued.\n");
            break;
        case 'D':
            if(front == NULL && rear == NULL)
                printf("Queue is empty.\n");
            else
            {
                dequeue(&front, &rear, &data);
                printf("The element dequeued from the Queue is : %d\n", data);
                printf("Successfully Dequeued.\n");
            }
            break;
        case 'E':
            if(front == NULL && rear == NULL)
                printf("Queue is empty.\n");
            else
                printf("The first enqueued element into the Queue is : %d\n", peek(front, rear));
            break;
        case 'X':
            printf("Program Closed.\n");
            break;
        default:
            printf("Invalid Choice! Please Try Again...\n");
            break;
        }
    }while(ch != 'X');
    return 0;
}

void init(Node **front, Node **rear)
{
    *front = *rear = NULL;
}
Node *createNode(int value)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->next = NULL;
    tmp->data = value;
    return tmp;
}
void enqueue(Node **front, Node **rear, int value)
{
    Node *newNode = createNode(value);
    if(*front == NULL && *rear == NULL)
    {
        *front = *rear = newNode;
        return;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}
void dequeue(Node **front, Node **rear, int *data)
{
    Node *tmp;
    if(*front == NULL && *rear == NULL)
        return;
    if(*front == *rear)
    {
        *data = (*front)->data;
        *front = *rear = NULL;
        return;
    }
    else
    {
        tmp = *front;
        *data = (*front)->data;
        
        (*front) = tmp->next;
        free(tmp);
    }
}
