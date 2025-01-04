#include <stdio.h>
int main() {
    int num;
    printf("Enter numbers :\n");
    while (scanf("%d", &num) != EOF) {
        printf("You entered: %d\n", num);
    }
    printf("End of input\n");
    return 0;
}  // press Ctrl+D to signal EOF in linux and ctrl+Z in windows
