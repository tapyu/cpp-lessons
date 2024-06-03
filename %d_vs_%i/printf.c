#include <stdio.h>

int main() {
    int decimal = 42;
    int octal = 052; // 42 in octal
    int hex = 0x2A; // 42 in hex

    printf("Testing for %%i:\n");
    printf("For the decimal variable: %i\n", decimal);
    printf("For the hex variable: %i\n", hex);
    printf("For the octal variable: %i\n", octal);
    
    printf("Testing for %%d:\n");
    printf("For the decimal variable: %d\n", decimal);
    printf("For the hex variable: %d\n", hex);
    printf("For the octal variable: %d\n", octal);
    
    return 0;
}
