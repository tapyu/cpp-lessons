#include <stdio.h>

int main() {
    // union
    union my_union {
        int a;   // can't use both a and b at once
        char b;
    } foo; // we are instantiating a variable named `foo` from `my_union`

    printf("union!\n");
    foo.a = 3; // OK
    printf("1st %d and %c\n", foo.a, foo.b);
    foo.b = 'c'; // NO! this affects the value of foo.a!
    printf("2nd %d and %c\n", foo.a, foo.b);
    
    // struct
    struct my_struct {
        int a;   // can use both a and b simultaneously
        char b;
    } bar; // we are instantiating a variable named `bar` from `my_struct`

    printf("struct!\n");
    bar.a = 3; // OK
    printf("1st %d and %c\n", bar.a, bar.b);
    bar.b = 'c'; // NO! this affects the value of bar.a!
    printf("2nd %d and %c\n", bar.a, bar.b);

    return 0;
}
