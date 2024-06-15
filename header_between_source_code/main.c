#include <stdio.h>
#include "example.h"

int main() {
    Point p;
    initialize(&p, 10, 20);
    printPoint(&p);

    Rectangle rect = { {0, 0}, {10, 20} };
    int area = computeArea(&rect);
    printf("Area of the rectangle: %d\n", area);

    globalCounter++;
    printf("Global counter: %d\n", globalCounter);

    return 0;
}
