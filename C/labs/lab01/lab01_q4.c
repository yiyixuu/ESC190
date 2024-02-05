#include <stdio.h>

void insertion_sort(int arr[], int length) {
    int i = 1;
    while(i < length) {
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;

            j -= 1;
        }
        i += 1;
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int length = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr, length);


    for(int i = 0; i < length; i++) {
        printf("%d\n", arr[i]);
    }
}