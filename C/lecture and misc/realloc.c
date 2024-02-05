// realloc is a way to resize a block of memory
// cannot do with array
// char *str = (char *)malloc(100*sizeof(char));
// str = (char *)realloc(str, 200*sizeof(char)); // args are pointer to block of memory and new size
// malloc and realloc might not be able to find enough memory, check using 
/* 
if(block == NULL) {
    exit(1); // exit terminates program, sents 1 to os
} 
*/

#include <stdlib.h>
#include <stdio.h>

void create_string(char **str, int sz) {
    *str = (char *)malloc(sz*sizeof(char));
    if(*str == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void safer_strcat(char **p_str1, char *str2) { //str1 must be allocated with malloc in main
    // need space at *p_str1 to hold both str1 and str2
    // need strlen(*p_str1) + strlen(str2) + 1 for the \0

    *p_str1 = (char *)realloc(*p_str1, strlen(*p_str1) + strlen(str2) + 1);
    if(*p_str1 == NULL) {
        printf("womp womp realloc failed\n");
        exit(1);
    }

    strcat(*p_str1, str2);
}

int main() {
    char *str = (char *)malloc(100*sizeof(char));
    str = (char *)realloc(str, 200*sizeof(char));
    if(str == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }


// error checking not necessary for in class practice, but should be necessary in real code


// pointers :: units in physics..?

    char *str = 0;
    create_string(&str, 100); // &str is of type char **, so create_string is void create_string(char **, int)



    // strcat concatenates two strings, assuming first string has enough space to fit the second one
    // c does not check
    char *str1 = (char *)malloc(4*sizeof(char));
    str1[0] = 'e';
    str1[1] = 'n';
    str1[2] = 'g';
    str1[3] = '\0';
    char *str2 = "sci";
    safer_strcat(&str1, str2);
    printf("%s\n", str1);
}