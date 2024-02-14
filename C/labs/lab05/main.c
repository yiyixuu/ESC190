#include "intlist.c"
#include <stdio.h>
#include <stdlib.h>

void print_list(IntList *list) {
    for(int i = 0; i < list->size; i++) {
        printf("%d ", list_get(list, i));
    }
    printf("\n");
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    IntList *list;
    create_list_from_data(&list, data, 5);
    print_list(list);
    return 0;
}