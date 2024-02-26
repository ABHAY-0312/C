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

struct Node *InsertAtIndex(struct Node *head, int index, int data)
{
    if (index < 0)
    {
        printf("Invalid index\n");
        return head;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (index == 0)
    {
        return InsertAtFirst(head, data);
    }

    struct Node *temp = head;
    int i = 0;

    while (i < index - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Index out of range\n");
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    return head;
}

struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct Node *InsertAfterValue(struct Node *head, int value, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL)
            {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }

    printf("Value not found in the list\n");
    return head;
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
    struct Node *head = NULL;

    // Inserting elements at the beginning
    head = InsertAtFirst(head, 40);
    head = InsertAtFirst(head, 30);
    head = InsertAtFirst(head, 20);
    head = InsertAtFirst(head, 10);

    // Displaying the original linked list
    printf("\nOriginal Linked List: ");
    displayLinked(head);

    // Inserting a node at index 2
    printf("\nAfter inserting 25 at index 2: ");
    head = InsertAtIndex(head, 2, 25);
    displayLinked(head);

    // Inserting a node at the end
    printf("\nAfter inserting 50 at the end: ");
    head = InsertAtEnd(head, 50);
    displayLinked(head);

    // Inserting a node after value 30
    printf("\nAfter inserting 35 after value 30: ");
    head = InsertAfterValue(head, 30, 35);
    displayLinked(head);

    // Deleting the first node
    printf("\nAfter deleting the first node: ");
    head = DeleteAtFirst(head);
    displayLinked(head);

    return 0;
}
