#include "func.hpp"

void ShellSort(int *mass, int n) {
    int i, j, d;
    int tmp;

    for (d = n / 2; d > 0; d /= 2) {
        for (i = d; i < n; i++) {
            tmp = mass[i];
            for (j = i; j >= d; j -= d) {
                if (tmp < mass[j - d])
                    mass[j] = mass[j - d];
                else
                    break;
            }
            mass[j] = tmp;
        }
    }
}