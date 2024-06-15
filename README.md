#### When should I use the `extern` keyword?

The extern keyword in `C` and `C++` is used to declare a global variable or function that is used in multiple source files and thus must be linked toghether. The `extern` keyword basically says that a function/variable that is referenced in a source file `file1.c` is [defined][1] somewhere else, say, in a source file `file2.c`.

Here, It is important to understand the difference between defining a variable and declaring a variable:

- A variable is declared when the compiler is informed that a variable exists (and this is its type); it does not allocate the storage for the variable at that point. You may declare a variable multiple times (though once is sufficient).
- A variable is defined when the compiler allocates the storage for the variable. You may only define it once within a given scope. A variable definition is also a declaration, but not all variable declarations are definitions.

#### How to define a global variable?

The clean, reliable way to declare and define global variables is to use a header file to contain an `extern` declaration of the variable. The header is included by the one source file that defines the variable and by all the source files that reference the variable.

For each program, one (and only one) source file defines the variable. Similarly, one header file should declare the variable. The header file is crucial; it enables cross-checking between independent TUs (the `.i` file generating after the preprocessing step. Each source file typically corresponds to a single translation unit) and ensures consistency.

The extern keyword is not required in the header file because it's common practice for header files to contain declarations, and declarations are implicitly treated as `extern`. I use the keyword `extern` in front of function declarations in headers for consistency — to match the `extern` in front of variable declarations in headers. Many people prefer not to use `extern` in front of function declarations; the compiler doesn't care


#### [Guidelines][2]

- A header file only contains `extern` declarations of variables — never `static` or unqualified variable definitions (e.g., `int myVariable = 42;`).
- For any given variable, only one header file declares it (SPOT — Single Point of Truth).
- A source file never contains `extern` declarations of variables — source files always include the unique header that declares them (for instance, if `a.c` defines the global variable `int i = 3;`, then you must declare `extern int i;` in `a.h`, and `a.c` must have the `#inclue a.h` directive).
- For any given variable, exactly one source file defines the variable, preferably initializing it too.
- The source file that defines the variable also includes the header to ensure that the definition and the declaration are consistent.
- Functions, classes, structures, and enum declaration don't necessarily need the `extern` keyword as it is implicitly treated as one. You can put the `extern` keyword in their declaration without any problem for the sake of clarity. Although it is also correct, it is less common. Therefore the `extern` keyword is commonly used for global variables only.
- Avoid global variables whenever possible — use functions instead.

---

### **Usage of the `static` keyword (`C` and `C++`)**

The static keyword can be used in a function declaration in several different contexts, and its meaning can vary depending on where it is used:
1. *Static Member Functions*: When you declare a member function as `static` inside a class, it means that the function belongs to the class itself rather than to any specific instance of the class. You can call a static member function using the class name, without creating an object of the class. See `./static_member-function/`.
1. *Static Variables inside function*: Inside a function, you can declare variables as `static`. The scope of that `static` variable exists only within that function, as any ordinary variable. However, since it is a `static` variable, it is initialized only once and it retains its value between the calls of the function it was defined.
    ```cpp
    #include <stdio.h>
     
    void f (void)
    {
        static int count = 0;   // static variable   
        int i = 0;              // automatic variable
        printf("%d %d\n", i++, count++);
    }
     
    int main(void)
    {
        for (int ndx=0; ndx<10; ++ndx)
            f();
        return 0;
    }
    ```
    output:
    ```
    0 0
    0 1
    0 2
    0 3
    0 4
    0 5
    0 6
    0 7
    0 8
    0 9
    ```
1. *Satic functions/variables in the source file*: If a function/variable is defined in the source file (but outside any function/class body) and with the `static` keyword, then that function/variable has *internal linkage*, that is, it will only be accessible within the [translation unit][5] where it is defined.
```c
// helper.cpp
#include <iostream>
#include "helper.h"

static void staticFunction() {
    std::cout << "This is a static function inside helper.cpp" << std::endl;
}

void globalFunction() {
    std::cout << "Calling staticFunction from globalFunction: ";
    staticFunction(); // Can be called within helper.cpp
}
```
```cpp
// helper.h
#ifndef HELPER_H
#define HELPER_H

void globalFunction(); // Declaration of a global function

#endif // HELPER_H
```
```cpp
// main.cpp
#include <iostream>
#include "helper.h"

int main() {
    globalFunction(); // Calls globalFunction, which calls staticFunction
    // staticFunction(); // This line would cause a compile-time error because staticFunction is not visible in main.cpp
    return 0;
}
```
In this case, we say that `staticFunction()` has **internal linkage** because of the static keyword, meaning it is visible to all functions within `helper.cpp` only. We say that such variables/functions have a **file scope**. Note that `staticFunction()` is not put into `helper.h` as it is not meant to be accessed outside `helper.cpp`. On the other hand, functions declared without the `static` keyword have **external linkage** by default, that is, they can be accessed from other translation units. Thus, it will become a *global scope* function/variabe since other file sources can access and modify it. In these cases, you **must** put them into its header file so that they can be accessed. Variables **must** have the `extern` keyword, while this is optional and usually omitted for functions, structures, enum, and classes. See main example.

[1]: https://stackoverflow.com/questions/1410563/what-is-the-difference-between-a-definition-and-a-declaration/1411005#1411005
[2]: https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files/1433387#1433387
[5]: https://github.com/tapyu/c-and-cpp-lessons/tree/1-build-process#preprocessing
