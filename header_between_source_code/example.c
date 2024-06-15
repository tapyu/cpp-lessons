#include "example.h"
#include <stdio.h>

// Definition of external variable
int globalCounter = 0;

void initialize(Point* p, int x, int y) {
    p->x = x;
    p->y = y;
}

int computeArea(const Rectangle* rect) {
    int width = rect->bottom_right.x - rect->top_left.x;
    int height = rect->bottom_right.y - rect->top_left.y;
    return width * height;
}

void printPoint(const Point* p) {
    printf("Point(x: %d, y: %d)\n", p->x, p->y);
}
