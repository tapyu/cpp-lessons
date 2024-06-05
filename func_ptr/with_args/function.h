#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

// function pointer
int (*selectOperation(char op))(int, int);

#endif // FUNCTIONS_H
