#include <iostream>
#include <string.h>

class MyString
{
    public:
        // MyString() = default; // This particular constructor takes no arguments and has an empty body. Using the `default` keyword is a good practice when you want to ensure that all non-static data members are initialized to their default values. However, I want to set m_data to nullptr when it is not used so I won't use it (`default` doesn't do that)
        MyString()
            : m_data(nullptr), m_size(0) // Member Initializer List (a comma-separated list)
            {
                // m_data = nullptr;
                // m_size = 0; // // Alternatively, you could write it but the member initializer list is generally more efficient because it directly initializes members without first default-initializing them and then assigning values. Using the member initializer list is considered a best practice in C++. It ensures that member variables are initialized correctly from the beginning and can be more efficient, especially for non-trivial types.
            }
        
        MyString(int len) // constructor function overload
        {
            printf("Initialize with the int constructor.\n");
            m_size = len;
            m_data = nullptr; // point m_data to null
        }
        
        MyString(const char* string) // constructor function overload
        {
            printf("Initialize with the char* constructor.\n");
            m_size = strlen(string);
            m_data = new char[m_size]; // m_data points to the internal pointer variable of this new char array. `new` dynamically allocates memory on the heap
            memcpy(m_data, string, m_size);
        }

        MyString(const MyString& other)
        {
            printf("I copied it!");
            m_size = other.m_size;
            if (other.m_data != nullptr) {
                m_data = new char[strlen(other.m_data)];
                memcpy(m_data, other.m_data, m_size);
            }
            else {
                m_data = nullptr;
            }
        }

        int get_size()
        {
            return m_size;
        }

        char* get_str()
        {
            return m_data;
        }

        ~MyString()
        {
            if (m_data != nullptr) {
                printf("%s Destroyed!\n", m_data);
                delete[] m_data; //  delete without [] is for single objects allocated with new, while delete[] is used for arrays allocated with new[]
            }
            // delete m_size; // The m_size variable is of type uint32_t, which is not a dynamically allocated resource like the m_data pointer. It's a stack variable, and its memory management is handled automatically by the C++ runtime. 
        }
    private:
        char* m_data;
        uint32_t m_size;
};

class Entity
{
    public:
        Entity(const MyString& name, std::string greeting)
            // : m_name(name)
        {
            m_name = name;
            std::cout << greeting << std::endl;
        }

        char* get_str()
        {
            return m_name.get_str();
        }
    private:
        // Declaration: When you write `MyString m_name;` in the private section, you are ONLY declaring a member variable named m_name, but not initializing it. Member variables are only initialized within the class's constructor(s).
        MyString m_name;
};

int main(int argc, char** argv)
{
    MyString test;              // it uses the empty constructor function
    MyString test2(666);        // it uses the int len constructor function
    MyString test3("Test");     // it uses the char*   constructor function
    printf("test has m_size set to %i.\n", test.get_size());
    printf("test2 has m_size set to %i.\n", test2.get_size());
    
    Entity rich_person("My gold", "Say hello to the rich person!"); // The object of the MyString class that is initialized with the string "Test" doesn't have a variable name assigned to it. It's a temporary object created on the fly as part of the constructor argument
    Entity thief(MyString(), "Say hello to the thief!"); // `()` signifies that you're creating a temporary MyString object using the empty argument constructor
    
    // printf("my_entity's string is %s\n", my_entity.get_str());
    return 0;
}