#include <stdio.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[abc]", str);
    printf("You entered: %s\n", str);
    return 0;
}
