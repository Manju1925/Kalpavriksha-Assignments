#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

void generateSubsets(int *arr,int size,int index,int *current,int currentSize,int **result,int *resultSize,int *resultColSize) {
    result[*resultSize] = (int *)malloc(currentSize * sizeof(int));
    for (int i = 0; i < currentSize; i++){
        result[*resultSize][i] = current[i];
    }
    resultColSize[*resultSize] = currentSize;
    (*resultSize)++;

    for (int i = index; i < size; i++) {
        current[currentSize] = arr[i];
        generateSubsets(arr, size, i + 1, current, currentSize + 1, result, resultSize, resultColSize);
    }
}

int main() {
    char input[100];
    scanf("%[^\n]", input);
    getchar();

    int arr[15];
    int size = 0;
    char *token = strtok(input, ",");
    while (token != NULL) {
        arr[size++] = atoi(token);
        token = strtok(NULL, ",");
    }
    
    qsort(arr, size, sizeof(int), compare);
    
    int **result = (int **)malloc((1 << size) * sizeof(int *));
    int *resultColSize = (int *)malloc((1 << size) * sizeof(int));
    int resultSize = 0;
    int *current = (int *)malloc(size * sizeof(int));
    
    generateSubsets(arr,size,0,current,0,result,&resultSize,resultColSize);
    
    printf("[");
    for (int i = 0; i < resultSize; i++) {
        printf("[");
        for (int j = 0; j < resultColSize[i]; j++) {
            printf("%d", result[i][j]);
            if (j < resultColSize[i] - 1) printf(", ");
        }
        printf("]");
        if (i < resultSize - 1) printf(", ");
    }
    printf("]\n");
    
    for (int i = 0; i < resultSize; i++) {
        free(result[i]);
    }
    free(result);
    free(resultColSize);
    free(current);
    
    return 0;
}
