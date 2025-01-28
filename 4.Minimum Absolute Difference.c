#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    
    char input[1000000];
    fgets(input, sizeof(input), stdin);
    
    int n =0;
    for (int i=0; input[i]!='\0';i++){
        if (input[i] == ' ') {
            n++;
        }
    }
    n++;

    int *arr = (int *)malloc(n * sizeof(int));
    char *token = strtok(input, " ");
    for (int i = 0; token != NULL; i++) {
        arr[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    qsort(arr,n,sizeof(int),compare);


    int min_diff = __INT_MAX__;
    for(int i = 1; i < n; i++){
        int diff = arr[i] - arr[i - 1];
        if (diff <min_diff){
            min_diff = diff;
        }
    }

    int flag = 1;
    for (int i=1; i<n; i++){
        if (arr[i] - arr[i-1] == min_diff){
            if (!flag){
                printf(",");
            }
            printf("[%d,%d]",arr[i-1],arr[i]);
            flag =0;
        }
    }

    free(arr);

    return 0;
}
