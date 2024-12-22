#include <stdio.h>
#include <stdlib.h>
#include "list.h"

ListNode* createNode(int data) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));

    if (!head) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    head->data = data;
    head->next = NULL;
    return head;
}

ListNode* createNodeFromArray(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }

    ListNode* newNode = createNode(arr[0]);
    ListNode* head = newNode;

    for (int i = 1; i < n; i++) {
        newNode->next = createNode(arr[i]);
        newNode = newNode->next;
    }

    return head;
}

// O(n^2)
ListNode* createNodeFromArray2(int arr[], int n) {
    ListNode* node = NULL;

    for (int i = 0; i < n; i++) {
        node = insertAtEnd(node, arr[i]);
    }

    return node;
}

ListNode* createNodeFromArray3(int arr[], int n) {
    ListNode* node = NULL;
    
    for (int i = n - 1; i >= 0; i--) {
        node = insertAtBeginning(node, arr[i]);
    }

    return node;
}

ListNode* insertAtBeginning(ListNode* head, int data) {
    ListNode* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    return newNode;
}

void insertAtBeginningPointer(ListNode** head, int data) {
    ListNode* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

ListNode* insertAtEnd(ListNode* head, int data) {
    ListNode* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    ListNode* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    return head;
}

void insertAtEndPointer(ListNode** head, int data) {
    ListNode* newNode = createNode(data);
    
    while (*head != NULL) {
        head = &((*head)->next);
    }

    *head = newNode;
}

void printNode(ListNode** head) {
    while (*head != NULL) {
        printf("Value %d\n", (*head)->data);
        head = &((*head)->next);
    }
}