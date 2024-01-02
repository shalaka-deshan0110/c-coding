#include <stdlib.h>
#include <math.h>
#ifndef STATS_H
#define STATS_H

// compare function for qsort
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

// Mean
double mean(int inputs[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += inputs[i];
    }
    return sum / n;
}

// Median
double median(int inputs[], int n)
{
    qsort(inputs, n, sizeof(int), compare);

    if (n % 2 != 0) {
        return inputs[n / 2];
    }

    return (inputs[(n - 1) / 2] + inputs[n / 2]) / 2.0;
}


// Standard deviation
double standardDeviation(int inputs[], int n)
{

    double meanValue = mean(inputs, n);
    double sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += (inputs[i] - meanValue) * (inputs[i] - meanValue);
    }
    return sqrt(sum / n);
}


// Kurtosis
double kurtosis(int inputs[], int n)
{
    // Population Kurtosis =(∑(x-x')**4)/n⋅S**4

    double meanValue = mean(inputs, n);
    double std_dev = standardDeviation(inputs, n);

    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += pow((inputs[i] - meanValue), 4);
    }

    double kurtosis = (sum / n) / pow(std_dev, 4);
    return kurtosis;
}

#endif 