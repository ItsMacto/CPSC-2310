#include <stdio.h>

void printSize(int arr[]) {
    printf("Inside function: %zu\n", sizeof(arr));
    arr[0] = 24;
}

int main() {
    int array[10];
    printf("Inside main: %zu\n", sizeof(array));
    printSize(array);
    printf("Arr element 0: %d \n", array[0]);
    return 0;
}
