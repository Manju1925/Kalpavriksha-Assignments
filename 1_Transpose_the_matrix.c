#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d",&n);
    
    int adj[n][n];
    
    for(int i=0; i<n; i++){
        for( int j=0; j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    
    for(int i=0; i<n; i++){
        for( int j=i+1; j<n;j++){
            int temp =adj[i][j];
            adj[i][j] = adj[j][i];
            adj[j][i] = temp;
        }
    }
    
    for(int i=0; i<n; i++){
        for( int j=0; j<n;j++){
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}