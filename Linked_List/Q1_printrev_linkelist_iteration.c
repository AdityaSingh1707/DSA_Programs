// 1. Print the values of Linked_List in reverse order.
#include "linkedlist.h"
void rev_order(Node *head);

int main()
{
    Node *Head = NULL;
    append(&Head, 5);
    append(&Head, 10);
    append(&Head, 15);
    append(&Head, 20);
    append(&Head, 25);
    rev_order(Head);
    printf("NULL\n");
    return 0;
}

void rev_order(Node *head)
{
    Node *last, *current;
    last = NULL;
    printf("\n");
    while (head != last)
    {
        current = head;
        while (current->next != last)
        {
            current = current->next;
        }
        printf("%d -> ", current->data);
        last = current;
    }
}
