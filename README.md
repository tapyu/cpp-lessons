# Pointers

## **What are pointers?**

In `C` and `C++`, pointers are variables that store memory addresses as their values. In essence, it "points" to the location in memory where a specific piece of data is stored. Pointers provide a way to indirectly access and manipulate data in memory (see `./basic-functionality/main.c`).

---

## **Pointer Syntax**

<table>
<tr>
    <th colspan="3"><h2>Pointer syntax</h2></th>
</tr>
<tr>
    <th>Code</th>
    <th><a href="https://www.youtube.com/watch?v=2ybLD6_2gKM&ab_channel=LowLevelLearning">How you should read it</a></th>
    <th>Comments</th>
</tr>
<tr>
    <td>${\color{blue}int \space \color{red}* \color{violet}px \space \color{green}= \space \color{yellow}\& \color{cyan}x}$</td>
    <td>${\color{blue}Integer \space \color{red}pointer \space \color{violet}named \space px \space \color{green}is \space set \space to}$
        ${\color{yellow}the \space address \space of \space \color{cyan}x}$.</td>
    <td>This syntax is used to initialize the pointer variable. This is the unique situation that $\color{red}*$ reads $\color{red}pointer$. In all others, $\color{red}*$ will denote the dereference process. By "integer pointer", we mean that this pointer points to an address whose stored value is an integer. The syntax <code>int* px = &x;</code> can also be used as an alternative to <code>int *px = &x;</code>. Although both are commonly adopted, I prefer the latter <a href="https://stackoverflow.com/questions/14536658/pointer-syntax-in-c">because</a> <code>int* a, b;</code> produces a integer pointer <code>a</code> and an integer <code>b</code>, even though it wrongly seems that both <code>a</code> and <code>b</code> are integer pointers. However, the former is useful for casting, e.g. <code>char *char_ptr = (char*)int_ptr;</code> (see the casting branch).</td>
</tr>
<tr>
    <td>${\color{blue}int \space \color{red}* \color{violet}parr \space \color{green}= \space \color{cyan}arr}$</td>
    <td>${\color{blue}Integer \space \color{red}pointer \space \color{violet}named \space parr \space \color{green}is \space set \space to}$
        ${\color{cyan}the \space address \space of \space the \space first \space element \space in}$ ${\color{cyan} the \space integer \space array \space arr}$
        <br>or<br>
        ${\color{blue}Integer \space \color{red}pointer \space \color{violet}named \space parr \space \color{green}is \space set \space to}$
        ${\color{cyan}the \space internal \space pointer \space of \space the \space}$ ${\color{cyan} variable \space arr}$.</td>
    <td>In this command, <code>arr</code> is some <code>int</code> array. When you use this syntax, you are telling <code>parr</code> to store the memory address of the first array element of <code>arr</code> (<code>arr[0]</code>). We call this memory address the <b>internal pointer variable</b>. All <a href="https://en.wikipedia.org/wiki/Composite_data_type">composite data types</a> (e.g., arrays, structures, etc...) have its own internal pointer, and it is always the memory address of its first element (see <code>./pointer-arithmetic/int_array.c</code>). Note that it also works for strings as they are represented as <code>char</code> arrays in <code>C</code> and therefore are also a composite data type (see <code>./pointer-arithmetic/char_array.c</code>). This syntax is equivalent to <code>int *parr = &arr[0]</code>, but it is much more concise and therefore more adopted. When the compiler uses the internal pointer of the variable, we often say that "the variable <b>decays</b> into a pointer to its first element". On the other hand, we cannot write <code>int *p = i</code> if <code>i</code> is a single <code>int</code> because it is a <a href="https://en.wikipedia.org/wiki/Primitive_data_type">primitive data type</a> and therefore it has no internal pointer variable.</td>
</tr>
<tr>
    <td>${\color{red}* \color{violet}px \space \color{green}= \space \color{cyan}5}$</td>
    <td>${\color{red}The \space stored \space value \space pointed \space by \space}$
        ${\color{violet}px \space \color{green}is \space set \space to \space \color{cyan}5}$.</td>
    <td>This process is called "dereference", and it is used to assign the new value to a variable that is out of the scope in question.</td>
</tr>
<tr>
    <td>${\color{blue}int \space \color{cyan}y \space \color{green}= \space \color{red}* \color{violet}px}$</td>
    <td>${\color{blue}Integer \space \color{cyan}named \space y \space \color{green}is \space set \space to \space}$
        ${\color{red}the \space stored \space value \space pointed \space by \space \color{violet}px}$.</td>
    <td>It is also a dereference, but in the other way around, that is, the value of a variable that is out of the scope in question is assigned to a local variable.</td>
</tr>
<tr>
    <td>${\color{blue}int \space \color{cyan}y \space \color{green}= \space \color{violet}parr \color{orange}[n]}$</td>
    <td>${\color{blue}Integer \space \color{cyan}named \space y \space \color{green}is \space set \space to \space}$
        ${\color{violet}the \space value \space in \space the \space memory \space address}$
        ${\color{violet}pointed \space by \space parr\color{orange}, \space but \space shifted \space}$
        ${\color{orange}in \space n\times X \space bytes}$</td>
    <td>In this expression, <code>X</code> is the memory size (in bytes) of each element in the array <code>arr</code> and <code>n</code> is any positive or negative interger value. This notation is an sintactic sugar to its <a href="https://stackoverflow.com/questions/4622461/difference-between-pointer-index-and-pointer">equivalent</a> command, <code>*(parr+n)</code>. In fact, a pointer arithmetic is performed on <code>parr</code> before dereferencing it. This syntax might be called "dereference via indexing". See the <a href="https://github.com/tapyu/c-and-cpp-lessons/tree/5-pointer-reference-memory#what-is-pointer-arithmetic">pointer arithmetic</a> section for more info.</td>
