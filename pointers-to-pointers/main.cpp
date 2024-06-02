#include <iostream>

int main(int argc, char** argv) {
    int x = 42;
    int *ptr1 = &x;         // Pointer to int
    int **ptr2 = &ptr1;     // Pointer to pointer to int (double pointer)

    // Accessing and modifying the value through ptr1
    std::cout << "Accessing the value of x through ptr1: " << *ptr1 << std::endl;

    // Accessing and modifying the value through ptr2
    **ptr2 = 100;           // Modify the value of x through ptr2

    std::cout << "Accessing the value of x through ptr1 after modification using ptr2: " << *ptr1 << std::endl;

    return 0;
}
