#include <stdio.h> // that shit here is from C, but we can use it in C++ without any problem

int main(int argc, char** argv) {
    int i = 0;

    int *pi = &i;
    int &ri = i;

    *pi += 1; // update i by 1
    ri += 1; // update i by 1

    printf("%i\n", i);

    return 0;
}