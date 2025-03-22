#include <iostream>
#include <vector>

class BoolVector
{
private:
    std::vector<unsigned char> data;
    size_t length;

public:
    BoolVector() : length(0) {}

    void push_back(bool value) {
        if (length % 8 == 0) {
            data.push_back(0);
        }
        data[length / 8] |= (value << (length % 8));
        length++;
    }

    bool get(size_t index) const {
        if (index >= length)
            throw std::out_of_range("Index is out of range");
        return (data[index / 8] >> (index % 8)) & 1;
    }

    bool operator[](size_t index) const {
        if (index >= length) 
            throw std::out_of_range("Index out of range");
        return get(index);
    }

    void set(size_t index, bool value) {
        if (index >= length)
            throw std::out_of_range("Index is out of range");
        if (value)
            data[index / 8] |= (1 << (index % 8));
        else
            data[index / 8] &= ~(1 << (index % 8));
    }

    size_t size() const {
        return length;
    }

    void insert(size_t index, bool value) {
        if (index >= length) {
            throw std::out_of_range("Index is out of range");
        }

        if (index == length) {
            push_back(value);
            return;
        }

        push_back(false);

        for (size_t i = length - 1; i > index; --i) {
            set(i, get(i - 1));
        }

        set(index, value);
    }

    void erase(size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index is out of range");
        }

        for (size_t i = index; i < length - 1; ++i) {
            set(i, get(i + 1));
        }

        length--;
    }

    friend std::ostream& operator<<(std::ostream& os, const BoolVector& bv) {
        for (size_t i = 0; i < bv.length; ++i) {
            os << bv.get(i) << " ";
        }
        os << std::endl;
        return os;
    }
};

int main()
{
    BoolVector bv;

    bv.push_back(true);
    bv.push_back(false);
    bv.push_back(true);
    bv.push_back(false);

    std::cout << "Initial vector: ";
    std::cout << bv;
    
    bv.insert(2, true);
    std::cout << "After inserting true at index 2: ";
    std::cout << bv;
    
    bv.erase(1);
    std::cout << "After erasing index 1: ";
    std::cout << bv;
    
    bv.set(0, false);
    std::cout << "After setting index 0 to false: ";
    std::cout << bv;

    std::cout << "Size of vector: " << bv.size() << std::endl;
    std::cout << bv[0];

    return 0;
}