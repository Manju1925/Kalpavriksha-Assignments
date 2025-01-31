void generatePrimes(int primes[], int q) {
    int count = 0, num = 2;
    while (count < q) {
        int isPrime = 1;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            primes[count++] = num;
        }
        num++;
    }
}

int* waiter(int number_count, int* number, int q, int* result_count) {
    int* primes = (int*)malloc(q * sizeof(int));
    generatePrimes(primes, q);
    int* answer = (int*)malloc(number_count * sizeof(int));
    int answerIndex = 0;
    int* A = (int*)malloc(number_count * sizeof(int));
    int A_size = number_count;

    for (int i = 0; i < number_count; i++) {
        A[i] = number[i];
    }

    for (int i = 0; i < q; i++) {
        int prime = primes[i];
        int* B = (int*)malloc(number_count * sizeof(int));
        int* new_A = (int*)malloc(number_count * sizeof(int));
        int B_size = 0, new_A_size = 0;

        for (int j = A_size - 1; j >= 0; j--) {
            if (A[j] % prime == 0) {
                B[B_size++] = A[j];
            } else {
                new_A[new_A_size++] = A[j];
            }
        }

        for (int j = B_size - 1; j >= 0; j--) {
            answer[answerIndex++] = B[j];
        }

        free(A);
        A = new_A;
        A_size = new_A_size;
        free(B);
    }

    for (int i = A_size - 1; i >= 0; i--) {
        answer[answerIndex++] = A[i];
    }

    free(A);
    free(primes);
    *result_count = answerIndex;
    return answer;
}
