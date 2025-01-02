#include <stdio.h>
#include <stdlib.h>
// #include "list/list.h"
#include "array/array.h"

int main() {
    int arr[] = {5, 2, 6, 7, 1}; 
    size_t itemSize = sizeof(arr[0]);
    size_t length = sizeof(arr) / itemSize;

    Array array = createArrayFromRegularArray(arr, length, itemSize);

    arrayMergeSortInt(&array);
    printArray(&array);

    int v = 7;
    size_t ind = arrayBinarySearchInt(&array, &v);
    printf("ind - %zu\n", ind);

    freeArray(&array);

    return 0;
}
