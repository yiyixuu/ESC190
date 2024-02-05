int linear_search(int *a, int sz, int elem) {
    for(int i = 0; i < sz; i++) {
        if(a[i] == elem) {
            return i;
        }
    }
    return -1;
}

void reverse_arr(int *arr, int sz) {
    int temp;
    for(int i = 0; i < sz/2; i++) {
        temp = arr[i];
        arr[i] = arr[sz-1-i];
        arr[sz-1-i] = temp;
    }
}