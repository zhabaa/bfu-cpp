#include <iostream>
#include "Matrix.cpp"

int main() {
    Matrix<int, 3, 3> mat1;
    Matrix<int, 3, 3> mat2;

    Matrix<int, 3, 3> sum;
    Matrix<int, 3, 3> prod;


    std::cout << "Enter Matrix 1:" << std::endl;
    std::cin >> mat1;

    std::cout << "Enter Matrix 2:" << std::endl;
    std::cin >> mat2;

    std::cout << "Matrix 1:" << std::endl << mat1;
    std::cout << "Matrix 2:" << std::endl << mat2;

    sum = mat1 + mat2;
    prod = mat1 * mat2;

    std::cout << "Sum:" << std::endl << sum;
    std::cout << "Product:" << std::endl << prod;

    ++mat1;
    std::cout << "++ Matrix 1:" << std::endl << mat1;

    std::cout << "Determinant: " << mat1.determinant() << std::endl;
    std::cout << "Determinant: " << mat2.determinant() << std::endl;
    std::cout << "Determinant: " << sum.determinant() << std::endl;
    std::cout << "Determinant: " << prod.determinant() << std::endl;

    return 0;
}