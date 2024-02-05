#include <stdio.h>

int main() {

    // int a = 5;
    int b; //not initialized but declared

    // double, char, int*, char*
    // int* stores address of int
    // char* stores address of char

    // printf("Hello, World!\n");

    char* s1 = "hi!"; // puts "hi" followed by "\0" in memory 
                      // stores address of "h" in s1
    printf("%s\n", s1); // %s: string
    // %d: integer (d stands for decimal)
    printf("%ld\n", s1); // %ld: long decimal (another type of integer, stores more data than the normal integer)

    printf("the string is %s, stored at %ld\n", s1, s1);


    int a = 43;
    printf("the integer is %d\n", a);
    // printf("the integer is %s\n", a); // segmentation fault, going to memory address 43 and trying to print it as a string

    return 0;
}
