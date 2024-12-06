#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Enter r1, x1, y1: ";
    int r1, x1, y1;
    cin >> r1 >> x1 >> y1;

    cout << "Enter r2, x2, y2: ";
    int r2, x2, y2;
    cin >> r2 >> x2 >> y2;

    double d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    double s, s1, s2;

    double pi = 2 * acos(0.0);

    if (d >= (r1 + r2)) {
        s1 = pi * pow(r1, 2);
        s2 = pi * pow(r2, 2);
        s = s1 + s2;

    } else if (d <= fabs(r1 - r2)) {
        s1 = pi * r1 * r1;
        s2 = pi * r2 * r2;

        s = fmax(s1, s2);

    } else {
        double s, s1, s2, a1, a2, h1, h2;

        h1 = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
        h2 = (r2 * r2 - r1 * r1 + d * d) / (2 * d);

        a1 = r1 * r1 * acos(h1 / r1) + h1 * sqrt(r1 * r1 - h1 * h1);
        a2 = r2 * r2 * acos(h2 / r2) + h2 * sqrt(r2 * r2 - h2 * h2);

        s1 = pi * r1 * r1;
        s2 = pi * r2 * r2;

        s = s1 + s2 - (a1 + a2);
    }
    cout << s;
}