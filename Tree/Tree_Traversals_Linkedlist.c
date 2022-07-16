#include <stdio.h>
#include <stdlib.h>
#define ITEM TNode *

typedef struct tr
{
    int data;
    struct tr *left, *right;
} TNode;

TNode *createNode(int value);
void preorder_recursive(TNode *root);
void inorder_recursive(TNode *root);
void postorder_recursive(TNode *root);
void preorder_iterative(TNode *root);
void inorder_iterative(TNode *root);
void postorder_iterative(TNode *root);

typedef struct st
{
    ITEM *arr;
    int tos, size;
} Stack;

void init_Stack(Stack *pts, int size);
int isEmpty_Stack(const Stack *pts);
int isFull_Stack(const Stack *pts);
int push_Stack(Stack *pts, ITEM data);
int pop_Stack(Stack *pts, ITEM *data);
ITEM peek_Stack(const Stack *pts);

typedef struct qu
{
    ITEM *arr;
    int rear, front, size;
} Queue;

void init_Queue(Queue *ptq, int size);
int isEmpty_Queue(Queue *ptq);
int isFull_Queue(Queue *ptq);
int enqueue_Queue(Queue *ptq, ITEM data);
int dequeue_Queue(Queue *ptq, ITEM *data);
void levelorder(TNode *root);

