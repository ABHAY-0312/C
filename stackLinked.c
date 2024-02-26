#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

struct Node *top = NULL;

void push(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = x;
    newNode->link = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Underflow");
        return;
    }

    struct Node *temp = top;
    top = top->link;
    printf("Popped: %d\n", temp->data);
    free(temp);
}

void display() {
    struct Node *temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);

    display();

    pop();

    display();

    return 0;
}
