#include<stdio.h>
#include<pthread.h>
int balance = 1000;
void * deposit(void *arg);
void *withdraw(void *arg);

int main()
{
    scanf("%d",&balance);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, deposit, (void*)1);
    pthread_create(&t2, NULL, withdraw, (void*)2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("all done: balance = %d\n", balance);
    return 0;
}

void* deposit(void *arg)
{
    int i;
    for(i=0; i<10000; ++i)
        ++balance;
    return NULL;
}
void* withdraw(void *arg)
{
    int i;
    for(i=0; i<10000; ++i)
        --balance;
    return NULL;
}