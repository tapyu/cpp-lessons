#include <iostream>

int main(int argc, char** argv) {
    int i = 0; // lvalue to rvalue assignment
    
    int& lref = i;               // lvalue reference to lvalue
    const int& another_lref = 5; // lvalue reference to rvalue (unique exception here it happens)
    
    int&& rref = 5; // rvalue reference to rvalue

    std::cout << "Although rref = " << rref << " does not seem that useful, just wait until you see move semantics :)" << std::endl;
    return 0;
}