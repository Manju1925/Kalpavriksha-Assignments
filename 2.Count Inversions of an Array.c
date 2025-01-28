#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100000];
    scanf("%[^\n]%*c", input);
    long long arr[100000];
    int idx = 0;
    char *ptr = input;

    while (*ptr != '\0') {
        if (isdigit(*ptr) || *ptr == '-') {
            long long val;
            sscanf(ptr, "%lld", &val);
            arr[idx++] = val;
            while (isdigit(*ptr) || *ptr == '-') {
                ptr++;
            }
        } else {
            ptr++;
        }
    }

    long long swaps = 0;
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < idx - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                long long temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }

    printf("%lld", swaps);
    return 0;
}
