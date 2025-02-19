#include <iostream>
#include <algorithm>

template <typename T>
class MyVector {
private:
    T* data;
    size_t size_;
    size_t capacity_;

public:
    MyVector() : data(nullptr), size_(0), capacity_(0) {}

    MyVector(const MyVector& other) : size_(other.size_), capacity_(other.capacity_) {
        data = new T[capacity_];
        std::copy(other.data, other.data + size_, data);
    }

    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data = new T[capacity_];
            std::copy(other.data, other.data + size_, data);
        }
        return *this;
    }

    ~MyVector() {
        delete[] data;
    }

    void resize(size_t new_size) {
        if (new_size > capacity_) {
            reserve(new_size);
        }
        if (new_size > size_) {
            for (size_t i = size_; i < new_size; ++i) {
                data[i] = T();
            }
        }
        size_ = new_size;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > capacity_) {
            T* new_data = new T[new_capacity];
            std::copy(data, data + size_, new_data);
            delete[] data;
            data = new_data;
            capacity_ = new_capacity;
        }
    }

    void shrink_to_fit() {
        if (size_ < capacity_) {
            T* new_data = new T[size_];
            std::copy(data, data + size_, new_data);
            delete[] data;
            data = new_data;
            capacity_ = size_;
        }
    }

    T& front() {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[0];
    }

    T& back() {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[size_ - 1];
    }

    size_t size() const {
        return size_;
    }

    bool empty() const {
        return size_ == 0;
    }

    size_t capacity() const {
        return capacity_;
    }

    void push_back(const T& value) {
        if (size_ >= capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data[size_++] = value;
    }

    void insert(size_t pos, const T& value) {
        if (pos > size_) {
            throw std::out_of_range("Invalid position");
        }
        if (size_ >= capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        for (size_t i = size_; i > pos; --i) {
            data[i] = data[i - 1];
        }
        data[pos] = value;
        ++size_;
    }

    void erase(size_t pos) {
        // Удалене по индексу
        if (pos >= size_) {
            throw std::out_of_range("Invalid position");
        }
        for (size_t i = pos; i < size_ - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size_;
    }

    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

int main() {
    MyVector<long> vec;
    
    for (int i = 0; i < 1'000'000; ++i) {
        vec.push_back(i);
    }

    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    vec.shrink_to_fit();

    std::cout << "shrink_to_fit value: " << vec.capacity() << std::endl;



    return 0;
}