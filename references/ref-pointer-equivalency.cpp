#include <iostream>

void wrong_add_to_int(int i) {
    i += 5;
}

void right_add_to_int_reference(int &r) {
    r += 5;
}

void right_add_to_int_pointer(int *p) {
    *p += 5;
}

int main(int argc, char** argv) {
    int i = 0;
    int &ri = i;
    int *pi = &i;

    wrong_add_to_int(i);
    std::cout << "You cannot update i by passing it to a func. i = " << i << std::endl;

    right_add_to_int_reference(ri);
    std::cout << "But you can update is by passing by reference. i = " << i << std::endl;

    right_add_to_int_pointer(pi);
    std::cout << "You can also achieve an equivalent result by using a pointer. i = " << i << std::endl;
    return 0;
}