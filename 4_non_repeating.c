#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_WORDS 50
#define MAX_LENGTH 1000

int main() {
    char sentence[MAX_LENGTH];
    char words[MAX_WORDS][MAX_WORDS];
    int count = 0, idx = 0;
    
    fgets(sentence,sizeof(sentence),stdin);
    
    for( int i=0; i<strlen(sentence);i++){
        if(sentence[i]!=' ' && sentence[i]!= '\n'){
            words[count][idx++] = sentence[i];
        }else if(idx>0){
            words[count][idx] = '\0';
            count++;
            idx=0;
        }
    }
    
    if(idx >0){
        words[count][idx] = '\0';
        count++;
    }
    
    int flag = 0;
    for(int i=0;i<count;i++){
        int repeat = 0;
        for( int j=0;j<count; j++){
            if(strcmp(words[i], words[j]) == 0) {
                repeat++;
            }
        }
        
        if( repeat == 1){
            printf("%s\n",words[i]);
            flag = 1;
            break;
        }
    }
    
    if (!flag) {
        printf("");
    }
    return 0;
}
