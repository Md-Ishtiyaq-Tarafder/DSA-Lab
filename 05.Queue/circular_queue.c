#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int count;      
    int maxSize;
} Queue;

// Queue initialization
bool initQueue(Queue *q, int capacity) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    q->maxSize = capacity;
    q->data = (int *)malloc(capacity * sizeof(int));
    if (q->data == NULL) {
        printf("Error: Memory allocation failed.\n");
        return false;
    }
    return true;
}

bool isFull(Queue *q) {
    return q->count == q->maxSize;
}

bool isEmpty(Queue *q) {
    return q->count == 0;
}

int size(Queue *q) {
    return q->count;
}

// Circular logic
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d.\n", value);
        return;
    }
    q->rear = (q->rear + 1) % q->maxSize;
    q->data[q->rear] = value;
    q->count++;
    printf("Enqueued %d. Current size: %d\n", value, size(q));
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1;
    }
    int dequeuedValue = q->data[q->front];
    q->front = (q->front + 1) % q->maxSize;
    q->count--;
    return dequeuedValue;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;
    }
    return q->data[q->front];
}

// Memory cleanup
void freeQueue(Queue *q) {
    if (q->data != NULL) {
        free(q->data);
        q->data = NULL;
    }
}

int main() {
    Queue myQueue;
    int capacity = 3; 

    if (!initQueue(&myQueue, capacity)) {
        return 1;
    }

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    
    printf("\nProcessing item: %d\n", dequeue(&myQueue)); 
    
    printf("Adding new item after a dequeue...\n");
    enqueue(&myQueue, 40); 
    
    printf("\n--- Queue Status ---\n");
    printf("Current Size: %d\n", size(&myQueue));
    printf("Front Element (Peek): %d\n", peek(&myQueue)); 
    printf("--------------------\n\n");

    freeQueue(&myQueue);
    return 0;
}
