# Libraries

**What is a library?**

A C/C++ library is a collection of precompiled code modules that can be used to perform common tasks or provide reusable functionality within C or C++ programs. 

**How does a library look like on my computer?**

Libraries on your computer are typically stored as binary files. The exact file format and organization can vary depending on the programming language, the platform.
- *Shared Libraries (Dynamic Link Libraries - DLLs on Windows, Shared Objects - SO files on Linux, Dylibs on macOS)*: These are libraries that are loaded at runtime when a program is executed. They have a file extension like `.dll`, `.so`, or `.dylib`. These files contain compiled code that multiple programs can use simultaneously. They are typically stored in system directories or directories specified in the system's library search path.
- *Static Libraries (Libraries - LIB files on Windows, Archive files - A files on Linux)*: These are libraries that are linked with the program at compile-time. They contain precompiled object code. On Windows, they have a `.lib` extension, and on Linux, they are often archive files with a `.a` extension. Static libraries are linked directly into the executable, increasing the size of the resulting binary.
- *Standard Libraries*: The standard libraries for C and C++ are typically provided as part of the compiler installation. These libraries include the C Standard Library (libc on Unix-like systems), the C++ Standard Library (libstdc++ or libc++ on Unix-like systems), and others. They are typically located in system directories.
- *Header Files*: In addition to the binary library files, libraries often provide header files (with extensions like `.h`, `.hpp`, or `.hxx`) that contain declarations of functions, classes, and data structures provided by the library. Header files are typically included in your source code to use the library's functionality.

**Main categories for a C/C++ library**
- *Functionality and Purpose*:
    - *Standard Libraries*: Bundled with the programming language or platform (e.g., C Standard Library, C++ Standard Library).
    - *Utility Libraries*: Provide general-purpose functions and utilities (e.g., string manipulation, data structures).
    - *Domain-Specific Libraries*: Focus on specific application domains (e.g., graphics, scientific computing, networking).
- *Linking Method*:
    - *Static Libraries*: Linked at compile-time, resulting in larger executables.
    - *Shared Libraries*: Loaded at runtime, reducing executable size and enabling code sharing.
- *Ownership and Source*:
    - *Third-Party Libraries*: Developed by external sources, not part of the language or platform.
    - *Standard Libraries*: Officially provided and maintained by the language or platform.
- *Distribution*:
    - *Packaged Libraries*: Distributed as binary packages (e.g., DLLs, SO files) or package manager dependencies.
    - *Source Libraries*: Distributed as source code that must be compiled and linked.
- *Platform Compatibility*:
    - *Cross-Platform Libraries*: Designed to work on multiple operating systems and architectures.
    - *Platform-Specific Libraries*: Designed for a specific platform or architecture.
- *Licensing*:
    - *Open Source Libraries*: Released under open-source licenses (e.g., MIT, GPL).
    - *Proprietary Libraries*: Owned and licensed by a specific organization or company.

**What is the header file?**

Header files are human-readable files that serve to communicate the interface of the library to users, enabling them to properly use and interact with the library's features. When using a library, whether static or shared, it is common practice to provide a corresponding header file that contains the necessary declarations for the library's functions, classes, structures, and other entities. This allows users of the library to include the header file in their own code and access the functionality provided by the library. In `C++`, the `#include` directive is used to include header files. Directives are commands or instructions that are processed by the preprocessor before the actual compilation of the code. Directives are typically preceded by the `#` symbol. Header files typically contain function declarations, class definitions, constants, and other declarations that are needed for the compilation and usage of functions and types defined in the external source file (`.cpp` file).
- User-Defined Header Files:
    - These files are typically given a `.h` extension, and sometimes a `.hpp` extension in `C++` to indicate that they are header files.
    - When including user-defined header files, the `#include` directive is typically used with double quotes, such as `#include "myheader.h"`.
    - User-defined header files contain declarations and definitions specific to your project or library and are often organized within your project's directory structure.
    - It is a common convention to give them the same base name (e.g., `mylib.h` and `mylib.cpp`) for clarity and organization, but it is not a strict requirement. 
