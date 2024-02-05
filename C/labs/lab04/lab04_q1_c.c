#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fp = fopen("a.txt", "r");
    if(fp == NULL) {
        printf("cannot open file");
        exit(1);
    }
    char c;
    do {
        c = fgetc(fp);
        printf("%c", c);
    } while (c!= EOF);
    // fclose(fp);
}