#include <stdio.h>
#define N 5

int stack[N];
int top = -1;

void push() {
    int x;
    printf("Enter the value: ");
    scanf("%d", &x);
    if (top == N - 1) {
        printf("Overflow\n");
    } else {
        top++;
        stack[top] = x;
    }
}

void pop() {
    int item;
    if (top == -1) {
        printf("Underflow\n");
    } else {
        item = stack[top];
        top--;
        printf("Popped: %d\n", item);
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        push();
    }

    printf("Popping elements:\n");
    while (top >= 0) {
        pop();
    }

    return 0;
}
