#include <stdio.h>


double sum(double x, double y) {
    return x + y;
}

void change_a(int *p_a) {
    *p_a = 44;
}


int main() {
    int aa = 43;


    int *p_aa = &aa; // p_aa is type int*, stores address of aa in p_aa
    change_a(p_aa); // changes the value at adress p_aa to 43
    // aa is now 44

    printf("%d\n", aa);

    double s = sum(1.2, 3.4);

    printf("%f\n", s);

    char *str = "hello";
    printf("%s is stored at %ld\n", str, (long int) str);

    int arr[] = {5, 6, 7};

    printf("%d\n", arr[0]);
    printf("%ld\n", arr); // arr is the address of the first element of the array
    printf("%d\n", *arr); // same as arr[0] same as *(arr+0)


    char *str2 = "hello";
    printf("%c\n", str2[0]); // prints h
    printf("%c\n", *str2); // prints h
    printf("%c\n", *(str2+0)); // prints h

}