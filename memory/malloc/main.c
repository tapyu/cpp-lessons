#include <stdio.h>
#include <stdlib.h>

struct FlexibleArray {
    int length;  // 4-byte length
    int array[]; // since it is declared but not defined it is 0-byte length
};

int main() {
    int n = 6;
    printf("The size of an int is %zu\n", sizeof(int));
    printf("The size of FlexibleArray, containing an int and unsized int arry, is %zu\n", sizeof(struct FlexibleArray));

    struct FlexibleArray *fa = malloc(sizeof(struct FlexibleArray) + n * sizeof(int)); //
    fa->length = n;

    for (int i = 0; i < fa->length; i++) {
        fa->array[i] = i * i;
        printf("%d ", fa->array[i]);
    }

    printf("\n");
    free(fa);
    return 0;
}
