#include <iostream>

class MyClass
{
private:
    int *my_int;
public:
    MyClass(int i);
    ~MyClass();
    void print_my_int();
    static void greeting();
};

MyClass::MyClass(int i)
{
    my_int = new int(i); // Allocate memory for my_int and initialize it with i
}

MyClass::~MyClass()
{
    delete my_int;
}

void MyClass::print_my_int()
{
    std::cout << "My stored string in my object is " << *my_int << std::endl;
}

void MyClass::greeting()
{
    std::cout << "Welcome to the class `MyClass`! Let us instantiate an object from this class." << std::endl;
}


int main(int argc, char** argv)
{
    MyClass::greeting();
    MyClass my_object(5);
    my_object.print_my_int();

    return 0;
}