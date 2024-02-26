#ifndef LAB06_Q1_STRUCTS_H
#define LAB06_Q1_STRUCTS_H

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
    node *head;
    int size;
} LL;

#endif // LAB06_Q1_STRUCTS_H
