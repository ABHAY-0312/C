#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL)
    {
        newNode->next = newNode; // Point to itself to form a circular link
        return newNode;
    }

    struct Node *temp = head;

    // Traverse to the last node
    while (temp->next != head)
    {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
    newNode->next = head;

    return head;
}

struct Node *DeleteAtFirst(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty. \n");
        return head;
    }

    struct Node *firstNode = head;
    struct Node *lastNode = head;

    while (lastNode->next != head)
    {
        lastNode = lastNode->next;
    }

    if (firstNode == lastNode) // Only one node in the list
    {
        free(head);
        return NULL;
    }

    lastNode->next = firstNode->next;
    head = firstNode->next; // Update head to the next node
    free(firstNode);
    
    return head;
}


void displayLinked(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node *current = head;

    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    printf("\nOriginal Circular Linked List: ");
    displayLinked(head);

    printf("\nAfter inserting 40 at the end: ");
    head = InsertAtEnd(head, 40);
    displayLinked(head);

    printf("\nAfter inserting 60 at the end: ");
    head = InsertAtEnd(head, 60);
    displayLinked(head);

    printf("\nAfter inserting 80 at the end: ");
    head = InsertAtEnd(head, 80);
    displayLinked(head);

    printf("\nAfter inserting 100 at the end: ");
    head = InsertAtEnd(head, 100);
    displayLinked(head);

    printf("\nAfter deleting the first node: ");
    head = DeleteAtFirst(head);
    displayLinked(head);

    return 0;
}
