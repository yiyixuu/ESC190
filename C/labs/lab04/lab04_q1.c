#include <stdio.h>
#include <stdlib.h>

int main() {
    char *c = (char *) malloc(10*sizeof(char));

    printf("%c\n", c[1000000000]);
}