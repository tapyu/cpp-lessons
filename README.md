# Libraries

#### **What is a library?**

A C/C++ library is a collection of precompiled code modules that can be used to perform common tasks or provide reusable functionality within C or C++ programs. 

#### **How does a library look like on my computer?**

Libraries on your computer are typically stored as binary files. The exact file format and organization can vary depending on the programming language, the platform.
- *Shared Libraries (Dynamic Link Libraries - DLLs on Windows, Shared Objects - SO files on Linux, Dylibs on macOS)*: These are libraries that are loaded at runtime when a program is executed. They have a file extension like `.dll`, `.so`, or `.dylib`. These files contain compiled code that multiple programs can use simultaneously. They are typically stored in system directories or directories specified in the system's library search path.
- *Static Libraries (Libraries - LIB files on Windows, Archive files - A files on Linux)*: These are libraries that are linked with the program at compile-time. They contain precompiled object code. On Windows, they have a `.lib` extension, and on Linux, they are often archive files with a `.a` extension. Static libraries are linked directly into the executable, increasing the size of the resulting binary.
- *Standard Libraries*: The standard libraries for C and C++ are typically provided as part of the compiler installation. These libraries include the C Standard Library (libc on Unix-like systems), the C++ Standard Library (libstdc++ or libc++ on Unix-like systems), and others. They are typically located in system directories.
- *Header Files*: In addition to the binary library files, libraries often provide header files (with extensions like `.h`, `.hpp`, or `.hxx`) that contain function declarations, classes, and data structures provided by the library. Header files typically come with the library file to enable users to use the library's functionality without having to dig deep into the source core. Moreover, for proprietary programs, we don't have access to the source code, at all, and therefore the header files might be our unique way out to understand how to use the library.

#### **Main categories for a C/C++ library**
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

#### **What is the header file?**

Header files are human-readable files that serve to communicate the interface of the library to users, enabling them to properly use and interact with the library's features. When using a library, whether static or shared, it is common practice to provide a corresponding header file that contains the necessary declarations for the library's functions, classes, structures, and other entities. This allows users of the library to include the header file in their own code and access the functionality provided by the library. In `C++`, the `#include` directive is used to include header files. Directives are commands or instructions that are processed by the preprocessor before the actual compilation of the code. Directives are typically preceded by the `#` symbol. Header files typically contain function declarations, class definitions, constants, and other declarations that are needed for the compilation and usage of functions and types defined in the external source file (`.cpp` file).
- User-Defined Header Files:
    - These files are typically given a `.h` extension, and sometimes a `.hpp` extension in `C++` to indicate that they are header files.
    - When including user-defined header files, the `#include` directive is typically used with double quotes, which means to search in the current directory (relative path). For example, `#include "myheader.h"` means to access the file `./myheader.h`.
    - User-defined header files contain declarations and definitions specific to your project or library and are often organized within your project's directory structure.
    - It is a common convention to give them the same base name (e.g., `mylib.h` and `mylib.cpp`) for clarity and organization, but it is not a strict requirement. 
- `C++` Standard Library Header Files:
    - `C++` Standard Library header files often do not have a `.h` extension, and they are included using angle brackets, like `#include <iostream>`.
    - The omission of the `.h` extension is a convention within the `C++` Standard Library to distinguish these headers from traditional `C` headers, which often use the `.h` extension.
    - These headers provide standardized interfaces to `C++` language features and standard library components.
It is important to note that while these conventions are common, they are not strict rules enforced by the language itself. The presence or absence of the extension doesn't affect how the compiler or preprocessor treats the file. The choice of file extension and inclusion method is ultimately defined by the project's convention.

However, it is also important to note that header files are not used exclusively for libraries; they are a fundamental part of `C`/`C++` programming and serve various purposes beyond just defining library interfaces. Header files are also used to:
- *Declare Function Prototypes/declarations*: Header files commonly declare function prototypes, allowing you to use functions defined in other source files. This is essential for breaking up your code into multiple source files while maintaining proper encapsulation. See `./c-header-files-for-func-prot`
- *Share Common Definitions*: Header files can contain shared constants, macros, and data structure definitions that multiple source files need. This promotes code reusability and consistency.

#### **What is the difference between a shared and a static library?**

Shared Libraries (Dynamic Link Libraries on Windows, Shared Objects on Linux, and Dylibs on macOS) and Static Libraries serve different purposes in software development and are linked with programs in different ways. The main difference between using a shared library and a static library lies in how the library is linked to your program at runtime. When you link against a static library, the library code is physically copied into your executable file during the linking process. This means that your program becomes self-contained and can be run independently without relying on the presence of the static library at runtime. The library code becomes part of your program's binary.

