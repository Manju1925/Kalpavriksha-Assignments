#include <stdio.h>
#include <ctype.h>

int main() {

    char str[6003];
    scanf("%[^\n]%*c",str);
    
    int arr[3000];
    int idx=0;
    char* ptr=str;
    while (*ptr){
        if(isdigit(*ptr)||(*ptr == '-' && isdigit(*(ptr+1)))){
            int num;
            sscanf(ptr,"%d",&num);
            arr[idx++]=num;

            while (isdigit(*ptr) || *ptr == '-'){
                ptr++;
            }
        }else{
            ptr++;
        }
    }
    
    for( int i=0; i<idx;i++){
        int min = i;
        for( int j=i+1;j<idx;j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    
    printf("[");
    int item = 0;
    for( int i=0;i<idx-2;i++){
        
        if( i>0 && arr[i] == arr[i-1]) continue;
        
        int j = i+1;
        int k = idx-1;
        while(j<k){
            if( (arr[i]+arr[j]+arr[k]) == 0){
                if(item!=0){
                    printf(",");
                }
                item++;
                printf("[%d %d %d]",arr[i],arr[j],arr[k]);
                j++;k--;
                
                while ( j<k && arr[j] == arr[j-1]) j++;
                while ( j<k && arr[k] == arr[k+1]) k--;
            }else if((arr[i]+arr[j]+arr[k]) < 0){
                j++;
            }else{
                k--;
            }
        }
        
    }
    
    printf("]");
    return 0;
}
