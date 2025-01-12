#include<stdio.h>
#include<string.h>

int main(){

    char str1[100];
    char str2[100];
    scanf("%[^\n]",str1);
    getchar();

    scanf("%[^\n]",str2);
    getchar();

    int n1 = strlen(str1);
    int n2 = strlen(str2);

    if( n1!=n2){
        printf("false");
        return 0;
    }
    

    for( int i =0; i<n1; i++){
        if(str1[i]!=str2[n1-1-i]){
            printf("false");
            return 0;
        }
    }

    printf("true");
    return 0;
}