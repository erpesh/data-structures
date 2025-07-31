#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    char* key;
    unsigned long hash;
} HashEntry;

typedef struct {
    size_t capacity;
    size_t size;
    HashEntry* entries;
    void** values;
} HashMap;

HashMap* hashmap_create();
void hashmap_free(HashMap* map);
void hashmap_set(HashMap* map, const char* key, void* value);
void* hashmap_get(HashMap* map, const char* key);
bool hashmap_delete(HashMap* map, const char* key);
bool hashmap_has_key(HashMap* map, const char* key);

#endif