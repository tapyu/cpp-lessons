#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // Dynamic memory allocation for an integer variable
    int *x = (int*)malloc(sizeof(int));
    
    if (x == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *x = 10;

    // Using the dynamically allocated integer
    printf("x = %d\n", *x);

    // Freeing the allocated memory
    free(x);

    return 0;
}