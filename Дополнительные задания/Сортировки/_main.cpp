#include <iostream>
#include <fstream>
#include <algorithm>

#include "func.hpp"

#pragma comment(linker, "/STACK:16777216")

int main()
{
    std::ifstream in("../../input.txt");
    std::ofstream out("../../output.txt");

    // int mas[3'000'000];
    int mas[5];
    int n;

    in >> n;

    for (int i = 0; i < n; i++)
    {
        in >> mas[i];
    }

    bubbleSort(mas, n);

    for (int i = 0; i < n; i++)
    {
        out << mas[i] << " ";
    }

    return 0;
}

// shell
// bubble
//