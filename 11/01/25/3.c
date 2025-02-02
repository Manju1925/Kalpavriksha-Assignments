#include <stdio.h>

int main() {
    char str1[50], str2[50];
    printf("Enter two strings separated by ';': ");
    scanf("%[^;]%*c%[^;]%*c", str1, str2);
    printf("First string: %s\n", str1);
    printf("Second string: %s\n", str2);
    return 0;
}
