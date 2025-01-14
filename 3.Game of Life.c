#include <stdio.h>
#include <ctype.h>

int main() {

    char str[1000];
    scanf("%[^\n]",str);
    
    int col = 1;
    
    for( int i=2; str[i]!=']';i++){
        if(isspace(str[i])) col++;
    }
    
    int arr[100];
    
    char *ptr = str;
    int idx =0;
    while(*ptr){
        if(isdigit(*ptr)){
            int num;
            sscanf(ptr,"%d",&num);
            arr[idx++] = num;
            
            while(isdigit(*ptr)){
                ptr++;
            }
        }else{
            ptr++;
        }
    }
    
    int row = idx/col;
    
    int mat[row][col];
    idx = 0;
    for( int i=0; i<row;i++){
        for( int j=0; j<col;j++){
            mat[i][j] = arr[idx++];
        }
    }
    int ans[row][col];
    idx = 0;
    for( int i=0; i<row;i++){
        for( int j=0; j<col;j++){
            int r[] = {-1,-1,-1,0,0,1,1,1};
            int c[] = {-1,0,1,-1,1,-1,0,1};
            
            int count = 0;
                
            for( int k=0; k<8;k++){
                int x = r[k] + i;
                int y = c[k] + j;
                    
                if( y>=0 && y<col && x>=0 && x<row && mat[x][y]==1 ){
                    count++;
                }
            }
            
            if( mat[i][j] == 1 ){
                if( count < 2 || count > 3){
                    ans[i][j] = 0;
                }else{
                    ans[i][j] = 1;
                }
            }else{
                if(count == 3) ans[i][j] = 1;
                else ans[i][j] = 0;
            }
        }
    }
    
    printf("[");
    int k =0;
    for( int i=0; i<row;i++){
        if(k!=0) printf(",");
        k++;
        printf("[");
        int x =0;
        for( int j=0; j<col;j++){
            if(x!=0) printf(" ");
            x++;
            printf("%d",ans[i][j]);
        }
        printf("]");
    }
    printf("]");
    return 0;
}
