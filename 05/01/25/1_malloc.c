#include <stdio.h>
#include <stdlib.h>

int main() {
    int *x = (int*) malloc(sizeof(int)); 
    if (x == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *x = 10;
    printf("%d\n", *x); 

    free(x);
    return 0;
}
