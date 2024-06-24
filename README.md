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

> WARNING: In `C`, using `inline` is not a so recommended approach by the [annoying StackOverflow community](https://stackoverflow.com/questions/78657695/how-to-use-inline-function-across-multiple-c-files-without-the-declared-but-n?noredirect=1#comment138681776_78657695). It is a suggestion and seems unecessary and optimizations are usually performed be the compiler without you need to check what functions should be inlined: "'So it is not used in C anymore?' Yes. (I use it to remove one gcc warning). 'inline seemed very effective' why would a compiler inline only functions marked inline? Sounds ineffective. **All functions (that compiler can) can be inlined**.". So don't give a damn about it...

The `inline` keyword in C/C++ is used to suggest to the compiler that it should attempt to expand the function inline rather than calling it through the usual function call mechanism. When a function is declared as inline, the compiler attempts to insert the complete body of the function in every place where the function is called, rather than generating a call to the function. This can reduce the overhead of function calls and is especially used for small, frequently called functions. Regardless, keep in mind that the `inline` keyword is a suggestion to the compiler, and the compiler is free to ignore it. Although it might be considered a good practice to use it when reasonable, modern compilers perform their own optimizations and may choose to inline functions regardless of the `inline` keyword.

- Each .c file is compiled independently into .o output. If you define the inline function in a .c file, other source files cannot see such function, so that cannot be inlined. Therefore the inline function should be in the .h file to allow the code to be shared.
- Inline functions are defined in the header because, in order to inline a function call, the compiler must be able to see the function body.
- functions defined in the header must be marked `inline` because otherwise, every translation unit which includes the header will contain a definition of the function, and the linker will complain about multiple definitions (a violation of the One Definition Rule). The `inline` keyword suppresses this, allowing multiple translation units to contain (identical) definitions.
- A function call may be inlined even if not declared inline in special cases where the compiler can determine this is correct and desirable. For instance, when a static function is called only once, it will very likely be inlined.
- **While it's generally true that header files contain declarations, inline functions are a notable exception** where definitions are also placed in headers to allow for inlining.
- Inline function definitions need to be visible wherever the function is invoked. You can define the function in a .c file if you only want to use it within that .c file, otherwise you need to define it in a .h file so that the definition can be #included wherever it is needed.
- Don't declare an `inline extern` function in a header file. This creates an "external definition" for the function, and you can only have one of those in your entire program.

However, **`inline` keyword should be used carefully as it may cause linking issues**. Moreover, it has different behaviour for `C` and `C++`

#### `C`

In `C`, unlike `C++`, **inline does not enforce internal linkage**. For example, in

```c
//main.c
#include <stdio.h>

inline int f(int x) {
    return x;
}

int main() {
    printf("Hello inline function: %d\n", f(1));
    return 0;
}
```

we get

```
/usr/bin/ld: /tmp/ccpTpPeP.o: in function `main':
file1.c:(.text+0x17): undefined reference to `f'
collect2: error: ld returned 1 exit status
```

The assembly code (`gcc -S main.c -o main.s`) is

```asm
	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"Hello inline function: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$1, %edi
	call	f@PLT
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
```

The assembly code generated includes a call to `f@PLT`, which indicates that the linker expects to find the function `f` in the Procedure Linkage Table (PLT). This happens because the **`inline` keyword does not necessarily enforce the internal linkage** (i.e., visibility limited to the translation unit where it is defined).

##### Solution 1: `static inline` function for nonshared functions

The `inline` keyword alone does not provide a linkage specification that the linker can use to find the function definition. Adding `static` ensures that the function has internal linkage, making its definition available within the translation unit and avoiding undefined references. By adding `static` in the previous snippet, we get the following assembly code:
```asm
...
	.file	"main.c"
	.text
	.type	f, @function
f:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc

...

    call	f

...
```

##### Solution 2: `extern inline` functions across multiple files

A example is

`main.c`:
```c
#include <stdio.h>
#include "file1.h"

int main() {
    printf("Hello inline function: %d\n", f(1));

    int y = some_function();

    printf("Hi from file1: %d\n", y);
    return 0;
}
```
`file1.c`:
```c
#include "main.h"
#include "file1.h"

// declares that `inline int f(int x)` is defined somewhere else
extern inline int f(int x);

// Use the extern inline function in another file
int some_function() {
    return f(3);
}
```
`file1.h`:
```c
#ifndef FILE1_H
#define FILE1_H

// definition of `f` -> you MUST define it in the header file as each translation unit that imports `file1.h` needs to have the implementation of `f` in order to inline it
inline int f(int x) {
    return x;
}

// Declare the some_function function
int some_function();

#endif // FILE1_H
```

Sources
- https://stackoverflow.com/questions/78657695/how-to-use-inline-function-across-multiple-c-files-without-the-declared-but-n
- https://stackoverflow.com/questions/6312597/is-inline-without-static-or-extern-ever-useful-in-c99
- https://stackoverflow.com/questions/2752644/is-there-a-way-to-define-c-inline-function-in-c-file-rather-than-h-file
- https://stackoverflow.com/questions/62163802/c-small-function-not-inlining
- https://stackoverflow.com/questions/48172290/static-and-extern-inline-functions-in-c
- https://stackoverflow.com/questions/78657888/extern-inline-vs-static-inline-shared-functions-what-is-the-correct-form
- https://stackoverflow.com/questions/25000497/whats-the-difference-between-static-inline-extern-inline-and-a-normal-inline-f

#### `C++`


```cpp
inline int add(int a, int b) {
    return a + b;
}
```
When you define a member function inside a class definition, it is implicitly considered inline by the compiler.
```cpp
class MyClass {
public:
    int add(int a, int b) { // This function is implicitly inline
        return a + b;
    }
};
```
If you don't want that `add()` be interpreted as inline, you should avoid defining it within the class definition. Instead, declare the function in the class definition and define it outside the class in a separate source file.
```cpp
// MyClass.h
#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
public:
    int add(int a, int b); // Declaration only, no inline
};

#endif // MYCLASS_H
```

```cpp
// MyClass.cpp
#include "MyClass.h"

int MyClass::add(int a, int b) { // Definition, not inline
    return a + b;
}
```

[1]: https://stackoverflow.com/questions/1410563/what-is-the-difference-between-a-definition-and-a-declaration/1411005#1411005
[2]: https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files/1433387#1433387
[5]: https://github.com/tapyu/c-and-cpp-lessons/tree/1-build-process#preprocessing
