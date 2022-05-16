#include"CircularLinkedList.h"
int main()
{
    CNode *Head = NULL;
    int ch, data, posi;
    do
    {
        printf("Enter 1: To append a node.\n");
        printf("Enter 2: To insert a node.\n");
        printf("Enter 3: To display all the nodes.\n");
        printf("Enter 4: To delete a node at nth position.\n");
        printf("Enter 5: Exit.\n");
        printf("Enter your choice :\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter the data to be stored in the node : \n");
                scanf("%d", &data);
                append(&Head, data);
                printf("Circular Linked List :\n");
                traverse(Head);
                printf("\n");
                break;
            case 2:
                printf("Enter the data to be stored in the node : \n");
                scanf("%d", &data);
                insert_begin(&Head, data);
                printf("Circular Linked List :\n");
                traverse(Head);
                printf("\n");
                break;
            case 3:
                printf("Circular Linked List :\n");
                traverse(Head);
                break;
                printf("\n");
            case 4:
                printf("Enter the nth position at which the node is to be deleted : \n");
                scanf("%d", &posi);
                delete(&Head, posi);
                traverse(Head);
                printf("\n");
                break;
            case 5:
                printf("Program Closed.\n");
                break;
            default :
                printf("Invalid Choice! Enter your choice again :\n");
                break;
        }
    } while(ch != 5);
    

    return 0;
}
