In `C++`, a class is a user-defined data type that encapsulates data (attributes) and functions (methods) that operate on the data. Classes are defined using the class keyword followed by the class name and a body enclosed in curly braces `{ }`.

Let us consider the following declarations in a [header file][2] (in the [source code][1], you find the actual implementation of each member function).

```cpp
class Regengine
{
public:
    virtual bool exec(const std::string &str, size_t offset, struct match &m) const = 0;
    virtual ~Regengine() {}
};
```

- Class Name (`Regengine`): Names the class and serves as a blueprint or template for creating objects.
- Access Specifiers (`public`): Determines the visibility and accessibility of class members. public members are accessible from outside the class and by derived classes.

## Member functions

Member Function Declaration (`exec`): Functions defined within the class are called member functions. They can have various access specifiers (`public`, `private`, `protected`) and may include parameters.

## Virtual and Pure Virtual Functions

Virtual functions allow overriding by derived classes. They enable polymorphism, where different classes can provide different implementations of the same function signature.

Pure Virtual Functions (`virtual bool exec(...) const = 0`): Pure virtual functions are declared with = 0 and have no implementation in the base class. They must be overridden by any derived class, making the base class abstract.

## Inheritance

`C++` supports inheritance, where one class (derived class) can inherit characteristics (methods and properties) from another class (base class). **Inheritance is specified using a colon `:` followed by the access specifier and the name of the base class**.

```cpp
class PatternList : public Regengine
{
public:
    bool exec(const std::string &str, size_t offset, struct match &m) const override;
    void add_pattern(std::unique_ptr<Regengine> pattern);
private:
    std::vector<std::unique_ptr<Regengine>> patterns;
};
```

- Derived Class (`PatternList`): Inherits from Regengine using public inheritance.
- Override (`override`): Indicates that `exec` is overriding a virtual function from the base class `Regengine`. This ensures that the derived class provides its own implementation of the virtual function.

[1]: https://gitlab.com/pdfgrep/pdfgrep/-/blob/master/src/regengine.cc?ref_type=heads
[2]: https://gitlab.com/pdfgrep/pdfgrep/-/blob/master/src/regengine.h?ref_type=heads
