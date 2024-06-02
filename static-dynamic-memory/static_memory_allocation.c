#include <stdio.h>

int main(int argc, char** argv) {
    // Static memory allocation for an integer variable
    int x = 10;

    // Static memory allocation for an array
    int arr[5] = {1, 2, 3, 4, 5};

    // Using the variables
    printf("x = %d\n", x);
    printf("arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);

    return 0;
}