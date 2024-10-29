#include <iostream>
#include <limits>

using namespace std;

// Отрисовка числового треугольника
void numericalTriangle() {

    int height;
    cout << "\nВведите положительное целое число для высоты треугольника: ";

    while (!(cin >> height) || height <= 0) {
        cout << "Некорректный ввод. Пожалуйста, введите положительное целое число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
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
    cout << "\nВведите неотрицательное целое число для n: ";

    while (!(cin >> n) || n < 0) {
        cout << "Некорректный ввод. Пожалуйста, введите неотрицательное целое число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int k = 0; k <= n; ++k) {
        cout << "C(" << n << ", " << k << ") = " << binomialCoefficient(n, k) << endl;
    }
}

// Вычисление среднего арифметического
void calculatingTheArithmeticMean() {

    double sum = 0.0;
    int count = 0, element;

    cout << "Введите координаты (целые числа) точек на линии (введите 0 для завершения): ";

    while (cin >> element && element != 0) {
        sum += element;
        count++;
    }
    cout << "Среднее арифметическое: " << (count == 0 ? 0 : sum / count) << endl;
}

int main() {

    int choice;

    do {
        cout << "\n  1. Числовой треугольник.\n";
        cout << "  2. Нахождение биномиальных коэффициентов.\n";
        cout << "  3. Вычисление среднего арифметического для введенных координат точек на линии.\n";
        cout << "  4. Выход.\n";
        cout << "\nМеню программы, введите соответствующий номер для выбора действия: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {

            case 1:
                cout << "Вы выбрали числовой треугольник.\n";
                numericalTriangle();
                break;

            case 2:
                cout << "Вы выбрали нахождение биномиальных коэффициентов.\n";
                findingBinomialCoefficients();
                break;

            case 3:
                cout << "Вы выбрали вычисление среднего арифметического.\n";
                calculatingTheArithmeticMean();
                break;

            case 4:
                cout << "Выход из программы.\n";
                break;

            default:
                cout << "Неверный выбор, попробуйте снова.\n";
        }
    } while (choice != 4);

    return 0;
}
