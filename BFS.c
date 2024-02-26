#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue structure for BFS
struct Queue {
    int front, rear;
    int array[MAX_VERTICES];
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to enqueue a vertex to the queue
void enqueue(struct Queue* queue, int item) {
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
}

// Function to dequeue a vertex from the queue
int dequeue(struct Queue* queue) {
    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

// Graph structure
struct Graph {
    int numVertices;
    int** adjMatrix;
};

// Function to create a new graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++)
            graph->adjMatrix[i][j] = 0; // Initialize with 0
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int startVertex, int endVertex) {
    graph->adjMatrix[startVertex][endVertex] = 1;
    graph->adjMatrix[endVertex][startVertex] = 1; // For an undirected graph
}

// Function to perform Breadth-First Search (BFS) on the graph
void BFS(struct Graph* graph, int startVertex) {
    // Create a queue for BFS
    struct Queue* queue = createQueue();

    // Array to keep track of visited vertices
    int visited[MAX_VERTICES] = {0};

    // Enqueue the start vertex and mark it as visited
    enqueue(queue, startVertex);
    visited[startVertex] = 1;

    printf("BFS starting from vertex %d: ", startVertex);

    while (queue->front != -1) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Visit all adjacent vertices of the dequeued vertex
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                // Enqueue the adjacent vertex if it has not been visited
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
    }

    // Free the memory allocated for the queue
    free(queue);
}

// Function to free the memory allocated for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++)
        free(graph->adjMatrix[i]);
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    // Create a graph with 6 vertices
    struct Graph* graph = createGraph(6);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    // Perform BFS starting from vertex 0
    BFS(graph, 0);

    // Free the memory allocated for the graph
    freeGraph(graph);

    return 0;
}
