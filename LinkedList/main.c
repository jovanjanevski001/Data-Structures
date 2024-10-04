#include "linked_list.h"

int main()
{
    Node* head = (Node*) malloc(sizeof(Node));
    head = NULL;

    int user_input = 0, pos = 0, i = 0, key = 0;

    printf("******** Linked List Visual ********\n");
    printf("1. Add node to front of the list\n");
    printf("2. Add node to back of the list\n");
    printf("3. Add node to the list\n");
    printf("4. Delete node from the front of the list \n");
    printf("5. Delete node from the back of the list \n");
    printf("6. Delete node from the list \n");
    printf("7. Length of the list\n");
    printf("8. Search for a node in the list \n");
    printf("9. Print the list\n");
    printf("10. Exit\n");
    printf("***********************************\n");
    
    while (user_input != 10)
    {   
        printf("Select an option: ");
        scanf("%d", &user_input);
        
        if (user_input == 1)
            head = InsertNodeFront(head, i);
        
        else if (user_input == 2)
            head = InsertNodeTail(head, i);
        
        else if (user_input == 3)
        {
            printf("Enter the position of the new node: ");
            scanf("%d", &pos);
            head = InsertNode(head, i, pos);
        }

        else if (user_input == 4)
            head = DeleteNodeFront(head);
        
        else if (user_input == 5)
            head = DeleteNodeEnd(head);
        
        else if (user_input == 6)
        {
            printf("Enter the position of the node to be deleted: ");
            scanf("%d", &pos);
            head = DeleteNode(head, pos);
        }

        else if (user_input == 7)
            printf("Length of the list is: %d\n", GetLength(head));
        
        else if (user_input == 8)
        {
            printf("Enter the key to find: ");
            scanf("%d", &key);

            if (Search(head, key) == TRUE)
                printf("%d was found in the list\n", key);
            else
                printf("%d was not found in the list\n", key);
        }
        
        else if (user_input == 9)
            PrintList(head);
        
        i++;
    }

    free(head);

    return 0;
}