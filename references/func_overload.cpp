#include <iostream>

void print_name(std::string&& name) {
    std::cout << "It prints from the rvalue input argument! " << name << std::endl;
}

void print_name(const std::string& name) { // function overload
    std::cout << "It prints from the lvalue input argument! " << name << std::endl;
}

int main(int argc, char** argv) {
    std::string name = "Mike";
    std::string second_name = " Smith";
    std::string full_name = name + second_name;

    print_name(name + second_name); // I am passing an rvalue as input argument
    print_name(full_name);         //  I am passing an lvalue as input argument
}