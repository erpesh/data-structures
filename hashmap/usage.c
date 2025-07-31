#include "hashmap.h"
#include "../array/array.h"
#include "../array/array.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple custom struct
typedef struct {
    char name[20];
    int age;
} Person;

int main() {
    // Create hashmap
    HashMap* map = hashmap_create();

    // --- Store int array as value ---
    Array* scores = malloc(sizeof(Array));
    *scores = createArray(sizeof(int), 4);

    for (int i = 0; i < 5; i++) {
        int score = i * 10;
        arrayAppend(scores, &score);
    }

    hashmap_set(map, "scores", scores);

    // --- Store string as value ---
    char* greeting = strdup("Hello, World!");
    hashmap_set(map, "greeting", greeting);

    // --- Store struct as value ---
    Person* person = malloc(sizeof(Person));
    strcpy(person->name, "Alice");
    person->age = 30;
    hashmap_set(map, "person", person);

    // --- Retrieve and use values ---
    Array* retrievedScores = (Array*) hashmap_get(map, "scores");
    printf("Scores: ");
    for (size_t i = 0; i < retrievedScores->length; i++) {
        printf("%d ", *(int*)arrayAt(retrievedScores, i));
    }
    printf("\n");

    char* retrievedGreeting = (char*) hashmap_get(map, "greeting");
    printf("Greeting: %s\n", retrievedGreeting);

    Person* retrievedPerson = (Person*) hashmap_get(map, "person");
    printf("Person: %s (%d years old)\n", retrievedPerson->name, retrievedPerson->age);

    // --- Clean up ---
    freeArray(retrievedScores);
    free(scores);
    free(greeting);
    free(person);
    hashmap_free(map);

    return 0;
}
