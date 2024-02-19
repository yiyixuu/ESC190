#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void create_LL(node **p_head, int *data, int size) {
    if(size == 0) {
        *p_head = NULL;
        return;
    }

    node *cur = (node *) malloc(sizeof(node));
    cur->data = data[0];
    *p_head = cur;

    for(int i = 1; i < size; i++) {
        cur->next = (node *) malloc(sizeof(node));
        cur->next->data = data[i];
        cur = cur->next;
    }

    cur->next = NULL;
}

void print_LL(node *head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
}

void insert_LL(node **p_head, int ind, int num) {
    node *new = (node *) malloc(sizeof(node));
    new->data = num;

    if(ind == 0) {
        new->next = *p_head;
        *p_head = new;
    } else {
        node *cur = *p_head;

        for(int i = 0; i < ind - 1; i++) {
            cur = cur->next;
        }

        new->next = cur->next;
        cur->next = new;
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    node *head;
    create_LL(&head, data, size);
    print_LL(head);
    printf("\n");

    insert_LL(&head, 2, 10);
    print_LL(head);
    printf("\n");

    insert_LL(&head, 0, 20);
    print_LL(head);
    printf("\n");

    insert_LL(&head, 6, 30);
    print_LL(head);
    printf("\n");

    return 0;

}