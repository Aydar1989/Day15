#include <stdio.h>
#include <stdlib.h>
#include "../data_libs/data_io.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"
#include "../data_libs/data_stat.h"

double sort(double *data, int n);


int main() {
    double *data = NULL;
    int n;

    scanf("%d", &n);

    data = (double *)calloc(n, sizeof(double));

    printf("LOAD DATA...\n");
    input(data, n);

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n);
    output(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);

    printf("\nFINAL DECISION:\n\t");
    if (make_decision(data, n)) {
        printf("YES");
    } else
        printf("NO");
        
    free(data);
    return 0;
}


double sort(double *data, int n) {
    int x;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                x = data[j];
                data[j] = data[j + 1];
                data[j + 1] = x;
            }
        }
    }
    return x;
}