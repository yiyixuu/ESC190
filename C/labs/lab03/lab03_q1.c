#include <stdio.h>

void set_int1(int x) {
    x = 42;
}
void set_int2(int *p_x) {
    *p_x = 42;
}


int main() {
    int x = 41;
    printf("x is %d\n", x);
    set_int1(x);
    printf("x is %d\n", x); // didn't change x to 42 because x is a local variable in set_int1
    set_int2(&x);
    printf("x is %d\n", x); // x is changed to 42 because the value at the address of x is passed in and the value at the address is changed
}