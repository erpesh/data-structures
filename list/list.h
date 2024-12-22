#ifndef LIST_H
#define LIST_H

typedef struct List {
    int data;
    struct List* next;
} List;

List* createNode(int data);
List* createNodeFromArray(int arr[], int n); // O(n)
List* createNodeFromArray2(int arr[], int n); // O(n^2)
List* createNodeFromArray3(int arr[], int n); // O(n)

List* insertAtBeginning(List* head, int data);
void insertAtBeginningPointer(List** head, int data);

List* insertAtEnd(List* head, int data);
void insertAtEndPointer(List** head, int data);

void printNode(List** head);

#endif // LIST_H