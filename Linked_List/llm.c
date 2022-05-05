#include "linkedlist.h"

// Function to create a node...

Node *create(int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Function to append a node to the linked list.... 

void append(Node **head, int value)
{
    Node *new_node = NULL, *temp = *head;
    new_node = create(value);
    if(temp == NULL){
        *head = new_node;
        return;
    }
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;

}

// Function to display (traverse) the linked list  

void traverse(Node *head)
{
    if(head == NULL)
    {
        printf("The Linked List is empty.\n");
        return;
    }
    while(head != NULL)
    {
        printf(" %d --> ",head->data);
        head = head->next;
    }
    printf("NULL \n");
}

// Function to delete a node from linked list... 

int delete(Node **head, int n)
{
    Node *current = *head, *prev;
    if(n == 1)
    {
        *head = current->next;
        free(current);
        return 1;
    }
    int i;
    for(i = 1; current != NULL && i <= n-1; i++)
    {
        prev = current;
        current = current->next;
    }
    if(current == NULL)
        return 0;
    prev->next = current->next;
    free(current);
    return 1;
}

// Function to add a new node at nth position in the linked list...

int add_node_at(Node **head, int n, int data)
{
    if(n < 1)
    {
        return 0;
    }
    Node *new = create(data);
    if(n == 1)
    {
        new->next = *head;
        *head = new;
        return 1;
    }
    int i;
    Node *curr = *head, *prev;
    for(i = 1; curr != NULL && i < n; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL)
        return 0;
    prev->next = new;
    new->next = curr;
    return 1;
}

// Function to add a new node before the nth position in the linked list...

int add_node_before(Node **head, int n, int data)
{
    return add_node_at(head, n-1, data);
}

// Function to add a new node after the nth position in the linked list...

int add_node_after(Node **head, int n, int data)
{
    return add_node_at(head, n+1, data);
}

