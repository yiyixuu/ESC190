#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void add_to_beginning(Node **head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

int main() {
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    add_to_beginning(&head, 2);
    //print the list
    Node *current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    
    return 0;
}