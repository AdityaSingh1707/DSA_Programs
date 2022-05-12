// Q3. Reverse the Linked_List.

#include "linkedlist.h"
void reverse_Llist(Node **Head);

int main()
{
    Node *Head = NULL;
    append(&Head, 5);
    append(&Head, 10);
    append(&Head, 15);
    append(&Head, 20);
    append(&Head, 25);
    printf("Linked List : ");
    traverse(Head);
    reverse_Llist(&Head);
    printf("Reversed Linked List : ");
    traverse(Head);
    return 0;
}

void reverse_Llist(Node **Head)
{
    Node *curr_node = *Head, *prev_node = NULL, *next_node;
    while (curr_node != NULL)
    {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    *Head = prev_node;
}
