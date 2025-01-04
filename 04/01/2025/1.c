// Call by address in C 

#include <stdio.h>

void modify(int *x) {
    *x = 20;
}

int main() {
    int a = 10;
    modify(&a);
    printf("%d\n", a);
    return 0;
}

