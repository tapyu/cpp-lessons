#include <stdio.h>
#include "functions.h"

// Function implementations
void add(int a, int b) {
    printf("Addition: %d + %d = %d\n", a, b, a + b);
}

void subtract(int a, int b) {
    printf("Subtraction: %d - %d = %d\n", a, b, a - b);
}

void multiply(int a, int b) {
    printf("Multiplication: %d * %d = %d\n", a, b, a * b);
}

void divide(int a, int b) {
    if (b != 0) {
        printf("Division: %d / %d = %d\n", a, b, a / b);
    } else {
        printf("Error: Division by zero!\n");
    }
}
