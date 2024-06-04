#include <stdio.h>

int main() {
    double num = 12345.6789;

    printf("Using %%f: %f\n", num);    // Fixed-point notation -> 12345.678900
    printf("Using %%F: %F\n", num);    // Fixed-point notation. Identical to `%f`, unless when `num` is `nan` or `inf` (from `math.h`). In this case, the string is printed in uppercase instead of lowercase. -> 12345.678900
    printf("Using %%e: %e\n", num);    // Scientific notation (lowercase e) -> 1.234568e+04
    printf("Using %%E: %E\n", num);    // Scientific notation (uppercase E) -> 1.234568E+04
    printf("Using %%g: %g\n", num);    // Shortest representation between %e and %f (approximates the floating part if the exponent is less than 4) -> 12345.7
    printf("Using %%G: %G\n", num);    // Shortest representation between %E and %f (approximates the floating part if the exponent is less than 4) -> 12345.7

    return 0;
}
