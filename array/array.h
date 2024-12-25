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
Array arrayCopy(Array* array);

// Helper functions
// TODO: possibly unite increase and decrease capacity
void increaseCapacity(Array* array, size_t increase);
void doubleCapacity(Array* array);
void decreaseCapacity(Array* array);

void* arrayAt(Array* array, size_t index);

void arrayAppend(Array* array, void* item);
void insertAtIndex(Array* array, void* item, size_t index);
void swapTwoElements(Array* array, size_t i, size_t j);
void arrayRemove(Array* array, size_t index);
void arrayExtend(Array* self, Array* array);
void arraySlice(Array* array, size_t lo, size_t hi); // TODO
void arrayReverseSlice(Array* array, size_t lo, size_t hi);
void arrayReverse(Array* array);

void printArray(Array* array);

#endif // ARRAY_H