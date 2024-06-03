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
            printf("Today is Sunday.\n"
                   "The stored value to enum is %i", today);
            break;
        case MONDAY:
            printf("Today is Monday.\n"
                   "The stored value to enum is %i", today);
            break;
        case TUESDAY:
            printf("Today is Tuesday.\n"
                   "The stored value to enum is %i", today);
            break;
        case WEDNESDAY:
            printf("Today is Wednesday.\n"
                   "The stored value to enum is %i", today);
            break;
        case THURSDAY:
            printf("Today is Thursday.\n"
                   "The stored value to enum is %i", today);
            break;
        case FRIDAY:
            printf("Today is Friday.\n"
                   "The stored value to enum is %i", today);
            break;
        case SATURDAY:
            printf("Today is Saturday.\n"
                   "The stored value to enum is %i", today);
            break;
        default:
            printf("Invalid day.\n");
            break;
    }

    return 0;
}
