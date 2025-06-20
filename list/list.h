#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../array/array.h"

typedef struct List {
    void* data;
    struct List* next;
} List;

List* createList(void* data);
List* createListFromArray(Array* array); // O(n)
List* createListFromArray2(Array* array); // O(n)
void freeList(List* head);

List* insertAtBeginning(List* head, void* data);
void insertAtBeginningPointer(List** head, void* data);

List* insertAtEnd(List* head, void* data);
void insertAtEndPointer(List** head, void* data);

void printList(List** head);

#endif // LIST_H