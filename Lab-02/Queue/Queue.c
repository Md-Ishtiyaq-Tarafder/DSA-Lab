#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int maxSize;
} Queue;

// Initialize the queue and allocate memory dynamically
bool initQueue(Queue *q, int capacity) {
    q->front = 0;
    q->rear = -1;
    q->maxSize = capacity;
    q->data = (int *)malloc(capacity * sizeof(int));
    if (q->data == NULL) {
        printf("Error: Memory allocation failed.\n");
        return false;
    }
    return true;
}

// Check if the queue is full
bool isFull(Queue *q) {
    return q->rear == q->maxSize - 1;
}

// Checks if the queue is empty
bool isEmpty(Queue *q) {
    return q->front > q->rear;
}

// Returns the total number of elements currently stored in the queue
int size(Queue *q) {
    if (isEmpty(q)) {
        return 0;
    }
    return (q->rear - q->front) + 1;
}

// Adds a new element to the queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d.\n", value);
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
    printf("Enqueued %d. Current size: %d\n", value, size(q));
}

// Removes and returns the first (front) element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1;
    }
    int dequeuedValue = q->data[q->front];
    q->front++;
    return dequeuedValue;
}

// Returns the first element in the queue
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;
    }
    return q->data[q->front];
}

// Free dynamically allocated memory
void freeQueue(Queue *q) {
    if (q->data != NULL) {
        free(q->data);
        q->data = NULL;
    }
}

int main() {
    Queue myQueue;
    int capacity = 5;

    if (!initQueue(&myQueue, capacity)) {
        return 1;
    }

    printf("Is queue empty? %s\n", isEmpty(&myQueue) ? "Yes" : "No");

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    
    printf("\n--- Queue Status ---\n");
    printf("Current Size: %d\n", size(&myQueue));
    printf("Front Element (Peek): %d\n", peek(&myQueue));
    printf("--------------------\n\n");

    printf("Dequeued element: %d\n", dequeue(&myQueue));
    printf("Size after dequeue: %d\n", size(&myQueue));
    printf("New Front Element: %d\n", peek(&myQueue));

    freeQueue(&myQueue);
    return 0;
}
