// Stack Implementation Using Linked List...

#include <stdio.h>
#include <stdlib.h>
typedef struct st
{
    int data;
    struct st *next;
} Node;
void init(Node **Head);
Node *createNode(int value);
int isEmpty(Node *Head);
void push(Node **Head, int value);
void pop(Node **Head, int *data);
int peek(Node *Head);

int main()
{
    int data;
    Node *Stack = NULL;
    char ch, dump;
    do
    {
        printf("\nPress A : To Initialize the Stack.\n");
        printf("Press B : To Push an element into the Stack.\n");
        printf("Press C : To Pop out topmost element from the Stack.\n");
        printf("Press D : To check whether the Stack is Empty or Not?\n");
        printf("Press E : To display the topmost element of the Stack.\n");
        printf("Press X : Close the program.\n");
        printf("Enter your Choice :\n");
        scanf("%c%c", &ch, &dump);

        switch (ch)
        {
        case 'A':
            init(&Stack);
            printf("Successfully Initialized.\n");
            break;
        case 'B':
            printf("Enter the element to be pushed into the Stack :\n");
            scanf("%d%c", &data, &dump);
            addbeg(&Stack, data);
            printf("Successfully Pushed.\n");
            break;
        case 'C':
            if (Stack == NULL)
                printf("Linked List is Empty.\n");
            else
                delbeg(&Stack, &data);
            printf("The element poped out from the Stack is : %d\n", data);
            printf("Successfully Poped.\n");
            break;
        case 'D':
            if (Stack == NULL)
                printf("Stack is Empty.\n");
            else
                printf("Stack is not Empty.\n");
            break;
        case 'E':
            if (Stack == NULL)
                printf("Stack is Empty.\n");
            else
                printf("The topmost element of the Stack : %d\n", peek(Stack));
            break;
        default:
            printf("Invalid Choice!\nTry Again...\n");
            break;
        }

    } while (ch != 'X');

    return 0;
}
void init(Node **Head)
{
    Head = NULL;
}
Node *createNode(int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = NULL;
    temp->data = value;
    return temp;
}
int isEmpty(Node *Head)
{
    if (Head == NULL)
        return 1;
    return 0;
}
void push(Node **Head, int value)
{
    Node *newNode = createNode(value);
    if (*Head == NULL)
    {
        *Head = newNode;
        return;
    }
    newNode->next = *Head;
    *Head = newNode;
}
void pop(Node **Head, int *data)
{
    if (*Head == NULL)
        return;
    Node *tmp = *Head;
    *data = tmp->data;
    *Head = tmp->next;
    free(tmp);
}
int peek(Node *Head)
{
    return Head->data;
}
