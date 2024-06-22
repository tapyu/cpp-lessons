## `extern` keyword (`C`/`C++`)

The `extern` keyword is used in the context of **declaring** variables that are **defined** elsewhere, typically in another file. Since header file serves as an interface that declares variables and functions, **`extern` is usually used in header files**. For instance,

```c
// shared.h
#ifndef SHARED_H
#define SHARED_H

extern int sharedVariable; // declaration of sharedVariable
void greeting(); // declaration of greeting(). For function declarations, the `extern` keyword is not mandatory and is usually not used (it is not wrong, though). The function header (i.e., the prototype) is enough.

#endif
```

> PS: Note that **the `extern` keyword is not mandatory when declaring functions, classes, structures, and enum**. Writing the prototype (i.e., the header without the body) is enough to declare them. However, for variables, the `extern` keyword is mandatory.

`extern int sharedVariable;` is just the declaration of `sharedVariable`. The actual definition of `sharedVariable` is somewhere else, that is, the actual allocation and initialization of `sharedVariable` is not in `shared.h`. [Every][1] source file that includes `shared.h` is aware that there is an identifier named `sharedVariable`. Therefore, the compiler accepts references to that identifier, even though the specific location where this identifier was defined is unknown --- This happens at compile time. At linking time, the definition of `sharedVariable` must be resolved or an error is prompted.

You can define `sharedVariable` in `shared.c`, `main.c`, or any other source file that includes `shared.h`. At linking time, the object files (i.e., `.o`) are linked by the compiler, which searches among them for the definition of `sharedVariable`. You must define `sharedVariable` only once, otherwise an error is prompted.

This feature brings code modularity, ensuring that variables and functions can be shared across different translation units¹. For example, let us consider the following code:

```c
// shared.c
#include "shared.h"
#include <stdio.h>

int sharedVariable = 42; // definition (and initialization), IT MUST OCCUR ONLY ONCE

void greeting() {
    printf("The sharedVariable is: %d\n", sharedVariable);
}
```

```c
// main.c
#include <stdio.h>
#include "shared.h"

int main() {
    printf("Value of sharedVariable: %d\n", sharedVariable);
    greeting();
    return 0;
}
```

If `shared.h` is included in multiple source files (`shared.c` and `main.c` in this case) without `extern`, each source file will have its own definition of `sharedVariable`. This leads to a conflict during linking because the linker sees multiple definitions of the same variable. **You can only define a variable once, but you can declare it multiple times**.

In the previous example, `sharedVariable` is defined in `shared.c`, which is a good practice as it is declared in `shared.h`, but you can move that definition to somewhere else:
```c
// main.c
#include <stdio.h>
#include "shared.h"

int sharedVariable; // Definition. We are not initializing it (i.e., `= 42;`), though

int main() {
    printf("Value of sharedVariable: %d\n", sharedVariable);
    greeting();
    return 0;
}
```
```c
// shared.c
#include "shared.h"
#include <stdio.h>

void greeting() {
    printf("The sharedVariable is: %d\n", sharedVariable);
}
```

#### declaration
- A variable is declared when the compiler is informed that a variable exists (and this is its type)
- it does not allocate the storage for the variable at that point.
- You may declare a variable multiple times (though once is sufficient).
- Declaration is what the compiler needs to accept references to that identifier.

#### definition
- A variable is defined when the compiler allocates the storage for the variable.
- You may only define it once.
- A variable definition is also a declaration, but not all variable declarations are definitions.

#### [Guidelines][2]

- A header file only contains `extern` declarations of variables — never `static` or unqualified variable definitions (e.g., `int myVariable = 42;`).
- SPOT — Single Point of Truth: For any given variable, only one header file declares it (although you are allowed to declare it in other header files, it is not a good practice).
- A source file never contains `extern` declarations of variables — source files always include the unique header that declares them.
- For any given variable, exactly one source file defines the variable, preferably initializing it too.
- For any variable that is intended to have external linkage (i.e., non-`static` variables), the source file that defines it must also include the header that declares it to ensure that the definition and the declaration are consistent. This source and header file should have the same base name. For example, if `a.h` declares `extern int i;`, it is a good practice to define it in `a.c` (e.g., `int i = 100;`) and to make sure that `a.c` contains the `#include "a.h"` directive.
- In the header file, functions, classes, structures, and enum declaration don't necessarily need the `extern` keyword as it is implicitly treated as one. You can put the `extern` keyword in their declaration without any problem for the sake of clarity. Although it is also correct, it is less common. Therefore the `extern` keyword is commonly used for global variables only.
- Avoid global variables whenever possible — use functions instead.

¹: Each source file that includes a header file, along with the included header files, constitutes a separate translation unit. A translation unit in C/C++ is the result of the preprocessing stage, where the source file and all the header files it includes generate the translation unit (a `.i` file).

