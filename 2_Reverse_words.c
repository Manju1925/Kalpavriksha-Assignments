#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char sentence[1000];
    char words[100][100];
    int count = 0;

    scanf("%[^\n]%*c", sentence);

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, " ");
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i != 0) {
            printf(" ");
        }
    }

    return 0;
}
