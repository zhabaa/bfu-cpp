#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int first() {
    unsigned int lenght;

    cout << "Enter lenght: ";
    cin >> lenght;

    vector<int> vec;

    for (int i = 0; i < lenght; ++i) {
        int element;
        cin >> element;
        vec.push_back(element);
    };

    cout << "Seq: ";
    for (int i : vec) {
        std::cout << i << ' ';
    };

    cout << endl;

    long product = 1;
    int min_value = numeric_limits<int>::max();
    int min_value_index = -1;
    bool found = false;

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] >= -2 && vec[i] <= 20) {
            found = true;
            product *= vec[i];

            if (min_value > vec[i]) {
                min_value = vec[i];
                min_value_index = i;
            }
        }
    };

    if (found) {
        cout << "Product: " << product << "\n"
             << "Min value: " << min_value << "\n"
             << "Index: " << min_value_index << endl;
    } else {
        cout << "Нет чисел на отрезке" << endl;
    }

    return 1;
}

int second() {
    unsigned int n;

    cout << "Enter n: ";
    cin >> n;

    long sumDigit = 0;

    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) {
            sumDigit += digit;
        }
        n /= 10;
    }

    cout << "Sum of even: " << sumDigit << endl;
    return 1;
}

int main() {
    second();
}