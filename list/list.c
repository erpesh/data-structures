#include "list.h"

List* createList(void* data) {
    List* head = (List*)malloc(sizeof(List));

    if (!head) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    head->data = data;
    head->next = NULL;
    return head;
}

List* createListFromArray(Array* array) {
    if (array->length == 0) {
        return NULL;
    }

    List* newNode = createList(arrayAt(array, 0));
    List* head = newNode;

    for (size_t i = 1; i < array->length; i++) {
        newNode->next = createList(arrayAt(array, i));
        newNode = newNode->next;
    }

    return head;
}

List* createListFromArray2(Array* array) {
    if (array->length == 0) {
        return NULL;
    }

    List* node = NULL;
    
    for (size_t i = array->length; i > 0; i--) {
        node = insertAtBeginning(node, arrayAt(array, i - 1));
    }

    return node;
}

void freeList(List* head) {
    while (head->data != NULL) {
        List* temp = head;
        head = head->next;
        free(temp);
    }
}

List* insertAtBeginning(List* head, void* data) {
    List* newNode = createList(data);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    return newNode;
}

void insertAtBeginningPointer(List** head, void* data) {
    List* newNode = createList(data);
    newNode->next = *head;
    *head = newNode;
}

List* insertAtEnd(List* head, void* data) {
    List* newNode = createList(data);

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

void insertAtEndPointer(List** head, void* data) {
    List* newNode = createList(data);
    
    while (*head != NULL) {
        head = &((*head)->next);
    }

    *head = newNode;
}

void printList(List** head) {
    while (*head != NULL) {
        printf("Value %d\n", *(int*)(*head)->data);
        head = &((*head)->next);
    }
}