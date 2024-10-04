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

/* Inserts a node at the given position of the list */
Node* InsertNode(Node* head, int data, int pos)
{
    if (pos != 1 && pos > GetLength(head) || pos < 1)
    {
        printf("Position not in the bounds of the list!\n");
        return head;
    }

    Node* current = head;
    Node* new_node = CreateNode(data);
    int n = 1;      //  starting position of the list is 1

    /* If the node is inserted as the new head */
    if (pos == 1)
        return InsertNodeFront(head, data);
    
    while (current != NULL)
    {
        /* Stops just before the given position */
        if (n == pos-1)
            break;
        
        n++;
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;

    return head;
}

/* Deletes a node from the front of the list */
Node* DeleteNodeFront(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    free(temp);

    return head;
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
    free(current_node);
    
    return head;
}

/* Deletes a node from the list given by the key */
Node* DeleteNode(Node* head, int pos)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    if (pos != 1 && pos > GetLength(head) || pos < 1)
    {
        printf("Position given is out of bounds of the list!\n");
        return head;
    }

    if (pos == 1)
        return DeleteNodeFront(head);

    Node* current = head;
    Node* temp;
    int n = 1;
    
    while (current != NULL)
    {
        /* Stop just before the position */
        if (n == pos-1)
            break;

        n++;
        current = current->next;
    }

    temp = current->next;    
    current->next = current->next->next;

    free(temp);

    return head;
}


/* Returns the length of the linked list */
int GetLength(Node* head)
{
    int n = 0;
    Node* current = head;

    while (current != NULL)
    {
        n++;
        current = current->next;
    }
    
    return n;
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
    if (head == NULL)
        printf("List is empty!!!");

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    return;
}