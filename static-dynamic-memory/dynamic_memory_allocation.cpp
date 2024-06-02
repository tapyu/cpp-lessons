#include <iostream>

int main(int argc, char** argv) {
    // Dynamic memory allocation for an integer variable
    int *x = new int; // you want to allocate for an integer variable with an initial value, use `int *x = new int(5)` instead
    
    if (x == nullptr) {
        // Memory allocation failed
        std::cerr << "Memory allocation failed!" << std::endl;
        return 1;
    }

    // Memory allocation was successful
    *x = 42;
    // Using the dynamically allocated integer
    std::cout << "x = " << *x << std::endl;
    delete x;  // Don't forget to free the allocated memory

    return 0;
}