int main()
{
    char ch, dump;

    TNode *root = NULL;
    root = createNode(10);

    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);

    do
    {
        printf("\nPress A : Preorder Traversal (Using Recursion).\n");
        printf("Press B : Inorder Traversal (Using Recursion).\n");
        printf("Press C : Postorder Traversal (Using Recursion).\n");
        printf("Press D : Preorder Traversal (Using Iteration).\n");
        printf("Press E : Inorder Traversal (Using Iteration).\n");
        printf("Press F : Postorder Traversal (Using Iteration).\n");
        printf("Press G : Levelorder Traversal (Using Iteration).\n");
        printf("Press X : Close the Program.\n");
        printf("Enter your choice :\n");
        scanf("%c%c", &ch, &dump);

        switch (ch)
        {
        case 'A':
            printf("\nPreorder Traversal (Using Recursion) :-\n");
            preorder_recursive(root);
            break;
        case 'B':
            printf("\nInorder Traversal (Using Recursion) :-\n");
            inorder_recursive(root);
            break;
        case 'C':
            printf("\nPostorder Traversal (Using Recursion) :-\n");
            postorder_recursive(root);
            break;
        case 'D':
            printf("\nPreorder Traversal (Using Iteration) :-\n");
            preorder_iterative(root);
            break;
        case 'E':
            printf("\nInorder Traversal (Using Iteration) :-\n");
            inorder_iterative(root);
            break;
        case 'F':
            printf("\nPostorder Traversal (Using Iteration) :-\n");
            postorder_iterative(root);
            break;
        case 'G':
            printf("\nLevelorder Traversal (Using Iteration) :-\n");
            levelorder(root);
            break;
        case 'X':
            printf("\nProgram Closed.\n");
            break;
        default:
            printf("Please try again!\n");
        }
    } while (ch != 'X');
    return 0;
}
TNode *createNode(int value)
{
    TNode *temp = (TNode *)malloc(sizeof(TNode));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Recursive Traversals...

void preorder_recursive(TNode *root)
{
    if (root == NULL)
        return;
    else
    {
        printf("%d ", root->data);
        preorder_recursive(root->left);
        preorder_recursive(root->right);
    }
}
void inorder_recursive(TNode *root)
{
    if (root == NULL)
        return;
    else
    {
        inorder_recursive(root->left);
        printf("%d ", root->data);
        inorder_recursive(root->right);
    }
}
void postorder_recursive(TNode *root)
{
    if (root == NULL)
        return;
    else
    {
        postorder_recursive(root->left);
        postorder_recursive(root->right);
        printf("%d ", root->data);
    }
}

// Iterative Traversals...

void preorder_iterative(TNode *root)
{
    if (root == NULL)
        return;
    TNode *tmp;
    Stack S;
    init_Stack(&S, 20);
    push_Stack(&S, root);
    while (!isEmpty_Stack(&S))
    {
        pop_Stack(&S, &tmp);
        printf("%d ", tmp->data);
        if (tmp->right != NULL)
            push_Stack(&S, tmp->right);
        if (tmp->left != NULL)
            push_Stack(&S, tmp->left);
    }
}
void inorder_iterative(TNode *root)
{
    if (root == NULL)
        return;
    Stack S;
    init_Stack(&S, 20);
    while (root != NULL || !isEmpty_Stack(&S))
    {
        while (root != NULL)
        {
            push_Stack(&S, root);
            root = root->left;
        }
        if (isEmpty_Stack(&S) == 1)
            break;
        else
        {
            pop_Stack(&S, &root);
            printf("%d ", root->data);
            root = root->right;
        }
    }
}
void postorder_iterative(TNode *root)
{
    if (root == NULL)
        return;
    TNode *tmp;
    Stack S;
    init_Stack(&S, 20);
    do
    {
        while (root != NULL)
        {
            if (root->right != NULL)
                push_Stack(&S, root->right);
            push_Stack(&S, root);
            root = root->left;
        }
        pop_Stack(&S, &root);
        if (root->right != NULL && peek_Stack(&S) == root->right)
        {
            pop_Stack(&S, &tmp);
            push_Stack(&S, root);
            root = root->right;
        }
        else
        {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (!isEmpty_Stack(&S));
}
void levelorder(TNode *root)
{
    TNode *tmp;
    if (root == NULL)
        return;
    Queue Q;
    init_Queue(&Q, 20);
    enqueue_Queue(&Q, root);

    while (!isEmpty_Queue(&Q))
    {
        dequeue_Queue(&Q, &tmp);
        printf("%d ", tmp->data);
        if (tmp->left != NULL)
            enqueue_Queue(&Q, tmp->left);
        if (tmp->right != NULL)
            enqueue_Queue(&Q, tmp->right);
    }
}
// Stack Functions...

void init_Stack(Stack *pts, int size)
{
    pts->arr = (int *)malloc(size * sizeof(int));
    pts->size = size;
    pts->tos = -1;
}

int isEmpty_Stack(const Stack *pts)
{
    if (pts->tos == -1)
        return 1;
    return 0;
}

int isFull_Stack(const Stack *pts)
{
    if (pts->tos == pts->size - 1)
        return 1;
    return 0;
}

int push_Stack(Stack *pts, ITEM data)
{
    if (isFull_Stack(pts) == 1)
        return 0;
    pts->tos++;
    pts->arr[pts->tos] = data;
    return 1;
}

int pop_Stack(Stack *pts, ITEM *data)
{
    if (isEmpty_Stack(pts) == 1)
        return 0;
    *data = pts->arr[pts->tos];
    pts->tos--;
    return 1;
}
ITEM peek_Stack(const Stack *pts)
{
    return pts->arr[pts->tos];
}

// Queue Functions...

void init_Queue(Queue *ptq, int size)
{
    ptq->arr = (int *)malloc(sizeof(int));
    ptq->size = size;
    ptq->front = ptq->rear = -1;
}
int isEmpty_Queue(Queue *ptq)
{
    if (ptq->front == -1 && ptq->rear == -1)
        return 1;
    return 0;
}
int isFull_Queue(Queue *ptq)
{
    if ((ptq->front == 0 && ptq->rear == (ptq->size - 1)) || (ptq->front == ptq->rear + 1))
        return 1;
    return 0;
}
int dequeue_Queue(Queue *ptq, ITEM *data)
{
    int tmp;
    if (isEmpty_Queue(ptq) == 1)
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
int enqueue_Queue(Queue *ptq, ITEM data)
{
    if (isFull_Queue(ptq) == 1)
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
