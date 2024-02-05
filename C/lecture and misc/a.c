#include <stdio.h>
#include <stdlib.h>

int main() {
    char *p = (char *) malloc(10000);
    // printf("%c\n", p[50000000]); 
    printf("%s\n", p+10000-3); // no null character at the end, will keep printing

    int ** p_p_int;
    p_p_int = (int **) malloc(2*sizeof(int *));
    int * p_int = *p_p_int;
    int my_int = *p_int; // nonsense address, segfault
}