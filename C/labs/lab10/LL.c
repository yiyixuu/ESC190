// syntax from C
// functions, conditionals, loops
// structs, pointers
// #define, #if/#endif, #include


// Linked lists
// A way to store lists without pre-allocating blocks of memory

// // [2, , ,1, , , ]
//            X
//           ^\
//          /  |
// A->B->C  D->E->F

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char *data;
    struct node *next;
} node;
//      10
//     n10
//    /   \
//   1    5
// head   n2

// head->A->B
void create_LL(node **p_head, char *data, int size)
{
    if(size == 0){
        *p_head = NULL;
        return;
    }
    node *cur = (node *)malloc(sizeof(node));
    cur->data = data[0];
    *p_head = cur;
    for(int i = 1; i < size; i++){
        cur->next = (node *)malloc(sizeof(node));
        cur->next->data = data[i];
        cur = cur->next;
    }
    cur->next = NULL;
}
 


// typedef struct node{
//     int data;
//     struct node *next;
// } node; 
void print_LL(node *head)
{
    // head is always the (address of) node we're currently printing
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
}

void insert_LL(node **p_head, int ind, int num)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = num;
    // insert num at index ind
    if(ind == 0){
        new->next = *p_head;
        *p_head = new;
    }
    else{
        // go through the linked list until node i-1
        // insert the new node after i-1
        node *cur = *p_head;
        for(int i = 0; i < ind - 1; i++){
            cur = cur->next;
        }
        new->next = cur->next;
        cur->next = new;
    }

}