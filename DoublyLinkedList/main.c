#include "DoublyLinkedList.h"

int main()
{
    Node* head = (Node*) malloc(sizeof(Node));
    head = NULL;

    for (int i = 0; i < 5; i++)
        head = AddNodeHead(head, i);
    
    PrintList(head);

    head = AddNodeTail(head, 33);
    head = AddNodeTail(head, 3);
    head = AddNodeTail(head, 6);
    head = AddNodeTail(head, -1);
    
    PrintList(head);

    return 0;
}