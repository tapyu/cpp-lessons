#include <stdio.h>

// Function declarations for different types
void print_int(int x, const char *label) {
    printf("%s: int: %d\n", label, x);
}

void print_double(double x, const char *label) {
    printf("%s: double: %f\n", label, x);
}

void print_string(const char *x, const char *label) {
    printf("%s: string: %s\n", label, x);
}

// Macro using _Generic to select the appropriate function
#define print(x, label) _Generic((x),               \
                                 int: print_int,    \
                                 double: print_double, \
                                 const char *: print_string)(x, label)

int main() {
    int a = 10;
    double b = 3.14;
    const char *c = "Hello, World!";
    
    print(a, "Variable a"); // Calls print_int
    print(b, "Variable b"); // Calls print_double
    print(c, "Variable c"); // Calls print_string
    
    return 0;
}
