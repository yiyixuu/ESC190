#include <stdio.h>

int main() {
    int a = 42;
    int b;
    // char* s1 = "abcdef"; //s1 is type char*, stores address of a in abcdef
    // char c = '@';
    double d = 3.14;

    // printf("the int is %d\n", a);
    // printf("the char is %c\n", c);
    // printf("the double is %f\n", d);
    a = 34;
    int *p_a = &a; // p_a is type int*, stores address of a in p_a
                   // &a: address in memory table where a is stored

    printf("the address of a is %ld\n", p_a);
    printf("the value of a is %d\n", a); // *p_a: value stored at address p_a

    // addresses of values are referred to as pointers

    double x = 12.34;
    double *p_x = &x;

    double y = 25 + *p_x; // 25+12.34

    char *s1 = "hello!"; // * is part of the type (char*), not the variable name
    char c = *s1; // c = 'h' // * is the dereference operator, get value at given address
    
}