#include "DoublyLinkedList.h"

/* Creates and initializes a new node */
Node* CreateNode(int data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

/* Adds a node to the front of the list */
Node* AddNodeHead(Node* head, int data)
{
    Node* new_node = CreateNode(data);
    
    // list is empty
    if (head == NULL)
        return new_node;
    
    head->prev = new_node;
    new_node->next = head;

    return new_node;
}

void PrintList(Node* head)
{
    Node* current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    
    printf("\n");

    return;
}