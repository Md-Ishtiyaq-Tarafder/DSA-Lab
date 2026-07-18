#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *items;
    int top;
    int capacity;
} Stack;

// 1. Initialize the stack and allocate memory dynamically
bool initStack(Stack *s, int totalCapacity) {
    s->top = -1;
    s->capacity = totalCapacity;
    s->items = (int *)malloc(s->capacity * sizeof(int));
    if (s->items == NULL) {
        printf("Memory allocation failed!\n");
        return false;
    }
    return true;
}

// 2. To check if the stack is full
bool isFull(Stack *s) {
    return s->top == s->capacity - 1; 
}

// 3. To check if the stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// 4. To count the total number of items currently inside the stack
int size(Stack *s) {
    return s->top + 1;
}

// 5. To insert element on the top of the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d.\n", value);
        return;
    }
    s->top++;
    s->items[s->top] = value;
    printf("Pushed %d onto the stack. Current size: %d\n", value, size(s));
}

// 6. To remove element from the top of the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1; 
    }
    int poppedValue = s->items[s->top];
    s->top--;
    return poppedValue;
}

// 7. To display the top element of stack without removing it
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1;
    }
    return s->items[s->top];
}

// 8. To free the dynamically allocated memory
void freeStack(Stack *s) {
    if (s->items != NULL) {
        free(s->items);
        s->items = NULL;
    }
}

int main() {
    Stack myStack;
    int maxCapacity = 5;

    if (!initStack(&myStack, maxCapacity)) {
        return 1;
    }

    printf("Initial stack size: %d\n", size(&myStack));

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    
    printf("\n--- Stack Status ---\n");
    printf("Current Size: %d\n", size(&myStack));
    printf("Top Element: %d\n", peek(&myStack));
    printf("--------------------\n\n");

    printf("Popped element: %d\n", pop(&myStack));
    printf("Size after pop: %d\n", size(&myStack));

    freeStack(&myStack);
    return 0;
}
