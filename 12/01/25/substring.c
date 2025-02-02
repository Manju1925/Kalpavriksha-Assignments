#include<stdio.h>
#include<string.h>

int main(){

    char str1[100];
    char str2[100];
    scanf("%[^\n]",str1);
    getchar();

    scanf("%[^\n]",str2);
    getchar();

    char *idx = strstr(str1,str2);

    if(idx!=NULL){
        printf("%d",idx-str1);
    }else{
        printf("-1");
    }
    
    return 0;
}