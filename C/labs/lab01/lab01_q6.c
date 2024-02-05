#include <stdio.h>

void seq_replace(int *arr1, unsigned arr1_sz, int *arr2, unsigned long arr2_sz) {
    for(int i = 0; i < arr1_sz - arr2_sz + 1; i++) {
        int equal = 1; // 1 is true, 0 is false, assume theyre equal to start
        for(int j = 0; j < arr2_sz; j++) {
            if(arr1[i+j] != arr2[j]) {
                equal = 0; // sub arrays are not equal
                break;
            }
        }
        if(equal == 1) { // if the sub arrays are equal
            for(int j = 0; j < arr2_sz; j++) {
                arr1[i+j] = 0;
            }
        }
    }
}

int main() {
    int a[] = {5, 6, 7, 8, 6, 7};
    int b[] = {6, 7};
    seq_replace(a, 6, b, 2);

    for(int i = 0; i < 6; i++) {
        printf("%d\n", a[i]);
    }
}