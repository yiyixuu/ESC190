#include <stdlib.h>


typedef struct node{
    char *data;
    struct node *next;
} node;

typedef struct GraphNode {
    char *data; 
    node *head;
    struct GraphNode *next;
} GraphNode;

void made_graph(GraphNode **head) {
    
}
