#include <iostream>
#include <bitset>
#include <climits>
#include <cfloat>

// Информация о пользователе
void myInformation() {
    std::cout << "Гриднев Егор Михайлович, 241-326\n" << std::endl;
}

// Информация о типах данных
void printDataTypeInfo() {
    std::cout << "Min int = " << INT_MIN
              << ", Max int = " << INT_MAX
              << ", Size of int = " << sizeof(int) << " bytes\n";

    std::cout << "Min unsigned int = " << 0
              << ", Max unsigned int = " << UINT_MAX
              << ", Size of unsigned int = " << sizeof(unsigned int) << " bytes\n";

    std::cout << "Min short = " << SHRT_MIN
              << ", Max short = " << SHRT_MAX
              << ", Size of short = " << sizeof(short) << " bytes\n";

    std::cout << "Min unsigned short = " << 0
              << ", Max unsigned short = " << USHRT_MAX
              << ", Size of unsigned short = " << sizeof(unsigned short) << " bytes\n";

    std::cout << "Min long = " << LONG_MIN
              << ", Max long = " << LONG_MAX
              << ", Size of long = " << sizeof(long) << " bytes\n";

    std::cout << "Min long long = " << LLONG_MIN
              << ", Max long long = " << LLONG_MAX
              << ", Size of long long = " << sizeof(long long) << " bytes\n";

    std::cout << "Min double = " << DBL_MIN
              << ", Max double = " << DBL_MAX
              << ", Size of double = " << sizeof(double) << " bytes\n";

    std::cout << "Min char = " << CHAR_MIN
              << ", Max char = " << CHAR_MAX
              << ", Size of char = " << sizeof(char) << " bytes\n";

    std::cout << "Min bool = " << std::boolalpha << false
              << ", Max bool = " << std::boolalpha << true
              << ", Size of bool = " << sizeof(bool) << " bytes\n";
}

// Представление числа в различных типах данных
void numberRepresentation() {
    int number;

    std::cout << "\nВведите число: ";
    std::cin >> number;

    std::cout << "Двоичное представление: " << std::bitset<16>(number) << std::endl;
    std::cout << "bool: " << static_cast<bool>(number) << std::endl;
    std::cout << "double: " << static_cast<double>(number) << std::endl;
    std::cout << "char: " << static_cast<char>(number) << std::endl;
}

// Решение линейного уравнения вида a * x = b
void solvingTheEquation() {
    double a, b;

    std::cout << "\nВведите коэффициенты для уравнения a * x = b: ";
    std::cin >> a >> b;

    if (a != 0) {
        std::cout << a << " * x = " << b << std::endl;
        std::cout << "x = " << b << " / " << a << std::endl;
        std::cout << "x = " << b / a << std::endl;
    } else {
        std::cout << "Ошибка: деление на ноль" << std::endl;
    }
}

// Нахождение середины отрезка
void midPointOfTheSegment() {
    double a, b;

    std::cout << "\nВведите координаты начала и конца отрезка: ";
    std::cin >> a >> b;

    std::cout << "Середина отрезка находится в точке с координатой: " << double(a + b) / 2.0 << std::endl;
}

int main() {
    myInformation();
    printDataTypeInfo();
    numberRepresentation();
    solvingTheEquation();
    midPointOfTheSegment();

    return 0;
}
