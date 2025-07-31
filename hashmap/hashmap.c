#include "hashmap.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define INITIAL_CAPACITY 8
#define LOAD_FACTOR_THRESHOLD 0.66
#define PERTURB_SHIFT 5

static unsigned long hash_func(const char* key) {
    unsigned long hash = 5381;
    int c;

    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c; // same as hash * 33 + c
    }

    return hash;
}

static size_t find_slot(HashMap* map, const char* key, unsigned long hash, bool* found) {
    size_t mask = map->capacity - 1; // Using a mask to prevent '%' usage for efficiency
    size_t i = hash & mask;
    size_t perturb = hash; // step
    *found = false;

    while (map->entries[i].key != NULL) {
        if (map->entries[i].hash == hash && strcmp(map->entries[i].key, key) == 0) {
            *found = true;
            return i;
        }
        // calculate next index using Perturbation Probing
        i = (5 * i + 1 + perturb) & mask;
        perturb >>= PERTURB_SHIFT;
    }

    return i;
}

static void resize(HashMap* map) {
    size_t old_capacity = map->capacity;
    HashEntry* old_entries = map->entries;
    void** old_values = map->values;

    size_t new_capacity = old_capacity * 2;
    map->capacity = new_capacity;
    map->entries = calloc(new_capacity, sizeof(HashEntry));
    map->values = calloc(new_capacity, sizeof(void*));
    map->size = 0;

    for (size_t i = 0; i < old_capacity; i++) {
        if (old_entries[i].key != NULL) {
            hashmap_set(map, old_entries[i].key, old_values[i]);
            free(old_entries[i].key);
        }
    }

    free(old_entries);
    free(old_values);
}

HashMap* hashmap_create() {
    HashMap* map = malloc(sizeof(HashMap));
    map->capacity = INITIAL_CAPACITY;
    map->size = 0;
    map->entries = calloc(INITIAL_CAPACITY, sizeof(HashEntry));
    map->values = calloc(INITIAL_CAPACITY, sizeof(void*));

    return map;
}

void hashmap_free(HashMap* map) {
    for (size_t i = 0; i < map->size; i++) {
        free(map->entries[i].key);
    }

    free(map->entries);
    free(map->values);
    free(map);
}

void hashmap_set(HashMap* map, const char* key, void* value) {
    if ((double)map->size / map->capacity > LOAD_FACTOR_THRESHOLD) {
        resize(map);
    }

    unsigned long hash = hash_func(key);
    bool found;
    size_t i = find_slot(map, key, hash, &found);

    if (!found) {
        map->entries[i].key = strdup(key);
        map->entries[i].hash = hash;
        map->size++;
    }

    map->values[i] = value;
}

void* hashmap_get(HashMap* map, const char* key) {
    unsigned long hash = hash_func(key);
    bool found;
    size_t i = find_slot(map, key, hash, &found);

    return found ? map->values[i] : NULL;
}

bool hashmap_delete(HashMap* map, const char* key) {
    unsigned long hash = hash_func(key);
    bool found;
    size_t i = find_slot(map, key, hash, &found);

    if (!found) return false;

    free(map->entries[i].key);
    map->entries[i].key = NULL;
    map->values[i] = NULL;
    map->size--;

    return true;
}

bool hashmap_has_key(HashMap* map, const char* key) {
    unsigned long hash = hash_func(key);
    bool found;
    find_slot(map, key, hash, &found);

    return found;
}