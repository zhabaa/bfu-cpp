#include <iostream>
#include "BigInt.cpp"


int main() {
    BigInt a = 12;
    BigInt b = 12;
    BigInt c = 123;
    /*
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    */

    
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    BigInt sum;
    BigInt mul;

    sum = a + b + c;
    mul = a * b * c;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Mul: " << mul << std::endl;
    std::cout << (a < b) << std::endl;
    std::cout << (a > b) << std::endl;
    std::cout << (a == b) << std::endl;


    return 0;
}
