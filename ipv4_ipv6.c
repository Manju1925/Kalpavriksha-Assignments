#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isIPv4(char *str){
    int octets = 0;
    char *token = strtok(str,".");
    
    while(token != NULL){
        int num = atoi(token);
        if (num < 0 || num > 255 || strlen(token) > 3 ){
            return 0;
        }
        octets++;
        token = strtok(NULL,".");
    }
    return octets == 4;
}

int isIPv6(char *str){
    int groups = 0;
    char *token = strtok(str,":");
    
    while (token != NULL){
        if (strlen(token) < 1 || strlen(token) > 4) {
            return 0;
        }
        for (int i = 0; i < strlen(token); i++) {
            if (!((token[i] >= '0' && token[i] <= '9') || (token[i] >= 'a' && token[i] <= 'f'))) {
                return 0;
            }
        }
        groups++;
        token = strtok(NULL, ":");
    }
    return groups == 8;
}

int main() {
    char str[50];
    fgets(str, 50, stdin);
    str[strcspn(str, "\n")] = 0;
    
    if(isIPv6(str)){
        printf("IPv6\n");
    }
    else if(isIPv4(str)) {
        printf("IPv4\n");
    }
    else{
        printf("Neither\n");
    }
    
    return 0;
}
