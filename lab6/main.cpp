#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

const int MAX_N = 10'000;

void printSequence(int numbers[MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
}

int sumOfDigits(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int getFirstDigit(int x) {
    while (x >= 10) {
        x /= 10;
    }
    return x;
}

int getMaxDigit(int x) {
    int max = -1;
    while (x > 0) {
        max = fmax(max, x % 10);
        x /= 10;
    }
    return max;
}

bool customComparator(int a, int b) {
    int firstDigitA = getFirstDigit(a);
    int firstDigitB = getFirstDigit(b);

    if (firstDigitA != firstDigitB) {
        return firstDigitA < firstDigitB;
    }

    int maxDigitA = getMaxDigit(a);
    int maxDigitB = getMaxDigit(b);

    if (maxDigitA != maxDigitB) {
        return maxDigitA < maxDigitB;
    }

    return a < b;
}

bool hasDuplicates(int x) {
    int digits[10] = {0};

    while (x > 0) {
        int digit = x % 10;
        if (digits[digit] > 0) {
            return true; 
        }
        digits[digit]++;
        x /= 10;
    }
    return false;
}

bool hasFive(int x) {
    int count = 0;
    while (x > 0) {
        if (x % 10 == 5) {
            return true;
        }
        x /= 10;
    }
    return false;
}

int first() {
    int numbers[MAX_N];
    int n;

    cout << "Введите количество элеметнов <= 10000: ";
    cin >> n;

    cout << "Введите последовательность: ";

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    bool hasSum14 = false;

    for (int i = 0; i < n; i++) {
        if (sumOfDigits(numbers[i]) == 14) {
            hasSum14 = true;
            break;
        }
    }

    if (!hasSum14) {
        cout << "Нет чисел, сумма цифр которых равна 14." << endl;
        printSequence(numbers, n);
        return 0;
    }

    sort(numbers, numbers + n);

    cout << "Отсортированная последовательность: ";
    printSequence(numbers, n);

    return 0;
}

int second() {
    int n;

    cout << "Введите количество элеметнов <= 10000: ";
    cin >> n;

    int numbers[n];
    
    cout << "Введите последовательность: ";

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers, numbers + n, customComparator);
    printSequence(numbers, n);

    return 0;
}

int third() {
    int n;

    cout << "Введите размерность матрицы: ";
    cin >> n;

    int matrix[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << endl;

    for (int i = 0; i < n; ++i) {
        printSequence(matrix[i], n);
        cout << endl;
    }

    int minValue = INT_MAX;
    int minCol = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] < minValue) {
                minValue = matrix[i][j];
                minCol = j;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (matrix[i][minCol] < 0) {
            matrix[i][minCol] = 0;
        }
    }

    cout << "Изменённая матрица:" << endl;

    for (int i = 0; i < n; ++i) {
        printSequence(matrix[i], n);
        cout << endl;
    }

    return 0;
}

// int fourth() {
//     int n;

//     cout << "Введите количество элементов <= 10000: ";
//     cin >> n;

//     int arr[20'000];

//     cout << "Введите последовательность натуральных чисел:\n";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int index = 0;

//     for (int i = 0; i < n; i++) {
//         if (!hasDuplicates(arr[i])) {
//             arr[index++] = arr[i];
//             if (hasFive(arr[i])) {
//                 arr[index++] = arr[i];
//             }
//         }
//     }

//     cout << "Полученная последовательность (каждый элемент по одному разу):\n";
//     for (int i = 0; i < index; i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

int fourth() {
    int n;
    int arr[MAX_N];

    cout << "Введите количество элементов <= 10000: ";
    cin >> n;

    cout << "Введите элементы:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int index = 0;

    for (int i = 0; i < n; ++i) {
        if (!hasDuplicates(arr[i])) {
            arr[index++] = arr[i];
            if (hasFive(arr[i])) {
                arr[index++] = arr[i];
            }
        }
    }
    n = index;

    cout << "Измененная последовательность:\n";

    printSequence(arr, n);

    return 0;
}

int main() {
    fourth();
    return 0;
}
