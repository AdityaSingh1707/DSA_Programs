// Header File including all functions of Linked List. 

#include <stdio.h>
#include <stdlib.h>
typedef struct st
{
    int data;
    struct st *next;
} Node;
Node *create(int data);
void append(Node **head, int data);
void traverse(Node *head);
int delete (Node **head, int node_number);
int add_node_at(Node **head, int node_number, int data);
int add_node_after(Node **, int node_number, int data);
int add_node_before(Node **head, int node_number, int data);
void reverse_linkedlist(Node **Head);
void rev_order_rec(Node *head);
void rev_order_iter(Node *head);
