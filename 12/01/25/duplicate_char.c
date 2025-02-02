#include<stdio.h>
#include<string.h>

int main(){

    char str[100];
    scanf("%s",str);

    int map[256] = {0};
    char ans[]="";
    int length = strlen(str);
    for( int i=0; i<length;i++){
        int ch = (int)str[i];

        if(map[ch] == 0){
            map[ch] = 1;
            char temp[2] = {str[i], '\0'};
            strcat(ans, temp);
        }
    }

    printf("%s",ans);
    return 0;
}