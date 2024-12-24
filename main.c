#include <stdio.h>
#include <stdlib.h>
// #include "list/list.h"
#include "array/array.h"

int main() {
    int arr[] = {1, 2, 3, 4, 125}; 
    size_t itemSize = sizeof(arr[0]);
    size_t length = sizeof(arr) / itemSize;

    Array array = createArrayFromRegularArray(arr, length, itemSize);
    // Array array = createArray(sizeof(int), 1);
    // int value = 1;

    // arrayAppend(&array, &value);
    // arrayAppend(&array, &value);
    // int v2 = 4;
    // arrayAppend(&array, &v2);
    // arrayAppend(&array, &value);

    printArray(&array);
    arrayRemove(&array, 3);
    printf("\n");
    printArray(&array);

    printf("\nindex 2 - %d\n", *(int*)arrayAt(&array, 2));
    free(array.items);

    return 0;
}
