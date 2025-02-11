#include <iostream>
#include "BigInt.cpp"


int main() {
    BigInt a = 12;
    BigInt b = 130;
    BigInt c = -100;
    /*
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    */

    std::cout << std::endl;
    std::cout << a << std::endl;
    std::cout << std::endl;
    std::cout << b << std::endl;
    std::cout << std::endl;
    std::cout << c << std::endl;

    BigInt sum;

    std::cout << std::endl;
    sum = a + b + c;

    std::cout << "Sum: " << sum << std::endl;


    return 0;
}
