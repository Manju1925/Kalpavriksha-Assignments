#include<stdio.h>
#include<string.h>

int main(){

    char str[100];
    scanf("%[^\n]",str);
    getchar();

    char *token;
    token = strtok(str," ");

    int count =0;
    while(token!=NULL){
        count++;
        token = strtok(NULL," ");
    }

    printf("\n %d",count);
    return 0;
}