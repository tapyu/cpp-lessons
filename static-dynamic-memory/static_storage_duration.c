#include <stdio.h>

int globalVar = 42; // Static storage duration

void check() {
    printf("Does the global variable really global? globalVar = %i\n", globalVar);
}

int main(int argc, char** argv) {
    static int localVar = 24; // Static storage duration within a function

    printf("Global variable: %d\n", globalVar);
    printf("Local static variable: %d\n", localVar);
    check();

    return 0;
}