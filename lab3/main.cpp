#include <iostream>
#include <string>

using namespace std;

string getBitRepresentation(unsigned int x) {
    string bits;
    for (int i = 31; i >= 0; --i) {
        bits += (x & (1 << i)) ? '1' : '0';
    }
    return bits;
}

int main(){
    unsigned int x;
    int i;
    
    cout << "Enter x value:" << endl;
    cin >> x;

    cout << "Enter bit number:" << endl;
    cin >> i;

    if (i < 0 || i >= 32) {
        cout << "Incorrect bit index" << endl;
        return 1;
    }

    string bitRepresentation = getBitRepresentation(x);
    cout << "Bit representation of x:\n"
        << bitRepresentation << endl;

    int i_bytes = (x >> i) & 1;

    cout << "Value of i-th bit of number x: " << i_bytes << endl;
}