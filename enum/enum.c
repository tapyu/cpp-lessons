#include <stdio.h>

// Define an enum for days of the week
enum Day {
    SUNDAY,    // 0
    MONDAY,    // 1
    TUESDAY,   // 2
    WEDNESDAY, // 3
    THURSDAY,  // 4
    FRIDAY,    // 5
    SATURDAY   // 6
};

int main() {
    // Declare a variable of type enum Day
    enum Day today;

    // Assign a value to the variable
    today = WEDNESDAY;

    // Use the enum variable in a switch statement
    switch (today) {
        case SUNDAY:
            printf("Today is Sunday.\n");
            break;
        case MONDAY:
            printf("Today is Monday.\n");
            break;
        case TUESDAY:
            printf("Today is Tuesday.\n");
            break;
        case WEDNESDAY:
            printf("Today is Wednesday.\n");
            break;
        case THURSDAY:
            printf("Today is Thursday.\n");
            break;
        case FRIDAY:
            printf("Today is Friday.\n");
            break;
        case SATURDAY:
            printf("Today is Saturday.\n");
            break;
        default:
            printf("Invalid day.\n");
            break;
    }

    printf("The stored value to enum is %i", today);

    return 0;
}
