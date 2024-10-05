#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <limits>
#include <unordered_set>

using namespace std;

int sumOfDigits(int digit) {
    int sum = 0;

    while (digit > 0) {
        sum += digit % 10;
        digit /= 10;
    }

    return sum;
}

int getFirstDigit(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

int getMaxDigit(int num) {
    int maxDigit = 0;
    while (num > 0) {
        int digit = num % 10;
        if (digit > maxDigit) {
            maxDigit = digit;
        }
        num /= 10;
    }
    return maxDigit;
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

void replaceNegativeElements(vector<vector<int>>& matrix, int column) {
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][column] < 0) {
            matrix[i][column] = 0;
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }
}

bool duplicateDigits(int number) {
    unordered_set<int> digits;
    while (number > 0) {
        int digit = number % 10;
        if (digits.find(digit) != digits.end()) {
            return true;
        }
        digits.insert(digit);
        number /= 10;
    }
    return false;
}

int first() {
    srand(time(nullptr));

    int n;
    cout << "Введите количество элементов последовательности (n <= 10000): ";
    cin >> n;

    if (n > 10000) {
        cerr << "Количество элементов должно быть не более 10000.\n";
        return 1;
    }

    vector<int> numbers(n);
    
    for (int& num : numbers) {
        num = rand();
    }

    cout << "Последовательность чисел: ";
    for (const int& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    bool flag = false;

    for (int i = 0; i < n; i++) {
        if (sumOfDigits(numbers[i]) == 14) {
            flag = true;
            break;
        }
    }

    if (flag) {
        sort(numbers.begin(), numbers.end());
        cout << "Отсортированная последовательность чисел: ";

        for (const int& num : numbers) {
            cout << num << " ";
        }
    } else {
        cout << "В последовательности нет элементов, сумма которых равна 14" << endl;
    }

    return 0;
}

int second() {
    int n;
    cout << "Введите количество элементов (n <= 1000): ";
    cin >> n;

    if (n > 1000) {
        cerr << "Количество должно быть не более 1000.\n";
        return 1;
    }

    vector<int> numbers(n);

    cout << "Введите элементы: " << endl;
    for (int &num : numbers) {
        cin >> num;
    }

    sort(numbers.begin(), numbers.end(), customComparator);

    cout << "Отсортированная последовательность: ";
    for (const int &num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

int third() {
    int n, m, k;

    srand(time(nullptr));

    cout << "Введите количество n и m (n, m <= 100): ";
    cin >> n >> m;

    cout << "Введите ограничение для элементов матрицы: ";
    cin >> k;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = rand() % (2 * k + 1) - k;
            // cin >> matrix[i][j];
        }
    }

    printMatrix(matrix);
    cout << endl;

    int minElement = numeric_limits<int>::max();
    int minColumn = -1;
    
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minColumn = j;
            }
        }
    }
    
    if (minColumn != -1) {
        replaceNegativeElements(matrix, minColumn);

        cout << "Изменённая матрица:\n";
        printMatrix(matrix);
    } else {
        cout << "Матрица не содержит элементов." << endl;
    }
    
    return 0;
}

int fourth() {
    int n;
    cout << "Введите количество элементов (n <= 10000): ";
    cin >> n;

    vector<int> sequence(n);

    cout << "Введите последовательность:" << endl;
    
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    vector<int> result;
    for (int num : sequence) {
        if (!duplicateDigits(num)) {
            result.push_back(num);

            int temp = num;
            bool flag = false;

            while (temp > 0) {
                if (temp % 10 == 5) {
                    flag = true;
                    break;
                }
                temp /= 10;
            }
            if (flag) {
                result.push_back(num);
            }
        }
    }

    cout << "Итоговая последовательность:" << endl;

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

int main() {
    fourth();
    return 0;
}
