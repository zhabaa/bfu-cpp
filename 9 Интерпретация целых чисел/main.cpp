#include <iostream>

using namespace std;

int main() {
    short num = 0x8FFF;
    unsigned char* bytePtr = (unsigned char*)&num;

    cout << "Content of bytes " << num << " (0x" << hex << num << "):\n";
    for (size_t i = 0; i < sizeof(short); i++) {
        cout << "byte " << i << ": 0x" << hex << static_cast<int>(bytePtr[i]) << endl;
    }

    return 0;
}
