#include <iostream>
#include <limits>
#include <string>

using namespace std;

void tasks_345(){
        cout << scientific << "type\t\t│ size (bytes)\t| min()\t\t\t│ max()\n"

        << string(80, '-') << "\n"

        << "bool\t\t│ "
        << sizeof(bool) << "\t\t| "
        << numeric_limits<bool>::min() << "\t\t\t│ "
        << numeric_limits<bool>::max() << "\n"

        << "char\t\t| "
        << sizeof(char) << "\t\t| "
        << int(numeric_limits<char>::min()) << "\t\t\t| "
        << int(numeric_limits<char>::max()) << "\n"

        << "int\t\t│ "
        << sizeof(int) << "\t\t| "
        << numeric_limits<int>::min() << "\t\t│ "
        << numeric_limits<int>::max() << "\n"

        << "short\t\t| "
        << sizeof(short) << "\t\t| "
        << numeric_limits<short>::min() << "\t\t| "
        << numeric_limits<short>::max() << "\n"

        << "long\t\t| "
        << sizeof(long) << "\t\t| "
        << numeric_limits<long>::min() << "\t\t| "
        << numeric_limits<long>::max() << "\n"
        
        << "long long\t| "
        << sizeof(long long) << "\t\t| "
        << numeric_limits<long long>::min() << "\t| "
        << numeric_limits<long long>::max() << "\n"

        << "float\t\t│ "
        << sizeof(float) << "\t\t| "
        << numeric_limits<float>::min() << "\t\t│ "
        << numeric_limits<float>::max() << "\n"

        << "double\t\t│ "
        << sizeof(double) << "\t\t| "
        << numeric_limits<double>::min() << "\t\t│ "
        << numeric_limits<double>::max() << "\n"

        << "long double\t| "
        << sizeof(long double) << "\t\t| "
        << numeric_limits<long double>::min() << "\t| "
        << numeric_limits<long double>::max() << "\n"

        << "uchar\t\t│ "
        << sizeof(unsigned char) << "\t\t| "
        << int(numeric_limits<unsigned char>::min()) << "\t\t\t│ "
        << int(numeric_limits<unsigned char>::max()) << "\n"

        << "uint\t\t| "
        << sizeof(unsigned int) << "\t\t| "
        << numeric_limits<unsigned int>::min() << "\t\t\t| "
        << numeric_limits<unsigned int>::max() << "\n"

        << "ushort\t\t| "
        << sizeof(unsigned short) << "\t\t| "
        << numeric_limits<unsigned short>::min() << "\t\t\t| "
        << numeric_limits<unsigned short>::max() << "\n"
        
        << "ulong\t\t| "
        << sizeof(unsigned long) << "\t\t| "
        << numeric_limits<unsigned long>::min() << "\t\t\t| "
        << numeric_limits<unsigned long>::max() << "\n"

        << "ulong long\t| "
        << sizeof(unsigned long long) << "\t\t| "
        << numeric_limits<unsigned long long>::min() << "\t\t\t| "
        << numeric_limits<unsigned long long>::max() << "\n";

}

void task_6(){
    char char_a = 52, char_b = 92;
    cout << "Char:\t" << char_a << " + " << char_b << " = " << char(char_a + char_b) << char_a + char_b << endl;

    int int_a = 1, int_b = 2;
    cout << "Int:\t" << int_a << " + " << int_b << " = " << int_a + int_b << endl;

    short short_a = 1, short_b = 1;
    cout << "Short:\t" << short_a << " + " << short_b << " = " << short_a + short_b << endl;

    long long_a = 1, long_b = 1;
    cout << "Long:\t" << long_a << " + " << long_b << " = " << long_a + long_b << endl;

    long long llong_a = 1, llong_b = 2;
    cout << "Long long:\t" << llong_a << " + " << llong_b << " = " << llong_a + llong_b << endl;

    float float_a = 1.f, float_b = 2.f;
    cout << "Float:\t" << float_a << " + " << float_b << " = " << float_a + float_b << endl;

    double double_a = 1., double_b = 2.;
    cout << "Double:\t" << double_a << " + " << double_b << " = " << double_a + double_b << endl;

    long double ldouble_a = 1.0, ldouble_b = 2.;
    cout << "Long double:\t" << ldouble_a << " + " << ldouble_b << " = " << ldouble_a + ldouble_b << endl;

    unsigned char uc_a = 1, uc_b = 2;
    cout << "unsigned Char:\t" << uc_a << " + " << uc_b << " = " << uc_a + uc_b << endl;

    unsigned int ui_a = 1, ui_b = 2;
    cout << "unsigned Int:\t" << ui_a << " + " << ui_b << " = " << ui_a + ui_b << endl;

    unsigned short us_a = 1, us_b = 2;
    cout << "unsigned Short:\t" << us_a << " + " << us_b << " = " << us_a + us_b << endl;

    unsigned long ul_a = 1, ul_b = 2;
    cout << "unsigned Long:\t" << ul_a << " + " << ul_b << " = " << ul_b + ul_b << endl;

    unsigned long long ull_a = 1, ull_b = 2;
    cout << "unsigned Long long:\t" << ull_a << " + " << ull_b << " = " << ull_a + ull_b << endl;
}

int main(){
    // 1
    cout << "Перемеенная - именованная область памяти, которую можно использовать для доступа к данным.\n" << endl;
    
    // 2
    cout << "Целочисленные:\n"
        << " - Знаковые (int, short, long, long long)\n"
        << " - Беззнаковые (unsigned ...)\n\n"

        << "Вещественные:\n"
        << " - float\n"
        << " - double\n"
        << " - long double\n\n"

        << "Символьные:\n"
        << " - char\n"
        << " - wchar_t (широкий символ)\n\n"

        << "Логические:\n"
        << " - bool\n" << endl;

    // 3, 4, 5 
    cout << "Tasks 3, 4, 5\n";
    tasks_345();

    cout << endl;

    cout << "Task 6\n";
    task_6();
}
