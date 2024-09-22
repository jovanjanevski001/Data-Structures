#include "linked_list.h"

/* Creates a new node */
Node* CreateNode(int data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

/* Inserts a node to the front of the list */
Node* InsertNodeFront(Node* head, int data)
{
    Node* new_node = CreateNode(data);
    new_node->next = head;

    return new_node;
}

/* Inserts a node to the end of the list */
Node* InsertNodeTail(Node* head, int data)
{
    Node* new_node = CreateNode(data);

    // list is empty, so the new node is the head
    if (head == NULL)
        return new_node;

    Node* current_node = head;      //  to traverse the list

    while (current_node->next != NULL)
        current_node = current_node->next;

    current_node->next = new_node;

    return head; 
}

/* Inserts a node after the given key */
Node* InsertNodeAfter(Node* head, int data, int key)
{   
    Node* current_node = head;

    while (current_node != NULL)
    {
        if (current_node->data == key)
            break;
        
        current_node = current_node->next;
    }
        
    if (current_node == NULL)
        return head;

    Node* new_node = CreateNode(data);
    new_node->next = current_node->next;
    current_node->next = new_node;

    return head;
}

/* Inserts a node before the given key */
Node* InsertNodeBefore(Node* head, int data, int key)
{
    Node* current_node = head;
    Node* prev_node = current_node;

    while (current_node != NULL)
    {
        if (current_node->data == key)
            break;

        prev_node = current_node;
        current_node = current_node->next;
    }

    /* Key not found! */
    if (current_node == NULL)
        return head;


    Node* new_node = CreateNode(data);

    /* Inserting a node before the first node of the list */
    if (prev_node == current_node)
    {
        new_node->next = current_node;
        return new_node;
    }

    /* Inserting a node before any other node in the list */
    else
    {
        new_node->next = current_node;
        prev_node->next = new_node;
        return head;
    }
}

/* Deletes a node from the front of the list */
Node* DeleteNodeFront(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    return head = head->next;
}

/* Deletes a node from the end of list */
Node* DeleteNodeEnd(Node* head)
{

    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        printf("Last node removed!\n");
        return NULL;
    }

    Node* current_node = head;
    Node* prev_node = current_node;

    while (current_node->next != NULL)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }    

    prev_node->next = NULL;

    return head;
}

/* Deletes a node from the list given by the key */
Node* DeleteNode(Node* head, int key)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    Node* current_node = head;
    Node* prev_node = current_node;

    while (current_node != NULL)
    {
        if (current_node->data == key)
            break;
        prev_node = current_node;
        current_node = current_node->next;
    }    

    /* Key not found in list! */
    if (current_node == NULL)
        return NULL;

    /* If first node was deleted */
    if (prev_node == current_node)
        head = current_node->next;

    else
        prev_node->next = current_node->next;

    return head;
}

/* Searches the linked list to find key */
int Search(Node* head, int key)
{
    Node* current_node = head;

    while (current_node != NULL)
    {
        if (current_node->data == key)
            return TRUE;
        
        current_node = current_node->next;
    }
    
    return FALSE;
}

/* Prints the linked list */
void PrintList(Node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    return;
}