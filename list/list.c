#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List* createNode(int data) {
    List* head = (List*)malloc(sizeof(List));

    if (!head) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    head->data = data;
    head->next = NULL;
    return head;
}

List* createNodeFromArray(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }

    List* newNode = createNode(arr[0]);
    List* head = newNode;

    for (int i = 1; i < n; i++) {
        newNode->next = createNode(arr[i]);
        newNode = newNode->next;
    }

    return head;
}

// O(n^2)
List* createNodeFromArray2(int arr[], int n) {
    List* node = NULL;

    for (int i = 0; i < n; i++) {
        node = insertAtEnd(node, arr[i]);
    }

    return node;
}

List* createNodeFromArray3(int arr[], int n) {
    List* node = NULL;
    
    for (int i = n - 1; i >= 0; i--) {
        node = insertAtBeginning(node, arr[i]);
    }

    return node;
}

List* insertAtBeginning(List* head, int data) {
    List* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    return newNode;
}

void insertAtBeginningPointer(List** head, int data) {
    List* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

List* insertAtEnd(List* head, int data) {
    List* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    List* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    return head;
}

void insertAtEndPointer(List** head, int data) {
    List* newNode = createNode(data);
    
    while (*head != NULL) {
        head = &((*head)->next);
    }

    *head = newNode;
}

void printNode(List** head) {
    while (*head != NULL) {
        printf("Value %d\n", (*head)->data);
        head = &((*head)->next);
    }
}