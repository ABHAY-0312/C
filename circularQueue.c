//CIRCULAR QUEUE USING ARRAY

#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if (((rear + 1) % N) == front)
    {
        printf("QUEUE IS FULL");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("QUEUE IS UNDERFLOW"); // UNDERFLOW MEANS QUEUE IS EMPTY
    }
    else if (front == rear)
    {
        printf("Dequeued: %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Dequeued: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}
void display() {
    int i = front;
    if (front == -1 && rear == -1) {
        printf("QUEUE IS EMPTY \n");
    } else {
        printf("QUEUE IS:");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[i]);  // Print the last element
    }
}

void main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);

    display(); // Display the queue (1 2 3)

    dequeue(); // Dequeue 1
    dequeue(); // Dequeue 2
    dequeue(); // Dequeue 3

    display(); // Display the queue (empty)

    dequeue(); // This will print "QUEUE IS UNDERFLOW" because the queue is empty
}

 