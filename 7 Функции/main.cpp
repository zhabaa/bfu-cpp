#include "matrix.hpp"
#include <iostream>

using namespace std;

int main() {
    int n = 2;
    int matrix[100][100];

    readMatrix(matrix, n);
    
    if (!(checkCondition(matrix, n))) {
        cout << "Условие не выполняется" << endl;
        return 0;
    }

    processMatrix(matrix, n);
    writeMatrix(matrix, n);

    return 0;
}
