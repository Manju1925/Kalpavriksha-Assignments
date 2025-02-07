#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CITY_LENGTH 101

void trim(char *str) 
{
    int start = 0;
    while (str[start] != '\0' && str[start] == ' ') 
    {
        start++;
    }
    int end = strlen(str) - 1;
    while (end >= start && str[end] == ' ') 
    {
        end--;
    }
    int length = end - start + 1;
    for (int i = 0; i < length; i++) 
    {
        str[i] = str[start + i];
    }
    str[length] = '\0';
}

int main() 
{
    int n;
    scanf("%d\n", &n);
    char source[n][CITY_LENGTH], dest[n][CITY_LENGTH];

    for (int i = 0; i < n; i++) 
    {
        scanf("%[^-]->%[^\n]\n", source[i], dest[i]);
        trim(source[i]);
        trim(dest[i]);
    }

    int start = -1;
    for (int i = 0; i < n; i++) 
    {
        int is_dest = 0;
        for (int j = 0; j < n; j++) 
        {
            if (strcmp(source[i], dest[j]) == 0) 
            {
                is_dest = 1;
                break;
            }
        }
        if (!is_dest) 
        {
            start = i;
            break;
        }
    }



    int visited[n];
    for (int i = 0; i < n; i++) 
    {
        visited[i] = 0;
    }

    int current = start;
    int first_output = 1;

    while (!visited[current]) 
    {
        visited[current] = 1;

        if (!first_output) 
        {
            printf(", ");
        }
        printf("%s->%s", source[current], dest[current]);
        first_output = 0;

        int next = -1;
        for (int i = 0; i < n; i++) 
        {
            if (strcmp(dest[current], source[i]) == 0 && !visited[i]) 
            {
                next = i;
                break;
            }
        }

        if (next == -1) 
        {
            break;
        }

        current = next;
    }

    printf("\n");
    return 0;
}