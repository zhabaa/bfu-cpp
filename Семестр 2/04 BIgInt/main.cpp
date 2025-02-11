#include <iostream>
#include "BigInt.cpp"


int main() {
    BigInt a = 1;
    BigInt b = 10;
    BigInt c = 100;
    /*
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    */

    
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    BigInt sum;

    sum = a + b + c;

    std::cout << "Sum: " << sum << std::endl;


    return 0;
}
