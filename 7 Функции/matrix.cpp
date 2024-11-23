#include "matrix.hpp"
#include <iostream>
#include <limits.h>

using namespace std;

int hasDigit(int x, int digit) {
    while (x > 0) {
        if (digit == x % 10) {
            return true;
        }
        x /= 10;
    }
    return false;
}

void readMatrix(int matrix[100][100], int& n) {
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
}

bool checkCondition(int matrix[100][100], int n) {
    for (int i = 0; i < n; ++i) {
        int diagonalElement = matrix[i][i];
        if (!(diagonalElement > 0 && (hasDigit(diagonalElement, 3) || hasDigit(diagonalElement, 5)))) {
            return false;
        }
    }
    return true;
}

void processMatrix(int matrix[100][100], int n) {
    for (int j = 0; j < n; ++j) {

        int minElement = INT_MAX;
        int minRowIndex = -1;

        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minRowIndex = i;
            }
        }

        int sumOfSquares = 0;

        for (int i = 0; i < n; ++i) {
            sumOfSquares += matrix[i][j] * matrix[i][j];
        }

        if (minRowIndex != -1) {
            matrix[minRowIndex][j] = sumOfSquares;
        }
    }
}

void writeMatrix(int matrix[100][100], int n) {
    cout << "Итоговая матрица:" << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
