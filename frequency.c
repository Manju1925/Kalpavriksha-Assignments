#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 256

int main() {
    char string[10000];
    int freq[MAX_CHAR] = {0};
    int i, first = 1;
    
    scanf("%[^\n]%*c", string);
    
    for (i = 0; string[i] != '\0'; i++) {
        freq[string[i]]++;
    }

    printf("{");
    for (i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            if (first == 0) {
                printf(", ");
            }
            printf("%c:%d", i, freq[i]);
            first = 0;
        }
    }
    printf("}");

    return 0;
}