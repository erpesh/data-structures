#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node* createNode(int data) {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));

    if (!head) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    head->data = data;
    head->next = NULL;
    return head;
}

struct Node* createNodeFromArray(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }

    struct Node* newNode = createNode(arr[0]);
    struct Node* head = newNode;

    for (int i = 1; i < n; i++) {
        newNode->next = createNode(arr[i]);
        newNode = newNode->next;
    }

    return head;
}

// O(n^2)
struct Node* createNodeFromArray2(int arr[], int n) {
    struct Node* node = NULL;

    for (int i = 0; i < n; i++) {
        node = insertAtEnd(node, arr[i]);
    }

    return node;
}

struct Node* createNodeFromArray3(int arr[], int n) {
    struct Node* node = NULL;
    
    for (int i = n - 1; i >= 0; i--) {
        node = insertAtBeginning(node, arr[i]);
    }

    return node;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    return newNode;
}

void insertAtBeginningPointer(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    return head;
}

void insertAtEndPointer(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    while (*head != NULL) {
        head = &((*head)->next);
    }

    *head = newNode;
}

void printNode(struct Node** head) {
    while (*head != NULL) {
        printf("Value %d\n", (*head)->data);
        head = &((*head)->next);
    }
}