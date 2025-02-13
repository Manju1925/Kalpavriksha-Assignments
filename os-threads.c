#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int count = 0;
pthread_mutex_t lock;
void* add();
/* DO NOT CHANGE ABOVE CODE */

int main() {
    int input;
    scanf("%d", &input);

    pthread_mutex_init(&lock, NULL);

    int thread_count = input / 100000;
    pthread_t threads[thread_count];

    for (int i = 0; i < thread_count; i++) {
        pthread_create(&threads[i], NULL, add, NULL);
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("%d", count);
    return 0;
}

/* DO NOT CHANGE BELOW CODE */
void* add() {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock);   // Lock before updating count
        count += 1;
        pthread_mutex_unlock(&lock); // Unlock after updating count
    }
    return NULL;
}