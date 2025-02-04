#include <stdio.h>
#include <stdlib.h>

int longestSubarrayWithSumK(int arr[], int n, int k) {
    int left = 0, right = 0, sum = 0, maxLength = 0;

    while (right < n) {
        sum += arr[right];

        while (sum > k && left <= right) {
            sum -= arr[left];
            left++;
        }

        if (sum == k) {
            maxLength = (right - left + 1) > maxLength ? (right - left + 1) : maxLength;
        }

        right++;
    }

    return maxLength;
}

int main() {
    int arr[] = {1, 2, 3, 1, 1, 1, 5, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;

    printf("Longest Subarray Length with Sum %d: %d\n", k, longestSubarrayWithSumK(arr, n, k));

    return 0;
}
