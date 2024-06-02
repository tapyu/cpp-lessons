#include <iostream>

int main(int argc, char** argv) {
    int i = 0;
    int& ref = i;
    ref = 5;

    std::cout << "i = " << i << std::endl;
    return 0;
}