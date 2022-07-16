// Array Implementation for Binary Tree...
#include <stdio.h>
#include <stdlib.h>
typedef struct st
{
    char *arr;
    int size;
} Tree;

void init(Tree *pqt, int size);
int root(Tree *pqt, char key);
int set_right(Tree *pqt, char key, int parent);
int set_left(Tree *pqt, char key, int parent);
void preorder(Tree *pqt, int rp);
void postorder(Tree *pqt, int rp);
void inorder(Tree *pqt, int rp);
void levelorder(Tree *pqt);

int main()
{
    Tree *T;
    int size, ch;
    char dump;

    printf("Enter the number of nodes in tree : \n");
    scanf("%d%c", &size, &dump);

    init(T, size);

    root(T, 'A');

    set_left(T, 'B', 0);
    set_right(T, 'C', 0);

    set_left(T, 'D', 1);
    set_right(T, 'E', 1);

    set_left(T, 'F', 2);
    set_right(T, 'G', 2);

    do
    {
        printf("\nPress A : Preorder Traversal.\n");
        printf("Press B : Inorder Traversal.\n");
        printf("Press C : Postorder Traversal.\n");
        printf("Press D : Level Order Traversal.\n");
        printf("Press E : Close Program.\n");
        printf("Enter your choice :\n");
        scanf("%d%c", &ch, &dump);
        switch (ch)
        {
        case 1:
            printf("Preorder Traversal for Given Binary Tree :\n");
            preorder(T, 0);
            printf("\n");
            break;
        case 2:
            printf("Inorder Traversal for Given Binary Tree :\n");
            inorder(T, 0);
            printf("\n");
            break;
        case 3:
            printf("Postorder Traversal for Given Binary Tree :\n");
            postorder(T, 0);
            printf("\n");
            break;
        case 4:
            printf("Levelorder Traversal for Given Binary Tree :\n");
            levelorder(T);
            printf("\n");
            break;
        case 5:
            printf("Program Closed.\n");
            break;
        default:
            printf("Please try again! \n");
        }
    } while (ch != 5);

    return 0;
}

void init(Tree *pqt, int size)
{
    pqt->arr = (char *)malloc(size * sizeof(char));
    pqt->size = size;
}
int root(Tree *pqt, char key)
{
    if (pqt->arr[0] == '-')
        return 0;
    else
    {
        pqt->arr[0] = key;
        return 1;
    }
}
int set_left(Tree *pqt, char key, int parent)
{
    if (pqt->arr[parent] == '-')
        return 0;
    else
    {
        pqt->arr[(2 * parent) + 1] = key;
        return 1;
    }
}
int set_right(Tree *pqt, char key, int parent)
{
    if (pqt->arr[parent] == '-')
        return 0;
    else
    {
        pqt->arr[(2 * parent) + 2] = key;
        return 1;
    }
}
void preorder(Tree *pqt, int rp)
{
    if (pqt->size < 0)
        return;
    if (rp <= pqt->size - 1)
    {
        printf("%c ", pqt->arr[rp]);
        preorder(pqt, (2 * rp) + 1);
        preorder(pqt, (2 * rp) + 2);
    }
}
void inorder(Tree *pqt, int rp)
{
    if (pqt->size < 0)
        return;
    if (rp <= pqt->size - 1)
    {
        inorder(pqt, (2 * rp) + 1);
        printf("%c ", pqt->arr[rp]);
        inorder(pqt, (2 * rp) + 2);
    }
}
void postorder(Tree *pqt, int rp)
{
    if (pqt->size < 0)
        return;
    if (rp <= pqt->size - 1)
    {
        postorder(pqt, (2 * rp) + 1);
        postorder(pqt, (2 * rp) + 2);
        printf("%c ", pqt->arr[rp]);
    }
}
void levelorder(Tree *pqt)
{
    int i;
    for (i = 0; i < pqt->size; i++)
    {
        printf("%c ", pqt->arr[i]);
    }
}
