#include <stdio.h>

int main(int argc, char** argv) {
    // char variable
    char c = 'a';
    printf("Value of char: %c\n", c);
    printf("Memory size of char: %zu bytes\n\n", sizeof(char));
    
    // float variable
    float f = 3.1416f; // put the `f` suffix
    printf("Value of float: %f\n", f);
    printf("Memory size of float: %zu bytes\n\n", sizeof(float));
    
    // double variable
    double d = 3.1416;
    printf("Value of double: %lf\n", d);
    printf("Memory size of double: %zu bytes\n\n", sizeof(double));
    
    // long double variable
    long double ld = 3.141592653589793238462643383279502884L; // put the `L` suffix
    printf("Value of long double: %Lf\n", ld);
    printf("Memory size of long double: %zu bytes\n\n", sizeof(long double));

    // signed integer variable
    signed int i = 10;
    printf("Value of signed int: %i\n", i);
    printf("Memory size of signed int: %zu bytes\n\n", sizeof(signed int));

    // signed integer variable (in octal)
    signed int octa_i = 032;
    printf("Value of signed int in octal: %o\n", octa_i); // // use %i to convert from octal to decimal
    printf("Memory size of octal int: %zu bytes\n\n", sizeof(signed int));

    // signed integer variable (in hexadecimal)
    signed int hex_i = 0x1a;
    printf("Value of signed int in hexadecimal: %x\n", hex_i); // use %i to convert from hexadecimal to decimal
    printf("Memory size of hexadecimal int: %zu bytes\n\n", sizeof(signed int));

    // unsigned integer variable
    unsigned int ui = 10u; // put the `u` suffix
    printf("Value of unsigned int: %u\n", ui);
    printf("Memory size of unsigned int: %zu bytes\n\n", sizeof(unsigned int));

    // signed short integer variable
    signed short int s = 32767; // The maximum value that can be represented in a signed short
    printf("Value of signed short int: %hi\n", s);
    printf("Memory size of signed short int: %zu bytes\n", sizeof(signed short int));
    s = s + 1; // attempting to exceed the range results in numeric overflow
    printf("Value of short after overflow: %i\n\n", s);

    // unsigned short integer variable
    unsigned short int us = 10;
    printf("Value of unsigned short int: %hu\n", us);
    printf("Memory size of unsigned short int: %zu bytes\n\n", sizeof(unsigned short int));

    // signed long integer variable
    signed long int l = 1234567890l; // put the `l` suffix
    printf("Value of signed long int: %li\n", l);
    printf("Memory size of signed long int: %zu bytes\n\n", sizeof(signed long int));

    // unsigned long integer variable
    unsigned long int ul = 1234567890ul; // put the `ul` suffix
    printf("Value of unsigned long int: %lu\n", ul);
    printf("Memory size of unsigned long int: %zu bytes\n\n", sizeof(unsigned long int));
    
    // signed long long integer variable
    signed long long int ll = 1234567890123456789ll; // put the `ll` suffix
    printf("Value of signed long long int: %lli\n", ll);
    printf("Memory size of signed long long int: %zu bytes\n\n", sizeof(signed long long int));

    // unsigned long long integer variable
    unsigned long long int ull = 1234567890123456789ull; // put the `ull` suffix
    printf("Value of unsigned long long int: %llu\n", ull);
    printf("Memory size of unsigned long long int: %zu bytes\n\n", sizeof(unsigned long long int));

    // Declare size_t variable
    size_t size = 42;
    printf("Value of size_t: %zu\n", size);
    printf("Memory size of size_t: %zu bytes\n", sizeof(size));

    return 0;
}