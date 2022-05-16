#include<stdio.h>
#include<stdlib.h>
typedef struct Cnode
{
    int data;
    struct Cnode *next;
}CNode;
CNode *create_node(int value);
void append(CNode **Head, int value);
void traverse(CNode *head);
void insert_begin(CNode **Head, int value);
void delete(CNode **Head, int n);
