#include <iostream>
#include <limits>

using namespace std;

int main() {
    int q1, p1, q2, p2, a;
    cin >> q1 >> p1 >> q2 >> p2 >> a;

    int min_cost = numeric_limits<int>::max();

    for (int i = 0; i <= a / q1 + 1; ++i) {
        int remain = a - i * q1;

        int trips = 0;

        if (remain > 0) {
            trips = (remain + q2 - 1) / q2;
        }

        int cost = i * p1 + trips * p2;

        min_cost = min(min_cost, cost);
    }

    cout << min_cost << endl;
    return 0;
}