#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    char source[] = "My source string";
    char destination[50] = "My destination string"; // up-to-50-sized string

    printf("Before strcpy: source string = \"%s\". Its length is %lu.\n", source, strlen(source));
    printf("Before strcpy: destination string = \"%s\". Its length is %lu.\n", destination, strlen(destination));

    // destination = source; // you cannot do it in C
    strcpy(destination, source); // instead, do it

    printf("After strcpy: source string = \"%s\". Its length is %lu.\n", source, strlen(source));
    printf("After strcpy: destination string = \"%s\". Its length is %lu.\n", destination, strlen(destination));

    char new_string[] = ". This is a new string.";

    strcat(destination, new_string);

    printf("After strcat: \"%s\". Its length is %lu.\n", destination, strlen(destination));

    return 0;
}