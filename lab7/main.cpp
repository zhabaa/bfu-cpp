#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }
}



bool containsThreeOrFive(int number) {
    while (number != 0) {
        int digit = abs(number % 10);
        if (digit == 3 || digit == 5) {
            return true;
        }
        number /= 10;
    }
    return false;
}

bool checkDiagonalElements(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; ++i) {
        if (matrix[i][i] <= 0 || !containsThreeOrFive(matrix[i][i])) {
            return false;
        }
    }
    return true;
}

int first() {
    int n, m, k;

    srand(time(nullptr));

    cout << "Введите количество n и m (n, m <= 100): ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Матрица: " << endl;
    printMatrix(matrix);

    if (checkDiagonalElements(matrix, n)) {
        for (int j = 0; j < n; ++j) {

            int minElement = numeric_limits<int>::max();
            int minIndex = -1;

            for (int i = 0; i < n; ++i) {
                if (matrix[i][j] < minElement) {
                    minElement = matrix[i][j];
                    minIndex = i;
                }
            }

            int sumOfSquares = 0;

            for (int i = 0; i < n; ++i) {
                sumOfSquares += matrix[i][j] * matrix[i][j];
            }

            matrix[minIndex][j] = sumOfSquares;
        }

        cout << "Итоговая матрица:" << endl;
        printMatrix(matrix);
    } else {
        cout << "Не все диагональные элементы > 0 и содержат цифры 3 или 5." << endl;
    }

    return 0;
}

int main() {
    first();
    return 0;
}