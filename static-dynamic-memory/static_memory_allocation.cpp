#include <iostream>

int main(int argc, char** argv) {
    // Static memory allocation for an integer variable
    int x = 10;

    // Static memory allocation for an array
    int arr[5] = {1, 2, 3, 4, 5};

    // Using the variables
    std::cout << "x = " << x << std::endl;
    std::cout << "arr[0] = " << arr[0] << ", arr[1] = " << arr[1] << std::endl;

    return 0;
}