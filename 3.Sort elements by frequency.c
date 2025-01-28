#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    long long val;
    int fq;
    int f_idx;
} Pr;

Pr *process(long long *arr, int *sz, int n) {
    Pr *res = (Pr *)malloc(n * sizeof(Pr));
    int idx = 0;
    for (int i = 0; i < n; i++) {
        int pos = find_idx(res, idx, arr[i]);
        if (pos != -1) {
            res[pos].fq++;
        } else {
            res[idx].val = arr[i];
            res[idx].fq = 1;
            res[idx].f_idx = i;
            idx++;
        }
    }
    *sz = idx;
    return res;
}

int find_idx(Pr *res, int sz, long long val) {
    for (int i = 0; i < sz; i++) {
        if (res[i].val == val) {
            return i;
        }
    }
    return -1;
}

int main() {
    char input[100000];
    scanf("%[^\n]%*c", input);
    long long arr[100000];
    int id = 0;
    char *ptr = input;

    while (*ptr != '\0') {
        if (isdigit(*ptr) || *ptr == '-') {
            long long num;
            sscanf(ptr, "%lld", &num);
            arr[id++] = num;
            while (isdigit(*ptr) || *ptr == '-') {
                ptr++;
            }
        } else {
            ptr++;
        }
    }

    int sz = 0;
    Pr *res = process(arr, &sz, id);

    for (int i = 0; i < sz - 1; i++) {
        for (int j = 0; j < sz - 1 - i; j++) {
            if (res[j].fq < res[j + 1].fq || 
               (res[j].fq == res[j + 1].fq && res[j].f_idx > res[j + 1].f_idx)) {
                Pr tmp = res[j];
                res[j] = res[j + 1];
                res[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < res[i].fq; j++) {
            printf("%lld ", res[i].val);
        }
    }
    printf("\n");
    free(res);

    return 0;
}
