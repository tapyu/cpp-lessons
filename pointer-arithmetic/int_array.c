#include <stdio.h>

int main(int argc, char** argv) {
    int i[] = {888, 888, 888, 888};
    int *pi = i; // pi points to the internal pointer of the variable `i`, that is, the address of its first array element, 10.
    int d = 5;
    // int *pd = d; // you cannot do it as `d` has no internal since it is a primitive data type

    printf("Before, the i vector is {");
    for(int j = 0; j < sizeof(i)/sizeof(int); j++) {
        if (j != (sizeof(i)/sizeof(int)) - 1) {
        printf("%i, ", i[j]);
        } else {
            printf("%i}\n", i[j]);
        }
    }
    *pi = 0; // pi is dereferencing i[0]

    printf("Now,    the i vector is {");
    for(int j = 0; j < sizeof(i)/sizeof(int); j++) {
        if (j == 0){
            printf("%i  , ", i[j]);
        } else if (j != (sizeof(i)/sizeof(int)) - 1) {
        printf("%i, ", i[j]);
        } else {
            printf("%i}\n\n", i[j]);
        }
    }

    printf("The internal pointer of the int array is                      : %p\n"
           "The address of the first int array element is                 : %p\n"
           "The stored value (.i.e., the memory address) of the pointer is: %p\n"
           "PS: - Each memory address, by definition, stores 1 byte and is usually represented in hexadecimal.\n"
           "    - Each memory address of a 64-bit (32-bit) memory architecture has a 64/4=16 (32/4=8) hexadecimal digits\n\n",
           (void*)i, (void*)&i[0], (void*)pi);


    printf("The memory size of a int variable is: %zu bytes, or equivalently %lu bits as each byte has 8 bits.\n", sizeof(int), 8*sizeof(int));

    printf("Since each memory address storages 1 byte, the integer number `i[0]` occupies the memory addresses");
    char *char_pi = (char*)pi; // cast from a int pointer to a char pointer to be able to shift the memory address address in 1 byte only with each increment (1 byte is the memory size of a char)
    for (int j = 0; j < sizeof(int); j++) {
        printf(" %p", (void*)char_pi);
        if (j != sizeof(int)-1) {
            printf(",");
        } else {
            printf(".\n\n");
        }
        char_pi++; // shift the memory address in 1 byte
    }
    

    printf("Since `pi` is a int pointer, the command `pi = pi + 1` shifts stored memory address of `pi` in %zu bytes, which is the memory size of a `C` `int` variable.\n\n",
            sizeof(int));

    pi = pi + 1; // Move pi to the memory address of the next integer (20) (instead, you could use `pi++`)
    printf("After the command `pi = pi + 1;`, the stored memory address of `pi` is %p, which is the beginning of the memory address of `i[1]`.", (void*)pi);



    return 0;
}