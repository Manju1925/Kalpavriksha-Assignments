#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int compare(const void *a, const void *b){
    return (*(int *)b - *(int *)a);
}

int solve(int *player, int *trainer, int n1, int n2){
    qsort(player,n1,sizeof(int),compare);
    qsort(trainer,n2,sizeof(int),compare);

    int i =0, j= 0, count=0;

    while(i < n1 && j < n2){
        if (player[i] <= trainer[j]){
            count++;
            i++;
            j++;
        } else {
            i++;
        }
    }
    return count;
}

int main(){
    char *input1 = (char *)malloc(10000 * sizeof(char));
    char *input2 = (char *)malloc(100000 * sizeof(char));

    scanf("%[^\n]%*c", input1);
    scanf("%[^\n]%*c", input2);

    int *player =(int *)malloc(10000 * sizeof(int));
    int *trainer = (int *)malloc(10000 * sizeof(int));
    int index1=0, index2 =0;

    char *ptr1 =input1;
    char *ptr2 =input2;

    while (*ptr1 != '\0'){
        if (isdigit(*ptr1)){
            int num;
            sscanf(ptr1,"%d",&num);
            player[index1++] = num;
            while(isdigit(*ptr1)){
                ptr1++;
            }
        } else{
            ptr1++;
        }
    }

    while (*ptr2 != '\0'){
        if (isdigit(*ptr2)){
            int num;
            sscanf(ptr2,"%d",&num);
            trainer[index2++]=num;
            while (isdigit(*ptr2)){
                ptr2++;
            }
        }else{
            ptr2++;
        }
    }

    int ans = solve(player, trainer, index1, index2);
    printf("%d\n", ans);

    free(input1);
    free(input2);
    free(player);
    free(trainer);

    return 0;
}
