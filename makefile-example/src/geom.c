#include <stdio.h>
#include <math.h>
#include "../include/gd.h"

int main(void) {
    double x = get_double("Enter the x value: ", -100, 100);
    double y = get_double("Enter the y value: ", -100, 100);

    double d = sqrt(pow(x,2) + pow(y,2));

    printf("The distance is %lf km", d);

    return 0;
}