### How to handle errors in `C`/`C++`

- Return Codes:
  - In `C`, functions often return error codes to indicate failure. **A common convention is to return 0 for success and non-zero values for errors**.
  - In `C++`, you can throw exceptions to signal errors. This allows you to propagate errors up the call stack and catch them where they can be handled appropriately.
- Error Codes and Enumerations:
  - Define error codes or use enumerations to represent specific error conditions. This makes error messages more meaningful. Example in `C`:
  ```c
  enum ErrorCodes {
    SUCCESS = 0,
    FILE_NOT_FOUND = 1,
    INVALID_ARGUMENT = 2,
    // ...
  };
  ```
- Standard Error Stream (`stderr`):
  - Print error messages and diagnostics to the standard error stream (stderr) instead of the standard output (stdout). This allows users to separate error messages from normal program output.
  - In `C`, you can use `fprintf(stderr, ...)` to write to `stderr`.
- Logging:
  - Implement logging mechanisms to record detailed information about errors, warnings, and program state.
  - Libraries like `log4c` (`C`) or various `C++` logging libraries are available.
- Exception Handling (`C++`)
  - In C++, you can use try-catch blocks to catch and handle exceptions.
  - Throw exceptions with meaningful error messages to provide context.
  ```cpp
  try {
      // Code that may throw an exception
  } catch (const std::exception& e) {
      // Handle the exception
  }
  ```

### **What is the use of the `noexcept` keyword (`C++`)**

The `noexcept` specifier in `C++` is used to indicate that a particular function does not throw any exceptions. It is a way for a programmer to make a **promise** that a function will not propagate exceptions beyond its scope.

- Performance: Exception handling can have a performance cost, especially when exceptions are thrown frequently. *By marking a function as `noexcept`, you inform the compiler that it doesn't need to generate additional code for exception handling, which can result in faster execution.*
- Error Handling: In some cases, you may want to handle errors within a function without propagating exceptions. Using noexcept makes it clear that the function is responsible for handling any errors it encounters without relying on exceptions.
- Resource Management: When you work with resource management (like memory allocation or file I/O), you might want to ensure that the resource cleanup happens reliably. Using noexcept helps you avoid unexpected exceptions that could interfere with proper cleanup.

Example:
```cpp
// Move constructor using an rvalue reference
MyString(MyString&& other) noexcept {
    // Steal the ownership of the dynamically allocated memory
    str = other.str;
    other.str = nullptr; // Ensure the source object has no ownership
}
```


### **The use of std::cerr (C++)**

It is one of the standard output streams provided by the C++ Standard Library, more specifically by the `std::ostream` class. It is designed for writing error messages and other diagnostic information to the standard error stream. It is an instance of the  class.

`std::cerr` itself does not throw exceptions. Exceptions are typically thrown by C++ code when exceptional conditions occur, and they can be caught and handled using try and catch blocks. `std::cerr` is often used for reporting errors or exceptions, but it doesn't itself throw exceptions.


---

# Common errors:

## initializer element is not constant

Example:

```c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int x = add(1,1);

int main() {
    printf("Hello inline function: %d\n", x);
    return 0;
}
```

"initializer element is not constant," occurs because in C, global variables must be initialized with constant expressions. However, add(1,1) is not considered a constant expression since it involves a function call. In C, constant expressions are typically simple literals or constant expressions involving literals, such as 1, 1 + 1, or 3 * 4.

To solve this, you need to initialize the variable x within a function, such as main, where it is allowed to perform computations using function calls. Here’s how you can modify your code:

```c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int x; // Declare the global variable without initialization

int main() {
    x = add(1, 1); // Initialize x within the main function
    printf("Hello inline function: %d\n", x);
    return 0;
}
```
