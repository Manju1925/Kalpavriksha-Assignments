#include <stdio.h>

int main() {
    char name[50], city[50];
    int age;
    printf("Enter data in the format Name,Age,City: ");
    scanf("%[^,],%d,%[^,\n]", name, &age, city);
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("City: %s\n", city);
    return 0;
}
