#include <iostream>
#include <string.h>

class MyString
{
public:
    MyString() = default;
    
    MyString(const char* string)
    {
        printf("Created!\n");
        m_size = strlen(string);
        m_data = new char[m_size];
        memcpy(m_data, string, m_size);
    }

    MyString(const MyString& other)
    {
        printf("Copied!\n");
        m_size = other.m_size;
        m_data = new char[strlen(other.m_data)];
        memcpy(m_data, "copied!", m_size);
    }

    MyString(MyString&& other) noexcept
    {
        printf("Moved!\n");
        // associate `MyString("Cherno")` to m_data and m_size
        m_data = other.m_data;
        m_size = other.m_size;

        other.m_data = nullptr; // setting the original data to nullptr to, when the destroyer of `MyString("Cherno")` get called, it does not destroy the value we just stole!
        other.m_size = 0;
    }

    void print_name()
    {
        printf("%s\n", m_data);
    }

    ~MyString()
    {
        printf("Destroyed!\n");
        delete[] m_data;
    }
private:
    char* m_data;
    uint32_t m_size;
};

class Entity
{
    public:
        Entity(const MyString& name)
            : m_name(name) // without `MyString&& name`, it would call the MyString(const MyString& other) constructor! It would be a problem because we are literally allocating unnecessary memory on the heap by copying the content of `name` in a new variable.
        {
        }

        Entity(MyString&& name) // constructor overload
            : m_name(std::move(name)) // now, with this constructor whose argument is a rvalue reference, we call the `MyString(MyString&& other)` constructor
        {
        }

        void print_name()
        {
            m_name.print_name();
        }

    private:
        MyString m_name;
};

int main(int argc, char** argv)
{
    Entity entity(MyString("Cherno")); // without `Entity(MyString&& name)`, the rvalue `MyString("Cherno")` is created in this line command and would be passed by reference to `Entity(const MyString& name)`. `: m_name(name)` would call the `MyString(const MyString& other)` constructor and a new variable would've be created. That is undesirable as we would have an unecessary duplicated data. With move semantics, we can move the rvalue `MyString("Cherno")` instead of copying it!
    entity.print_name();
    return 0;
}