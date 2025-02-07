#include <stdio.h>
#include <string.h>

#define MAX_LOG_SIZE 100000
#define MAX_ACTION_LENGTH 101

int main() 
{
    char logs[MAX_LOG_SIZE][MAX_ACTION_LENGTH];
    int logCount = 0;
    int threshold, first = 1;
    char input[MAX_LOG_SIZE * MAX_ACTION_LENGTH];
    int i,j,k;
    
    scanf("%[^\n]%*c", input);
    
    char *token = strtok(input, " ");
    while (token != NULL) 
    {
        strcpy(logs[logCount], token);
        logCount++;
        token = strtok(NULL, " ");
    }
    
    scanf("%d", &threshold);

    int visited[MAX_LOG_SIZE] = {0};  

    printf("[");

    for (i = 0; i < logCount; i++) 
    {
        if (visited[i]) 
        {
            continue;  
        }

        int count = 0;
        for (j = 0; j < logCount; j++) 
        {
            if (strcmp(logs[i], logs[j]) == 0) 
            {
                count++;
            }
        }

        if (count < threshold) 
        {
            if (!first) 
            {
                printf(", ");
            }
            printf("\"%s\"", logs[i]);
            first = 0;

            
            for (k = 0; k < logCount; k++) 
            {
                if (strcmp(logs[i], logs[k]) == 0) 
                {
                    visited[k] = 1;
                }
            }
        }
    }

    printf("]\n");
    return 0;
}