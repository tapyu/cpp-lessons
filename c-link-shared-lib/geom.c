#include <stdio.h>
#include <math.h>

// prompt user to enter a double.
// re-prompt if the input is out of bounds
// given: prompt (print), min (double), and max (double)
// returns: the inputted double
double get_double(char *prompt, double min, double max) // prompt is a pointer to a character
{
    double input;
    do
    {
        printf("%s", prompt);
        scanf("%lf", &input); // & -> address-of operator
        if (input < min) printf("Must be at least %lf\n", min);
        if (input > max) printf("Must be at most %lf\n", max);
        
    }
    while (input < min || input > max);
    return input;
}

int main(int argc, char** argv)
{
    double x = get_double("Enter the x value: ", -100, 100);
    double y = get_double("Enter the y value: ", -100, 100);

    double d = sqrt(pow(x,2) + pow(y,2));

    printf("The distance is %lf meters", d);

    return 0;
}