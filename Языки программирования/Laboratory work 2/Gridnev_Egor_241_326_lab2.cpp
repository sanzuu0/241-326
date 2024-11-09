#include <iostream>
#include <limits>

// Отрисовка числового треугольника
void numericalTriangle() {
    int height;
    std::cout << "\nВведите положительное целое число для высоты треугольника: ";

    while (!(std::cin >> height) || height <= 0) {
        std::cout << "Некорректный ввод. Пожалуйста, введите положительное целое число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

// Вычисление биномиального коэффициента
long long binomialCoefficient(int n, int k) {
    long long result = 1;

    if (k > n - k)
        k = n - k;

    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

// Нахождение биномиальных коэффициентов
void findingBinomialCoefficients() {
    int n;
    std::cout << "\nВведите неотрицательное целое число для n: ";

    while (!(std::cin >> n) || n < 0) {
        std::cout << "Некорректный ввод. Пожалуйста, введите неотрицательное целое число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int k = 0; k <= n; ++k) {

        if (binomialCoefficient(n, k) < 0) {
            std::cout << "C(" << n << ", " << k << ") = Произошло переполнение" << std::endl;
        } else {
            std::cout << "C(" << n << ", " << k << ") = " << binomialCoefficient(n, k) << std::endl;
        }
    }
}

// Вычисление среднего арифметического
void calculatingTheArithmeticMean() {
    double sum = 0.0;
    int count = 0, element;

    std::cout << "Введите координаты (целые числа) точек на линии (введите 0 для завершения): ";

    while (std::cin >> element && element != 0) {
        sum += element;
        count++;
    }
    std::cout << "Среднее арифметическое: " << (count == 0 ? 0 : sum / count) << std::endl;
}

int main() {

    int choice = 0;

    while (choice != 4) {
        std::cout << "\n  1. Числовой треугольник.\n";
        std::cout << "  2. Нахождение биномиальных коэффициентов.\n";
        std::cout << "  3. Вычисление среднего арифметического для введенных координат точек на линии.\n";
        std::cout << "  4. Выход.\n";
        std::cout << "\nМеню программы, введите соответствующий номер для выбора действия: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Вы выбрали числовой треугольник.\n";
                numericalTriangle();
                break;

            case 2:
                std::cout << "Вы выбрали нахождение биномиальных коэффициентов.\n";
                findingBinomialCoefficients();
                break;

            case 3:
                std::cout << "Вы выбрали вычисление среднего арифметического.\n";
                calculatingTheArithmeticMean();
                break;

            case 4:
                std::cout << "Выход из программы.\n";
                break;

            default:
                std::cout << "Неверный выбор, попробуйте снова.\n";
        }
    }

    return 0;
}
