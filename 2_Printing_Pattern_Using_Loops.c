#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	
    int matrix_size = 2 * n - 1;
    for (int i=0; i < matrix_size;i++) {
        for (int j=0; j < matrix_size;j++) {
            int value;
            if (i <= j && i+j <matrix_size) {
                value = n-i;
            }
            else if (i <= j && i+j >= matrix_size-1) {
                value = n-(matrix_size-j-1);
            }
            else if (i >= j && i+j < matrix_size) {
                value = n-j;
            }
            else {
                value = n - (matrix_size-i-1);
            }
            printf("%d ", value);
        }
        printf("\n");
    }
    
    return 0;
}