#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

int main(){
    char str[100005];
    scanf("%[^\n]%*c", str);

    int nums[100005],idx = 0;
    char *ptr = str;

    while(*ptr) {
        if(isdigit(*ptr)||(*ptr == '-' && isdigit(*(ptr + 1)))){
            int num;
            sscanf(ptr, "%d", &num);
            nums[idx++] = num;

            while(isdigit(*ptr) || *ptr == '-'){
                ptr++;
            }
        }else{
            ptr++;
        }
    }
    
    if(idx == 0){
        printf("0");
        return 0;
    } 

    int ans =INT_MIN, sum =0;

    for(int i = 0; i < idx; i++){
        sum+=nums[i];
        if(sum > ans){
            ans =sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }

    printf("%d\n", ans);
    return 0;
}

