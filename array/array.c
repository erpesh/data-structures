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

Array arrayCopy(Array* array) {
    size_t arraySize = array->length * array->itemSize;

    Array copy = {
        .length = array->length,
        .capacity = array->length, // Capacity set to length
        .itemSize = array->itemSize,
        .items = malloc(arraySize)
    };

    if (copy.items == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    memcpy(copy.items, array->items, arraySize);

    return copy;
}

void freeArray(Array* array) {
    if (array->items) {
        free(array->items);
        array->items = NULL;
    }
}

void increaseCapacity(Array* array, size_t newCapacity) {
    void* newItems = realloc(array->items, array->itemSize * newCapacity);
    if (newItems == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }

    array->items = newItems;
    array->capacity = newCapacity;
}

void doubleCapacity(Array* array) {
    increaseCapacity(array, array->capacity * 2);
}

void decreaseCapacity(Array* array) {
    if (array->length >= array->capacity / 2) {
        printf("Array's capacity shouldn't be decreased.\n");
        return;
    }

    size_t newCapacity = array->capacity / 2;

    void *newItems = realloc(array->items, array->itemSize * newCapacity);
    if (newItems == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }

    array->items = newItems;
    array->capacity = newCapacity;
}

void* arrayAt(Array* array, size_t index) {
    if (index >= array->length) {
        printf("Index out of range\n");
        printf("Length - %zu, ", array->length);
        printf("index - %zu\n", index);
        exit(1);
    }
    return (char*)array->items + (index * array->itemSize);
}

void replaceAtIndex(Array* array, size_t index, void* item) {
    void* target = arrayAt(array, index);
    memcpy(target, item, array->itemSize);
}

void arrayAppend(Array* array, void* item) {
    if (array->length >= array->capacity) {
        doubleCapacity(array);
    }

    void* target = (char*)array->items + (array->length * array->itemSize);
    memcpy(target, item, array->itemSize);

    array->length++;
}

void insertAtIndex(Array* array, void* item, size_t index) {
    if (index > array->length) {
        printf("Index out of range\n");
        exit(1);
    }

    if (array->length >= array->capacity) {
        doubleCapacity(array);
    }

    void* src = (char*)array->items + index * array->itemSize;
    void* dest = (char*)array->items + (index + 1) * array->itemSize;
    size_t bytesToMove = (array->length - index) * array->itemSize;

    // Move all elements after the index by 1 position
    memmove(dest, src, bytesToMove);

    // Insert new item
    void* target = (char*)array->items + index * array->itemSize;
    memcpy(target, item, array->itemSize);

    array->length++;
}

void swapTwoElements(Array* array, size_t i, size_t j) {
    if (i >= array->length || j >= array->length) {
        printf("Index out of range\n");
        exit(1);
    }

    if (i == j) {
        return;
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

    if (array->length < array->capacity / 2) {
        decreaseCapacity(array);
    }
}

void arrayExtend(Array* self, Array* array) {
    printf("capacity before %zu\n", self->capacity);
    if (self == NULL || array == NULL) {
        printf("Array(s) can't be NULL\n");
        exit(1);
    }

    size_t totalLength = self->length + array->length;

    if (totalLength > self->capacity) {
        size_t newCapacity = self->capacity * 2;
        if (totalLength > newCapacity) {
            newCapacity = totalLength;
        }
        increaseCapacity(self, newCapacity);
    }

    void* destination = (char*)self->items + (self->length * self->itemSize);
    memcpy(destination, array->items, array->length * array->itemSize);

    self->length = totalLength;
    printf("capacity after %zu\n", self->capacity);
}

void arraySlice(Array* array, size_t lo, size_t hi) {
    if (hi > array->length) {
        hi = array->length;
    }

    size_t newLength;
    if (lo >= hi) {
        newLength = 0;
    }
    else {
        newLength = hi - lo;
    }

    array->items = arrayAt(array, lo);
    array->length = newLength;
}

void arrayReverseSlice(Array* array, size_t lo, size_t hi) {
    // If hi out of bounds set it to the end of array
    if (hi > array->length) {
        hi = array->length;
    }

    for (size_t i = lo, j = hi - 1; i < j; i++, j--) {
        swapTwoElements(array, i, j);
    }
}

void arrayReverse(Array* array) {
    arrayReverseSlice(array, 0, array->length);
}

size_t arrayIndex(Array* array, void* item) {
    for (size_t i = 0; i < array->length; i++) {
        if (memcmp(arrayAt(array, i), item, array->itemSize) == 0) {
            return i;
        }
    } 
    return array->length;
}

size_t arrayCount(Array* array, void* item) {
    size_t count = 0;
    for (size_t i = 0; i < array->length; i++) {
        if (memcmp(arrayAt(array, i), item, array->itemSize) == 0) {
            count++;
        }
    }
    return count;
}

void arrayMerge(Array* array, size_t left, size_t mid, size_t right, Compare compare) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    Array leftArr = createArray(array->itemSize, n1);
    Array rightArr = createArray(array->itemSize, n2);

    memcpy(leftArr.items, arrayAt(array, left), n1 * array->itemSize);
    leftArr.length = n1;
    memcpy(rightArr.items, arrayAt(array, mid + 1), n2 * array->itemSize);
    rightArr.length = n2;

    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        void* leftItem = arrayAt(&leftArr, i);
        void* rightItem = arrayAt(&rightArr, j);
        if (compare(leftItem, rightItem)) {
            replaceAtIndex(array, k, arrayAt(&leftArr, i));
            i++;
        }
        else {
            replaceAtIndex(array, k, arrayAt(&rightArr, j));
            j++;
        }
        k++;
    }

    while (i < n1) {
        replaceAtIndex(array, k, arrayAt(&leftArr, i));
        i++;
        k++;
    }
    while (j < n2) {
        replaceAtIndex(array, k, arrayAt(&rightArr, j));
        j++;
        k++;
    }
    freeArray(&leftArr);
    freeArray(&rightArr);
}

void arrayMergeSort(Array* array, size_t left, size_t right, Compare compare) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;

        arrayMergeSort(array, left, mid, compare);
        arrayMergeSort(array, mid + 1, right, compare);

        arrayMerge(array, left, mid, right, compare);
    }
}


void printArray(Array* array) {
    for (size_t i = 0; i < array->length; i++) {
        printf("element %zu - ", i);
        printf("%d\n", *(int*)arrayAt(array, i));
    }
}
