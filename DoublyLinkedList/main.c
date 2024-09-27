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
    
    int n = GetLength(head);
    
    printf("n is %d\n", n);
    PrintList(head);


    head = AddNode(head, 55, 0);
    PrintList(head);


    return 0;
}