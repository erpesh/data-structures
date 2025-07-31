// usage.c

#include "array.h"
#include <stdio.h>

int main() {
    // Create an array of ints with initial capacity 4
    Array arr = createArray(sizeof(int), 4);

    // Append elements 1 to 5
    for (int i = 1; i <= 5; i++) {
        arrayAppend(&arr, &i);
    }

    printf("Initial array:\n");
    printArray(&arr);

    // Insert 99 at index 2
    int value = 99;
    arrayInsertAtIndex(&arr, &value, 2);
    printf("\nAfter inserting 99 at index 2:\n");
    printArray(&arr);

    // Replace element at index 0 with 100
    int replacement = 100;
    arrayReplaceAtIndex(&arr, 0, &replacement);
    printf("\nAfter replacing element at index 0 with 100:\n");
    printArray(&arr);

    // Remove element at index 1
    arrayRemove(&arr, 1);
    printf("\nAfter removing element at index 1:\n");
    printArray(&arr);

    // Reverse the array
    arrayReverse(&arr);
    printf("\nAfter reversing:\n");
    printArray(&arr);

    // Sort using quicksort
    arrayQuickSortInt(&arr);
    printf("\nAfter quicksort:\n");
    printArray(&arr);

    // Binary search for 99
    int search = 99;
    size_t index = arrayBinarySearchInt(&arr, &search);
    if (index < arr.length) {
        printf("\nFound 99 at index %zu\n", index);
    } else {
        printf("\n99 not found\n");
    }

    // Copy array
    Array copy = arrayCopy(&arr);
    printf("\nCopied array:\n");
    printArray(&copy);

    // Slice the original array to keep elements from index 1 to 3
    arraySlice(&arr, 1, 4);
    printf("\nSliced array (index 1 to 3):\n");
    printArray(&arr);

    // Extend the sliced array with the copy
    arrayExtend(&arr, &copy);
    printf("\nAfter extending sliced array with copied array:\n");
    printArray(&arr);

    // Free memory
    freeArray(&arr);
    freeArray(&copy);

    return 0;
}
