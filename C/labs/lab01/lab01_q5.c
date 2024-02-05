#include <stdio.h>

int getLength(char *str) {
    int length = 0;
    while(str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char *str = "hello";
    printf("length is %d\n", getLength(str));
}