---

### **`static` keyword (`C`/`C++`)**

The static keyword can be used in a function declaration in several different contexts, and its meaning can vary depending on where it is used:
1. *Static Member Functions*: When you declare a member function as `static` inside a class, **it means that the function belongs to the class itself rather than to any specific instance of the class**. You can call a static member function using the class name, without creating an object of the class. See `./static_member-function/`.
1. *Static Variables*: **`static` variables have internal linkage**, meaning the variable is only visible within the translation unit where it is defined. They should not be accessed from other source files. This is useful for encapsulating the variable within the file, preventing name conflicts and unintended access.
    ```c
    // main.c
    #include "example.h"
    #include <stdio.h>
    int main() {
        printf("hello external: %d", external_variable);
        // printf("hello external: %d", static_variable); // you cannot access to this `static` variable as it is linked to the `example.c` translation unit.
        return 0;
    }
    ```
    ```c
    // example.h
    #ifndef EXAMPLE_H
    #define EXAMPLE_H
    
    // Declaration of an external variable
    extern int external_variable;
    // extern int static_variable; // you cannot have an external linkage of a `static` variable since it is only visible within the translation unit where it is defined
    #endif
    ```
    ```c
    // example.c
    #include "example.h"
    #include <stdio.h>
    static int static_variable = 100;
    int external_variable = 42;
    ```
    You should notice that, if it is defined within a function, the scope of that `static` variable exists only within that function, as any ordinary variable. Nevertherless, since it is `static`, it is initialized only once in that translation unit and it retains its value between the calls of the function it was defined.
    ```c
    // main.c
    #include <stdio.h>
        
    void f (void)
    {
        static int count = 0;   // static variable   
        int i = 0;              // automatic variable
        printf("non-static int: %d\nstatic int: %d\n", i++, count++);
    }
    
    int main(void)
    {
        for (int ndx=0; ndx<10; ++ndx)
            f();
        
        // printf("Hi static: %d", count); // you cannot access it from outside `f`
            
        return 0;
    }
    ```
    output:
    ```
    non-static int: 0
    static int: 0
    non-static int: 0
    static int: 1
    non-static int: 0
    static int: 2
    non-static int: 0
    static int: 3
    non-static int: 0
    static int: 4
    non-static int: 0
    static int: 5
    non-static int: 0
    static int: 6
    non-static int: 0
    static int: 7
    non-static int: 0
    static int: 8
    non-static int: 0
    static int: 9
    ```
1. *Satic functions*: likewise, **`static` functions also have internal linkage**, that is, it will only be accessible within the [translation unit][5] where it is defined.
    ```c
    // helper.cpp
    #include <iostream>
    #include "helper.h"
    
    static void staticFunction() {
        std::cout << "This is a static function inside helper.cpp" << std::endl;
    }
    
    void globalFunction() {
        std::cout << "Calling staticFunction from globalFunction: ";
        staticFunction(); // it can only be called within `helper.cpp`
    }
    ```
    ```cpp
    // helper.h
    #ifndef HELPER_H
    #define HELPER_H
    
    void globalFunction(); // Declaration of a global function
    
    #endif
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
    In this case, we say that `staticFunction()` has **internal linkage** because of the static keyword, meaning it is visible to all functions within `helper.cpp` only. We say that such variables/functions have a **file scope**. Note that `staticFunction()` is not put into `helper.h` as it is not meant to be accessed outside `helper.cpp`. On the other hand, **functions declared without the `static` keyword have external linkage by default**, that is, they can be accessed from other translation units. Thus, it will become a *global scope* function/variabe since other file sources can access and modify it. Follow these instructions as a rule of thumb:
    - Functions without the `static` keyword have external linkage by default and should have their declarations placed in header files, allowing other source files to see and use them.
    - `static` functions should typically not be declared in header files. Declaring them in header files would be misleading, as they cannot be accessed from other translation units.

---

### `inline` keyword (`C`/`C++`)

The `inline` keyword is used to suggest to the compiler that add can be inlined at its call site. However, in C, unlike C++, **inline does not automatically provide internal linkage**. For example, in

```c
#include <stdio.h>


inline int f(int x) {
    return x;
}

int main() {
    printf("Hello inline function: %d\n", f(1));
    return 0;
}
```

we obtain

```
❯ gcc -o file1 file1.c
/usr/bin/ld: /tmp/ccQPWsmH.o: in function `main':
file1.c:(.text+0xe): undefined reference to `f'
collect2: error: ld returned 1 exit status
```

[1]: https://stackoverflow.com/questions/1410563/what-is-the-difference-between-a-definition-and-a-declaration/1411005#1411005
[2]: https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files/1433387#1433387
[5]: https://github.com/tapyu/c-and-cpp-lessons/tree/1-build-process#preprocessing
