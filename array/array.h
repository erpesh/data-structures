#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

typedef struct {
    size_t length;
    size_t capacity;
    size_t itemSize;
    void* items;
} Array;

Array createArray(size_t itemSize, size_t initCapacity);
Array createArrayFromRegularArray(void* regularArray, size_t length, size_t itemSize);
// TODO
void decreaseCapacity(Array* array);

void arrayAppend(Array* array, void* item);
void* arrayAt(Array* array, size_t index);
void swapTwoElements(Array* array, size_t i, size_t j);
void arrayRemove(Array* array, size_t index);

void printArray(Array* array);

#endif // ARRAY_H