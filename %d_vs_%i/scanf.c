#include <stdio.h>

int main() {
    int num;

    printf("Testing for %%i:\n");
    printf("Enter  42, 052, or 0x2A (either one will result in 42 in decimal): ");
    scanf("%i", &num);
    printf("The number (in decimal) using %%i is: %i\n", num);
    printf("The number (in decimal) using %%d is: %d\n", num);
    
    printf("Testing for %%d:\n");
    printf("Enter  42, 052, or 0x2A (entering 052 or 0x2A will not work correctly, only 42 will): ");
    scanf("%d", &num);
    printf("The number (in decimal) using %%i is: %i\n", num);
    printf("The number (in decimal) using %%d is: %d\n", num);
    
    return 0;
}
