#ifndef EXAMPLE_H
#define EXAMPLE_H

// Constants
#define MAX_BUFFER_SIZE 1024

// Type definitions
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point top_left;
    Point bottom_right;
} Rectangle;

// Function declarations
void initialize(Point* p, int x, int y);
int computeArea(const Rectangle* rect);
void printPoint(const Point* p);

// External variables
extern int globalCounter;

// Class definition (C++ only)
#ifdef __cplusplus
class Shape {
public:
    virtual void draw() const = 0;
};

class Circle : public Shape {
private:
    Point center;
    int radius;
public:
    Circle(Point c, int r);
    void draw() const override;
};
#endif // __cplusplus

#endif // EXAMPLE_H