- `C++` Standard Library Header Files:
    - `C++` Standard Library header files often do not have a `.h` extension, and they are included using angle brackets, like `#include <iostream>`.
    - The omission of the `.h` extension is a convention within the `C++` Standard Library to distinguish these headers from traditional `C` headers, which often use the `.h` extension.
    - These headers provide standardized interfaces to `C++` language features and standard library components.
It is important to note that while these conventions are common, they are not strict rules enforced by the language itself. The presence or absence of the extension doesn't affect how the compiler or preprocessor treats the file. The choice of file extension and inclusion method is ultimately defined by the project's convention.

**What is the difference between a shared and a static library?**

Shared Libraries (Dynamic Link Libraries on Windows, Shared Objects on Linux, and Dylibs on macOS) and Static Libraries serve different purposes in software development and are linked with programs in different ways. The main difference between using a shared library and a static library lies in how the library is linked to your program at runtime. When you link against a static library, the library code is physically copied into your executable file during the linking process. This means that your program becomes self-contained and can be run independently without relying on the presence of the static library at runtime. The library code becomes part of your program's binary.

On the other hand, when you link against a shared library, your program only contains references to the functions or symbols provided by the library. The actual library code resides in a separate shared library file (`.so` file on Linux, `.dll` file on Windows). At runtime, the operating system dynamically loads the shared library and resolves the references from your program to the corresponding functions in the library. This allows multiple programs to share the same instance of the library in memory, reducing memory usage.

In terms of workflow, the process of compiling and linking your program is generally the same whether you're using a shared library or a static library. You still need to include the necessary header files, link against the library, and ensure the library is properly installed on the system.

Overall, the choice between using a shared library or a static library depends on various factors, including the specific requirements of your program, considerations for memory usage, ease of deployment, and potential library versioning issues.

A shared library is often referred to as a runtime library because it is loaded and linked dynamically at runtime when the program is executed. It provides functionality that can be accessed by multiple programs simultaneously. A static library, on the other hand, is often referred to as a development library because it is used during the development and compilation phase of a program. It contains precompiled code that is linked directly into the executable at compile time, making the program self-contained and independent of external dependencies. However, it's important to note that these terms can sometimes be used interchangeably or with different interpretations depending on the context. The key distinction is that shared libraries are dynamically linked at runtime, while static libraries are statically linked at compile time.

**When I include the header file by using the directive `#include` in my project, how does the system know where to find it?**

When you include a header file using the #include directive in your C++ project, the system or the compiler follows a predefined search path to locate the header file. Here's how it typically works:
1. *Standard Library Header Files' paths*: The compiler first looks in its system directories for standard library headers. These directories are predefined and include paths like `/usr/include` on Linux and macOS or `C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\include` on Windows, depending on your development environment.
1. *User-Defined Paths*: If the header file is not found in the system directories, the compiler checks additional paths that you can specify. These paths can be set in several ways:
    1. *Command-Line Options*: You can use command-line options to specify include directories with the `-I` flag (e.g., `-I/path/to/includes`).
    1. *Environment Variables*: Some compilers allow you to set environment variables (e.g., `CPLUS_INCLUDE_PATH` or `CPATH`) to specify additional include paths.
    1. *IDE or Build System Settings*: Integrated development environments (IDEs) like Visual Studio or build systems like CMake allow you to configure include directories in project settings or configuration files.
1. *Relative Paths*: If you include a header with a relative path (e.g., `#include` "`myheader.h`"), the compiler looks for the header file relative to the location of the source file that includes it.
1. *Library-Specific Paths*: Some libraries may have their own include paths that you need to configure separately when using those libraries. (?)

