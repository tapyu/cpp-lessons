# Build process

<p align="center">
  <img src="assets/general-build-process.jpg" alt="All the build/compilation process">
</p>

**What is a compiler?**

C/C++ compilers are software tools that translate human-readable source code written in the C or C++ programming languages into [*machine languages*][10], that is, a set of instructions made of zeros and ones. This set of instructions are represented in the computer as an executable file that can run on a computer's hardware.

**What is the build process?**

Build process is a multi-stage process that includes
- Preprocessing
- Compiling
- Assembling
- Linking

The key step is the compilation phase, where the source code is analyzed, optimized, and translated into an intermediate representation known as assembly code (for `C`) or object code (for `C++`). The software that perform these processes tasks are called *compiler* (although compiling is just one of the steps performed by the compiler).

#### **What are the main `C`/`C++` compilers and debuggers?**

- GCC (GNU Compiler Collection): One of the most widely used open-source compilers, GCC supports a variety of programming languages, including `C` and `C++`. It's available on multiple platforms, making it a popular choice for `C`/`C++` development. Both `gcc` and `g++` are part of the GCC suite and are commonly used to compile `C` and `C++` programs on various platforms, including Unix-like systems (Linux, macOS, BSD), as well as Windows through tools like MinGW or MSYS2. MinGW is a port of the GCC (GNU Compiler Collection) for Windows. It provides a GCC-based development environment on Windows. Developers who prefer GCC and a more Unix-like development experience often use MinGW on Windows.
  - `gcc`: The GNU `C` Compiler, which primarily compiles `C` code.
  - `g++`: The GNU `C++` Compiler, which compiles `C++` code.
  - `gdb`: The GCC debugger.
- Clang: Developed by the LLVM project, Clang is known for its fast compilation times and excellent diagnostics. It's often used as an alternative to GCC, especially in the `C++` community. On [macOS][2], the most commonly used `C`/`C++` compiler is Clang, which is part of the LLVM (Low-Level Virtual Machine) project. Clang has become the default compiler on macOS for `C` and `C++` development.
  - `clang`: `C` compiler
  - `clang++`: `C++` compiler
  - `lldb`: The LLVM debugger.
- Microsoft Visual `C++` (MSVC): MSVC is the compiler provided by Microsoft as part of Visual Studio. It's a primary choice for [Windows][4] development with `C++`.
- Intel `C++` Compiler: Intel's compiler is known for its optimization capabilities, especially for Intel processors. It's commonly used in high-performance computing (HPC) and scientific computing.

A more detailed comparision between `gcc` and `clang` can be found in [here][21].

#### **What are the main options/flags used when running a compiler?**
Although there are many `C`/`C++` compilers out there, their options/flags are stardarized. The main options are:
<table>
<tr>
  <th colspan="2"><h2>Most used options</h2></th>
</tr>
<tr>
  <th>Option</th>
  <th>Description</th>
</tr>
<tr>
  <td><code>-O0</code>, <code>-O1</code>, <code>-O2</code>, <code>-O3</code>, <code>-Os</code></td>
  <td>Optimization level, where <code>0</code>, <code>1</code>, <code>2</code>, <code>3</code>, and <code>s</code> stand for "no optimization", "basic optimization", "moderate optmization", "high-level optimization", and "code size optimization" (which means prioritizing the reduction of the size of the generated machine code at the expense of some potential runtime performance), respectively.</td>
</tr>
<tr>
  <td><code>-g</code></td>
  <td>Include debugging information in the generated executable. It adds debugging symbols to the binary, which can be extremely helpful for debugging and analyzing your program when it encounters issues or crashes. <b> You can only debug a compiled executable if you add debugging informantion in it by using this flag at compile time</b>.</td>
<tr>
<tr>
  <td><code>-Wall</code></td>
  <td>Enables most commonly used warning messages.</td>
</tr>
<tr>
  <td><code>-Wextra</code></td>
  <td>Enables some additional warning messages not covered by <code>-Wall</code>.</td>
</tr>
<tr>
  <td><code>-Wunused</code></td>
  <td>Warn about unused variables, functions, etc.</td>
</tr>
<tr>
  <td><code>-Wuninitialized</code></td>
  <td>Warn if a local variable is used without being initialized.</td>
</tr>
<tr>
  <td><code>-Wformat</code></td>
  <td>Check calls to <code>printf</code> and <code>scanf</code>, etc., for format string issues.</td>
