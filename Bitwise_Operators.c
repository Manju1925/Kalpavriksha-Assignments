#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k) {
    int max_and = 0;
    int max_or = 0;
    int max_xor = 0;
    
    for( int i=1; i<=n;i++){
        for( int j=i+1;j<=n;j++){
            int a = i & j;
            int b = i | j;
            int c = i ^ j;
            if( a > max_and && a < k){
                max_and = a;
            }
            if( b > max_or && b < k){
                max_or = b;
            }
            if( c > max_xor && c < k){
                max_xor = c;
            }
        }
    }
    
    printf("%d\n", max_and);
    printf("%d\n", max_or);
    printf("%d\n", max_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}