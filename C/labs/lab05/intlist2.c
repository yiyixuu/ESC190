#include "intlist.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



// Allocate memory for an object of type IntList, initialize
// its data to equal the data in data_arr, and set its size
// Store the address of the new object in *p_IntList
void create_list_from_data(IntList **p_IntList, int *data_arr, int size) {
    *p_IntList = (IntList *) malloc(sizeof(IntList));
    (*p_IntList)->data = (int*) malloc(size * sizeof(int));

    if ((*p_IntList)->data == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    memcpy((*p_IntList)->data, data_arr, size * sizeof(int));
    (*p_IntList)->size = size;
    (*p_IntList)->capacity = size;
}


// Append new_elem to the end of list
void list_append(IntList *list, int new_elem) {
    if(list->size + 1 > list->capacity) {
        printf("reallocating\n");
        list->data = (int*) realloc(list->data, (list->capacity + 1) * sizeof(int));

        if (list->data == NULL) {
            printf("Memory reallocation failed\n");
            exit(1);
        }

        list->capacity++;

        printf("new capacity: %d\n", list->capacity);
    }
    list->data[list->size] = new_elem;
    list->size++;
}


// Insert new_elem at index in list. new_elem should now be at
// location index.
// Use the function memmove to move elements of list->data as needed
// If the capacity needs to grow, use realloc to increase the capacity by
// a factor of 2
void list_insert(IntList *list, int new_elem, int index) {
    if(list->size + 1 > list->capacity) {
        printf("reallocating\n");
        list->data = (int*) realloc(list->data, (list->capacity + 1) * sizeof(int));

        if (list->data == NULL) {
            printf("Memory reallocation failed\n");
            exit(1);
        }

        list->capacity++;

        printf("new capacity: %d\n", list->capacity);
    }

    memmove(list->data+index+1, list->data+index, (list->size-index) * sizeof(int));
    list->data[index] = new_elem;
    list->size++;
}

// Delete the element at index index

void list_delete(IntList *list, int index) {
    memmove(list->data + index, list->data + index + 1, (list->size - index) * sizeof(int));
    list->size--;

    if(list->size <= list->capacity/2) {
        printf("reallocating (shrinking)\n");
        list->data = (int*) realloc(list->data, list->size * sizeof(int));

        if (list->data == NULL) {
            printf("Memory reallocation failed\n");
            exit(1);
        }

        list->capacity = list->size;

        printf("new capacity: %d\n", list->capacity);
    }
}

// call free as appropriate to free the memory used by list
// Note: the order in which you free list->data and list
// itself is important (how?)
void list_destroy(IntList *list) {
    free(list->data);
    free(list);
}

// Return the element at index index in list
int list_get(IntList *list, int index) {
    return list->data[index];
}

void print_list(IntList *list) {
    printf("[");
    for(int i = 0; i < list->size; i++) {
        printf("%d", list_get(list, i));
        if(i != list->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}