#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} ListNode;

ListNode* createNode(int data);
ListNode* createNodeFromArray(int arr[], int n); // O(n)
ListNode* createNodeFromArray2(int arr[], int n); // O(n^2)
ListNode* createNodeFromArray3(int arr[], int n); // O(n)

ListNode* insertAtBeginning(ListNode* head, int data);
void insertAtBeginningPointer(ListNode** head, int data);

ListNode* insertAtEnd(ListNode* head, int data);
void insertAtEndPointer(ListNode** head, int data);

void printNode(ListNode** head);

#endif // LIST_H