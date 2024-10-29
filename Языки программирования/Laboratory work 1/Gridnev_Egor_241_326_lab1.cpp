#include <iostream>
#include <bitset>
#include <climits>
#include <cfloat>

using namespace std;

// Информация о пользователе

void myInformation() {
    cout << "Гриднев Егор Михайлович, 241-326" << endl;
}

// Информация о типах данных

void printDataTypeInfo() {
    cout << "Min int = " << INT_MIN
         << ", Max int = " << INT_MAX
         << ", Size of int = " << sizeof(int) << " bytes\n";

    cout << "Min unsigned int = " << 0
         << ", Max unsigned int = " << UINT_MAX
         << ", Size of unsigned int = " << sizeof(unsigned int) << " bytes\n";

    cout << "Min short = " << SHRT_MIN
         << ", Max short = " << SHRT_MAX
         << ", Size of short = " << sizeof(short) << " bytes\n";

    cout << "Min unsigned short = " << 0
         << ", Max unsigned short = " << USHRT_MAX
         << ", Size of unsigned short = " << sizeof(unsigned short)  << " bytes\n";

    cout << "Min long = " << LONG_MIN
         << ", Max long = " << LONG_MAX
         << ", Size of long = " << sizeof(long) << " bytes\n";

    cout << "Min long long = " << LLONG_MIN
         << ", Max long long = " << LLONG_MAX
         << ", Size of long long = " << sizeof(long long) << " bytes\n";

    cout << "Min double = " << DBL_MIN
         << ", Max double = " << DBL_MAX
         << ", Size of double = "<< sizeof(double) << " bytes\n";

    cout << "Min char = " << CHAR_MIN
         << ", Max char = " << CHAR_MAX
         << ", Size of char = " << sizeof(char) << " bytes\n";

    cout << "Min bool = " << boolalpha << false
         << ", Max bool = " << boolalpha << true
         << ", Size of bool = " << sizeof(bool) << " bytes\n";
}

// Представление числа в различных типах данных
void numberRepresentation() {
    int number;

    cout << "\nВведите число: ";
    cin >> number;

    cout << "Двоичное представление: " << bitset<16>(number) << endl;
    cout << "bool: " << static_cast<bool>(number) << endl;
    cout << "double: " << static_cast<double>(number) << endl;
    cout << "char: " << static_cast<char>(number) << endl;
}

// Решение линейного уравнения вида a * x = b

void solvingTheEquation() {
    double a, b;

    cout << "\nВведите коэффициенты для уравнения a * x = b: ";
    cin >> a >> b;

    if (a != 0) {
        cout << a << " * x = " << b << endl;
        cout << "x = " << b << " / " << a << endl;
        cout << "x = " << b / a << endl;
    } else {
        cout << "Ошибка: деление на ноль" << endl;
    }
}

// Нахождение середины отрезка

void midPointOfTheSegment() {
    double a, b;

    cout << "\nВведите координаты начала и конца отрезка: ";
    cin >> a >> b;

    cout << "Середина отрезка находится в точке с координатой: " << double(a + b) / 2.0 << endl;
}

int main() {

    myInformation();
    printDataTypeInfo();
    numberRepresentation();
    solvingTheEquation();
    midPointOfTheSegment();

    return 0;
}
