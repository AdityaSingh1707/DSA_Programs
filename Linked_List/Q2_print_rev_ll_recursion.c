// 2. Print the values of Linked_List in reverse order using recursion.


#include "linkedlist.h"
void printrevLinkedlist(Node *head);

int main()
{
    Node *Head = NULL;
    append(&Head, 5);
    append(&Head, 10);
    append(&Head, 15);
    append(&Head, 20);
    append(&Head, 25);
    printrevLinkedlist(Head);
    printf("NULL\n");
    return 0;
}
void printrevLinkedlist(Node *head)
{
    if (head != NULL)
    {
        rev_order_rec(head->next);
        printf("%d -> ", head->data);
    }
}
