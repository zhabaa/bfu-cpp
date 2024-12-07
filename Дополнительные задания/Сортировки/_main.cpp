#include <iostream>
#include <fstream>
#include <algorithm>

#include "func.hpp"

#pragma comment(linker, "/STACK:16777216")

int main() {
	std::ifstream in("../../input.txt");
    std::ofstream out("../../output.txt");

    int mas[3'000'000];
    int n;

    in >> n;

    for (int i = 0; i < n; i++) {
        in >> mas[i];
    }

    // std::sort(mas, mas+n);

    for (int i = 0; i < n; i++) {
        out << mas[i] << " ";
    }

	return 0;
}