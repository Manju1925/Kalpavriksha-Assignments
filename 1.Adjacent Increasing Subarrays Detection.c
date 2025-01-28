#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

int cmp(int *arr, int sz){
    int prv = 0;
    int cur = 1;
    int ans = 0;

    for(int i = 1; i < sz; i++){
        if (arr[i - 1] < arr[i]){
            cur++;
        }else{
            prv = cur;
            cur = 1;
        }
        ans = ans > cur / 2 ? ans : cur / 2;
        ans = ans > (prv < cur ? prv : cur) ? ans : (prv < cur ? prv : cur);
    }
    return ans;
}

int main() {
    char *buf = (char *)malloc(100000 * sizeof(char));
    scanf("%[^\n]%*c", buf);
    int *arr = (int *)malloc(100000 * sizeof(int));
    int cnt = 0;
    char *tra = buf;

    while(*tra != '\0'){
        if (isdigit(*tra) || *tra == '-'){
            int num;
            sscanf(tra, "%d", &num);
            arr[cnt++] = num;
            while (isdigit(*tra) || *tra == '-'){
                tra++;
            }
        }else{
            tra++;
        }
    }

    int ans = cmp(arr, cnt);
    printf("%d\n", ans);

    free(buf);
    free(arr);
    return 0;
}
