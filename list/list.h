#ifndef LIST_H
#define LIST_H

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void printNode(struct Node** head);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
struct Node* createNodeFromArray(int arr[], int n);
#endif // LIST_H