</tr>
<tr>
  <td><code>-std=<ins>std</ins></code></td>
  <td>Specify the language standard to which the program should conform. For C++ (using <code>g++</code> or equivalent), you can use <code>-std=c++11</code> to specify that your code should conform to the C++11 (2011) standard, <code>-std=c++14</code> for C++14 (2014), <code>-std=c++17</code> for the C++17 (2017), or <code>-std=c++20</code> for C++20 (2020). For C (using <code>gcc</code> or equivalent), you can use <code>-std=c89</code> or <code>-ansi</code> to specify the ANSI (American National Standards Institute) C standard published in 1989 by by ANSI (it is the original/first standard for the C programming language), <code>-std=c99</code> to specify the C99 standard (which is the 1999 revision of the C standard. It introduced several new features and improvements over the original ANSI C standard, in 1989), <code>-std=c11</code> to Specify the C11 standard (which is the 2011 revision of the C standard. It includes additional features and improvements over C99). Using the correct <code>-std</code> flag is important to ensure that your code is compatible with the features and syntax defined in a particular version of the C/C++ standard.</td>
<tr>
<tr>
  <td><code>-I<ins>path</ins></code></td>
  <td>Specify a directory to be searched for header files. It adds the given directory to the list of places to look for header files during compilation. For multiple directories, you must use <code>-I<ins>path</ins></code> multiple times.</td>
</tr>
<tr>
  <td><code>-M</code></td>
  <td>Generates a list of makefile dependencies suitable for use with <code>make</code>.</td>
</tr>
<tr>
  <td><code>-MM</code></td>
  <td>Similar to <code>-M</code>, but it doesn't include system header files.</td>
</tr>
<tr>
  <td><code>-MF <ins>path/to/file</ins></code></td>
  <td>Specifies the name of the file to write the dependencies to.</td>
</tr>
<tr>
  <td><code>-MT <ins>target</ins></code></td>
  <td>Specifies the name of the target to consider when looking for dependencies.</td>
</tr>
<tr>
  <td><code>-D<ins>MACRO</ins></code></td>
  <td>Define a preprocessor macro. For instance, in <code>gcc -DDEBUG my_program.c -o my_program</code>,<code>-DDEBUG</code> option defines a macro named <code>DEBUG</code>. This means that, during the compilation process, the preprocessor will replace occurrences of DEBUG in your source code with the specified value, which is typically 1. If you don't provide a value after <code>-D</code>, the macro is defined with a value of 1 by default. You can use this technique to conditionally include or exclude portions of code based on whether a certain macro is defined. For instance, you might have something like:
<code>
#ifdef DEBUG
  // Debug-specific code here
#endif
</code>
    So, if you compile your program with -DDEBUG, the code within the #ifdef DEBUG block will be included; otherwise, it will be excluded. This is a common practice for enabling or disabling debugging statements or features in your code without modifying the source directly.</td>
</tr>
<tr>
  <th colspan="2"><h2>Not so used</h2></th>
</tr>
<tr>
  <td><code>-Werror</code></td>
  <td>Treats all warning messages as errors.</td>
</tr>
<tr>
  <td><code>-Wconversion</code></td>
  <td>Warn about implicit type conversions that may lose data. This can catch potential bugs related to type conversions.</td>
</tr>
<tr>
  <td><code>-Wshadow</code></td>
  <td>Warn when a local variable shadows another variable. It helps avoid unintended variable shadowing.</td>
</tr>
</table>

---

## The usual and most direct compilation process (without build automation tools)

For 99.9999% of cases, to get the compilation done, it is enough to run
  ```
  ❯ gcc main.c -o straight-forward-program
  ❯ ./straight-forward-program
  Hello, World!
```

However, under the hood, the preprocessing, compiling, assembling, and linking have occurred silently. Let us break each step down.

---

## Preprocessing

![](./assets/preprocessing.png)

