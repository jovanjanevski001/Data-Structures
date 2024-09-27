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

Node* AddNodeHead(Node* head, int data);
Node* AddNodeTail(Node* head, int data);
Node* AddNode(Node* head, int data, int position);

int GetLength(Node* head);
void PrintList(Node* head);

#endif // DOUBLY_LINKED_LIST_H