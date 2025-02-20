#include <iostream>
#include <vector>
#include <cstdint>

template<typename T>
class BitVector {
private:
    std::vector<T> data;
    size_t size_;

public:
    BitVector() : size_(0) {}

    void push_back(bool value) {
        if (!(size_ % (sizeof(T) * 8))) {
            data.push_back(0);
        }

        size_t index = size_ / (sizeof(T) * 8);
        size_t bit = size_ % (sizeof(T) * 8);

        if (value) {
            data[index] |= (1 << bit);
        } else {
            data[index] &= ~(1 << bit);
        }
        size_++;
    }

    bool operator[](size_t index) const {
        size_t block = index / (sizeof(T) * 8);
        size_t bit = index % (sizeof(T) * 8);
        return (data[block] >> bit) & 1;
    }

    void set(size_t index, bool value) {
        size_t block = index / (sizeof(T) * 8);
        size_t bit = index % (sizeof(T) * 8);
        if (value) {
            data[block] |= (1 << bit);
        } else {
            data[block] &= ~(1 << bit);
        }
    }

    size_t size() const {
        return size_;
    }

    void insert(size_t index, bool value) {
        if (index >= size_) {
            push_back(value);
            return;
        }
        push_back(false);
        for (size_t i = size_ - 1; i > index; --i) {
            set(i, (*this)[i - 1]);
        }
        set(index, value);
    }

    void erase(size_t index) {
        for (size_t i = index; i < size_ - 1; ++i) {
            set(i, (*this)[i + 1]);
        }
        size_--;
    }
};

int main() {
    BitVector<uint64_t> bv;
    bv.push_back(true);
    bv.push_back(false);
    bv.push_back(true);

    std::cout << "Size: " << bv.size() << std::endl;
    std::cout << "Values: ";
    for (size_t i = 0; i < bv.size(); ++i) {
        std::cout << bv[i] << " ";
    }
    std::cout << std::endl;

    bv.insert(1, false);
    std::cout << "After insert: ";
    for (size_t i = 0; i < bv.size(); ++i) {
        std::cout << bv[i] << " ";
    }
    std::cout << std::endl;

    bv.erase(1);
    std::cout << "After erase: ";
    for (size_t i = 0; i < bv.size(); ++i) {
        std::cout << bv[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}