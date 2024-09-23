#include "DoublyLinkedList.h"

int main()
{
    Node* head = (Node*) malloc(sizeof(Node));
    head = NULL;

    for (int i = 0; i < 5; i++)
        head = AddNodeHead(head, i);
    
    PrintList(head);
    
    return 0;
}