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
- Since `Base` has no pure virtual function, **it is a concrete class**.

## Member functions and `const` member functions

- Member Function Declaration (`display()` and `show()`): Functions defined within the class are called member functions or methods. 
- When a member function is declared as `const`, it means that the function does not modify the object’s state. To enforce this, within a const member function, the `this` pointer is treated as a pointer to a constant object.
	- `show()` is a `const` member function. This means within `show`, `this` is of type `const Base* const` (a constant object).
		- The first `const` means that `this` points to a constant object of type `Base`, so you cannot modify the object’s members through this. Putting `const` in the function member declaration (`void show() const`) leads to this first `const`.
		- The last `const` means that the pointer itself cannot be changed to point somewhere else.
	- `display()` is not a `const` member function, so `this` is of type `Base* const`.
		- `Base*` means this points to a non-constant object of type `Base`, so you can modify the object’s members through this.
		- The last `const` again means that the pointer itself cannot be changed to point somewhere else.

## Virtual

Virtual functions allow overriding by derived classes. They enable polymorphism, where different classes can provide different implementations of the same function signature. In the previous example, even though the `virtual` functions like `show()` and `display()` are intended to be overridden by derived classes, you can still define their behavior in `Base` and call these functions on Base objects.

Suppose you add the following to `example.h`:
```cpp
// example.h
class Derived : public Base {
public:
    // Override of the virtual member function `show()` from the Base class
	// The overriden function provides polymorphism for it
    // This function is constant and does not modify the state of the object.
    void show() const override;

    // Override of the virtual member function `display()` from the Base class
	// The overriden function provides polymorphism for it
    // This function can modify the state of the object.
    void display() override;

private:
    // Private data member
    // This member is not accessible directly outside the class and is only
    // used internally within the Derived class.
    int state = 0;
};
```
and to `example.cpp`:
```cpp
// Definition of Derived::show()
void Derived::show() const {
    std::cout << "Derived class show() const" << std::endl;
}

// Definition of Derived::display()
void Derived::display() {
    state++;  // Modify the state variable to demonstrate state change
    std::cout << "Derived class display() - state: " << state << std::endl;
}
```
and to `main.cpp`:
```cpp
Derived d;
d.display();   // Calls Derived::display()
d.show();      // Calls Derived::show()
d.display();   // Calls Derived::display()
```

The output is
```
❯ ./main
Derived class display() - state: 1
Derived class show() const
Derived class display() - state: 2
```

## `const` objects

When an object is declared as `const` in C++, it means that its value cannot be modified after initialization. This applies to variables, class member variables, function parameters, and references. Attempting to assign a new value to a `const` object or modify it in any way results in a compilation error. const objects are primarily used to ensure that certain values remain unchanged throughout the program, promoting code safety by preventing inadvertent modifications and enabling compiler optimizations based on the immutability of these values. When an object is declared as const, you can only call member functions that are themselves marked as const.

``` cpp
// main.cpp
const Derived cd;
cd.show();    // Calls Derived::show()
// cd.display(); // Error: cd is const, and display() is not a const member function
```

## Pure Virtual Functions

Pure virtual functions are declared with `= 0` and have no implementation in the base class. They must be overridden by any derived class, *making the base class abstract*. When a class contains at least one pure virtual function, **it becomes an abstract class**, and you cannot instantiate objects of that class directly.  So suppose we add

```cpp
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

    // Declaration of a pure virtual member function `new_greeting()`
    // This function is constant and does not modify the state of the object.
    // Being pure virtual (indicated by = 0), it makes `Base` an abstract class,
    // meaning that `Base` cannot be instantiated directly.
    // Derived classes must override this function.
    virtual void new_greeting() const = 0; 

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

class Derived : public Base {
public:
    // Override of the virtual member function `show()` from the Base class
    // The overriden function provides polymorphism for it
    // This function is constant and does not modify the state of the object.
    void show() const override;

    // Override of the virtual member function `display()` from the Base class
    // The overriden function provides polymorphism for it
    // This function can modify the state of the object.
    void display() override;

	// Overwrite of the pure virtual function `new_greeting()` from the Base class
    // This function provides specific behavior for `new_greeting()` in the Derived class.
    // It is marked as `const` to indicate that it does not modify the object's state.
    void new_greeting() const override; 

private:
    // Private data member
    // This member is not accessible directly outside the class and is only
    // used internally within the Derived class.
    int state = 0;
};
```

- `new_greeting()`: A pure virtual function (abstract function) marked with `= 0`, making Base an abstract class. It must be overridden by any non-abstract derived class. The function is also marked as const, indicating it does not modify the state of the object.

When a class contains at least one pure virtual function, **it becomes an abstract class**, and you cannot instantiate objects of that class directly.

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
