#include <stdio.h>

void fun(int n){
    int curr = 1;
    printf("%d",curr);

    for(int i=1; i<=n; i++){
        curr = curr * (n-i+1) / i;
        printf(",%d", curr);
    }

    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    fun(n - 1);
    return 0;
}
