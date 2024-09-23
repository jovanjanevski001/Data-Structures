#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* CreateNode(int data);

Node* AddNodeHead(Node* node, int data);

void PrintList(Node* head);


#endif // DOUBLY_LINKED_LIST_H