To find from where your system look for the header files, [run][1]:
```shell
    $(gcc -print-prog-name=cc1plus) -v
```
for `C++`, and
```shell
  $(gcc -print-prog-name=cpp) -v  
```
for `C`. For instance, you can check that `/usr/include/c++/11/cstdio` is indeed in your `C++` system path. If so, the system reads from this file whenever you type the `#include cstdio`directive.

To see all the recursive header filer depencency, you can [run][2]:
```shell
    g++ -MM -H main.cpp
```
where `main.cpp` is the main `C++` file in your project.

**And the library, where is it located?**
The `C++` Standard Libraries are typically bundled with the `g++` compiler. When you install `g++` or any other `C++` compiler, it includes the necessary standard libraries required to compile and link `C++` programs. These libraries are an integral part of the compiler distribution. Therefore, they don't exist as a separate shared library file on your system and you won't find it by looking for a .so (shared library) file.

---
## Example

In this example, we have a main program (`main.cpp`) that includes the header file `mylib.h`. The header file provides the function prototype for `printMessage()`. The actual implementation of `printMessage()` is defined in separate source files `mylib_static.cpp` and `mylib_shared.cpp`, which are compiled into static (`libmylib_static.a`) and shared (`libmylib_shared.so`) libraries, respectively.

Now, let's compile and use these files to create both a static and shared library.

1. **Create a static library** (leave only the function declaration of the static library in `mylib.h`):
    ```
    g++ -c mylib_static.cpp -o mylib_static.o
    ar rcs libmylib_static.a mylib_static.o
    ```
    - The `-c` option in the `g++` command stands for "compile-only" or "compile source files to object files." When you compile a source file with the `-c` option, it instructs the compiler to perform compilation steps up to generating the object file, but it does not perform the linking step. Therefore, The C++ compiler (`g++`) only compiles `myfile.cpp` into an object file (`myfile.o`). Using the `-c` option is useful when you want to compile individual source files separately and then link them together later. It allows for faster compilation when you have multiple source files, as you can compile them independently and avoid recompiling the entire program every time.
    - `ar` stands for "archive" and is a command-line utility for creating and manipulating static libraries. It combines one or more object files into a single archive file. In the case of a static library, it allows you to package your compiled code into a single file that can be linked with other programs during the compilation process.
        - `r`: Replace or add files to the archive.
        - `c`: Create the archive if it doesn't exist.
        - `s`: Write an index into the archive, which helps with faster symbol lookup during linking
    - `libmylib_static.a` is the name of the static library that will be created. The prefix `lib` is commonly used for libraries, followed by the name of the library (`mylib_static` in this case), and **the extension `.a` indicating it's a static library**.
    - The reason you needed to use the `ar` command separately is that creating a static library involves an additional step of archiving the object files into a single library file. When you compile a source file with `g++`, it produces an object file (e.g., `mylib_static.o`) that contains the compiled machine code for the functions in that source file. To create a static library, you may need to combine multiple object files into a single library file, which can be achieved using the `ar` command. Let's say you have two source files: `foo.cpp` and `bar.cpp`. You want to create a static library that includes the functions defined in both files. First, compile each source file into object files:
    ```
    g++ -c foo.cpp -o foo.o
    g++ -c bar.cpp -o bar.o
    ```
    Next, use the `ar` command to combine the object files into a static library:
    ```
    ar rcs libmylib.a foo.o bar.o
    ```
    After running the above commands, you will have a static library file `libmylib.a` that contains the compiled functions from both `foo.cpp` and `bar.cpp`. You can then link this library with your main program during the compilation process. On the other hand, when creating a shared library, you typically compile each source file separately into object files and then link them together to create the shared library file.
