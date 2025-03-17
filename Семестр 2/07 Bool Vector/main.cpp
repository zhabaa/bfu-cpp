#include <iostream>
#include <vector>
#include <algorithm>

class BitVector {
private:
    std::vector<unsigned char> data;
    size_t size_in_bits;

    size_t get_byte_index(size_t bit_index) const {
        return bit_index / 8;
    }

    size_t get_bit_offset(size_t bit_index) const {
        return bit_index % 8;
    }

public:
    BitVector(size_t size) : size_in_bits(size) {
        data.resize((size + 7) / 8, 0);
    }

    void push_back(bool value) {
        size_in_bits++;
        data.resize((size_in_bits + 7) / 8, 0);

        size_t byte_index = get_byte_index(size_in_bits - 1);
        size_t bit_offset = get_bit_offset(size_in_bits - 1);

        if (value) {
            data[byte_index] |= (1 << bit_offset);
        }
    }

    bool operator[](size_t index) const {
        size_t byte_index = get_byte_index(index);
        size_t bit_offset = get_bit_offset(index);
        return (data[byte_index] >> bit_offset) & 1;
    }

    bool& operator[](size_t index) {
        size_t byte_index = get_byte_index(index);
        size_t bit_offset = get_bit_offset(index);
        return ((data[byte_index] >> bit_offset) & 1) ? get_ref(byte_index, bit_offset, true): get_ref(byte_index, bit_offset, false);
    }

    bool& get_ref(size_t byte_index, size_t bit_offset, bool value){
        if (value){
            data[byte_index] |= (1 << bit_offset);
        } else {
            data[byte_index] &= ~(1 << bit_offset);
        }
        return ((data[byte_index] >> bit_offset) & 1) ? get_ref(byte_index, bit_offset, true): get_ref(byte_index, bit_offset, false);

    }


    size_t size() const {
        return size_in_bits;
    }

    void insert(size_t index, bool value) {
        size_in_bits++;
        data.resize((size_in_bits + 7) / 8, 0);

        for (size_t i = size_in_bits - 1; i > index; --i) {
            (*this)[i] = (*this)[i - 1];
        }
        (*this)[index] = value;

    }

    void erase(size_t index) {
        for (size_t i = index; i < size_in_bits - 1; ++i) {
            (*this)[i] = (*this)[i + 1];
        }
        size_in_bits--;
        data.resize((size_in_bits + 7) / 8, 0);
    }

    friend std::ostream& operator<<(std::ostream& os, const BitVector& bv) {
        for (size_t i = 0; i < bv.size(); ++i) {
            os << bv[i] << " ";
        }
        return os;
    }
};

int main() {
    BitVector bv(5);

    bv.push_back(true);
    bv.push_back(false);
    bv.push_back(true);
    bv.push_back(true);
    bv.push_back(false);

    bv.insert(2, false);
    bv[0] = false;

    std::cout << "Size: " << bv.size() << std::endl;
    std::cout << "elements: " << bv << std::endl;
    std::cout << "sizeof: " << sizeof(bv) << std::endl;
    
    bv.erase(3);
    std::cout << "elements after eraise: " << bv << std::endl;

    return 0;
}
