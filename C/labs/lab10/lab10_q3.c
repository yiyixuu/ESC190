#include <stdlib.h>
#include <stdio.h>


typedef struct GraphNode {
    char *data; 
    struct GraphNode *next;
} GraphNode;

int is_linked(GraphNode **adj, GraphNode *nodes, char *node1, char *node2) {
    int i_of_node1 = 0;

    GraphNode *current = nodes;
    while (current != NULL) {
        if (current->data == node1) {
            break;
        }
        i_of_node1++;
        current = current->next;
    }

    GraphNode *current_node = adj[i_of_node1];
    while (current_node != NULL) {
        if (current_node->data == node2) {
            printf("Yes\n");
            return 1;
        }
        current_node = current_node->next;
    }

    printf("No\n");
    return 0;
}
    

int main() {
    GraphNode *nodes; // linked list of all nodes in the graph
    GraphNode *adj[5]; // adjacency list of all nodes, indices correspond to their location in the nodes linked list

    GraphNode *yvr = (GraphNode *) malloc(sizeof(GraphNode));
    yvr->data = "YVR";
    GraphNode *yyz = (GraphNode *) malloc(sizeof(GraphNode));
    yyz->data = "YYZ";
    GraphNode *yul = (GraphNode *) malloc(sizeof(GraphNode));
    yul->data = "YUL";
    GraphNode *yow = (GraphNode *) malloc(sizeof(GraphNode));
    yow->data = "YOW";
    GraphNode *yyc = (GraphNode *) malloc(sizeof(GraphNode));
    yyc->data = "YYC";

    yvr->next = yyz;
    yyz->next = yul;
    yul->next = yow;
    yow->next = yyc;
    yyc->next = NULL;

    nodes = yvr;

    GraphNode *yvr_LL = (GraphNode *) malloc(sizeof(GraphNode));
    adj[0] = yvr_LL;
    yvr_LL->data = "YYZ";
    yvr_LL->next = (GraphNode *) malloc(sizeof(GraphNode));
    yvr_LL = yvr_LL->next;
    yvr_LL->data = "YUL";


    GraphNode *yyz_LL = (GraphNode *) malloc(sizeof(GraphNode));
    adj[1] = yyz_LL;
    yyz_LL->data = "YVR";
    yyz_LL->next = (GraphNode *) malloc(sizeof(GraphNode));
    yyz_LL = yyz_LL->next;
    yyz_LL->data = "YUL";
    yyz_LL->next = (GraphNode *) malloc(sizeof(GraphNode));
    yyz_LL = yyz_LL->next;
    yyz_LL->data = "YOW";


    GraphNode *yul_LL = (GraphNode *) malloc(sizeof(GraphNode));
    adj[2] = yul_LL;
    yul_LL->data = "YVR";
    yul_LL->next = (GraphNode *) malloc(sizeof(GraphNode));
    yul_LL = yul_LL->next;
    yul_LL->data = "YYZ";
    yul_LL->next = (GraphNode *) malloc(sizeof(GraphNode));
    yul_LL = yul_LL->next;
    yul_LL->data = "YOW";
    yul_LL->next = (GraphNode *) malloc(sizeof(GraphNode));
    yul_LL = yul_LL->next;
    yul_LL->data = "YYC";


    GraphNode *yow_LL = (GraphNode *) malloc(sizeof(GraphNode));
    adj[3] = yow_LL;
    yow_LL->data = "YYZ";
    yow_LL->next = (GraphNode *) malloc(sizeof(GraphNode));
    yow_LL = yow_LL->next;
    yow_LL->data = "YUL";


    GraphNode* yyc_LL = (GraphNode *) malloc(sizeof(GraphNode));
    adj[4] = yyc_LL;
    yyc_LL->data = "YUL";




    GraphNode *current = nodes;
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");


    GraphNode *current_node = nodes;
    for(int i = 0; i < 5; i++) {
        char *node_name = current_node->data;
        printf("%s: ", node_name);
        GraphNode *current = adj[i];
        while (current != NULL) {
            printf("%s ", current->data);
            current = current->next;
        }
        printf("\n");
        current_node = current_node->next;
    }
    
    is_linked(adj, nodes, "YYZ", "YOW");

}