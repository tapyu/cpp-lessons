#include <iostream>

int main() {
    int x = 10;
    auto lambda = [x]() { // change between `&x` and `x` to see the difference
        std::cout << "x inside lambda: " << x << std::endl;
    };

    x = 20; // Changing x after lambda definition
    lambda(); // Prints 10 or 20 depending on pass pass the value or by reference

    return 0;
}
