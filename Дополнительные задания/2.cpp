#include <iostream>

using namespace std;

int sumOfDigit(int n) {
    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main() {
    int count = 0;

    for (int i = 0; i < 1000000; ++i) {
        int part0 = i / 1000;
        int part1 = i % 1000;

        if (sumOfDigit(part0) == sumOfDigit(part1)) {
            count += 1;
        }
    }

    cout << "quantity of lucky tickets: " << count << endl;

    return 0;
}