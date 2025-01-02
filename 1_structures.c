#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define ITEM_NAME_LENGTH 20

typedef struct item_t
{
	char item_name[ITEM_NAME_LENGTH];
	int item_cost;
} item;

item cart[100];

int main() {
    int n,cost = 0;
    
    scanf("%d",&n);
    getchar();
    
    for (int i=0; i<n; i++) {
        char line[100];
        fgets(line, sizeof(line), stdin);
        char* token = strtok(line,",");
        strncpy(cart[i].item_name, token, ITEM_NAME_LENGTH - 1);
        cart[i].item_name[ITEM_NAME_LENGTH - 1] = '\0';

        token = strtok(NULL, ",");
        cart[i].item_cost = atoi(token);

        cost += cart[i].item_cost;
    }
    
    printf("item list\n");
    for ( int i=0; i<n; i++) {
        printf("%s,%d\n",cart[i].item_name,cart[i].item_cost);
    }
    
    printf("Total cost %d\n",cost);
    
    printf("item quantities\n");
    int Quantity[100]={0};
    
    for(int i=0;i<n; i++){
        int count = 1;
        if(Quantity[i] == 1) continue;
        
        for( int j=i+1; j<n;j++){
            if(strcmp(cart[i].item_name, cart[j].item_name) == 0){
                count++;
                Quantity[j] = 1;
            }
        }
        
        printf("%s - %d\n",cart[i].item_name,count);
    }

    
    return 0;
}