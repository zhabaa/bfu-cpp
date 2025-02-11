#include <iostream>
#include <string>
// #include <algorithm>
// #include <cctype>

class BigInt {
private:
    std::string number;
    bool is_negative;

    void remove_leading_zeros() {
        while (number.size() > 1 && number.back() == '0') {
            number.pop_back();
        }
        if (number == "0") {
            is_negative = false;
        }
    }

    void normalize() {
        // Удаляем ведущие нули
        remove_leading_zeros();
        // Если число равно нулю, оно всегда положительное
        if (number == "0") {
            is_negative = false;
        }
    }

    std::string add_number(const std::string& a, const std::string& b) const {

        std::string result;

        int carry = 0;
        size_t i = 0;

        while (i < a.size() || i < b.size() || carry) {
            
            int digit_a;
            int digit_b;

            // переписать в одну строчку

            if (i < a.size()) {
                digit_a = a[i] - '0';
            } else {
                digit_a = 0;
            }

            if (i < b.size()) {
                digit_b = b[i] - '0';
            } else {
                digit_b = 0;
            }

            int sum = digit_a + digit_b + carry;
            carry = sum / 10;

            result += (sum % 10) + '0';

            ++i;
        }
        return result;
    }

    std::string subtract_number(const std::string& a, const std::string& b) const {

        std::string result;

        int borrow = 0;
        size_t i = 0;

        while (i < a.size()) {

            int digit_a = a[i] - '0';
            int digit_b;

            // тоже переписать в строку

            if (i < b.size()) {
                digit_b = b[i] - '0';
            } else {
                digit_b = 0;
            }

            int diff = digit_a - digit_b - borrow;

            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result += diff + '0';

            ++i;
        }
        return result;
    }

    int compare_abs(const std::string& a, const std::string& b) const {
        if (a.size() != b.size()) {
            return a.size() - b.size();
        }

        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] != b[i]) {
                return a[i] - b[i];
            }
        }
        return 0;
    }

    std::string multiply_number(const std::string& a, const std::string& b) const {
        std::string result(a.size() + b.size(), '0');

        for (size_t i = 0; i < a.size(); ++i) {
            int carry = 0;

            for (size_t j = 0; j < b.size(); ++j) {
                int temp = (result[i + j] - '0') + (a[i] - '0') * (b[j] - '0') + carry;
                result[i + j] = (temp % 10) + '0';
                carry = temp / 10;
            }

            if (carry) {
                result[i + b.size()] += carry;
            }
        }
        return result;
    }

public:
    BigInt(long long num = 0) {
        is_negative = num < 0;

        if (num == 0) {
            number = "0";
            return;
        }

        num = std::abs(num);

        while (num > 0) {
            number += (num % 10) + '0';
            num /= 10;
        }
    }

    BigInt(const std::string& num) {
        if (num.empty()) {
            number = "0";
            is_negative = false;
            return;
        }
        size_t start = 0;
        if (num[0] == '-') {
            is_negative = true;
            start = 1;
        } else {
            is_negative = false;
        }

        for (size_t i = start; i < num.size(); ++i) {
            number += num[i];
        }

        std::cout << "[ctor] before " << num << std::endl;
        normalize();

        std::cout << "[ctor] after " << num << std::endl;
    }

    BigInt(const BigInt& other) : number(other.number), is_negative(other.is_negative) {}

    BigInt& operator=(const BigInt& other) {
        if (this != &other) {
            number = other.number;
            is_negative = other.is_negative;
        }
        return *this;
    }


    BigInt operator+(const BigInt& other) const {
        BigInt result;
        if (is_negative == other.is_negative) {
            result.is_negative = is_negative;
            result.number = add_number(number, other.number);

        } else {
            if (compare_abs(number, other.number) >= 0) {
                result.is_negative = is_negative;
                result.number = subtract_number(number, other.number);

            } else {
                result.is_negative = other.is_negative;
                result.number = subtract_number(other.number, number);
            }
        }
        std::cout << result << "before op+" << std::endl;

        result.normalize();

        std::cout << result << "after op+" << std::endl;

        return result;
    }

    BigInt& operator+=(const BigInt& other) {
        *this = *this + other;
        return *this;
    }

    BigInt operator*(const BigInt& other) const {
        BigInt result;

        result.number = multiply_number(number, other.number);
        result.is_negative = is_negative != other.is_negative;
        std::cout << result << "before op*" << std::endl;
        result.normalize();

        std::cout << result << "after op*" << std::endl;

        return result;
    }

    BigInt& operator*=(const BigInt& other) {
        *this = *this * other;
        return *this;
    }

    bool operator<(const BigInt& other) const {
        if (is_negative != other.is_negative) {
            return is_negative;
        }

        if (number.size() != other.number.size()) {
            return (number.size() < other.number.size()) != is_negative;
        }

        for (int i = number.size() - 1; i >= 0; --i) {
            if (number[i] != other.number[i]) {
                return (number[i] < other.number[i]) != is_negative;
            }
        }

        return false;
    }

    bool operator>(const BigInt& other) const {
        return other < *this;
    }

    bool operator==(const BigInt& other) const {
        return is_negative == other.is_negative && number == other.number;
    }

    bool operator!=(const BigInt& other) const {
        return !(*this == other);
    }

    // friend std::ostream& operator<<(std::ostream& os, const BigInt& num) {
    //     if (num.is_negative) {
    //         os << '-';
    //     }

    //     for (int i = 0; i < num.number.size(); ++i) {
    //         os << num.number[i];
    //     }

    //     return os;
    // }

    // friend std::istream& operator>>(std::istream& is, BigInt& num) {
    //     std::string input;
    //     is >> input;
    //     num = BigInt(input);

    //     return is;
    // }
    friend std::ostream& operator<<(std::ostream& os, const BigInt& num) {

        std::cout << num.number << "op<<" << std::endl;
        // std::cout << num << "op<<" << std::endl;

        if (num.is_negative) {
            os << '-';
        }
        for (int i = num.number.size() - 1; i >= 0; --i) {
            os << num.number[i];
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, BigInt& num) {
        std::string input;
        is >> input;
        std::cout << input << std::endl;
        num = BigInt(input);
        return is;
    }
};
