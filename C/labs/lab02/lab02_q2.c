#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *strcat1(char *destination, char *source) {
    int length1 = strlen(destination);
    int length2 = strlen(source);

    for(int i = 0; i < length2; i++) {
        destination[length1 + i] = source[i];
    }

    return destination;

}

char *strcat2(char* dest, char* source) {
    while (*dest != '\0') {
        dest++;
    }

    while(*source != '\0') {
        *dest++ = *source++;
    }

    return dest;
}

int main() {
    char string1[10000] = "string 1";
    char string2[] = "string 2";

    strcat1(string1, string2);
    
    printf("%s\n", string1);
    printf("%s\n", string2);

}