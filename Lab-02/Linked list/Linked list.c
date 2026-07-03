#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// List initialization
Node* createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(Node **head, int value) {
    Node *newNode = createNode(value);
    if (newNode == NULL) return;
    
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the front.\n", value);
}

void insertAtTail(Node **head, int value) {
    Node *newNode = createNode(value);
    if (newNode == NULL) return;

    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d as the first item.\n", value);
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the back.\n", value);
}

void deleteNode(Node **head, int value) {
    if (*head == NULL) {
        printf("Cannot delete from an empty list.\n");
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Successfully deleted %d.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Successfully deleted %d.\n", value);
}

// Display elements
void printList(Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("Current List: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node **head) {
    Node *current = *head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    Node *myList = NULL;

    insertAtHead(&myList, 20);
    insertAtHead(&myList, 10);
    insertAtTail(&myList, 30);
    
    printList(myList);

    deleteNode(&myList, 20);
    printList(myList);

    freeList(&myList);
    return 0;
}
