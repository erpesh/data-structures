#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

Array createArray(size_t itemSize, size_t initCapacity) {
    return (Array) {
        .length = 0,
        .capacity = initCapacity,
        .itemSize = itemSize,
        .items = malloc(itemSize * initCapacity),
    };
}

Array createArrayFromRegularArray(void* regularArray, size_t length, size_t itemSize) {
    size_t arraySize = itemSize * length;

    Array array = {
        .length = length,
        .capacity = length,
        .itemSize = itemSize,
        .items = malloc(arraySize)
    };

    if (array.items == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    memcpy(array.items, regularArray, arraySize);

    return array;
}

void arrayAppend(Array* array, void* item) {
    if (array->length >= array->capacity) {
        size_t newCapacity = array->capacity * 2;

        void* newItems = realloc(array->items, array->itemSize * newCapacity);
        if (newItems == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        array->items = newItems;
        array->capacity = newCapacity;
    }

    void* target = (char*)array->items + (array->length * array->itemSize);
    memcpy(target, item, array->itemSize);

    array->length++;
}

void* arrayAt(Array* array, size_t index) {
    if (index >= array->length) {
        printf("Index out of range\n");
        exit(1);
    }
    return (char*)array->items + (index * array->itemSize);
}

void swapTwoElements(Array* array, size_t i, size_t j) {
    if (i >= array->length || j >= array->length) {
        printf("Index out of range\n");
        exit(1);
    }

    if (i == j) {
        exit(0);
    }

    void* temp = malloc(array->itemSize);

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    void* a = arrayAt(array, i);
    void* b = arrayAt(array, j);
    
    memcpy(temp, a, array->itemSize);
    memcpy(a, b, array->itemSize);
    memcpy(b, temp, array->itemSize);

    free(temp);
}

void arrayRemove(Array* array, size_t index) {
    if (index >= array->length) {
        printf("Index out of range\n");
        exit(1);
    }

    void* src = (char*)array->items + (index + 1) * array->itemSize;
    void* dest = (char*)array->items + index * array->itemSize;
    size_t bytesToMove = (array->length - index - 1) * array->itemSize;

    memmove(dest, src, bytesToMove);
    
    array->length -= 1;
}

void printArray(Array* array) {
    for (size_t i = 0; i < array->length; i++) {
        printf("element %zu - ", i);
        printf("%d\n", *(int*)arrayAt(array, i));
    }
}
