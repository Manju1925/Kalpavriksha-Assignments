#include <stdio.h>

void generate(int n, int k, int start, int *seq, int index) {
    if(index == k){
        for(int i = 0; i < k; i++){
            printf("%d", seq[i]);
            if (i < k - 1) printf(" ");
        }
        printf("\n");
        return;
    }

    for(int i = start; i <= n; i++){
        seq[index] = i;
        generate(n, k, i+1,seq,index + 1);
    }
}

int main(){
    int k, n;
    scanf("%d %d",&k,&n);

    int seq[k];
    generate(n,k,1,seq, 0);

    return 0;
}
