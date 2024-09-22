#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* CreateNode(int data);

/* Insertion Functions */
Node* InsertNodeFront(Node* head, int data);
Node* InsertNodeTail(Node* head, int data);
Node* InsertNodeAfter(Node* head, int data, int key);
Node* InsertNodeBefore(Node* head, int data, int key);
/***********************/

/* Deletion Functions */
Node* DeleteNodeFront(Node* head);
Node* DeleteNodeEnd(Node* head);
Node* DeleteNode(Node* head, int key);
/**********************/

int Search(Node* head, int key);
void PrintList(Node* head);


#endif // LINKED_LIST_H