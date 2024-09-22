#include "linked_list.h"

int main()
{
    Node* head = (Node*) malloc(sizeof(Node));
    head = NULL;

    for (int i = 0; i < 10; i++)
    {
        head = InsertNodeTail(head, i);
    }
    
    PrintList(head);

    head = InsertNodeBefore(head, -1, 3);
    head = InsertNodeFront(head, 55);
    PrintList(head);
    
    
    if (Search(head, -123) == TRUE)
        printf("Key found!\n");
    else
        printf("Key not found\n");

    PrintList(head);

    return 0;
}