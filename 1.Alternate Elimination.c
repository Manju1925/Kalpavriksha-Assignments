#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    int start=1;
    int step=1;
    int leftToRight=1;
    
    while(n > 1){
        
        if(leftToRight || n%2 == 1){
            start += step;
        }
        step *= 2;
        n /= 2;
        leftToRight = !leftToRight;
    }
    
    printf("%d\n", start);
    return 0;
}
