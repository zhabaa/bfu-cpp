#include <iostream>

using namespace std;

int first() {
    unsigned int a, b, c;
    int result;

    cout << "Enter a, b, c:" << endl;
    cin >> a >> b >> c;

    if (a > b & b > c) {
        result = a - b - c;
        cout << result << endl;
    } else if (b > a & !(b % c)) {
        result = b / c + b - a;
        cout << result << endl;
    } else {
        result = a + b + c;
        cout << result << endl;
    }
    return 1;
}

int second() {
    unsigned n;

    cout << "Enter n value:" << endl;
    cin >> n;

    if (! (0 <= n <= 9)) {
        cout << "Это не цифра!" << endl;
        return 1;
    }

    switch (n) {
    case 0:
        cout << "Ноль" << endl;
        break;
    case 1:
        cout << "Один" << endl;
        break;
    case 2:
        cout << "Два" << endl;
        break;
    case 3:
        cout << "Три" << endl;
        break;
    case 4:
        cout << "Четыре" << endl;
        break;
    case 5:
        cout << "Пять" << endl;
        break;
    case 6:
        cout << "Шесть" << endl;
        break;
    case 7:
        cout << "Семь" << endl;
        break;
    case 8:
        cout << "Восемь" << endl;
        break;
    case 9:
        cout << "Девять" << endl;
        break;

    default:
        break;
    }

    return 1;
}

int third() {
    int x;
    cout << "Enter x (-1 or 1):" << endl;
    cin >> x;

    switch (x) {
    case 1:
        cout << "Positive number" << endl;
        break;
    case -1:
        cout << "Negative number" << endl;
        break;

    default:
        cout << "Incorrect value!" << endl;
        break;
    }
    return 1;
}


int main() {
    while (1) {
        third();
    }
    return 1;
}