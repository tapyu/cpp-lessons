#include <stdio.h>
#include <stdarg.h>

// Variadic function without a fixed argument before the ellipsis
void print_all_args(const char *format, ...) {
    va_list args;            // declares args
    va_start(args, format);  // defines args

    const char *p = format; // just to avoid changing `format` (a good practice)
    while (*p != '\0') {
        if (*p == 'd') {
            int i = va_arg(args, int);
            printf("%d ", i);
        } else if (*p == 'c') {
            int c = va_arg(args, int); // char is promoted to int when passed through ‘...’
            printf("%c ", c); // `%c` makes `c` be printed as the char it is
        } else if (*p == 'f') {
            double d = va_arg(args, double);
            printf("%f ", d);
        } else if (*p == 'A') {
            int* arr = va_arg(args, int*);
            int size = va_arg(args, int);
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
        }
        p++;
    }

    va_end(args);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4};

    // First argument acts as the format string
    print_all_args("dcAdf", 42, 'a', arr, sizeof(arr) / sizeof(arr[0]), 3.14);
    print_all_args("fdc", 2.71, 100, 'z');

    return 0;
}
