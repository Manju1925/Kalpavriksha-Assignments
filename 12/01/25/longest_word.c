#include<stdio.h>
#include<string.h>

int main(){

    char str[100];
    scanf("%[^\n]",str);
    getchar();

    char *token;
    token = strtok(str," ");

    int max = 0;
    char ans[] = "";
    while(token!=NULL){
        int n = strlen(token);
        if(n>max){
            max = n;
            strcpy(ans,token);
        }
        token = strtok(NULL," ");
    }

    printf("%s",ans);
    return 0;
}