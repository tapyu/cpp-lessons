#include <stdio.h>

int main(int argc, char** argv) {
    char my_string[] = "Hello";
    char *ptr = my_string; // array decay: pass the address of the first `char` element in the `my_string` char array

    while (*ptr != '\0') {
        printf("%c\n", *ptr);
        printf("Before the pointer arithmetic: the stored value (i.e., the memory address) of ptr is %p\n", (void*) ptr);
        ptr++; // pointer arithmetic: go to the next memory address in the char array (i.e., string)
        printf("After the pointer arithmetic: the stored value (i.e., the memory address) of ptr is %p\n", (void*) ptr);
    }

    return 0;
}