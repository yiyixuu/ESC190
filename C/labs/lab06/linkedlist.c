#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lab06_q1_structs.h"

// append integer new_elem to linked list my_list
void LL_append(LL *my_list, int new_elem) {
    node *new = (node *) malloc(sizeof(node));
    new->data = new_elem;
    new->next = NULL;

    if(my_list->head == NULL) {
        my_list->head = new;
    } else {
        node *cur = my_list->head;
        while(cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new;
    }
    my_list->size++;
}

int validate_list_length(LL *my_list) {
    int cnt = 0;
    if (my_list->head != NULL) {
        node *cur = my_list->head;
        while(cur != NULL) {
            cnt++;
            cur = cur->next;
        }
    }

    if(my_list->size == cnt) {
        return 1;
    } else {
        return 0;
    }
}

void LL_delete(LL *my_list, int index) {
    if(index >= my_list->size || index < 0) {
        return;
    } 
    else if(index ==0) {
        node *temp = my_list->head;
        my_list->head = my_list->head->next;
        free(temp);
    } 
    else if(index == my_list->size-1) {
        node *cur = my_list->head;
        for(int i = 0; i < index-1; i++) {
            cur = cur->next;
        }
        node *temp = cur->next;
        cur->next = NULL;
        free(temp);
    } else {
        node *cur = my_list->head;
        for(int i = 0; i < index-1; i++) {
            cur = cur->next;
        }
        node *temp = cur->next;
        cur->next = cur->next->next;
        free(temp);
    }
    my_list->size--;
}

void print_LL(LL *my_list) {
    node *cur = my_list->head;
    while(cur != NULL) {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}