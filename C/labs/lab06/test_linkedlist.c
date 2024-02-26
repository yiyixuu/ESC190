#include "linkedlist.c"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    LL my_list;
    my_list.head = NULL;
    my_list.size = 0;

    LL_append(&my_list, 5);
    LL_append(&my_list, 10);
    LL_append(&my_list, 15);
    LL_append(&my_list, 20);
    LL_append(&my_list, 25);

    print_LL(&my_list);
    printf("\n");


    LL_delete(&my_list, 0);
    // printf("size :%d\n", my_list.size);
    print_LL(&my_list);

    printf("%d\n", validate_list_length(&my_list));
    my_list.size = 20;
    printf("%d\n", validate_list_length(&my_list));
}
