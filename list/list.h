#ifndef LIST_H
#define LIST_H

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
struct Node* createNodeFromArray(int arr[], int n); // O(n)
struct Node* createNodeFromArray2(int arr[], int n); // O(n^2)
struct Node* createNodeFromArray3(int arr[], int n); // O(n)

struct Node* insertAtBeginning(struct Node* head, int data);
void insertAtBeginningPointer(struct Node** head, int data);

struct Node* insertAtEnd(struct Node* head, int data);
void insertAtEndPointer(struct Node** head, int data);

void printNode(struct Node** head);

#endif // LIST_H