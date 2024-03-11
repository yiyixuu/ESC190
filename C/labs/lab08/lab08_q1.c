// Q3
// include necessary libraries
#include <stdlib.h>
#include <stdio.h>

typedef struct CircularQueue {
    int *arr;
    int start;
    int end;
    int size;
} CircularQueue;

void init(CircularQueue *q, int size) {
    q->arr = (int *)malloc(size * sizeof(int));
    q->size = size;
    q->start = 0;
    q->end = -1;
}

void enqueue(CircularQueue *q, int item) {
    if(q->end == q->size-1) {
        q->arr[0] = item;
        q->end = 0;
    } else {
        q->arr[++q->end] = item;
        // q->end++;
    }

    
}

int dequeue(CircularQueue *q) {
    int ret_val = q->arr[q->start];
    q->arr[q->start] = (int) NULL;

    if(q->start == q->size-1) {
        q->start = 0;
    } else {
        q->start++;
    }

    return ret_val;
}

// void printqueue(CircularQueue *q) {
//     printf("index\t");
//     for(int i = 0; i < q->size; i++) {
//         printf("%d", i);
//         if(i < q->size) {
//             printf("\t");
//         } else {
//             printf("\n");
//         }
//     }
//     printf("     \t");
//     for(int i = 0; i < q->size; i++) {
//         if(q->arr[i] == NULL) {
//             printf(" ");
//         } else {
//             printf("%d", q->arr[i]);
//         }

//         if(i < q->size) {
//             printf("\t");
//         } else {
//             printf("\n");
//         }
//     }

//     printf("Begin at index: %d\n", q->start);
//     printf("End at index: %d\n", q->end);
// }

void printQueue(CircularQueue *q) {
    // just print the data array
    for(int i = 0; i < q->size; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
    // print start and end
    printf("Start: %d\n", q->start);
    printf("End: %d\n", q->end);
}

int main() {
    CircularQueue q;
    init(&q, 5);
    printQueue(&q);
    enqueue(&q, 1);
    printQueue(&q);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    printQueue(&q);
    dequeue(&q);
    printQueue(&q);
    enqueue(&q, 6);
    printQueue(&q);
    return 0;
}