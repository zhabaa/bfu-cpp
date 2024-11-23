// TODO шляпа делает не то когда в начале чтоит число начинающееся с единицы


#include <iostream>

using namespace std;

const int MAX_SIZE = 10000;


int sumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}


int main() {
    int arr[MAX_SIZE], n;

    cout << "Enter volume <= 10000: ";
    cin >> n;

    cout << "Enter sequence:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int newSize = 0;

    for (int i = 0; i < n; ++i) {
        if (sumOfDigits(arr[i]) % 6 != 0) {
            arr[newSize] = arr[i];
            newSize++;

            if (arr[i] / 10 == 1) {
                arr[newSize] = arr[i];
                newSize++;
            }
        }
    }

    n = newSize;

    cout << "Result:" << endl;

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
