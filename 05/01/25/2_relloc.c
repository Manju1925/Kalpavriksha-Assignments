#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr = (int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    arr = (int*) realloc(arr, 10 * sizeof(int));
    for (int i = n; i<10; i++) {
        arr[i] = i+1;
    }

    for (int i = 0; i< 10; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
