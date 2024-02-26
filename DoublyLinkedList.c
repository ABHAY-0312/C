#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *InsertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;

    if (head != NULL)
    {
        head->prev = ptr;
    }

    return ptr;
}

struct Node *DeleteAtFirst(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return head;
    }

    struct Node *ptr = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    free(ptr);

    return head;
}

void displayLinked(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Creating nodes and initializing data values
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->prev = NULL;
    head->next = second;
    second->data = 20;
    second->prev = head;
    second->next = third;
    third->data = 30;
    third->prev = second;
    third->next = fourth;
    fourth->data = 40;
    fourth->prev = third;

    fourth->next = NULL;

    // Displaying the original linked list
    printf("\nOriginal Linked List: ");
    displayLinked(head);

    // Inserting a node at the beginning
    printf("\nAfter inserting 5 at the beginning: ");
    head = InsertAtFirst(head, 5);
    displayLinked(head);

    // Deleting the first node
    printf("\nAfter deleting the first node: ");
   head = DeleteAtFirst(head);
    displayLinked(head);

    return 0;
}
