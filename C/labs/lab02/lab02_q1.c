#include <stdio.h>
#include <stdlib.h>

void f(char **string, int *length) {
    scanf("%d\n", length);

    *string = (char*)malloc((*length + 1) * sizeof(char));

    for(int i = 0; i < *length; i++) {
        scanf(" %c\n", &((*string)[i]));
    }

    (*string)[*length] = '\0';
}

int main() {
    char* string = NULL;
    int length;

    f(&string, &length);

    printf("User entered string: %s\n", string);

    free(string);

}