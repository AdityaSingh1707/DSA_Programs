#include"CircularLinkedList.h"

CNode *create_node(int value)
{
    CNode *temp = (CNode *)malloc(sizeof(CNode));
    temp->data = value;
    temp->next = NULL;
    return temp;
}
void append(CNode **Head, int value)
{
    CNode *new_node = create_node(value);
    if(*Head == NULL)
    {
        *Head = new_node;
        new_node->next = *Head;
        return;
    }
    CNode *current = *Head;
    while(current->next != *Head)
    {
        current= current->next;
    }
    current->next = new_node;
    current->next->next = *Head;
}
void insert_begin(CNode **Head, int value)
{
    CNode *new_node = create_node(value);
    if(*Head == NULL)
    {
        *Head = new_node;
        new_node->next = *Head;
        return;
    }
    CNode *current = *Head, *tmp = *Head;
    while(current->next != *Head)
    {
        current= current->next;
    }
    current->next = new_node;
    new_node->next = tmp;
    *Head = new_node;
}
void traverse(CNode *head)
{
    if(head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }
    CNode *curr = head;
    do
    {
        printf("%d --> ", curr->data);
        curr = curr->next;
    }
    while(curr != head);
    printf("%d (Head)\n", head->data);
    return;
}

void delete(CNode **head, int n)
{
    CNode *curr = *head, *temp;
    if(*head == NULL){
        return;
    }
    else if(n == 1 && (*head)->next == NULL)
    {
        *head = NULL;
        return;
    }
    else if(n == 1)
    {
        curr->data = curr->next->data;
        temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
    else
    {
        int i = 1;
        for(; i <= n-1; i++)
        {
            curr = curr->next;
            if(curr->next == *head)
                return;
        }
        curr->data = curr->next->data;
        temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
}
