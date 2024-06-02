#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::string source = "My source string";
    std::string destination = "My destination string";

    std::cout << "Before the copy: source string = \"" << source << "\". Its length is " << source.length() << "." << std::endl;
    std::cout << "Before the copy: destination string = \"" << destination << "\". Its length is " << destination.length() << "." << std::endl;

    destination = source; // in C++, you can do it :)

    std::cout << "After the copy: source string = \"" << source << "\". Its length is " << source.length() << "." << std::endl;
    std::cout << "After the copy: destination string = \"" << destination << "\". Its length is " << destination.length() << "." << std::endl;

    destination = destination + ". This is a new string."; // cat is easy easy, almost a Python :)

    std::cout << "After the cat: destination string = \"" << destination << "\". Its length is " << destination.length() << "." << std::endl;
}