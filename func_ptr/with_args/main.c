#include <stdio.h>
#include "functions.h"

int main() {
    int a = 10, b = 5;
    char op = '+';

    // Function pointer variable
    int (*fnc_ptr)(int, int);

    // Select operation based on operator
    fnc_ptr = selectOperation(op);

    // Check if operation is valid
    if (fnc_ptr != NULL) {
        // Call selected operation function
        printf("%d %c %d = %d\n", a, op, b, fnc_ptr(a, b));
    }

    return 0;
}
