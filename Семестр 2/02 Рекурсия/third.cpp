#include <iostream>
#include <fstream>

int n, m;
int start_i, start_j;
int end_i, end_j;

char field[100][100];
int board[100][100];

void search(int i, int j, int step) {
    if (i < 0 || j < 0 || i > n || j > m || field[i][j] == '#') {
        return;
    }

    if (step >= board[i][j]) {
        return;
    }

    board[i][j] = step;

    if (field[i][j] == 'E') {
        return;
    }

    search(i - 1, j, step + 1); // up
    search(i + 1, j, step + 1); // down
    search(i, j - 1, step + 1); // left
    search(i, j + 1, step + 1); // right

    search(i + 1, j + 1, step + 1); // right-up
    search(i - 1, j - 1, step + 1); // left-up
    search(i + 1, j - 1, step + 1); // left-down
    search(i - 1, j + 1, step + 1); // right-down
}

int main() {
    std::ifstream input("../grid.txt");

    input >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            input >> field[i][j];

            std::cout << field[i][j] << " ";

            board[i][j] = __INT_MAX__;

            if (field[i][j] == 'S') {
                start_i = i;
                start_j = j;
            } else if (field[i][j] == 'E') {
                end_i = i;
                end_j = j;
            }
        }
        std::cout << std::endl;
    }
    search(start_i, start_j, 0);

    std::cout << board[end_i][end_j] << std::endl;

    return 0;
}
