#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void dnfa_sort(int *arr, int n){
    int left=0,mid=0,right=n-1;
    
    while(mid<=right){
        if( arr[mid] == 0){
            int temp = arr[left];
            arr[left] = arr[mid];
            arr[mid] = temp;
            left++;mid++;
        }else if(arr[mid] == 1){
            mid++;
        } else{
            int temp = arr[right];
            arr[right] = arr[mid];
            arr[mid] = temp;
            right--;
        }
    }
}

int main() {

    int n;
    scanf("%d",&n);
    
    int arr[n];
    for( int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    dnfa_sort(arr,n);
    
    for(int i=0; i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