On the other hand, when you link against a shared library, your program only contains references to the functions or symbols provided by the library. The actual library code resides in a separate shared library file (`.so` file on Linux, `.dll` file on Windows). At runtime, the operating system dynamically loads the shared library and resolves the references from your program to the corresponding functions in the library. This allows multiple programs to share the same instance of the library in memory, reducing memory usage. **When you use a shared library (whether it's part of the C standard library or not), you typically need to manually specify the library for linking using the `-l` option with gcc or g++** (is that correct? I got this from ChatGPT) (see the `C` example in `c-link-shared-lib/`). The `-l` option is followed by the name of the library (without the `lib` prefix and the file extension). The order of the `-l` option matters in the `gcc`/`g++` command [because][4] when you add a library using the `-l` option, the linker does not unconditionally take all object files from the library. It only takes those object files that are currently needed, i.e. files that resolve some *currently* unresolved (pending) symbols. After that, the linker completely forgets about that library. If you specify just the library name (e.g., `-lmylibrary`), the linker usually prioritizes shared libraries (some libraries have their shared and static version) unless `-static` is used. If you specify the full name of a static library with its extension (e.g., `-lmylibrary.a`), it will look for the static version. If the library is located in a non-standard directory, you may also need to use the `-L` option to specify the library directory. In practice, if you're unsure, it's often safe to use the library name without an extension (e.g., `-lmylibrary`) when linking, and the linker will choose the appropriate version based on system defaults. If a shared library is available, it will be used; otherwise, the static library will be used.

In terms of workflow, the process of compiling and linking your program is generally the same whether you're using a shared library or a static library. You still need to include the necessary header files, link against the library, and ensure the library is properly installed on the system.

Overall, the choice between using a shared library or a static library depends on various factors, including the specific requirements of your program, considerations for memory usage, ease of deployment, and potential library versioning issues.

A shared library is often referred to as a runtime library because it is loaded and linked dynamically at runtime when the program is executed. It provides functionality that can be accessed by multiple programs simultaneously. A static library, on the other hand, is often referred to as a development library because it is used during the development and compilation phase of a program. It contains precompiled code that is linked directly into the executable at compile time, making the program self-contained and independent of external dependencies. However, it's important to note that these terms can sometimes be used interchangeably or with different interpretations depending on the context. The key distinction is that shared libraries are dynamically linked at runtime, while static libraries are statically linked at compile time.

#### **Static binary vs. dynamic binary**

Static linking involves including all library code into the executable at compile time. When you have a static binary, all the code needed to run the program is contained within a single executable file, that is, the executable is self-contained. This means that the program doesn't rely on external shared libraries at runtime. Advantages include ease of distribution (no external dependencies) and potentially slightly faster startup times. However, [static binaries are very seldom nowadays]. they have their use in special cases (like the tools in your initial ramdisk that doesn't have the infrastructure to support dynamic libraries) but other than that are not really in use and pretty much impossible to create for more complex programs due to plenty of libraries not supporting static linking.

Dynamic linking involves linking to shared libraries (or dynamic link libraries, DLLs) at runtime. When you have a dynamic binary, the executable is smaller, and the necessary library code is loaded into memory when the program starts or when the specific library function is called. This allows for more efficient memory usage when multiple programs use the same shared library. Changes to the shared library are reflected across all programs using it without recompiling them. Advantages of dynamic binaries are that libraries can be reused between different running applications,so they need less space and memory.

| Static Binary | Dynamic Binary |
| ---------|----------|
| Larger executable size. | Smaller executable size. |
| No external dependencies. | External dependencies on shared libraries. |
| Potentially faster startup time. | Increased startup time. |
| Potentially easier distribution. | Easier to update shared libraries without recompiling every binary. |

#### **Header file paths**

When you include a header file using the `#include` directive in your C++ project, the system or the compiler follows a predefined search path to locate the header file. Here's how it typically works:
1. *Standard Header File search paths*: The compiler first looks in its system directories for standard header file search paths. These directories are:
    - On *Linix* and *MacOS*: You can check these paths by [running][1], for `C++`:
    ```shell
    eval $(gcc -print-prog-name=cc1plus) -v
    ```
    which are `/usr/include/c++/11`, `/usr/include/x86_64-linux-gnu/c++/11`, `/usr/include/c++/11/backward`, `/usr/lib/gcc/x86_64-linux-gnu/11/include`, `/usr/local/include`, `/usr/include`, and, for `C`:
    ```shell
    eval $(gcc -print-prog-name=cpp) -v
    ```
    which are `/usr/lib/gcc/x86_64-linux-gnu/11/include`, `/usr/local/include`, `/usr/include/x86_64-linux-gnu`, and `/usr/include`. For instance, you can check that `/usr/include/c++/11/cstdio` is indeed in your `C++` system path. If so, the system reads from this file whenever you type the `#include cstdio`directive.
    - On Windows (depending on your development environment): `C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\include`.
