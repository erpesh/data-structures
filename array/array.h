#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    size_t length;
    size_t capacity;
    size_t itemSize;
    void* items;
} Array;

Array createArray(size_t itemSize, size_t initCapacity);
Array createArrayFromRegularArray(void* regularArray, size_t length, size_t itemSize);
Array arrayCopy(Array* array);
void freeArray(Array* array);

// Helper functions
void increaseCapacity(Array* array, size_t increase);
void doubleCapacity(Array* array);
void decreaseCapacity(Array* array);

void* arrayAt(Array* array, size_t index);
void replaceAtIndex(Array* array, size_t index, void* item);
void arrayAppend(Array* array, void* item);
void insertAtIndex(Array* array, void* item, size_t index);
void swapTwoElements(Array* array, size_t i, size_t j);
void arrayRemove(Array* array, size_t index);
void arrayExtend(Array* self, Array* array);
void arraySlice(Array* array, size_t lo, size_t hi); // from lo (inclusive) to hi (exclusive)
void arrayReverseSlice(Array* array, size_t lo, size_t hi);
void arrayReverse(Array* array);

size_t arrayIndex(Array* array, void* item); // Returns length of array if not found
size_t arrayCount(Array* array, void* item); 

// Sorting
typedef bool (*Compare)(void*, void*);

void arrayMerge(Array* array, size_t left, size_t mid, size_t right, Compare compare);
void arrayMergeSort(Array* array, size_t left, size_t right, Compare compare);
void arrayQuickSort(Array* array);

void printArray(Array* array);

#endif // ARRAY_H