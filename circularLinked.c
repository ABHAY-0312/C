#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        rear->next = front;
        printf("Enqueued: %d\n", x);
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
        printf("Enqueued: %d\n", x);
    }
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("Underflow");
        return;
    }

    struct Node *temp = front;
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

void display() {
    struct Node *temp = front;
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
        printf("\n");
    }
}

int main() {
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    display();

    dequeue();
    display();

    return 0;
}
