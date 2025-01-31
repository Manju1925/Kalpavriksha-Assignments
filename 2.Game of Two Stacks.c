int twoStacks(int maxSum, int a_count, int* a, int b_count, int* b) {
    int sum = 0, countA = 0, countB = 0, maxCount = 0;

    while (countA < a_count && sum + a[countA] <= maxSum) {
        sum += a[countA++];
    }
    maxCount = countA;

    while (countB < b_count && countA >= 0) {
        sum += b[countB++];
        
        while (sum > maxSum && countA > 0) {
            sum -= a[--countA];
        }

        if (sum <= maxSum) {
            maxCount = (countA + countB > maxCount) ? countA + countB : maxCount;
        }
    }
    
    return maxCount;
}