1. *User-Defined Paths*: If the header file is not found in the system directories, the compiler checks additional paths that you can specify. These paths can be set in several ways:
    1. *Command-Line Options*: You can use command-line options to specify include directories with the `-I` flag (e.g., `-I/path/to/includes`).
    1. *Environment Variables*: Some compilers allow you to set environment variables (e.g., `CPLUS_INCLUDE_PATH` or `CPATH`) to specify additional include paths.
    1. *IDE or Build System Settings*: Integrated development environments (IDEs) like Visual Studio or build systems like CMake allow you to configure include directories in project settings or configuration files.
1. *Relative Paths*: If you include a header with a relative path (e.g., `#include "myheader.h"`), the compiler looks for the header file relative to the location of the source file that includes it.
1. *Library-Specific Paths*: Some libraries may have their own include paths (outside the standard header file search paths) that you need to configure separately when using those libraries.

You can also check the header file dependency tree that is being used in a souce file by [running][2]:
```shell
    g++ -MM -H main.cpp
```

#### **Linking between a header file and its library**

Although the name of the header file may give a clue as to which library is being used, in general, **it's not possible to directly determine the library location (path+lib name) that is linked to the header file**. If an open-source project is using 3th-party libraries, it must specify which ones are being used beforehand. Then, you must install these libraries (see "How to install C/C++ libraries"). The installed library must be explicitly or implicitly linked if it isn't the C standard library (in this case, it is usually linked automatically). The linking process can be further divided into two types: static linking and dynamic (or shared) linking. Static library linking are resolved at compile time while shared library linking are resolved at runtime. The linker can solve it in several ways:

1. *The `C/C++` Standard Library*: The `C/C++` Standard Library generally refers to the library that is specified by the ISO C standard (ISO/IEC 9899). This library includes standard functions, macros, and types that are part of the C programming language. When people talk about the C Standard Library, they are usually referring to the set of functions and features defined by the ISO C standard. However, there is more than one implementation of the C Standard Library, and the specific implementation used can vary. Some of the common C standard libraries include:
    1. glibc (GNU C Library): glibc is the C library implementation provided by the GNU Project. It is widely used on Linux systems and many other Unix-like operating systems. The library file is often named `libc.so.x`, where "x" represents the version number.
    2. Musl libc: Musl is a lightweight and fast C library designed for embedded systems and minimalistic environments. Some Linux distributions, such as Alpine Linux, use Musl libc as an alternative to glibc.
    3. uClibc: uClibc is another lightweight C library designed for embedded systems. It aims to provide a smaller footprint than glibc, making it suitable for resource-constrained environments.
    4. Bionic: Bionic is the C library used by the Android operating system. It is a customized implementation tailored for Android-specific requirements.

    While these libraries implement the same standard functions specified by the ISO C standard, there can be some variations in behavior or additional features. In practice, the specific C library used often depends on the operating system and the choices made by the developers or maintainers of that system. **Many compilers, by default, automatically link your program with the C Standard Library**, that is, you don't need to pass the `-l` or `-L` option. Header files associated to the C Standard Library are usually `stdio.h`, `stdlib.h`, etc. **While the C Standard Library was historically provided as a static library, on many modern systems, including Linux, it is often implemented as a shared library.**
1. *Default library search paths*: At compile time and runtime, the linker must solve the linking of static and shared libraries, respectively. In both cases, the default library search path on a Linux system typically [are][6]: `/lib`, `/usr/lib`, `/lib32`,  `/usr/lib32`, `/lib64`, `/usr/lib64`, `/usr/local/lib`, `/opt/<package>/lib` (some software packages are installed in the `/opt/` directory). These directories are specified in the system's dynamic linker configuration and are usually stored in the `/etc/ld.so.conf` file and the files within the `/etc/ld.so.conf.d/` directory. You can view them using the
    ```
    ldconfig -v
    ```
    command. The `ldconfig` command also updates the linker's cache to include any new libraries installed in these paths. The paths in the `LD_LIBRARY_PATH` environment variable is also included in the standard system library paths.**At compilation time, when a library is in one of the default library search paths, you don't need to explicitly use the `-L` option to indicate the path to the library. The linker will automatically search these standard paths**. It is important to note, however, that `-L` specifies an additional directory where the linker should look for libraries only during the linking phase of the compilation time. **It does not affect the runtime library search path, which looks for only in the default library search paths**. Therefore, if the library is shared, then it needs to be searched at runtime and must be in the default library search paths.