- [The][1] input file for this stage is `*.c` file.
- It performs the following tasks:
  - Removing comments : It removes all the comments.
  - [Line Splicing][18] (`\`): The backslash `\` is used for line splicing, allowing you to break long lines of code into multiple lines for readability, are concatenated to form a single line.
  - Header files inclusion: [For][16] example, if the directive `#include <stdio.h>` is available in the program, then the preprocessor interprets the directive and replaces this directive with the content of the `/usr/include/stdio.h` file.
  - *Macro* expansion: A macro is a preprocessor directive that allows you to define a symbolic name or identifier for a sequence of code. They are used to create code snippets that can be easily reused and to introduce simple text substitutions. The most common use of macros in C is through the `#define` directive, which defines a macro. They can be [constant][17] macros, e.g., `#define BUFFER_SIZE 1024`, or [function-like][18] macros, e.g., `#define MAX(a, b) ((a) > (b) ? (a) : (b))`.
  - Resolve the *conditional compilation directives*: Using special preprocessing directives, you can include or exclude parts of the program according to various conditions. For example, `#ifdef DEBUG printf("Debugging is enabled.\n"); #endif`. Other conditional compilations are `#ifndef`, `#if`, `#elif`, `#else`. The preprocessor evaluates these conditions and determines whether the enclosed code should be included in the preprocessed output file.
  - *Line Control*: The `C` preprocessor [informs][19] the `C` compiler of the location in your source code where each token came from. A token in C can be defined as the smallest individual element of the C programming language that is meaningful to the compiler. It is the basic component of a C program. They can be Keywords (`double`, `if`, `while`, `return`, ...); Identifiers (variable and function names); Constants (`const int c_var = 20;`); Strings;  Special Symbols (`[]`, `()`, `{}`, `,`, `#`, ...); Operators (unary, binary, and ternary operators);
- In nutshell, the preprocessor expands the code.
- The output file is `*.i` or preprocessed file. This preprocessed file is the so-called [translation unit][22] (TU) (or more casually a compilation unit) and is the ultimate input to a `C` or `C++` compiler from which an object file is generated. Our static functions are visible only within this file.

### Example

```
  gcc -E main.c -o main.i
```
- [The][15] option `-E` Stop after the preprocessing stage; do not run the compiler proper. The output is in the form of preprocessed source code, which is sent to the standard output (or to a file with the `-o` option).

Alternatively, you can directly use `cpp` (`C` preprocessor) to obtain the preprocessed file:

```
  cpp main.c -o main2.i
```
Note that both file are exactly the same
```
  ❯ cmp main.i main2.i && echo "Files are equal" || echo "Files are not equal"
  Files are equal
```

### Compilation

![](./assets/compiling.png)

- The input file for this stage is `*.i` file.
- A tool called [*compiler*][15] takes the output of the preprocessor and converts it to assembly language.
- Assembly code, often referred to as assembly language or just assembly, is a low-level programming language that uses mnemonic symbols (e.g., `MOV` for "move," `ADD` for "add") to represent CPU operations (the so-called opcode), thus making the code human-readable.
- This is exactly the same code you may have worked with when programming microcontrollers directly in assembly language (e.g., 8051 microcontroller).
``![](./assets/compiler_parts.png)

- The first part of the compiler is called Front End: in which, the analysis of program syntax and semantics happens. First stage of the front-end part of the compiler is scanning the input text and Tokenization by identifying tokens such as keywords, identifiers, operators, and literals, then passing the scanned token to the parsing tool that ensures tokens are organized according to C rules to avoid compiler syntax errors. Second stage of the front-end of the compiler is checking if the sentence that has been parsed has the right meaning. And, this semantic check, if it fails you get a Semantic Error.
- The second part convert the code to assembly code. This conversion is not a one to one mapping of lines but instead a decomposition of `C` operations into numerous assembly operations.
- The output file is `*.s` or `*.asm` file.

### example

```
  gcc -S main.i -o main.s
```
- `-S`: Stop after the stage of compilation proper;

Strictly speaking, this is the most crucial part of the compilation process and cannot be done by no one but the `gcc` compiler. When we use the `gcc` to directly generate the executable file (without breaking down all the steps), what happens under the hood is: The `gcc` delegates all other compilation steps (preprocessing, assembling, and linking) to `cpp`, `as`, and `ld`, respectively, and only performs the compilation step. By doing so, we, `C` developers, can be unworried in calling such tools as it is already done by `gcc`. Therefore, we can work with a unique command interface (the `gcc`) to perform all the compilation process.

## Assembling

![](./assets/assembler.png)

- The input file for this stage is `*.asm` or `*.s` file.
- The `-c` option of `gcc/g++` is used specifically for compiling source files into object files without linking them. It doesn't matter what extension the source file has. The -c option instructs g++ to compile the source file but not to perform the linking step. The `-c` accepts both C (`.c`) or Assembly (`.s` or `.asm`) code.
- Each assembly instruction typically represents a single machine code instruction, which is a set of `0`'s and `1`'s. A part of this binary sequence is the *opcode*, while the remainder is usually memory address of variables or a numeric value. When you write Assembly code, you are essentially writing low-level instructions that are specific to the instruction set architecture (ISA) of the processor you are targeting. As a result, Assembly code written for one architecture is not directly executable on a different architecture.
- The tool that converts Assembly code into machine code is called *assembler*, and this task is called *assembling*.
- Likewise, the machine code generated by the assembler is also platform-specific, meaning that it is tailored to a specific computer architecture and operating system. The machine instructions for one type of CPU will probably not run on a different CPU architecture without modification.
- In low-level microcontroller programming, the assembler converts the assembly code into machine code (typically represented in hexadecimal) and embed it into the microcontroller, which reads this binary sequence and runs the program.
- [On the other hand][23], in `C`/`C++`, the assembler converts the assembly code into a `.o` intermediate file, known as object file. This intermediate representation is also a non-human-readable machine-level code, but is augmented with a symbol table with names and tags to make executable blocks (AKA modules) identifiable and relocatable. The `.o` file is not the final executable code, that is, it contains machine-readable instructions that cannot be directly executed by the operating system. This is because the linker will still realocate the modules of the object files and combined them with library file(s) to form a single executable file.
- The output file is `*.o` or `*.obj` file.

### example

```
  gcc -c main.s -o main.o
```
Alternatively, you can run
```
  as main.s -o main.o
```

where `as` the the GNU assembler. Note that both output are exactly the same. Again, you can check that both approaches produce the same output:
```
  ❯ cmp main.o main2.o && echo "Files are equal" || echo "Files are not equal"
  Files are equal
```

## Linking

*A quick historical note:*
[In][20] the old days, when dinosaurs roamed the data centers, many programs were complete in themselves. In those days there was generally no compiler–people wrote directly in assembly code–and the assembler actually generated an executable file which the machine could execute directly. As languages liked Fortran and Cobol started to appear, people began to think in terms of libraries of subroutines, which meant that there had to be some way to run the assembler at two different times, and combine the output into a single executable file. This required the assembler to generate a different type of output, which became known as an object file (I have no idea where this name came from). And a new program was required to combine different object files together into a single executable. This new program became known as the linker (the source of this name should be obvious).

![](./assets/linker.png)

- The input file for this stage is `*.o` file.
- The linker merges all the object code from multiple modules into a single one. If we are using a function from libraries, linker will link our code with that library function code.
- The `C` Standard Libraries are typically bundled with the `gcc` compiler. When you install `gcc` or any other `C` compiler, it includes the necessary standard libraries required to compile and link `C` programs. These libraries are an integral part of the compiler distribution. Therefore, they don't exist as a separate shared library file on your system and you won't find it by looking for a `.so` (shared library) or `.a` (static library) file.
- For libraries outside the `C` standard library, you must to link it manually.


### example

```
  gcc main.o -o myprogram
```

where `myprogram` is the executable file. Alternatively, you could directly use the `ld` command (the GCC linker) or `lld` (the LLVM linker) but guess what? Although it is not the most crucial part, manually linking you object file to an executable file is **COMPLICATED AS HELL**. At this point you are literally twiddling bits to perfectly match with the hardware and OS specifications of your machine. You must undestand stuffs such as computer organization and architecture, endianness, File Types, dynamic linker/loader paths, Build ID, OS Compatibility, Magic numbers, stripped and non-stripped executables, etc... Thankfully, `gcc` already knows all these details and wonderfully does this hard work for us by internally invoking `ld` with all the necessary options set. It is also important to state that, in practice, is highly not recommended to directly use `ld`. You should use `gcc` (or other compiler) instead.


---

## From executable code to the bit level: A deeper dive

The content inside `./myprogram` is the machine code or binary representation of your compiled program. It consists of instructions and data that the computer's processor can understand and execute directly. We can dive deeper and the the `./myprogram` at bit level or, equivalently, at hexadecimal level by using the `xxd` tool.

```
  xxd ./myprogram
```

Use the `-b` flag if you want to obtain bits instead hexadecimals and save it with the `.bin` extension. Its head is:

```
00000000: 7f45 4c46 0201 0100 0000 0000 0000 0000  .ELF............
00000010: 0300 3e00 0100 0000 6010 0000 0000 0000  ..>.....`.......
00000020: 4000 0000 0000 0000 9836 0000 0000 0000  @........6......
00000030: 0000 0000 4000 3800 0d00 4000 1f00 1e00  ....@.8...@.....
00000040: 0600 0000 0400 0000 4000 0000 0000 0000  ........@.......
00000050: 4000 0000 0000 0000 4000 0000 0000 0000  @.......@.......
00000060: d802 0000 0000 0000 d802 0000 0000 0000  ................
00000070: 0800 0000 0000 0000 0300 0000 0400 0000  ................
00000080: 1803 0000 0000 0000 1803 0000 0000 0000  ................
00000090: 1803 0000 0000 0000 1c00 0000 0000 0000  ................
000000a0: 1c00 0000 0000 0000 0100 0000 0000 0000  ................
000000b0: 0100 0000 0400 0000 0000 0000 0000 0000  ................
000000c0: 0000 0000 0000 0000 0000 0000 0000 0000  ................
000000d0: 2806 0000 0000 0000 2806 0000 0000 0000  (.......(.......
000000e0: 0010 0000 0000 0000 0100 0000 0500 0000  ................
```

1. Each hexadecimal digit contains 4 bits.
1. Each set of 4 hexadecimal digits contain 16 bits or 2 bytes (each byte contains 8 bits)
1. `00000000` counts, in hexadecimal, the number of bytes in the executable file. Each line contais 16 bytes (8 sets x 2 bytes per each set of 4 hex digits). By counting this in hexhadecimal we get `00000000`, `00000010`, `00000020`, ...
1. `.ELF............` is the actual content that the hexadecimal digits represents.
  - `7f45 4c46` represents the `ELF` values, which stands for Executable and Linkable Format. This sequence of hex digits is magic number, which is a signature indicating that this is an ELF file.
  - `0201` represents the ELF file class and data encoding (e.g., 32-bit or 64-bit, little-endian or big-endian).
  - `0100` represents the ELF file version.

Another important tool is the `objdump`, which is a command-line utility that is commonly used in Unix-like operating systems to display information about object files, executable files, and shared libraries. It is a part of the GNU Binutils suite of programming tools. `objdump` provides various functionalities for examining and analyzing binary files, including. For instance, `objdump` allows us to **dissasembly** an executable code, that is, it displays the assembly code for the instructions in a human-readable format. This is especially useful for understanding the low-level code of a program or library.
```sh
  objdump -d -Mintel ./myprogram > ./myprogram.asm # it is a sensible extension as its output is in assembly language
```

we get in the `main` section the following assembly code:
```asm
0000000000001149 <main>:
    1149:       f3 0f 1e fa             endbr64 
    114d:       55                      push   rbp
    114e:       48 89 e5                mov    rbp,rsp
    1151:       48 8d 05 ac 0e 00 00    lea    rax,[rip+0xeac]        # 2004 <_IO_stdin_used+0x4>
    1158:       48 89 c7                mov    rdi,rax
    115b:       b8 00 00 00 00          mov    eax,0x0
    1160:       e8 eb fe ff ff          call   1050 <printf@plt>
    1165:       b8 00 00 00 00          mov    eax,0x0
    116a:       5d                      pop    rbp
    116b:       c3                      ret 
```
You can say that the disassembled code you've shown is the assembly language representation of the main function in your executable, which is compatible with your computer archtecture, the operating system that you are using, etc... In other words, this set of assembly commands is totally platform-dependent, and it represents the set of instructions that make up the main function in your final program.


[1]: https://www.linkedin.com/pulse/c-build-process-details-abdelaziz-moustafa/
[2]: https://medium.com/hayoung-techlog/setup-for-c-on-mac-d2056a025c85#:~:text=Oct%203%2C%202022-,Clang%20vs%20G%2B%2B,%2B%2B%20is%20GNU%20c%2B%2B%20compiler.
[4]: https://www.reddit.com/r/cpp/comments/3pe6j9/why_should_i_use_clang_over_g/
[5]: https://llvm.org/
[6]: https://stackoverflow.com/questions/5708670/llvm-vs-clang-on-os-x#:~:text=LLVM%20is%20a%20backend%20compiler,a%20representation%20suitable%20for%20LLVM.
[8]: https://en.wikipedia.org/wiki/LLVM
[9]: https://en.wikipedia.org/wiki/Just-in-time_compilation (?)
[10]: https://cplusplus.com/doc/tutorial/introduction/
[11]: https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B
[12]: https://www.learncpp.com/cpp-tutorial/introduction-to-the-compiler-linker-and-libraries/
[13]: https://www.learncpp.com/cpp-tutorial/introduction-to-programming-languages/
[14]: https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
[15]: https://www.linkedin.com/pulse/understanding-c-program-compilation-process-fernandez-barreto/
[16]: https://www.linkedin.com/pulse/explanation-all-steps-compilation-juan-diego-petter/
[17]: https://gcc.gnu.org/onlinedocs/cpp/Object-like-Macros.html
[18]: https://en.wikipedia.org/wiki/C_preprocessor#Phases
[19]: https://gcc.gnu.org/onlinedocs/cpp/Line-Control.html
[20]: https://www.airs.com/blog/archives/38
[21]: https://alibabatech.medium.com/gcc-vs-clang-llvm-an-in-depth-comparison-of-c-c-compilers-899ede2be378
[22]: https://en.wikipedia.org/wiki/Translation_unit_%28programming%29
[23]: https://en.wikipedia.org/wiki/Interpreter_(computing)#Compilers_versus_interpreters
