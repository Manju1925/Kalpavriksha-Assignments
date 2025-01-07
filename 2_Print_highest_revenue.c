#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,m;
    
    scanf("%d",&n);
    scanf("%d",&m);
    
    char company[n][50];
    char ans_company[1000] = "";
    int max = -1;
    
    for( int i=0;i<n;i++){
        int company_revenue =0;
        scanf("%s", company[i]);
        
        for( int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            company_revenue+=x;
        }
        
        if(company_revenue > max){
            max = company_revenue;
            strcpy(ans_company,"");
            char idx[50];
            sprintf(idx,"%d",i);
            strcat(ans_company, idx);
        } else if( company_revenue == max ){
            char idx[50];
            sprintf(idx," %d",i);
            strcat(ans_company, idx);
        }
        
        
    }
    
    char *token = strtok(ans_company, " ");
    while(token!=NULL) {
        int idx = atoi(token);
        printf("%s\n", company[idx]);
        token = strtok(NULL, " ");
    }
    return 0;
}
