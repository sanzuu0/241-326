#include <iostream>
#include <limits>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;



void programMenu() {

    cout << "\nМеню программы, для выбора действия введите соответствующую цифру:\n";

    cout << "  1. Числовой треугольник." << endl;
    cout << "  2. Нахождение биномиальных коэффициентов." << endl;
    cout << "  3. Вычисление среднего арифметического введенных точек на прямой, заданных своими координатами." << endl;
    cout << "  4. Реализация выхода." << endl;
}


void numericalTriangle() {

    int height;

    cout << "\nВведите число: ";
    
    while (!(cin >> height) || height <= 0) {
        cout << "Неверный ввод. Пожалуйста, введите положительное целое число: ";
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


long long binomialCoefficient(int n, int k) {
    
    long long result = 1;
    
    if (k > n - k)  
        k = n - k; // Оптимизация: C(n, k) == C(n, n-k)

    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    
    return result;
}


void findingBinomialCoefficients() {
    
    int n;
    
    cout << "\nВведите значение n: ";
    
    while (!(cin >> n) || n < 0) {
        cout << "Неверный ввод. Пожалуйста, введите неотрицательное целое число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int k = 0; k <= n; ++k) {
        
        long long binomialCoeff = binomialCoefficient(n, k);
        
        if (binomialCoeff > 0) {
            cout << "C(" << n << ", " << k << ") = " << binomialCoefficient(n, k) << endl;
        } else {
            cout << "C(" << n << ", " << k << ") = Произошло переполнение" << endl;
        }
    }
}


void calculatingTheArithmeticMean() {

    double sum = 0.0;
    int count = 0;
    int element;

    cout << "\nВведите координаты точек на прямой (нажмите 0 для завершения ввода): ";

    cin >> element;

    while (element != 0) {
        sum += element;
        count++;
        cin >> element;
    }

    cout << "\nСреднее арифметическое: " << sum / count << endl;
}


int main() {
    
    int position = 4;

    while (true) {
        
        switch (position) {

            case 1:
                cout << "\nВы выбрали числовой треугольник." << endl;
                numericalTriangle();
                break;

            case 2:
                cout << "\nВы выбрали Нахождение биномиальных коэффициентов." << endl;
                findingBinomialCoefficients();
                break;

            case 3:
                cout << "\nВы выбрали Вычисление среднего арифметического введенных точек на прямой, заданных своими координатами." << endl;
                calculatingTheArithmeticMean();
                break;

            case 4:
                programMenu();
                break;

            default:
                cout << "Неверный формат ввода." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }

        cout << "\nВведите что хотите выбрать из меню: ";
        
        while (!(cin >> position) || position < 1 || position > 4) {
            cout << "Неверный ввод. Пожалуйста, выберите цифру от 1 до 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (position == 4) {
            cout << "Программа завершена." << endl;
            break;
        }
    }

    return 0;
}