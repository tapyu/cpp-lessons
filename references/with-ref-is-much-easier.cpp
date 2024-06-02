#include <iostream>

void add_to_int_by_reference(int &r) {
    r+=5;
}

void add_to_int_with_pointer(int *p) {
    *p+=5;
}

void add_to_int_wrong(int r) {
    r+=5;
}

int main(int argc, char** argv) {
    int i = 0;
    int &ri = i; // reference ri
    int *pi = &i; // pointer pi

    std::cout << "Before updating by reference: variable i = " << i << ". Its reference = " << ri << "." << std::endl;

    add_to_int_by_reference(ri);

    std::cout << "After updating by reference: variable i = " << i << ". Its reference = " << ri << "." << std::endl;

    add_to_int_wrong(i); // it will not update i
    add_to_int_wrong(ri); // it will not update i (surprisingly, add_to_int_wrong accepts receiving an int ref even though its function declaration waits for a int).

    std::cout << "If the function argument does not receive a reference, passing the i variable or its reference will fail. i = " << i << ". its reference = " << ri << "." << std::endl;

    add_to_int_with_pointer(pi);

    std::cout << "Note that we can achieve the same result by using a pointer: i = " << i << ". But this task is much easier if we use a reference." << std::endl;


    return 0;
}