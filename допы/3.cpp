#include <iostream>

using namespace std;

int sumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int isFirstOne(int number) {
    while (number / 10 > 0) {
        number /= 10;
    }

    return number == 1;
}

void del(int *mas, int& n) {
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (!(sumOfDigits(mas[i]) % 6)) {
            continue;
        }
        mas[j] = mas[i];
        j++;
    }
    n = j;
}

void dubl(int *mas, int& n) {
    for (int i = 0; i < n; i++) {
        if (isFirstOne(mas[i]) && mas[i] != 1) {
            for (int j = n; j > i; j--) {
                mas[j] = mas[j - 1];
            }
            i++;
            n++;
        }
    }
}

void print(int *mas, int& n) {
    for (int i = 0; i < n; ++ i) {
        cout << mas[i] << " ";
    }    
    cout << endl;
}

int main() {
    const int N_MAX = 20'000;

    int n;
    cout << "Enter lenght: ";
    cin >> n;

    int mas[N_MAX];

    cout << "Enter sequence:" << endl;

    for (int i = 0; i < n; ++i) {
        cin >> mas[i];
    }

    del(mas, n);
    dubl(mas, n);

    cout << "result: ";

    print(mas, n);
    
    return 0;
}