</tr>
<tr>
    <td>${\color{violet}parr \color{orange}[n] \space \color{green}= \space \color{cyan}5}$</td>
    <td>${\color{violet}The \space value \space in \space the \space memory \space address}$
        ${\color{violet}pointed \space by \space parr\color{orange}, \space but \space shifted \space}$
        ${\color{orange}in \space n\times X \space bytes,\space}$
        ${\color{green}is \space set \space to \space \color{cyan}5}$</td>
    <td>Same thing, but in the other way around. We assume that <code>parr</code> is an <code>int</code> pointer to the array <code>arr</code>. Note that the net result is perfectly equivalent to <code>arr[n] = 5</code>, but the actual operation is not that straightforward.</td>
</tr>
<tr>
     <td>${\color{red}p->age \space \color{green}= \space \color{cyan}5}$</td>
    <td>${\color{red}The \space stored \space value \space of \space the \space struct's}$
        ${\color{red}feild \space age \space that \space p \space points \space to \space \color{green}is \space set \space to \space \color{cyan}5}.$</td>
    <td>In this case, the pointer <code>p</code> is a structure pointer, e.g., <code>struct Person *p = &mike</code>. Note that the syntax <code>p->age</code> <a href="https://stackoverflow.com/questions/2575048/arrow-operator-usage-in-c/2575050#2575050">is equivalent to</a> <code>(*p).age</code></td>
</tr>
</table>

#### **What is pointer arithmetic?**

Pointer arithmetic is a fundamental concept in programming languages like `C` and `C++`, which allows you to perform arithmetic operations on pointers. Specifically, it involves adding or subtracting integers to/from pointers to manipulate memory addresses (see `./pointer-arithmetic/` examples).

- *Adding an Integer to a Pointer*: When you add an integer value to a pointer, you are effectively shifting forward the memory address stored by the pointer in a certain number of bytes. The size of the offset depends on the data type that the pointer points to. If `ptr` points to a variable type `X`, and this type occupies `Y` bytes in the memory, then the memory addres that `ptr` stores will be shifted forward in `Y` bytes. Desipe the memory size offset that the stored memory address will undergo, you can simply type `ptr = ptr + n;` (or `ptr+=n`), and then the memory address stored in `ptr` will be shifted forward in `n*Y` bytes. For example (you could use `ptr++`):
```c
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr; // ptr points to the internal pointer variable of `arr`, that is, the address of its first array element, 10.
    ptr = ptr + 1; // Move ptr to the next integer (20)
    int i = *ptr; // `i` is `20`
```
- *Subtracting an Integer from a Pointer*: You can also subtract an integer from a pointer, which has the opposite effect of moving the pointer backward in memory. Again, the size of the offset depends on the data type. For example (you could use `ptr--;` instead of `ptr = ptr - 1;`):
```c
    int arr[] = {10, 20, 30, 40};
    int *ptr = &arr[2]; // ptr points to the third element (30)
    ptr = ptr - 1; // Move ptr to the previous integer (20)
```

Sometimes you want to derefence the memory address pointed by `ptr` shifted by some amount, but you don't want to modify the the memory address stored in `ptr` during this process. In that situation, you can dereference via indexing:
```c
int arr[] = {50, 60, 70, 80, 90, 100, 110};
int *ptr = arr; // ptr points to the internal pointer variable of `arr`, that is, the address of its first array element, 50.
int i = ptr[2]; // dereference via indexing: `i` is set to `70`, the memory address of `ptr` did not change
```

Although this notation conveys the idea of an ordinary array indexing (i.e., `arr[2]`) and although it yields the same result of `arr[2]`, what we are doing here is: 1- Pointer arithmetic (but without modifying `parr`) 2- Dereference. In fact, the syntax `parr[2]` is equivalent to `*(parr + 2)` (first we do pointer arithmetic wihtout changing `parr`, then we dereference the resulting memory address). See `./pointer-arithmetic/dereference-via-indexing.c`.

---

# Memory

#### Memory address

Memory in a computer system is organized into discrete units called memory locations or addresses. The number of unique memory addresses that a system can generate is determined by the size of its memory address bus. The size of each memory location is often measured in bits, and the most common unit of storage is the byte, consisting of [**8 bits**](https://stackoverflow.com/questions/77167771/shouldnt-the-increasing-of-the-stored-memory-address-of-a-pointer-depend-on-the) (see `pointer-arithmetic/` examples).

Each memory address and is usually represented in hexadecimal, e.g., `0x7ffe100ee504`, where the prefix `0x` indicates that it is a hexadecimal number.

> NOTE: In a 64-bits memory architecture, each address contains 16 hex digits. However, the `C`/`C++` compiler [suppress](https://stackoverflow.com/a/7190827/13343959) the leading `0`'s when printing it out. Therefore, the full memory address is actually `0x00007ffe100ee504`.

#### **What is memory allocation?**

Memory allocation involves reserving a specific number of bytes in the computer's memory (RAM - Random Access Memory) for a specific purpose. This reserved space can be used to store data structures, variables, arrays, objects, and other program-related information. It is a fundamental concept in computer programming and is crucial for managing data and resources efficiently.

#### **Static vs. dynamic memory allocation**

Static memory allocation refers to the allocation of memory for variables at compile-time or during program startup. In statically allocated memory, the size and lifetime of the memory are fixed and determined at compile-time. This means that the memory for these variables is reserved in advance and remains constant throughout the program's execution (see `./static-dynamic-memory/static_memory_allocation.c and .cpp`).

Static memory allocation is useful when you know in advance the size and lifetime of the variables you need, and they don't need to change dynamically during program execution. It's suitable for situations where you have a fixed number of elements, constants, or global variables.

Dynamic memory allocation, as opposed to static memory allocation, involves allocating and deallocating memory during the program's runtime. This allows you to work with data structures of varying sizes and lifetimes, making dynamic memory allocation a powerful feature. **We manipulate dynamically allocated memories through pointers, which are used to access and modify the data in the allocated memory**.

Dynamic memory allocation comes with the responsibility of explicitly releasing memory to prevent memory leaks. In `C`, you use `free()` for deallocation, and in `C++`, you use `delete` for single objects and `delete[]` for arrays. Memory management is a critical aspect when working with dynamic memory.

In `C`, you can allocate memory dynamically using `malloc()`, which receives as input argument a `size_t` variable indicating the memory size you want to allocate. For instance, type `malloc(sizeof(int))` if you want to allocate a memory size with the length of an integer variable. This function will return a `void*` pointer to the beginning of the dynamically allocated memory block. This pointer is often referred to as a "generic" pointer because it doesn't have a specific type associated with it. Working with `void*` type allows flexibility because you can use it to allocate memory for objects of any type. If you want to allocate memory for an `int` variable, for exmaple, you need to explicitly cast it to `int` when assigning it to a pointer variable. Thefore, the final code becomes `int *dynam_int = (*int)malloc(sizeof(int));` (see `./static-dynamic-memory/dynamic_memory_allocation.c`):
1. `malloc(sizeof(int))`: allocates a memory block on you RAM with the length equal to an `int` variable. It returns a `void*` pointer which points to the beginning of that memory block;
1. `(* int)`: casts the `void*` pointer to a `int*` pointer;
1. `int *dynam_int =`: assined the casted `int*` pointer to the `*dinam_int` poiter;
There's no built-in mechanism for initializing the memory with a predefined value in a single step. Therefore, to set a value of the allocated memory, you must to type `*dynam_int = 5;` in another line.

In `C++`, you can dynamically allocated integer variable with the `new` keyword in a more straightforward manner: `int *dynam_int = new int(5);`:
1. `new int`: allocates a memory block on you RAM with the length equal to an `int` variable and returns an `int*` pointer that points to the beginning of that memory block;
1. `(5)` (optional): set the stored value of dynamically allocated memory to `5`;
1. `int *dynam_int =`: assigns this `int*` pointer to `*dynam_int`;

However, Using new and delete directly is error-prone and can lead to memory leaks and other issues if not handled carefully. The modern C++ best practice is to prefer smart pointers (`std::unique_ptr` and `std::shared_ptr`). They automatically manage the memory and reduce the risk of memory leaks, dangling pointers, and other common pitfalls associated with manual memory management. Therefore, it's advisable to use smart pointers whenever possible and resort to manual memory management only when you have a compelling reason to do so and understand the associated risks.

#### **Storage duration**

![image](https://github.com/tapyu/c-and-cpp-lessons/assets/22801918/6cc93ed9-48d2-4d5c-9796-daf63a7fc123)


Storage duration in `C` and `C++` refers to the lifetime of variables and memory blocks. It determines when and how long variables or memory allocations remain valid during program execution. Understanding storage duration is crucial for managing memory and writing robust programs.

There are four primary storage durations:

- *Automatic Storage Duration (ASD)* -> **stack**:
    - Variables with automatic storage duration are allocated memory on the **stack**.
    - Memory allocation and deallocation are handled automatically by the language: variables with storage duration are created when their scope is entered and destroyed when their scope is exited.
    - Local variables without the `static` keyword have automatic storage duration a limited lifetime determined by their scope.
    - Examples include local variables and function parameters.
    ```c
        void someFunction() {
            int x; // Automatic storage duration
        }
    ```
- *Dynamic Storage Duration (DSD)* -> **heap**:
    - Variables with dynamic storage duration are allocated on the **heap**. The heap is a region of a computer's memory managed by the operating system or a memory manager. It is used for dynamically allocated memory, which means you can request memory at runtime as needed. When you allocate memory on the heap, you are requesting for a memory that persists beyond the scope of the current function or block. This memory remains allocated until you explicitly release it. Therefore, you are responsible for releasing it when you're done using it.
    - Memory allocation and deallocation are controlled explicitly by the programmer.
    - The programmer is responsible for releasing memory when it is no longer needed to prevent *memory leaks*.
    - In many programming languages, such as `C` and `C++`, allocating memory on the heap involves using functions like `new` (in `C++`) or `malloc()` (in `C`) to request memory, and using `delete` (in `C++`) or `free()` (in `C`) to release it. You have to be careful to avoid *memory leaks* (not releasing memory) or accessing memory after it has been deallocated (which can lead to undefined behavior).
    ```c
    int* dynamicVar = (int*)malloc(sizeof(int)); // Dynamic storage duration in C
    *dynamicVar = 100;
    free(dynamicVar); // Explicit deallocation
    ```

- *Static Storage Duration* ->  **static memory** or **data segment**
    - Variables with static storage duration are typically allocated at program startup and deallocated when the program terminates.
    - They are typically declared using the `static` keyword or are in the global scope (see `./static-dynamic-memory/static_storage_duration.c`).  In `C` and `C++`, variables declared outside of functions (at file scope) have static storage duration by default.
    - These variables retain their values between function calls and are accessible from any part of the program where their scope is visible.
    - Variables with static storage duration are typically allocated in a special region of memory called the "data segment" or "global memory." This region is separate from the stack and the heap. The exact location within the data segment can vary depending on the platform and compiler.
    - They retain their values between function calls.
    ```c
    #include <stdio.h>

    int globalVar = 42; // Static storage duration, using `static` is redundant here

    int main() {
        static int localVar = 24; // Static storage duration within a function

        printf("Global variable: %d\n", globalVar);
        printf("Local static variable: %d\n", localVar);

        return 0;
    }
    ```
    - In this example, `globalVar` has file scope and is considered a global variable, while `localVar` has function scope but retains its value between function calls because it has static storage duration.
- *Thread Storage Duration* (C11 and C++11 and later)
    - A thread is the smallest unit of execution within a process. It is a fundamental concept in multithreading, which is the concurrent execution of multiple threads within the same process. Some concepts about threads:
        - Threads are lightweight execution units that share the same memory space and resources within a process. They are smaller in scope than processes, making them efficient for multitasking.
        - Parallel Execution: Threads allow a program to perform multiple tasks simultaneously, taking advantage of modern multicore processors. This parallelism can lead to improved performance and responsiveness in applications.
        - Thread States: Threads can be in various states, including running, ready, blocked, and terminated. The operating system's scheduler determines which thread runs at a given time.
        - Shared Memory: Threads within the same process share the same memory space, which allows them to access shared data and communicate with each other easily. However, this shared memory can lead to synchronization and data integrity issues that need to be carefully managed.
        - Thread Creation: Threads are typically created and managed by the operating system or a programming language's runtime library. Programmers can create threads explicitly in their code.
    - Thread Storage Duration is a storage duration introduced in C11 and C++11 standards to handle variables that are shared among threads.
    - Lifetime within a Thread: Variables with thread storage duration exist for the entire duration of the thread in which they are created. When a thread terminates, its thread storage duration variables are automatically destroyed.
    - Accessible Only Within the Thread: Thread storage duration variables are accessible only within the thread in which they are defined. Other threads cannot directly access these variables.

#### **What are deallocation and memory leak?**

A proper memory management also involves deallocating memory when it is no longer needed. Failure to deallocate memory can result in memory leaks, where memory is reserved but never released, leading to decreased system performance and potential program crashes.

#### **What are memory safety and garbage collector?**

Ensuring that allocated memory is used correctly and avoiding issues like buffer overflows (writing beyond allocated memory) is essential for memory safety. Languages like `C` and `C++` provide powerful memory management but also require careful coding practices to prevent memory-related errors. In some programming languages (e.g., `Java`, `C#`), automatic memory management techniques like garbage collection are used to automatically reclaim memory that is no longer in use. This simplifies memory management for programmers but introduces its own set of considerations.  In contrast to languages with garbage collection, languages like `C` and `C++` require manual memory management using `malloc()`, `free()`, `new`, and `delete` to allocate and deallocate memory. This can be error-prone but offers more control over memory usage.

## Memory size of variables (in bytes)

*The memory size of common data types in C can vary depending on the compiler and the target system's architecture*. However, there are standard data types with specified **minimum size** requirements in the `C` language standard. The sizes of unsigned types are typically the same as their signed counterparts on most systems and compilers (e.g., `unsigned int` typically uses at least 2 bytes, just like `int`). See `./memory/variables-memory-size.c`.

<table>
<tr>
    <th colspan="5"><h2>Variables</h2></th>
</tr>
<tr>
    <th>Variable type</th>
    <th>Bytes (a byte contains 8 bits)</th>
    <th><code>%</code> syntax</th>
    <th>Suffix for literals</th>
    <th>Comments</th>
</tr>
<tr>
    <td><code>char</code></td>
    <td>Tipically 1 byte (8 bits)</td>
    <td><code>%c</code></td>
    <td></td>
    <td>The a <code>char</code> variable may be signed or unsigned depending on the compiler's implementation. To explicitly specify the signedness of a <code>char</code>, you can use <code>signed char</code> or <code>unsigned char</code>.</td>
</tr>
<tr>
    <td><code>signed char</code></td>
    <td>Tipically 1 byte (8 bits)</td>
    <td><code>%c</code> (or <code>%hhi</code> for numerical output)</td>
    <td></td>
    <td>Of the same size as <code>char</code>, but guaranteed to be signed. Capable of containing at least the <code>[−127, +127]</code> range.</td>
</tr>
<tr>
    <td><code>unsigned char</code></td>
    <td>Tipically 1 byte (8 bits)</td>
    <td><code>%c</code> (or <code>%hhi</code> for numerical output)</td>
    <td></td>
    <td>Of the same size as <code>char</code>, but guaranteed to be unsigned. Capable of containing at least the <code>[0, 255]</code> range.</td>
</tr>
<tr>
    <td><code>int</code>, <code>signed</code>, <code>signed int</code></td>
    <td>At least 2 bytes (16 bits)</td>
    <td><code>%i</code>,<code>%d</code> (or <code>%o</code> or <code>%x</code> if you are using octal or hexadecimal representation, respectively)</td>
    <td></td>
    <td>Basic signed integer type. Capable of containing at least the <code>[−32,767, +32,767]</code> range. Use <code>0</code> or <code>0x</code> prefix if you are using octal or hexadecimal representation. The convesion to decimal (and vice-versa) is direct when you use <code>%i</code> or <code>%d</code> to refer to a hexadecimal or octal number.</td>
</tr>
<tr>
    <td><code>unsigned</code>, <code>unsigned int</code></td>
    <td>2 bytes (16 bits)</td>
    <td><code>%u</code></td>
    <td><code>u</code>, <code>U</code></td>
    <td>Basic unsigned integer type. Contains at least the <code>[0, 65,535]</code> range.</td>
</tr>
<tr>
    <td><code>short</code>, <code>short int</code>, <code>signed short</code>, <code>signed short int</code></td>
    <td>2 bytes (16 bits)</td>
    <td><code>%hi</code> or <code>%hd</code></td>
    <td></td>
    <td>Short signed integer type. Capable of containing at least the <code>[−32,767, +32,767]</code> range.</td>
</tr>
<tr>
    <td><code>unsigned short</code>, <code>unsigned short int</code></td>
    <td>2 bytes (16 bits)</td>
    <td><code>%hu</code></td>
    <td></td>
    <td>Short unsigned integer type. Contains at least the <code>[0, 65,535]</code> range.</td>
</tr>
<tr>
    <td><code>long</code>, <code>long int</code>, <code>signed long</code>, <code>signed long int</code></td>
    <td>At least 4 bytes (32 bits).</td>
    <td><code>%li</code>,<code>%ld</code></td>
    <td><code>l</code>, <code>L</code></td>
    <td>Long signed integer type. Capable of containing at least the <code>[−2,147,483,647, +2,147,483,647]</code> range.</td>
</tr>
<tr>
    <td><code>unsigned long</code>, <code>unsigned long int</code></td>
    <td>At least 4 bytes (32 bits).</td>
    <td><code>%lu</code></td>
    <td>both <code>l</code> or <code>L</code> and <code>u</code> or <code>U</code></td>
    <td>Long unsigned integer type. Capable of containing at least the <code>[0, 4,294,967,295]</code> range.</td>
</tr>
<tr>
    <td><code>long long</code>, <code>long long int</code>, <code>signed long long</code>, <code>signed long long int</code></td>
    <td>At least 8 bytes (64 bits).</td>
    <td><code>%lli</code>, <code>%lld</code</td>
    <td><code>ll</code> or <code>LL</code></td>
    <td>Long long signed integer type. Capable of containing at least the <code>[−9,223,372,036,854,775,807, +9,223,372,036,854,775,807]</code> range. Specified since the C99 (ISO/IEC 9899:1999) version of the standard.</td>
</tr>
<tr>
    <td><code>unsigned long long</code>, <code>unsigned long long int</code></td>
    <td>At least 8 bytes (64 bits).</td>
    <td><code>%llu</code></td>
    <td>both <code>u</code> or <code>U</code> and <code>ll</code> or <code>LL</code></td>
    <td>Long long unsigned integer type. Capable of containing at least the <code>[0, 18,446,744,073,709,551,615]</code> range. Specified since the C99 (ISO/IEC 9899:1999) version of the standard.</td>
</tr>
<tr>
    <td><code>float</code></td>
    <td>At least 4 bytes (32 bits).</td>
    <td><code>%f</code>, <code>%F</code>, <code>%g</code>, <code>%G</code>, <code>%e</code>, <code>%E</code>, <code>%a</code>, <code>%A</code></td>
    <td><code>f</code>, <code>F</code></td>
    <td>Real floating-point type, usually referred to as a "single-precision floating-point type". It is a <b>good practice</b> to add the <code>f</code> suffix to make it clear to the compiler and other developers that you are working with a <code>float</code> rather than a <code>double</code>. By default, many compilers treat numeric literals without suffixes as double. For example, <code>float f1 = 3.14;</code> may be implicitly treated as a <code>double</code>, while <code>float f2 = 3.14f;</code> is not. It's important to note that while using the <code>f</code> suffix is a good practice for <code>float</code> literals, it's not mandatory. In many situations, the compiler can perform implicit conversions from <code>double</code> to <code>float</code> when necessary. However, using the <code>f</code> suffix can help prevent unexpected behavior or type mismatch issues in your code, especially when dealing with <code>float</code> variables and constants.</td>
</tr>
<tr>
    <td><code>double</code></td>
    <td>At least 8 bytes (64 bits).</td>
    <td><code>%lf</code>, <code>%lF</code>, <code>%lg</code>, <code>%lG</code>, <code>%le</code>, <code>%lE</code>, <code>%la</code>, <code>%lA</code></td>
    <td></td>
    <td>Real floating-point type, usually referred to as a "double-precision floating-point type", or simply "double".</td>
</tr>
<tr>
    <td><code>long double</code></td>
    <td>At least 10 bytes (80 bits) on some systems.</td>
    <td><code>%Lf</code>, <code>%LF</code>, <code>%Lg</code>, <code>%LG</code>, <code>%Le</code>, <code>%LE</code>, <code>%La</code>, <code>%LA</code></td>
    <td><code>L</code>, <code>l</code>code></td>
    <td></td>
</tr>
<tr>
    <td><code>size_t</code></td>
    <td>Typically 32 bits (4 bytes) on 32-bit systems or 64 bits (8 bytes) on 64-bit systems</td>
    <td><code>%zu</code></td>
    <td></td>
    <td>An unsigned integer type that is used for representing the sizes of objects in memory. It is often used when dealing with memory allocation, arrays, and indexing. The <code>size_t</code> type is guaranteed to be able to represent the size of the largest object that can exist in the memory of the system.</td>
</tr>
<tr>
    <td><code>void*</code></td>
    <td>4 bytes (32 bits) of memory on 32-bit systems, or 8 bytes (64 bits) of memory on 64-bit systems.</td>
    <td><code>%p</code></td>
    <td></td>
    <td>A void pointer (e,g,<code>void* p</code>) is a generic pointer that lacks type information about the data it points. It can point to objects of any data type. The <code>%p</code> is used to refer to this type of variable in <code>prinf</code>/<code>scanf</code>. In practice, however, we usually use a typed pointer (e,g,<code>int* p</code>). Therefore, to use <code>%p</code>, we fist cast from a typed pointer to a void pointer, e.g., <code>int i = 5; int* pi = &i; printf("Hi %p", (void*)pi)</code></td>
</tr>
<tr>
    <th colspan="5"><h3><code>C++</code>-only data types</h3></th>
</tr>
<tr>
    <th>Variable type</th>
    <th>Bytes (a byte contains 8 bits)</th>
    <th><code>%</code> syntax</th>
    <th>Suffix for literals</th>
    <th>Comments</th>
</tr>
<tr>
    <td><code>bool</code></td>
    <td>Typically 1 byte (8 bits), representing <code>true</code> or <code>false</code>.</td>
    <td></td>
    <td></td>
    <td></td>
</tr>
<tr>
    <td>User-defined types</td>
    <td>Classes and structures in C++ can have variable sizes based on their member variables and alignment requirements.</td>
    <td></td>
    <td></td>
    <td></td>
</tr>
</table>

Other worthmention variables from `<stdint.h>` header in `C` and `<cstdint>` header in `C++`.
For signed integers:
- `int8_t`: 8-bit signed integer
- `int16_t`: 16-bit signed integer
- `int32_t`: 32-bit signed integer
- `int64_t`: 64-bit signed integer
For unsigned integers:
- `uint8_t`: 8-bit unsigned integer
- `uint16_t`: 16-bit unsigned integer
- `uint32_t`: 32-bit unsigned integer
- `uint64_t`: 64-bit unsigned integer

Using these types provides clarity and consistency, especially when working on projects where cross-platform compatibility is essential or when dealing with binary data formats that require precise bit widths.


---

# References (`C++`)

## **Reference syntax**

<table>
<tr>
    <th colspan="3"><h2>Reference syntax</h2></th>
</tr>
<tr>
    <th>Code</th>
    <th>How you should read it</th>
    <th>Comments</th>
</tr>
<tr>
    <td>${\color{blue}int\color{yellow}\& \space\color{violet}ref \color{green}= \color{cyan}i}$</td>
    <td>${\color{blue}Integer \space \color{yellow}lvalue \space reference}$
        ${\color{violet}named \space ref \space \color{green}refers \space \color{cyan}the \space integer \space lvalue \space i}$</td>
    <td>This syntax is used to initialize lvalue reference variables. A lvalue reference must refer a lvalue, except by the case bellow. See <code>lvalue_ref.cpp</code></td>
</tr>
<tr>
    <td>${\color{blue}const \space int\color{yellow}\& \space \color{violet}ref \color{green}= \color{cyan}5}$</td>
    <td>${\color{blue}Constant \space integer \space \color{yellow}lvalue}$
        ${\color{yellow}reference \space \color{violet}named \space ref \space \color{green}refers}$
        ${\color{cyan}the \space integer \space rvalue \space 5}$</td>
    <td>This is the unique exception where a lvalue reference can refer to a rvalue. You can do it because <code>const</code> lvalue reference (read-only reference) can bind rvalue. Normally, a temporary variable (an rvalue) in <code>C++</code> has a limited lifetime. It is created to hold a specific value or result of an expression and is destroyed at the end of the full-expression that creates it. When you bind a <code>const</code> lvalue reference to a temporary value, such as <code>const int& ref = 5</code>;, the <code>C++</code> compiler specifies that the temporary's lifetime is extended to match the lifetime of the reference variable <code>red</code>. This means that the temporary created by 5 (the rvalue) will not be destroyed at the end of the full-expression but will persist as long as the reference x is in scope. It must be noticed that, if a <code>const</code> lvalue reference is used to overload a function along with a rvalue reference for the same argument position, e.g., <code>void printName(const std::string& name)</code> and <code>void printName(std::string&& name)</code>, the C++ compiler will use <code>void printName(std::string&& name)</code> if you pass an rvalue input to it (e.g., <code>"Mike" + " Smith"</code>). See <code>func_overload.cpp</code>.</td>
</tr>
<tr>
    <td>${\color{violet}ref \color{green} = \color{cyan}i}$
        <br>or<br>
        ${\color{violet}ref \color{green} = \color{cyan}5}$
    </td>
    <td>${\color{violet}The \space lvalue \space referred \space the \space lvalue}$
        ${\color{violet}reference \space ref \space \color{green}is \space set \space to \color{cyan} \space i \space (or \space 5)}$</td>
    <td>This syntax is used to <b>assing by reference</b>. This process is equivalent to the C-style pointer-based approach <code>*pi = i;</code> or <code>*pi = 5;</code> (that is, dereference). You can assign by reference both rvalue and lvalue.</td>
</tr>
<tr>
    <td>${\color{blue} \space int\color{yellow}\&\& \space \color{violet}ref \color{green}= \color{cyan}5}$</td>
    <td>${\color{blue}Integer \space \color{yellow}rvalue \space reference}$
        ${\color{violet}named \space ref \space \color{green}refers \space \color{cyan}the \space integer \space rvalue \space 5}$</td>
    <td>This is used to initialized an rvalue reference. It must always refer to an rvalue. See <code>rvalue_ref.cpp</code>.</td>
</tr>
<tr>
    <td>${\color{violet}y \color{green}= std::move(\color{cyan}x\color{green})}$</td>
    <td>${\color{violet}object \space named \space y \space \color{green}steals \space an \space parameter}$
        ${\color{green}from\space \color{cyan}the \space object \space x}$</td>
    <td>Move semantic: Applies the <code>move()</code> constructor method from the class of <code>x</code>. It will steal some parameter of the <code>x</code> object. See <code>./move-semantics/</code>.</td>
</tr>
</table>

#### **What are lvalues and rvalues?**

Reference is a mechanism that allows you to create an alias or an alternative name for variables. References interact with objects in different ways, allowing more sophisticated memory managment and resource handling techniques, such as move semantics. In `C++`, we can categorize variables into [*lvalues* and *rlvaues*][8], which can be referenced by *lvalue references* and *rvalues references*, respectively.

Lvalues are also called *locator values* because they have a variable name assigned to that value. Rvalues, on the other hand, is a temporary value that has no variable assigned to it. Common examples values used as rvalues are: literals, also known as pure values or prvalues, e.g., `10`; operations involving prvalues, e.g., `10 + 3`; operations involving prvalues and lvalues, e.g., `i + 3`; are often used as rvalues. Once lvalues have been assigned to a specific memory location, they can be used as targets for assignment, whereas rvalues typically represent values that are computed on the fly and are not directly addressable in memory.

**[Example 1][7] `./references/l_to_r.cpp`:**
```cpp
    int i = 10;
```
By running `objdump -d -Mintel references/l_to_r | less`, we get the following assembly code in the main section:
```asm
0000000000001129 <main>:
    1129:       f3 0f 1e fa             endbr64 
    112d:       55                      push   rbp
    112e:       48 89 e5                mov    rbp,rsp
    1131:       c7 45 fc 0a 00 00 00    mov    DWORD PTR [rbp-0x4],0xa
    1138:       b8 00 00 00 00          mov    eax,0x0
    113d:       5d                      pop    rbp
    113e:       c3                      ret    
```
Let us break it down:

- `endbr64`: used for control flow enforcement technology (CET) and is usually inserted at the beginning of functions to ensure control flow integrity.
- `push rbp`: Save the value of the base pointer (rbp) onto the stack, typically to establish a new stack frame for the current function, typically to establish a new stack frame for the current function. The pop rbp instruction at the end of the function restores the previous base pointer value when the function exits. This mechanism helps maintain the integrity of the stack during function calls.
- `mov rbp, rsp`: This instruction moves the value of the stack pointer (rsp) into the base pointer (rbp). It's setting up a new stack frame for the function.
- `mov DWORD PTR [rbp-0x4], 0xa`: This instruction moves the value `0xa` (10 in decimal) into a 4-byte integer (`DWORD`) located at `[rbp-0x4]` (`4` bytes is the memory size of an `int`). This is essentially storing the integer value `10` in a local variable within the function.
- `mov eax, 0x0`: This instruction moves the value `0x0` (0 in decimal) into the `eax` register. This is often used to set the return value of a function, and in this case, it's setting the return value of main to `0`.
- `pop rbp`: This instruction pops the previously saved base pointer value from the stack, effectively cleaning up the stack frame before the function returns.
- `ret`: This is the return instruction. It tells the processor to return from the function, and the value in eax (set to 0 earlier) will be used as the return status.

The command `mov DWORD PTR [rbp-0x4], 0xa` is effecivelly doing your `int i = 10;`. The variable `i` has a memory address (`[rbp-0x4]`) and can be accessed by the variable name `i`. Therefore, it is an **lvalue**. On the other hand, the literal `10` is the hexadecimal numeric value `0xa`. It is a **temporary value** that has no name or storage (until it is assigned to the lvalue `i`). Therefore, `10` is an **rvalue**. Literals are often rvalues.

In summary, `int i = 10` is an lvalue-to-rvalue assignment. In this case
```cpp
int get_value() {
    return 10;
}

int main() {
    int i = get_value();
}
```
the command `int i = get_value()` is also an lvalue-to-rvalue assignment as `get_value()` returns a temporary value (the literal `10`) that has no name or location.

**Example 2 (`/.references/l_to_l.cpp`):**
```cpp
int i = 10;
int a = i;
```
It produces
```asm
0000000000001129 <main>:
    1129:       f3 0f 1e fa             endbr64 
    112d:       55                      push   rbp
    112e:       48 89 e5                mov    rbp,rsp
    1131:       c7 45 f8 0a 00 00 00    mov    DWORD PTR [rbp-0x8],0xa
    1138:       8b 45 f8                mov    eax,DWORD PTR [rbp-0x8]
    113b:       89 45 fc                mov    DWORD PTR [rbp-0x4],eax
    113e:       b8 00 00 00 00          mov    eax,0x0
    1143:       5d                      pop    rbp
    1144:       c3                      ret
```
The new commands are:

- `mov    DWORD PTR [rbp-0x8],0xa`: Same thing as `mov DWORD PTR [rbp-0x4], 0xa`, but at the address `[rbp-0x8]`. It is our `int i = 10;`. We already know that `i` is a `lvalue`
- `mov    eax,DWORD PTR [rbp-0x8]`: This instruction moves the 4-byte value located at `[rbp-0x8]` into the `eax` register. It's essentially loading the value 10 from memory into the eax register.
- `mov    DWORD PTR [rbp-0x4],eax`: This instruction moves the value stored in the `eax` register (which is now 10) into the 4-byte memory location pointed to by `[rbp-0x4]`. `[rbp-0x4]` is another local variable or storage location within the current stack frame. The two last commands perform our `int a = i;`, that is, it pass a value from a variable that has location (`[rbp-0x8]`) and name (`i`) to another variable that are location (`[rbp-0x4]`) and name (`a`).

Therefore, `int a = i;` is an lvalue-to-lvalue assignment.

#### **References vs. Pointers**

In `C`, which has no references, you primarily work with pointers to achieve similar functionality to what references provide in `C++`. In other words, there is an overlap in the functionalities provided by them. Certain things can be done by using either pointer or references (see `./refs-vs-pointers/ref-pointer-equivalency.cpp`). However, there are fundamental differences beween both:
1. References cannot be `NULL` (e.g., you cannot write `int &ref = NULL;`);
1. You cannot change the variable e.g. referenced by a reference. Once a reference is *associated* to a variable, it is that way forever (e.g., if `int $ref = i;`, you cannot also write `int $ref = another_i;`);
1. You cannot do math on references (e.g., you cannot write `int &a = i + 1;`) as you can do on pointers (e.g., you can write `int *pi = &i + 1`). See `./pointer-arithmetic/pointerpp.c`;
1. While you can have pointer to pointer (e.g., if `int *px = &x;` you can write `int **ppx = &px;`), you cannot have references to references (e.g., if `int &rx = x;`, you cannot write `int &&rrx = rx`). See `./pointers-to-pointers/`.

**The main point is, for some tasks, it is easier to work with references instead of pointers** (see `./refs-vs-pointers/with-ref-is-much-easier.cpp`). Moreover, [this crazy guy here][2] said that **all references is, under the hood, a pointer** but with some operation restrictions that make it easier to work with for some tasks. By running

```sh
objdump -d -Mintel ./refs-vs-pointers/how | less
```

we get in `main` section
```
0000000000001169 <main>:
    1169:       f3 0f 1e fa             endbr64 
    116d:       55                      push   rbp
    116e:       48 89 e5                mov    rbp,rsp
    1171:       48 83 ec 20             sub    rsp,0x20
    1175:       64 48 8b 04 25 28 00    mov    rax,QWORD PTR fs:0x28
    117c:       00 00 
    117e:       48 89 45 f8             mov    QWORD PTR [rbp-0x8],rax
    1182:       31 c0                   xor    eax,eax
    1184:       c7 45 e4 00 00 00 00    mov    DWORD PTR [rbp-0x1c],0x0
    118b:       48 8d 45 e4             lea    rax,[rbp-0x1c]
    118f:       48 89 45 e8             mov    QWORD PTR [rbp-0x18],rax
    1193:       48 8d 45 e4             lea    rax,[rbp-0x1c]
    1197:       48 89 45 f0             mov    QWORD PTR [rbp-0x10],rax
    119b:       48 8b 45 e8             mov    rax,QWORD PTR [rbp-0x18]
    119f:       8b 00                   mov    eax,DWORD PTR [rax]
    11a1:       8d 50 01                lea    edx,[rax+0x1]
    11a4:       48 8b 45 e8             mov    rax,QWORD PTR [rbp-0x18]
    11a8:       89 10                   mov    DWORD PTR [rax],edx
    11aa:       48 8b 45 f0             mov    rax,QWORD PTR [rbp-0x10]
    11ae:       8b 00                   mov    eax,DWORD PTR [rax]
    11b0:       8d 50 01                lea    edx,[rax+0x1]
    11b3:       48 8b 45 f0             mov    rax,QWORD PTR [rbp-0x10]
    11b7:       89 10                   mov    DWORD PTR [rax],edx
    11b9:       8b 45 e4                mov    eax,DWORD PTR [rbp-0x1c]
    11bc:       89 c6                   mov    esi,eax
    11be:       48 8d 05 3f 0e 00 00    lea    rax,[rip+0xe3f]        # 2004 <_IO_stdin_used+0x4>
    11c5:       48 89 c7                mov    rdi,rax
    11c8:       b8 00 00 00 00          mov    eax,0x0
    11cd:       e8 9e fe ff ff          call   1070 <printf@plt>
    11d2:       b8 00 00 00 00          mov    eax,0x0
    11d7:       48 8b 55 f8             mov    rdx,QWORD PTR [rbp-0x8]
    11db:       64 48 2b 14 25 28 00    sub    rdx,QWORD PTR fs:0x28
    11e2:       00 00 
    11e4:       74 05                   je     11eb <main+0x82>
    11e6:       e8 75 fe ff ff          call   1060 <__stack_chk_fail@plt>
    11eb:       c9                      leave  
    11ec:       c3                      ret    
```

Let us break it down:
- `1184: mov    DWORD PTR [rbp-0x1c],0x0`: Move the value `0` into a 32-bit memory location located 28 bytes below the base pointer (`rbp`). That is our "high"-level `C` command `int i = 0;`.
    - `mov`: This is the mnemonic for the "move" instruction, which is used to transfer data from one location to another.
    - `DWORD PTR`: specifies the size of the data being moved. In this case, `DWORD PTR` stands for "Double Word Pointer", which typically refers to a 32-bit value. It means that we are working with a 32-bit (4-byte) data item.
    - `[rbp-0x1c]`: This is the destination memory address where the data will be stored. `[rbp-0x1c]` means that we are accessing memory at an offset of 0x1c bytes (28 bytes) below the base pointer (rbp). The base pointer (`rbp`) is often used as a frame pointer in function prologues to access local variables and parameters. Note that `[rbp-0x1c]` is the address of the integer variable `i`.
    - `0x0`: This is the immediate value being moved into the specified memory location. In this case, it's the value zero (0x0).
- `118b: lea    rax,[rbp-0x1c]`: Calculate the address of a memory location of `[rbp-0x1c]`. The result of this calculation is stored in the `rax` register.
    - `lea`: This is the mnemonic for the "load effective address" instruction, which is used to calculate an effective memory address and load it into a register.
    - `rax`: This specifies the destination register where the calculated address will be stored. In this case, the result will be placed in the `rax` register.
    - `[rbp-0x1c]`: This is the memory address calculation. It calculates the effective address by subtracting `0x1c` (28 in decimal) from the value in the base pointer (`rbp`). So, it computes the address that is 28 bytes below the value in `rbp`.
- `118f: mov    QWORD PTR [rbp-0x18],rax`: move the 64-bit value contained in the `rax` register into an 8-byte memory location located 24 bytes below the base pointer (`rbp`). In other words, it puts it on the [stack][2]. Note that the address of `px` is `[rbp-0x18]`, and its value is indeed the addres of the variable `i`, which is `[rbp-0x1c]`. The instruction `118b` and `118f` form the implementation of our "high"-level `C` command `int *pi = &i`.
    - `QWORD PTR`: This part specifies the size of the data being moved. `QWORD PTR` stands for "Quad Word Pointer," which typically refers to a 64-bit (8-byte) value. It means that we are working with an 8-byte data item.
- `1193: lea    rax,[rbp-0x1c]`: Does exactly the same as the instruction `1184`.
- `1197: mov    QWORD PTR [rbp-0x10],rax`: Does exactly the same as the instruction `118f`, but in the memory `[rbp-0x10]`. Note that `1193` and `1197` form our "high"-level `C` command `int &ri = i`.

As you can see, pointers and the refereces are initialized in the same way. The difference between a pointer and a reference occurs after they are initialzied. The compiler manipulates them differently, applying severeal protections/restriction on the reference, which prevent us from things such as doing math with it. On the other hand, for some tasks, such restrictions enable us to use references in a more straightforward way when compared to pointers. For example, modifying a variable value by reference is much more straightforward when compared to the same solution via pointers.

#### What are move semantics?

Move semantics is a `C++` feature that allows you to efficiently **transfer ownership** of resources (such as dynamically allocated memory) from one object to another, typically **without having to create copies of the resources**. It is a feature introduced in `C++11` and later versions of the language.

Move semantics are particularly useful when dealing with objects that manage resources, like dynamic memory allocation or file handles. Without move semantics, copying such objects can be expensive in terms of time and memory. Move semantics allow you to "move" the internal resources from one object to another, leaving the source object in a valid but unspecified state.

The key components of move semantics in `C++`:
1. *Move Constructors and Move Assignment Operators*: Classes can define move constructors and move assignment operators (`std::move()`) to specify *how their resources should be moved when an object is transferred to another*. These special member functions typically involve shallow copying of pointers or handles and setting the source object to a safe state.
1. *rvalue References*: Move semantics rely on rvalue references.
1. `std::move()`: The `std::move()` function is used to convert an lvalue (an object with a name) into an rvalue reference. It is often used to indicate that you intend to move from an object rather than copy it.
1. After the moving the state of the previous owner becomes unspecified. It's important not to use that variable again after the move because it may contain a `nullptr` or other undefined values.  it means that the value is no longer predictable or defined after it has been moved from. However, it doesn't necessarily mean that the value will change or become some random value; it depends on the implementation and compiler.

See `./rvalue-and-move-semantics/`.

---

Good refs:

1. [you will never ask about pointers again after watching this video](https://www.youtube.com/watch?v=2ybLD6_2gKM&ab_channel=LowLevelLearning)
1. [so... what even is a "reference"?][2]
1. [you will never ask about pointer arithmetic after watching this video][3]
1. [wiki: Basic types table][4]
1. [Is the size of C "int" 2 bytes or 4 bytes?][5]

[2]: https://www.youtube.com/watch?v=wro8Bb6JnwU&ab_channel=LowLevelLearning
[3]: https://www.youtube.com/watch?v=q24-QTbKQS8&t=2s&ab_channel=LowLevelLearning
[4]: https://en.wikipedia.org/wiki/C_data_types#Basic_types
[5]: https://stackoverflow.com/a/11438838/13998346
[6]: https://en.wikipedia.org/wiki/Primitive_data_type
[7]: https://www.youtube.com/watch?v=fbYknr-HPYE&t=718s&ab_channel=TheCherno
[8]: https://www.youtube.com/watch?v=XS2JddPq7GQ
