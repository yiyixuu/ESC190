#include <stdio.h>

void set_value(int *a) {
    *a = 10;
}
int main() {
    int a = 5;
    printf("%d\n", a);

    set_value(&a);

    printf("%d\n", a);
}

