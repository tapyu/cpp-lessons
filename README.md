In `C++`, a class is a user-defined data type that encapsulates data (attributes) and functions (methods) that operate on the data. Classes are defined using the `class` keyword followed by the class name and a body enclosed in curly braces `{ }`.

For instance:

```cpp
// example.h

#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <iostream>
#include <string>

class Base {
public:
    // Declaration of a non-virtual member function `greeting()`
    // This function does not override or get overridden by any derived class.
    void greeting();  

    // Declaration of a virtual member function `show()`
    // This function is constant and does not modify the state of the object.
    // It is expected to be overridden by derived classes.
    virtual void show() const;  

    // Declaration of a virtual member function `display()`
    // This function can modify the state of the object and is expected to be overridden by derived classes.
    virtual void display();     

    // Virtual destructor
    // Ensures that the destructor of the derived class is called when a base class pointer
    // to a derived class object is deleted. This is important for proper resource cleanup.
    virtual ~Base() = default;  

private:
    // Private data member
    // This member is not accessible directly outside the class and is only
    // used internally within the Base class.
    int base = 0;               
};

#endif // EXAMPLE_H
```

```cpp
// example.cpp
#include "example.h"

// Definition of Base::show()
void Base::show() const {
    std::cout << "From Base.show() const (expected to be overridden as it contains `override`)" << std::endl;
    // base++; // you cannot modify it as show() is `const` (you can you can acess it, though)
}

// Definition of Base::display()
void Base::display() {
    std::cout << "From Base.display() (expected to be overridden as it contains `override`)" << std::endl;
    base++; // you can modify it as `display()` is not `const`
}

void Base::greeting() {
    std::cout << "From Base.greeting(): " << base << std::endl;
    base++; // you can modify it as `greeting()` is not `const`
}
```
```cpp
// main.cpp
#include "example.h"

int main() {
    Base b;
    b.greeting();
    b.display();
    b.greeting();
    b.show();
    return 0;
}
```

- Access Specifiers (`public`): Determines the visibility and accessibility of class members. public members are accessible from outside the class and by derived classes. You can have various access specifiers (`public`, `private`, `protected`).

## Member functions and `const` member functions

- Member Function Declaration (`display()` and `show()`): Functions defined within the class are called member functions or methods. 
- When a member function is declared as `const`, it means that the function does not modify the object’s state. To enforce this, within a const member function, the `this` pointer is treated as a pointer to a constant object.
	- `show()` is a `const` member function. This means within `show`, `this` is of type `const Base* const` (a constant object).
		- The first `const` means that `this` points to a constant object of type `Base`, so you cannot modify the object’s members through this. Putting `const` in the function member declaration (`void show() const`) leads to this first `const`.
		- The last `const` means that the pointer itself cannot be changed to point somewhere else.
	- `display()` is not a `const` member function, so `this` is of type `Base* const`.
		- `Base*` means this points to a non-constant object of type `Base`, so you can modify the object’s members through this.
		- The last `const` again means that the pointer itself cannot be changed to point somewhere else.

## Virtual and Pure Virtual Functions

Virtual functions allow overriding by derived classes. They enable polymorphism, where different classes can provide different implementations of the same function signature.

Pure Virtual Functions (`virtual bool exec(...) const = 0`): Pure virtual functions are declared with `= 0` and have no implementation in the base class. They must be overridden by any derived class, *making the base class abstract*.

## Inheritance

`C++` supports inheritance, where one class (derived class) can inherit characteristics (methods and properties) from another class (base class). **Inheritance is specified using a colon `:` followed by the access specifier and the name of the base class**.

Let us consider the following declarations in a [header file][2] (in the [source code][1], you find the actual implementation of each member function).

