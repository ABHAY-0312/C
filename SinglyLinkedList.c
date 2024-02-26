#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};



// Function to insert a node at the beginning of the linked list
struct Node *InsertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
 // Function to insert a node at a specific index in the linked list
// struct Node *InsertAtIndex(struct Node *head, int data, int index)
// {
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     struct Node *p = head;
//     int i = 0;
//     while (i != index - 1)
//     {
//         p = p->next;
//         i++;
//     }
//     ptr->data = data;
//     ptr->next = p->next;
//     p->next = ptr;
//     return head;
// }

// Function to insert a node at the end of the linked list
// struct Node *InsertAtEnd(struct Node *head, int data)
// {
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     ptr->data = data;
//     struct Node *p = head;
//     while (p->next != NULL)
//     {
//         p = p->next;
//     }
//     p->next = ptr;
//     ptr->next = NULL;
//     return head;
// }

// // Function to insert a node after a given node in the linked list
// struct Node *InsertAfterNode(struct Node *head, struct Node *prevNode, int data)
// {
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     ptr->data = data;
//     struct Node *p = head;
//     ptr->next = prevNode->next;
//     prevNode->next = ptr;
//     return head;
// }

// Function to delete the first node in the linked list
struct Node *DeleteAtFirst(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }

    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    
    return head;
}

// Function to delete a node at a specific index in the linked list
// struct Node *DeleteAtIndex(struct Node *head, int index)
// {
//     if (head == NULL)
//     {
//         printf("List is empty. Nothing to delete.\n");
//         return head;
//     }

//     struct Node *p = head;
//     struct Node *q = head->next;
//     for (int i = 0; i < index - 1; i++)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     p->next = q->next;
//     free(q);
    
//     return head;
// }

// // Function to delete the last node in the linked list
// struct Node *DeleteAtEnd(struct Node *head)
// {
//     if (head == NULL)
//     {
//         printf("List is empty. Nothing to delete.\n");
//         return head;
//     }

//     struct Node *p = head;
//     struct Node *q = head->next;
//     while (q->next != NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     p->next = NULL;
//     free(q);
  
//     return head;
// }

// // Function to delete a node with a specific value in the linked list
// struct Node *DeleteAtIndexAtGivenValue(struct Node *head, int value)
// {
//     struct Node *p = head;
//     struct Node *q = head->next;
//     if (q == NULL)
//     {
//         printf("List is empty. Nothing to delete.\n");
//         return head;
//     }
//     while (q->data != value && q->next != NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     if (q->data == value)
//     {
//         p->next = q->next;
//         free(q);
      
//     }
//     else
//     {
//         printf("Node with value %d not found.\n", value);
//     }
//     return head;
// }

void displayLinked(struct Node *ptr)
{
if (ptr == NULL)
    {
        printf("Linked list is empty.\n");
        return ;
    }
    struct Node *current = ptr;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 40;
    head->next = second;
    second->data = 60;
    second->next = third;
    third->data = 80;
    third->next = fourth;
    fourth->data = 100;
    fourth->next = NULL;

    printf("\nOriginal Linked List: ");
    displayLinked(head);

    printf("\nAfter inserting 300 at the beginning: ");
    head = InsertAtFirst(head, 300);
    displayLinked(head);

    // printf("\nAfter inserting 8 at index 2: ");
    // head = InsertAtIndex(head, 8, 2);
    // displayLinked(head);

    // printf("\nAfter inserting 85 at the end: ");
    // head = InsertAtEnd(head, 85);
    // displayLinked(head);

    // printf("\nAfter inserting 45 after the second node: ");
    // head = InsertAfterNode(head, second, 45);
    // displayLinked(head);

    printf("\nAfter deleting the first node: ");
    head = DeleteAtFirst(head);
    displayLinked(head);

    // printf("\nAfter deleting the node at index 2: ");
    // head = DeleteAtIndex(head, 2);
    // displayLinked(head);

    // printf("\nAfter deleting the last node: ");
    // head = DeleteAtEnd(head);
    // displayLinked(head);

    // printf("\nAfter deleting the node with value 50: ");
    // head = DeleteAtIndexAtGivenValue(head, 50);
    // displayLinked(head);

    return 0;
}
