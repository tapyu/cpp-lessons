# FAQ

### **"void foo(void)" vs. "void foo()"? (`C` and `C++`)**

```c
void foo(void);
```
[That][1] is the correct way to say "no parameters" in `C`, and it also works in `C++`.

But:

```c
void foo();
```
Means different things in `C` and `C++`! In `C` it means "could take any number of parameters of unknown types", and in `C++` it means the same as `foo(void)`, that is, no parameters are allowed.

Variable argument list functions are inherently un-typesafe and should be avoided where possible. Therefore, for the sake of unified approach, `void foo(void);` **should be used** for both `C` and `C++` whenever you want to declared a function which has no input arguments.

---

### **Object-like macro (`#define`) vs. constant variables (`const`) vs. enumerate (`enum`) (`C` and `C++`(?))**

#### `const`

A constant defined with the `const` qualifier, e.g.,
```c
const int maxAttempts = 3
```
is [best thought of as an unmodifiable variable][2]. It has all the properties of a variable: **it has a type, it has a size, it has linkage, you can take its address**. (The compiler might optimize away some of these properties if it can get away with it: for instance, constants whose address is never used may not get emitted into the executable image. But this is only by the grace of the as-if rule.) The only thing you can't do to a `const` datum is change its value.

#### `enum`

A constant defined with `enum` is a little different. It has a type and a size, but it doesn't have linkage, you can't take its address, and its type is unique. Both of these are processed during translation phase 7, so they can't be anything but an lvalue or rvalue. (I'm sorry about the jargon in the preceding sentence, but I would have to write several paragraphs otherwise.)

#### `#define`

A macro, e.g.,
```c
#define PI 3.14159265359
```
has far fewer constraints: it can expand to any sequence of tokens, as long as the overall program remains a well-formed program. It doesn't have any of the properties of a variable. Applying `sizeof` or `&` to a macro may or may not do something useful, depending on what the macro expands to. Macros are sometimes defined to expand to numeric literals, and such macros are sometimes thought of as constants, but they're not: "the compiler proper" (that is, translation phase 7) sees them as numeric literals.

#### conclusions

**It is generally considered good practice, nowadays, not to use a macro when a constant will do**. Macros don't obey the same scoping rules as all other identifiers, which can be confusing, and if you use a constant you give more information to translation phase 7 and thus also to the debugger. However, macros permit you to do things that cannot be done any other way, and if you need to do one of those things, you should not hesitate to use them. (Macros that are pulling their weight, in this sense, generally do not just expand to numeric literals, though I am not going to say never.)

---

### **`%f` vs. `%lf` (`C`)**
1. [For][3] `printf()` -> Arguments of type `float` are promoted to `double` so both `%f` and `%lf` work for double.
1. For `scanf()` -> you must use `%f` for float and `%lf` for double.

**Conclusion**: It is not necessary or standard to use `%lf` with `printf`. The correct practice is to use `%lf` with `scanf` for reading double values and use `%f` with `scanf` for reading float values. For printf, use `%f` (or its variants, i.e., `%e`, `%E`, `%g`, or `%G`) for printing both float and double values. This approach aligns with the standard C conventions and ensures compatibility and correctness in your code.

---

### **Why does the order of the `-l` option matter in the `gcc`/`g++` commands? (`C` and `C++`)**
[When][4] you add a library using the -l option, the linker does not unconditionally take all object files from the library. It only takes those object files that are currently needed, i.e. files that resolve some currently unresolved (pending) symbols. After that, the linker completely forgets about that library.

---

### **nullptr (`C++`) vs. NULL (`C`)**

`nullptr` and `NULL` serve similar purposes, but they have differences:

- `nullptr` is a `C++11` and later keyword, introduced to provide a more type-safe and robust way to represent null pointers. It can be used for pointers of any type.
- `NULL` is a macro defined in the `C` and `C++` standard libraries (typically as `(void*)0` or something similar). It is often used in `C` and older `C++` code to represent null pointers.
- In modern `C++` code, it's recommended to use `nullptr` for null pointers because it provides better type safety. However, if you're working with legacy code or `C` libraries, you may encounter `NULL`.

