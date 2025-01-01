#include <stdio.h>
#include <stdlib.h>
// #include "list/list.h"
#include "array/array.h"

bool compareIntAsc(void* a, void* b) {
    return *(int*)a <= *(int*)b;
}

int main() {
    int arr[] = {5, 2, 6, 7, 1}; 
    size_t itemSize = sizeof(arr[0]);
    size_t length = sizeof(arr) / itemSize;

    Array array = createArrayFromRegularArray(arr, length, itemSize);

    arrayMergeSort(&array, 0, array.length - 1, compareIntAsc);
    printArray(&array);

    freeArray(&array);

    return 0;
}
