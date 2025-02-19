#include <iostream>
#include <array>
#include <stdexcept>

template<typename T, size_t N, size_t M>
class Matrix {
private:
    std::array<std::array<T, M>, N> data;

    Matrix<T, N - 1, N - 1> createMinor(size_t row, size_t col) const {

        Matrix<T, N - 1, N - 1> minor;

        for (size_t i = 0, mi = 0; i < N; ++i) {
            if (i == row) continue;

            for (size_t j = 0, mj = 0; j < N; ++j) {
                if (j == col) continue;
                minor(mi, mj) = data[i][j];
                ++mj;
            }
            ++mi;
        }    
        return minor;
    }

public:
    Matrix() : data({}) {}

    Matrix(const Matrix& other) : data(other.data) {}

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                if (!(is >> matrix.data[i][j])) {
                    throw std::runtime_error("Invalid input");
                }
            }
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    Matrix operator+(const Matrix& other) const {
        static_assert(N == M, "Matrix addition requires square matrices");

        Matrix result;
        
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator+=(const Matrix& other) {
        static_assert(N == M, "Matrix addition requires square matrices");

        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    template<size_t K>
    Matrix<T, N, K> operator*(const Matrix<T, M, K>& other) const {
        static_assert(M == K, "Matrix multiplication requires compatible dimensions");

        Matrix<T, N, K> result;
        
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < K; ++j) {
                result(i, j) = T();
                for (size_t k = 0; k < M; ++k) {
                    result(i, j) += data[i][k] * other(k, j);
                }
            }
        }
        return result;
    }

    Matrix& operator*=(const Matrix& other) {
        *this = *this * other;
        return *this;
    }

    Matrix& operator++() {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                ++data[i][j];
            }
        }
        return *this;
    }

    T operator()(size_t i, size_t j) const {
        return data[i][j];
    }

    T& operator()(size_t i, size_t j) {
        return data[i][j];
    }

    T determinant() const {
        static_assert(N == M, "Determinant is only defined for square matrices");

        if constexpr (N == 1) {
            return data[0][0];
        } else if constexpr (N == 2) {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        } else {
            T det = 0;
            for (size_t col = 0; col < N; ++col) {
                auto minor = createMinor(0, col);
                det += (col % 2 == 0 ? 1 : -1) * data[0][col] * minor.determinant();
            }
            return det;
        }
    }
};
