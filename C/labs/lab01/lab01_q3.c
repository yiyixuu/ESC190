#include <stdio.h>

void change_array(char arr[]) {
    arr[0] = 'a';
}

int main() {
    char arr[100];

    change_array(arr);
    printf("%c\n", arr[0]);
}

