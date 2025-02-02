#include<stdio.h>
#include<string.h>

int main(){

    char str1[100];
    char str2[100];
    scanf("%s",str1);
    scanf("%s",str2);

    int map[256] = {0};

    int n1 = strlen(str1);
    int n2 = strlen(str2);

    if(n1 != n2){
        printf("false");
        return 0;
    }

    for( int i = 0; i<n1; i++){
        int ch1 = str1[i];
        int ch2 = str2[i];

        map[ch1]++;
        map[ch2]--;
    }

    for( int i=0; i<256; i++){
        if(map[i] != 0){
            printf("false");
            return 0;
        }
    }

    printf("true");
    return 0;
}