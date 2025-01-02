#include <stdio.h>

void mod_exp(long base, long exp, long mod);
void mod_exp(long base, long exp, long mod) {
    long ans = 1;
    while (exp>0) {
        if (exp%2 == 1) {
            ans = (ans*base)%mod;
        }
        exp=exp/2;
        base=(base*base)%mod;
    }
    printf("Result: %ld\n", ans);
}

long main() {
    long base, exp, mod;

    printf("Enter the base, exponent, modulus  : ");
    scanf("%ld %ld %ld", &base, &exp, &mod );

    if (mod <= 1 || exp < 0) {
        printf("Invalid Input\n");
        return 0;
    }

    mod_exp(base, exp, mod);
    return 0;
}