```cpp

class Regengine
{
public:
    virtual bool exec(const std::string &str, size_t offset, struct match &m) const = 0;
    virtual ~Regengine() {}
};

class PatternList : public Regengine
{
public:
    bool exec(const std::string &str, size_t offset, struct match &m) const override;
    void add_pattern(std::unique_ptr<Regengine> pattern);
private:
    std::vector<std::unique_ptr<Regengine>> patterns;
};
```

- Class Name (`Regengine`): Names the class and serves as a blueprint or template for creating objects.
- Derived Class (`PatternList`): Inherits from Regengine using public inheritance.
- Override (`override`): In C++, the `override` keyword is used to explicitly indicate that a member function in a derived class is intended to override a `virtual` function from a base class. **So `vitual` and `override` are used together**: `virtual` is used in `Regengine` to denote denote it must be overridden in derived classes, whereas `override` is used in `PatternList`, a class derived from `Regengine`.

> PS: when you see `{}` in a member function definition within a class declaration in a header file, it means that the function is being defined there and not just declared. The inline keyword is often omitted because functions defined inside a class are implicitly inline.

In the source code, `exec()` can be rewritten as follows:
```cpp
bool PatternList::exec(const string &str, size_t offset, struct match &m) const
{
	struct match m_copy = m;
	for (auto &r : patterns) {
		if (r->exec(str, offset, m_copy)) {
			m.start = m_copy.start;
			m.end = m_copy.end;
			return true;
		}
	}
	return false;
}
```
If you omit `override` in the derived class declaration, the function will still override the base class function if the signatures match. However, **using `override` explicitly is considered good practice because it prevents bugs** that can arise from accidentally mismatched function signatures or changes in the base class that are not properly reflected in derived classes.

## Constructor and Destructor

Classes in C++ can have constructors and destructors:

Constructor (`PosixRegex(const std::string &pattern, bool case_insensitive)`) and Destructor (`~PosixRegex()`)
- Constructor: Initializes objects of the class. It has the same name as the class and does not return any value.
- Destructor: Cleans up resources when an object goes out of scope or is explicitly deleted. It is invoked automatically when an object is destroyed.

For instance, if we have
```cpp
class PCRERegex : public Regengine
{
public:
	PCRERegex(const std::string &pattern, bool case_insensitive);
	~PCRERegex();
	bool exec(const std::string &str, size_t offset, struct match &m) const override;
private:
	pcre2_code *regex;
};
```
in the header file, in the source code, we can implement the constructor like
```cpp
PCRERegex::PCRERegex(const string &pattern, bool case_insensitive)
{
	int pcre_err;
	PCRE2_SIZE pcre_err_ofs;
	const uint32_t pcre_options = PCRE2_UTF | (case_insensitive ? PCRE2_CASELESS : 0);

	this->regex = pcre2_compile(reinterpret_cast<PCRE2_SPTR>(pattern.data()), pattern.size(),
				    pcre_options, &pcre_err, &pcre_err_ofs, nullptr);

	if (this->regex == nullptr) {
		PCRE2_UCHAR message[512]; // Actual size unknowable, longer messages get truncated
		pcre2_get_error_message(pcre_err, message, sizeof message / sizeof *message);
		err() << pattern << endl;
		err() << setw(pcre_err_ofs+1) << "^" << endl;
		err() << "Error compiling PCRE pattern: " << message << endl;
		exit(EXIT_ERROR);
	}
}
```
and the Destructor like
```cpp
PCRERegex::~PCRERegex()
{
	pcre2_code_free(this->regex);
}
```

## `this` keyword

In `C++`, every non-static member function has access to a special pointer called this. The this pointer points to the object that invoked the member function. For example, if you have an object obj of class MyClass and you call `obj.myFunction()`, within `myFunction`, the this pointer points to obj.

[1]: https://gitlab.com/pdfgrep/pdfgrep/-/blob/master/src/regengine.cc?ref_type=heads
[2]: https://gitlab.com/pdfgrep/pdfgrep/-/blob/master/src/regengine.h?ref_type=heads
