#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strcmp_rec(char *string1, char *string2) {

    if(strlen(string1) != strlen(string2)) {
        return 0;
    }

    if(strlen(string1) == 1 && strlen(string2) == 1) {
        if(string1[0] == string2[0]) {
            return 1;
        } else return 0;
    }

    if(string1[0] != string2[0]) {
        return 0;
    } else {
        return my_strcmp_rec(&string1[1], &string2[1]);
    }
}

int main() {
    char *string1 = "helli";
    char *string2 = "hello";

    printf("%d\n", my_strcmp_rec(string1, string2));

}