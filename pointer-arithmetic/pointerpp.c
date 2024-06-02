#include <stdio.h>

int main(int argc, char** argv) {
    int i = 0;
    int *p = &i + 1; // the `1` here means: move the memory address `X` bytes forward, where `X` is the number of bytes used to storage an integer. It happens because p is an integer pointer.

    printf("The address of the integer i is %p\n", (void *)&i);
    printf("However, the pointer p was initialized with the memory address %p\n", (void *)p);
    printf("Since we didn't initialize anything at this memory, dereferencing it will probably print a random spurious values: %i\n", *p);

    return 0;
}
