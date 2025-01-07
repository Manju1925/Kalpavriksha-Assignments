#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int n,m;
    char input[1000];
    scanf("%[^\n]s", input);
    int space =0;
    
    for( int i=2; input[i] != ']';i++){
        char ch = input[i];
        if( ch == ' ' ) space++;
    }
    m = space + 1;
    int temp[100];
    int idx = 0;
    
    char *ptr =input;
    while(*ptr) {
        if (isdigit(*ptr)) {
            int num;
            sscanf(ptr, "%d", &num); // sscanf
            temp[idx++] = num;
            while (isdigit(*ptr)) {
                ptr++;  
            }
        } else {
            ptr++;
        }
    }
    
    n = idx /m;
    idx = 0;
    int adj[n][m];
    idx =0;
    for ( int i=0; i<n; i++){
        for ( int j=0; j<m; j++){
            adj[i][j] = temp[idx];
            idx++;
        }
    }

    int top =0, bottom=n-1, left=0, right =m-1;
    
    printf("[");
    int flag=0;
    while ( top<=bottom && left<=right){
         
        for ( int i=left; i<=right;i++){
            if( flag > 0) printf(" ");
            printf("%d", adj[top][i]);
            flag++;
        }
        top++;

        for ( int i=top; i<=bottom; i++){
            printf(" %d", adj[i][right]);
        }
        right--;

        if ( top<=bottom){
            for (int i=right; i>=left;i--){
                printf(" %d", adj[bottom][i]);
            }
            bottom--;
        }

        if ( left<=right){
            for ( int i=bottom; i>=top; i--){
                printf(" %d",adj[i][left]);
            }
            left++;
        }
    }
    printf("]");
    return 0;
}
