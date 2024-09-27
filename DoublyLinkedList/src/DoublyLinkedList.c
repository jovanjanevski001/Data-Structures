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

/* Adds a node to the end of the list */
Node* AddNodeTail(Node* head, int data)
{
    Node* new_node = CreateNode(data);

    // list is empty
    if (head == NULL)
        return new_node;

    Node* current = head;

    /* Traverse the list until we reach the end */
    while (current->next != NULL)
        current = current->next;
    
    current->next = new_node;
    new_node->prev = current;

    return head;
}


Node* AddNode(Node* head, int data, int position)
{
    Node* new_node = CreateNode(data);

    // list is empty
    if (head == NULL)
        return new_node;

    Node* current = head;
    int n = 1;

    if (position == 1)
    {
        new_node = AddNodeHead(head, data);
        return new_node;
    }

    while (current != NULL && n < position-1)
    {
        current = current->next;
        n++;
    }

    if (current == NULL)
        return head;

    else
    {
        new_node->next = current->next;
        new_node->prev = current;
        current->next = new_node;
    }

    return head;
}

/* Returns the length of the list */
int GetLength(Node* head)
{
    Node* current = head;
    int length = 0;

    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    return length;
}

/* Prints the linked list */
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