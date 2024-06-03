#include <stdio.h>

int main() {
    int num;

    printf("scanf with %%i:\n");
    printf("Enter  42, 052, or 0x2A (either one will result in 42 in decimal): ");
    scanf("%i", &num);
    printf("printf with %%i is: %i\n", num);
    printf("printf with %%d is: %d\n", num);
    
    printf("scanf with %%d:\n");
    printf("Enter  42, 052, or 0x2A (entering 052 or 0x2A will not work correctly, only 42 will): ");
    scanf("%d", &num);
    printf("printf with %%i is: %i\n", num);
    printf("printf with %%d is: %d\n", num);
    
    return 0;
}
