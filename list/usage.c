#include <stdio.h>
#include <stdlib.h>
#include "../list/list.h"
#include "../array/array.h"

int main() {
    // Create raw int array
    int raw[] = {10, 20, 30, 40, 50};
    size_t len = sizeof(raw) / sizeof(raw[0]);

    // Wrap in Array struct
    Array array = createArrayFromRegularArray(raw, len, sizeof(int));

    // Create list from array
    List* list = createListFromArray(&array);
    printf("List from array:\n");
    printList(&list);

    // Insert at beginning and end
    int val1 = 5, val2 = 60;
    list = insertAtBeginning(list, &val1);
    list = insertAtEnd(list, &val2);

    printf("\nAfter inserting at beginning and end:\n");
    printList(&list);

    // Pointer-based insertions
    int val3 = 1, val4 = 99;
    insertAtBeginningPointer(&list, &val3);
    insertAtEndPointer(&list, &val4);

    printf("\nAfter pointer-based insertions:\n");
    printList(&list);

    // Cleanup
    freeList(list);
    freeArray(&array);

    return 0;
}
