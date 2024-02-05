#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int my_atoi(char *string) {
    int len = strlen(string);
    int res = 0;

    for(int i = 0; i < len; i++) {
        if(isdigit(string[i]) == 0) {
            return res;
        }
        res = res * 10 + string[i] - '0';

    }

    return res;
}

int main() {
    int val;
    char *string = "1234i";

    val = my_atoi(string);
    
    printf("%d", val);
}