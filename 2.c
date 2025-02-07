#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int find(char *str, char str1[][101], int n) 
{
    int i;
    for(i = 0; i < n; i++) 
    {
        if(strcmp(str, str1[i]) == 0) 
        {
            return 1;
        }
    }
    return 0;
}
 
int getnext(char *str, char str1[][101], int n) 
{
    int i;
    for(i = 0; i < n; i++) 
    {
        if(strcmp(str, str1[i]) == 0) 
        {
            return i;
        }
    }
    return 0;
}
 
int main() 
{
    int n, i;
    char str[202];
    char str1[100001][101], str2[100001][101];
    
    scanf("%d", &n);
    getchar();
    
    for(i = 0; i < n; i++) 
    {
        scanf("%[^\n]%*c", str);
        char *token = strtok(str, "->");
        while(token != NULL && token[strlen(token)-1] == ' ')
        {
            token[strlen(token)-1] = '\0';
        }
            
        while(token != NULL && *token == ' ')
        {
            token++;
        }
            
        if(token != NULL)
        {
            strcpy(str1[i], token);
        }
        

        token = strtok(NULL, "->");
        while(token != NULL && token[strlen(token)-1] == ' ')
        {
            token[strlen(token)-1] = '\0';
        }
            
        while(token != NULL && *token == ' ')
        {
            token++;
        }
            
        if(token != NULL)
        {
            strcpy(str2[i], token);
        }
            
    }
    
    int first = 0;
    for(i = 0; i < n; i++) 
    {
        if(find(str1[i], str2, n) == 0) 
        {
            first = i;
            break;
        }
    }
    
    printf("%s->%s", str1[first], str2[first]);
    
    int current = first;
    for(i = 0; i < n-1; i++) 
    {
        current = getnext(str2[current], str1, n);
        printf(", %s->%s", str1[current], str2[current]);
    }
    
    return 0;
}