---

### `%i` vs `%d`

See [comments][6] in the  `printf()` syntax.

---

### The terms `method` vs. `member function` (`C++`)

Both terms, "method" and "member function," can be used to describe a function `myFunction()` from the class `MyClass`, but there is a subtle difference in their usage based on the programming language and the paradigm being used.

In object-oriented programming, especially in languages like `C++` and `Java`, the term "member function" is more commonly used to describe functions that are part of a class, regardless of whether they are static or non-static. This is the more specific and widely understood term in the context of class-based object-oriented programming.

On the other hand, the term "method" is a more general term that can be used in a broader sense to describe a function associated with an object or a class. It's often used in object-oriented programming languages as well, but it's not as specific as "member function."

So, you can say:

- "`myFunction()` is a static member function of the class `MyClass`." - This is the most precise and widely accepted terminology in `C++`.
- "`myFunction()` is a method of the class `MyClass`." - This is a more general way to describe it, and it can be understood in the context of object-oriented programming, though it's less precise.

In summary, while both terms can be used, "member function" is more specific and commonly used in the context of class-based object-oriented programming like `C++`.


---

### `const` keyword (`C` and `C++`)

- *For pointers*: when you use a `const` pointer (e.g., `const char *ptr`), you cannot modify the characters through the pointer `ptr`. However, it does not make the pointer itself constant; you can change the pointer to point to a different memory location. Also, if `int i = 5;` and `const int *pi = &i;`, although you cannot modify `i` through `pi`, you can modify `i` directly, e.g., `i = 0;`. If we want, we can also change the memory address `pi` points to, e.g., `pi = &j;`, where `int j = 3;`. See `./const-keyword/main.c`.
- *For any other variable type:* When the const keyword is used with a variable that is not a pointer, it creates a constant (read-only) variable.

---

### `enum` (`C`/`C++`) vs. `enum class` (`C++`)

#### `enum`

An enum is followed by an enumerator list. Each name in the list is an identifier for an integer constant. By default, the first name in the enum is assigned the integer value 0, the second name is assigned 1, and so on. For example (see `enum/enum.c` for the complete example):
```c
enum Day {
    SUNDAY,    // 0
    MONDAY,    // 1
    TUESDAY,   // 2
    WEDNESDAY, // 3
    THURSDAY,  // 4
    FRIDAY,    // 5
    SATURDAY   // 6
};
```
You can also explicitly assign specific values to the names. For example:
```c
enum Day {
    SUNDAY = 1,   // 1
    MONDAY,       // 2
    TUESDAY = 5,  // 5
    WEDNESDAY,    // 6
    THURSDAY = 10,// 10
    FRIDAY,       // 11
    SATURDAY      // 12
};
```

#### `enum class`

In C++, both enum and enum class are used to define enumerations, but they have some important differences in terms of scope, type safety, and implicit conversions.

1. `enum`
    1. **Scope**: Enumerators are in the same scope as the enumeration.
        ```c
        enum Color { // enumeration Color
            RED,    // 0 (enumerator RED)
            GREEN,  // 1
            BLUE    // 2
        };
        Color c = RED; // No need to qualify RED with Color::
        ```
    1. **Implicit Conversions**: Enumerators implicitly convert to their underlying integer type.
        ```c
        int x = RED; // Allowed
        ```
    1. **Type Safety**: Less type-safe because enumerators are not strongly typed.
        ```c
        enum Color {
            RED, GREEN, BLUE
        };
        enum Size {
            SMALL, MEDIUM, LARGE
        };
        Color c = SMALL; // Allowed, but not intended (potential bug)
        ```