1. **Create a shared library** (leave only the function declaration of the shared library in `mylib.h`). When creating a shared library, you typically compile the source files into object files (`*.o`) first, and then use the linker to combine these object files into a shared library. To convert the `.cpp` file to an object file, run:
    ```
        g++ -c -fPIC mylib_shared.cpp -o mylib_shared.o
    ```
    - `-fPIC`: This option stands for "Position Independent Code" is used when creating a shared library to ensure that the generated code is relocatable. Relocatable code can be loaded into memory at different addresses by the operating system without any issues. This is crucial for shared libraries because multiple processes can use the same shared library, and each process may load the library at a different address in memory.

    Then, you can create an shared library `.so` by linking these object files together:
    ```
        g++ -shared mylib_shared.o -o libmylib_shared.so
    ```
    - `-shared`: This option instructs the compiler (or linker) to create a shared library instead of an executable or a static library. A shared library contains code and data that can be loaded into memory and shared by multiple programs at runtime. It allows for dynamic linking, where the library is linked with the executable when it is loaded or during runtime.

    The reason you use different tools (`ar` for static libraries and `g++` for shared libraries) to create libraries is due to the nature of the libraries themselves and how they are meant to be used. When you create a static library, you're essentially creating an archive of object files. `ar` is specifically designed for that task. On the other hand, `g++` (or any `C`/`C++` compiler) can be used to create shared libraries. When you use `g++` to create a shared library, you're essentially compiling the source code directly into a shared library file (`.so` on Linux).

    Alternatively, if your shared library is based only on one `.cpp` file, you can directly convert it to the shared library as follows:
    ```
        g++ -shared -fPIC mylib_shared.cpp -o libmylib_shared.so
    ```
    In practice, both approaches are common, and the choice between them often depends on the development workflow and the complexity of the project. Compiling to object file first is the more traditional and flexible approach. You first compile the source code into object files separately. This approach offers several advantages:
        - Incremental Builds: If your project has multiple source files, you can compile them individually to object files. When you make changes to one source file, you only need to recompile that file and relink, which can significantly speed up development.
        - Reusability: You can reuse the object files in multiple projects or when creating different libraries/executables.
        - Better Control: You have more control over the compilation process and can optimize individual source files differently.
    In the direct compilation to shared library, you compile the source code directly into a shared library without generating intermediate object files. This can simplify the build process, especially for small projects. However, it has some limitations:
        - Slower Builds: Compiling the entire source code into a shared library in one step can be slower, especially for larger projects, as all code must be recompiled each time.
        - Limited Reusability: The shared library generated may not be as reusable across projects, as it includes all the compiled code in one file.
1. Compile and link the main program with the libraries. 
    - Using the static library:
    ```
    g++ main.cpp -L. -lmylib_static -o program_static
    ```
    - Using the shared library:
    ```
    g++ main.cpp -L. -lmylib_shared -o program_shared
    ```
    - The `-L.` option is a compiler flag that specifies the directory where the linker should search for libraries specified by the `-l` option. In this case, the dot `.` represents the current directory.
    - When compiling the main program, we specify the library to link against using the `-l` option (e.g., `-lmylib_static` or `-lmylib_shared`). The linker (`ld`) resolves the function call to `printMessage()` by looking for the corresponding implementation in the linked library.
1. Run the programs:
    - `./program_static` for the static library
    - Before running `./program_shared` for the shared library, you must check whether the path of your shared library (`libmylib_shared.so`) is within the `LD_LIBRARY_PATH` environment variable. Setting the LD_LIBRARY_PATH environment variable is often necessary when you want to run an executable that depends on shared libraries that are not in the standard library search paths. This environment variable tells the dynamic linker where to find those libraries at runtime. If it is not set, you can run `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)` and then run `./program_shared`. Otherwise, you will get the error "./program_shared: error while loading shared libraries: libmylib_shared.so: cannot open shared object file: No such file or directory". This shows the fundamental difference between static and shared (or dynamic) library: shared library is loaded and linked dynamically at runtime when the program is executed. If it is not found by the linker, the program doesn't run.


[1]: https://stackoverflow.com/questions/344317/where-does-gcc-look-for-c-and-c-header-files/344525#344525
[2]: https://stackoverflow.com/a/18593344/13998346
