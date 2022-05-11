// 5. Design a menu including all the functions of Linked_List.

#include "linkedlist.h"
int main()
{
    int ch, i = 1, data, n;
    Node *Head = NULL;
    do
    {
        printf("Enter 1 : To append a node in linked list.\n");
        printf("Enter 2 : To delete a node from linked list.\n");
        printf("Enter 3 : To add a node at nth position of linked list.\n");
        printf("Enter 4 : To add a node before nth position of linked list.\n");
        printf("Enter 5 : To add a node after nth position of linked list.\n");
        printf("Enter 6 : To reverse the linked list.\n");
        printf("Enter 7 : To display the linked list.\n");
        printf("Enter 8 : To display the linked list in reverse order (Recursion).\n");
        printf("Enter 9 : To display the linked list in reverse order (Iteration).\n");
        printf("Enter 10: Exit.\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to be stored at Node %d :", i);
            scanf("%d", &data);
            append(&Head, data);
            i++;
            printf("\nOutcome Linked List: \n");
            traverse(Head);
            printf("\n");
            break;
        case 2:
            printf("Enter the position of node which is to be deleted : ");
            scanf("%d", &n);
            delete (&Head, n);
            printf("\nOutcome Linked List: \n");
            traverse(Head);
            printf("\n");
            break;
        case 3:
            printf("Enter the value to be stored at nth position : ");
            scanf("%d", &data);
            printf("Enter the position where node is to be added : ");
            scanf("%d", &n);
            add_node_at(&Head, n, data);
            i++;
            printf("\nOutcome Linked List: \n");
            traverse(Head);
            printf("\n");
            break;
        case 4:
            printf("Enter the value to be stored before nth position : ");
            scanf("%d", &data);
            printf("Enter the position before which the node is to be added : ");
            scanf("%d", &n);
            add_node_before(&Head, n, data);
            i++;
            printf("\nOutcome Linked List: \n");
            traverse(Head);
            printf("\n");
            break;
        case 5:
            printf("Enter the value to be stored after nth position : ");
            scanf("%d", &data);
            printf("Enter the position after which the node is to be added : ");
            scanf("%d", &n);
            add_node_after(&Head, n, data);
            i++;
            printf("\nOutcome Linked List: \n");
            traverse(Head);
            printf("\n");
            break;
        case 6:
            reverse_linkedlist(&Head);
            printf("Reversed Linked List : \n");
            printf("\nOutcome Linked List: \n");
            traverse(Head);
            printf("\n");
            break;
        case 7:
            printf("\nOutcome Linked List: \n");
            traverse(Head);
            printf("\n");
            break;
        case 8:
            printf(" Displaying Linked List in Reverse Order using recursion (Without Editing): \n");
            rev_order_rec(Head);
            printf("NULL\n");
            printf("\nOutcome Linked List: \n");
            traverse(Head);
            break;
        case 9:
            printf("Linked List in Reverse Order using iteration (Without Editing): \n");
            rev_order_iter(Head);
            printf("NULL\n");
            printf("\nOutcome Linked List: \n");
            traverse(Head);
            break;
        case 10:
            printf("CLOSED\n");
            break;
        default:
            printf("\nInvalid Choice : Enter your choice again.\n");
            break;
        }

    } while (ch != 10);
    return 0;
}
