#include <stdio.h>
#include <stdlib.h>
// #include "list/list.h"
#include "array/array.h"

int main() {
    int arr[] = {1, 2, 3, 4, 125}; 
    size_t itemSize = sizeof(arr[0]);
    size_t length = sizeof(arr) / itemSize;
    int arr2[] = {5, 6, 7, 8};

    Array array = createArrayFromRegularArray(arr, length, itemSize);
    // Array array = createArray(sizeof(int), 1);
    // int value = 1;

    // arrayAppend(&array, &value);
    // arrayAppend(&array, &value);
    // int v2 = 4;
    // arrayAppend(&array, &v2);
    // arrayAppend(&array, &value);

    printArray(&array);
    // arrayRemove(&array, 3);
    printf("\n");
    int val = 3;
    insertAtIndex(&array, &val, 1);
    printArray(&array);
    printf("\n");
    Array array2 = createArrayFromRegularArray(arr2, sizeof(arr2) / itemSize, itemSize);
    printArray(&array2);

    arrayExtend(&array, &array2);
    printf("\n");
    printArray(&array);

    free(array.items);

    return 0;
}
