#include <stdio.h>
#include "stats.h"

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Mean: %f\n", mean(arr, n));
    printf("Median: %f\n", median(arr, n));
    printf("Standard deviation: %f\n", standardDeviation(arr, n));
    printf("Kurtosis: %f\n", kurtosis(arr, n));

    return 0;
}