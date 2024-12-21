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

void printNode(struct Node** head) {
    struct Node** pointer = head;

    while (*pointer != NULL) {
        printf("Value %d\n", (*pointer)->data);
        pointer = &((*pointer)->next);
    }

}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node** pointer = head;
    
    while (*pointer != NULL) {
        pointer = &((*pointer)->next);
    }

    *pointer = newNode;
}

