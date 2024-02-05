#include <stdlib.h>
#include <stdio.h>

int main() {
    int *block_int = (int *)malloc(sizeof(int) * 150);
    block_int[7] = 42;

    printf("%d", block_int[7]);
}