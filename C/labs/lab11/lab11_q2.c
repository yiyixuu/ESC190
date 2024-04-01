#include <stdio.h>
#include <stdlib.h>

void bfs(int adjacency_matrix[6][6], int start_node) {
    int visited[6] = {0};
    int ds[6] = {0}; // queue
    int front = 0;
    int rear = 0;

    ds[rear] = start_node;
    rear++;
    visited[start_node] = 1;

    while (front < rear) {
        int current_node = ds[front];
        printf("%d\n", current_node+1);
        front++;
        for (int i = 0; i < 6; i++) {
            if (adjacency_matrix[current_node][i] == 1 && visited[i] == 0) {
                ds[rear] = i;
                rear++;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int adjacency_matrix[6][6], int start_node) {
    int visited[6] = {0};
    int ds[6] = {0}; // stack
    int top = 0;

    ds[top] = start_node;
    top++;
    visited[start_node] = 1;

    while (top > 0) {
        int current_node = ds[top-1];
        printf("%d\n", current_node+1);
        top--;
        for (int i = 0; i < 6; i++) {
            if (adjacency_matrix[current_node][i] == 1 && visited[i] == 0) {
                ds[top] = i;
                top++;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int adjacency_matrix[6][6] = {
//       1  2  3  4  5  6
        {0, 0, 1, 0, 0, 1}, // 1
        {0, 0, 1, 0, 1, 0}, // 2
        {1, 1, 0, 1, 1, 0}, // 3
        {0, 0, 1, 0, 1, 0}, // 4
        {0, 1, 1, 1, 0, 1}, // 5
        {1, 0, 0, 0, 1, 0}  // 6
    };

    bfs(adjacency_matrix, 0);

    dfs(adjacency_matrix, 0);

}