#include <stdio.h>
#include "functions.h"

int main() {
    // Declaration of a function pointer
    int (*func_pntr)(int, int); // instead of `(int, int)`, you can declare something like `(int a, int b)`, but it is not usual as it is not necessary

    // Assigning the address of 'add' function to the pointer
    func_pntr = &add;

    // Calling the function through the pointer
    int result = func_pntr(3, 2);
    printf("Result for (3,2) when the function pointer points to add(): %d\n", result);

    // Reassigning the pointer to another function
    func_pntr = &subtract;

    // Calling the new function through the same pointer
    result = func_pntr(3, 2);
    printf("Result for (3,2) when the function pointer points to subtract(): %d\n", result);

    return 0;
}
