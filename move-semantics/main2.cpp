#include <iostream>

int main(int argc, char** argv) {
    int x = 10;
    int&& rvalueRef = std::move(x); // Using std::move to create an rvalue reference

    std::cout << "x = " << x << std::endl;           // x is now in a valid but unspecified state
    std::cout << "rvalueRef = " << rvalueRef << std::endl;

    return 0;
}