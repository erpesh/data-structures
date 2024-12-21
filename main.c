#include <stdio.h>
#include <stdlib.h>
#include "list/list.h"

int main() {
    struct Node* node = createNode(2);
    // struct Node* node2 = createNode(2);
    // node->next = node2;
    insertAtBeginning(&node, 1);
    insertAtEnd(&node, 3);

    if (node != NULL) {
        // printf("Node created with data: %d\n", node->data);
        printNode(&node);
    }

    free(node); // Free the allocated memory to prevent memory leaks

    return 0;
}