1. `enum class`
    1. **Scope**: Enumerators are scoped within the enumeration. You need to use the scope operator (::) to access them
        ```cpp
        enum class Color {
            RED,    // 0
            GREEN,  // 1
            BLUE    // 2
        };
        Color c = Color::RED; // Need to qualify with Color::
        ```
    1. **Implicit Conversions**: Enumerators do not implicitly convert to their underlying integer type.
        ```cpp
        int x = Color::RED; // Error: no implicit conversion
        int x = static_cast<int>(Color::RED); // Allowed with explicit cast
        ```
    1. **Type Safety**: More type-safe because enumerators are strongly typed and scoped within the enumeration.
        ```cpp
        enum class Color {
            RED, GREEN, BLUE
        };
        enum class Size {
            SMALL, MEDIUM, LARGE
        };
        Color c = Size::SMALL; // Error: incompatible types
        ```
**Conclusion**:
- `enum`: Less type-safe, enumerators are in the same scope as the enumeration, and implicit conversions to integers are allowed.
- `enum class`: More type-safe, enumerators are scoped within the enumeration, and implicit conversions to integers are not allowed.
- **For modern `C++` code, `enum class` should be preferred** because they cause fewer surprises that could potentially lead to bugs.
- See `./enum/` for more details.

---

### `auto` keyword (`C++`)

The auto keyword in C++ is useful when you want the compiler to automatically deduce the data type of a variable based on its initializer.

The readability benefits of auto are often more apparent in situations involving complex types. For instance, if you were working with iterators of a templated container, the actual type might be quite lengthy and complex. Using auto allows the compiler to determine the type for you, reducing verbosity and making the code more concise. The readability benefits of auto are often more apparent in situations involving complex types, iterators from template classes, or when dealing with iterators in range-based for loops where the actual type may not be immediately obvious.

Using the auto keyword does not make C++ dynamically typed. C++ is still a statically-typed language. When you use auto, you are employing type inference at compile-time. The compiler deduces the type of the variable based on its initializer, but once the type is determined, it is fixed during compilation.In dynamically-typed languages, types are determined at runtime, and variables can change their type during the program's execution. In C++, with auto, you're getting a form of type inference without sacrificing the static typing characteristic of the language.

Example:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<std::pair<int, std::string>> keyValuePairs = {{1, "apple"}, {2, "banana"}, {3, "cherry"}};

    // Using auto to simplify the iterator type
    for (auto it = keyValuePairs.begin(); it != keyValuePairs.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    return 0;
}
```

---

### `union` vs. `struct`

**[With a union][7], you're only supposed to use one of the elements**, because they're all stored at the same address. This makes it useful when you want to store something that could be one of several types. A struct, on the other hand, has a separate memory location for each of its elements and they all can be used at once (see `./union_vs_struct/`).

### `typedef`

In C, typedef is a keyword used to create new type names (aliases) for existing types. This can make complex declarations more readable and easier to manage. It is especially useful when dealing with complex data structures, function pointers, etc.

A simple example with function pointers is
```c
typedef void (*OperationFunc)(int, int);
OperationFunc operation1;
OperationFunc operation2;
```

- Without `typedef`, you would have to declare the function pointer explicitly each time: `void (*operation1)(int, int);`.
- With `typedef`, we create an alias named `OperationFunc` to `typedef void (*OperationFunc)(int, int);`.

Advantages of Using typedef:
- Readability: It makes the code easier to read and understand, especially when dealing with complex types like function pointers or structures.
- Maintainability: If the underlying type changes, you only need to update the typedef declaration.
- Simplicity: Simplifies the syntax for declaring variables of the aliased type.

Other Common Uses of typedef:
- Structures: Create aliases for struct types to avoid repeatedly using the struct keyword.
- Arrays: Simplify array declarations.

[1]: https://stackoverflow.com/questions/693788/is-it-better-to-use-c-void-arguments-void-foovoid-or-not-void-foo
[2]: https://stackoverflow.com/questions/6393776/what-is-the-difference-between-a-macro-and-a-const-in-c
[3]: https://stackoverflow.com/questions/25860850/what-is-the-difference-between-f-and-lf-in-c
[4]: https://stackoverflow.com/questions/11893996/why-does-the-order-of-l-option-in-gcc-matter/11894098#11894098
[5]: https://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
[6]: https://github.com/tapyu/c-and-cpp-lessons/tree/5-pointer-reference-memory?tab=readme-ov-file#variables
[7]: https://stackoverflow.com/a/346541/23333162
