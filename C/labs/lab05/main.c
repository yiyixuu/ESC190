#include "intlist.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int data[] = {1, 2, 3, 4, 5};
    IntList *list;
    create_list_from_data(&list, data, 5);
    print_list(list);
    return 0;
}