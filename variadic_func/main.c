#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return total;
}

int main() {
    printf("Sum of 2, 3, 4: %d\n", sum(3, 2, 3, 4));
    printf("Sum of 5, 10, 15, 20: %d\n", sum(4, 5, 10, 15, 20));

    return 0;
}