1. *Explicit linking*: During the compilation time and for libraries other than the Standard C library, you should use the `-l` flag followed by the library name without the `lib` prefix and the `.a` or `.so` extension. Moreover, if the library path is different from the default librarry search paths, you need to pass the `-L` option followed by the path you want the linker search for. For example, in `g++ main.cpp -L. -lmylib_shared -o program_shared`, the `-L.` option is a compiler flag that specifies the directory path where the linker should search for libraries specified by the `-l` option.
1. *Implicit Linking*: Some libraries may be implicitly linked when you use certain compiler options or language features. For example, when you use OpenMP directives in your code (`#pragma omp`), the OpenMP runtime library is typically linked automatically.

When you have the executable, you can use the `ldd` command, which is a Linux utility used for printing the shared library dependencies of an executable or a shared library. It stands for "List Dynamic Dependencies." When you run `ldd` followed by the path to an executable or shared library, it will display a list of the shared libraries that the specified binary depends on.

```sh
ldd /path/to/your/executable
```

For instance, run `ldd c-link-shared-lib/geom` to list the all the shared libraries dependency and see where the `libm` library is located in you system. This path comes from the `/etc/ld.so.conf.d/x86_64-linux-gnu.conf` config file. That is, the linker can associate this library from the standard system library paths. See this [amazing video][7] about linking libraries manually.


#### **When to use a library over a source `.c`/`.cpp` code and its header file**

Whenever you see a set of classes (or whatever) that fulfill a more general need than just this project. [For instance][3], an Engineer called Steve Baker is writing C++ in the “wasm” environment (I have no idea what this shit is) for running C++ in a browser window. So his “general web storage” software is an absolute ‘natural’ for turning into a library. He knows for 100% sure that sometime in the future, he will need something like this in another C++/wasm environment - so he is writing this code with generality in mind and it’s going into a stack of other libraries I’ve written over the years.

#### **How to install `C`/`C++` libraries?**

On Linux, you can obtain more `C`/`C++` libraries via
1. Package manager: Most Linux distributions provide a package manager (e.g., `apt` for Debian/Ubuntu, `yum`/`dnf` for Red Hat/Fedora, `pacman` for Arch Linux) that allows you to easily install software packages, including libraries.
    - On Ubuntu:
        - You can search on https://packages.ubuntu.com/ for a header file or a library and find out which Ubuntu package contain it. [For instance][9], by searching for `poppler`, you can find that the Ubuntu package [`libpoppler-cpp-dev`][8] contains `cpp/poppler-document.h`, which is required in the project. Alternatively, you can use the terminal (if `apt-file` is not present, you must `apt-get` it)
        ```
        ❯ apt-file -x search 'cpp/poppler-document.h'
        libpoppler-cpp-dev: /usr/include/poppler/cpp/poppler-document.h
        ```
        to find out which package contains that file.
        - You can run `dpkg --list` to get all installed packages, in addition to its description and the architecture. `pkg-config --list-all` can also do that, but the package is named as it is in the `.pc` (pkg-config) file, [see here][10].
        - The command `dpkg -L libpoppler-cpp-dev` shows all files in the `libpoppler-cpp-dev` package.
1. Some libraries may not be available as pre-packaged binaries in your distribution's repositories. In such cases, you can download the source code for the library and compile it yourself. The process generally involves running `./configure`, `make`, and `make install` commands.

#### [How to find out/discover more C/C++ libraries][11]


[1]: https://stackoverflow.com/a/344525/13998346
[2]: https://stackoverflow.com/a/18593344/13998346
[3]: https://www.quora.com/When-should-one-build-libraries-for-personal-C-projects
[4]: https://stackoverflow.com/questions/11893996/why-does-the-order-of-l-option-in-gcc-matter
[5]: https://youtu.be/GExnnTaBELk?t=941
[6]: https://unix.stackexchange.com/a/22937/480687
[7]: https://www.youtube.com/watch?v=tOQZlD-0Scc&ab_channel=LowLevelLearning
[8]: https://packages.ubuntu.com/kinetic/amd64/libpoppler-cpp-dev/filelist
[9]: https://stackoverflow.com/questions/77226416/how-to-know-the-linux-package-name-i-need-to-install-in-order-to-get-a-missing-c
[10]: https://stackoverflow.com/a/16702644/13998346
[Static binaries are very seldom nowadays]: https://www.reddit.com/r/linux/comments/6pkzf5/static_and_dynamic_binaries/
[11]: https://www.reddit.com/r/cpp_questions/comments/17mor5v/comment/k7mqam1/?context=3
