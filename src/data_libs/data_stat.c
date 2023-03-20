#include "data_stat.h"

#include <stdio.h>

double max(double *data, int n) {
    int max_v = data[0];
    for (int i = 0; i < n; i++) {
        if (max_v < data[i]) max_v = data[i];
    }
    return max_v;
}

double min(double *data, int n) {
    int min_v = data[0];
    for (int i = 0; i < n; i++) {
        if (min_v > data[i]) min_v = data[i];
    }
    return min_v;
}

double mean(double *data, int n) {
    double mean_v = data[0];
    for (int i = 0; i < n; i++) {
        mean_v += data[i];
    }
    mean_v = mean_v / n;

    return mean_v;
}

double variance(double *data, int n) {
    double variance_v = data[0];
    double x = mean(data, n);
    for (int i = 0; i < n; i++) variance_v = variance_v + (((data[i] - x) * (data[i] - x)) / n);

    return variance_v;
}
