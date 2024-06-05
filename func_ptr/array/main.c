#include <stdio.h>
#include "functions.h"

int main() {
    // Array of function pointers
    void (*operations[4])(int, int) = {add, subtract, multiply, divide};

    int choice, a, b;
    
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Choose an operation: \n");
    printf("0: Add\n");
    printf("1: Subtract\n");
    printf("2: Multiply\n");
    printf("3: Divide\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice >= 0 && choice < 4) {
        // Call the chosen operation function using the function pointer
        operations[choice](a, b);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
