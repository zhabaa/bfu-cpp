#include <iostream>

using namespace std;

int main(){
    unsigned short a, b;
    
    cout << "Введите стороны прямоугольника через пробел:\n";
    cin >> a >> b;

    cout << "Периметр: " << 2 * (a + b) << endl;
    return 0;
}
