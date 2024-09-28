#include <iostream>
#include <limits>
#include <string>


using std::cin;
using std::cout;
using std::endl;


long long factorial(int n) {

    long long result = 1;

    for (int i = 1; i < n + 1; i++) {
        result *= i;  
    }
    return result;
}


void programMenu() {

    cout << endl << "Меню программы, для выбора действия введите соответствующую цифру:";

    cout << "  1. Числовой треугольник." << endl;
    cout << "  2. Нахождение биномиальных коэффициентов." << endl;
    cout << "  3. Вычисление среднего арифметического введенных точек на прямой, заданных своими координатами." << endl;
    cout << "  4. Реализация выхода." << endl;
}


void numericalTriangle() {

    int height;
    int index = 1;

    cout << endl << "Введите число: ";
    cin >> height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < index; j++) {
            cout << j;
        }
        index++;      
        cout << endl;      
    }      
}


int findingBinomialCoefficients() {
    
    int n;
    long long coefficients = 1;
    
    cout << endl << "Введите значение n для n!/(k!*(n - k)!): ";
    cin >> n;
    
    for (int k = 1; k <= n; ++k) {
        
        long long newCoefficients = coefficients * (n - k + 1) / k;
        
        if (newCoefficients < 0) {
            cout << endl << "Произошло переполнение на индексе " << k << endl;
            return 1; 
        }
        
        cout << "n: " << n 
            << "  k: " << k
            << "  coef: " << newCoefficients << endl;
        coefficients = newCoefficients;
    }
    
    return 0;
}


void calculatingTheArithmeticMean() {

    double sum = 0.0;
    int count = 0;
    int element;
    
    cout << endl << "Введите координаты точек на прямой (нажмите 0 для завершения ввода): ";
    
    cin >> element;
    
    while (element != 0) {
        sum += element;
        count++;
        cin >> element;
    }

    cout << endl << "Среднее арифметическое: " << sum / count << endl;
    
}


int exit_program() {

    int value;

    cout << endl << "Выход из программы осуществляется через цифру 4, чтобы остаться или выбрать другую задачу, введите цифру соответсвующую выбранному пункту." << endl;
    cout << endl << "Ввод: ";
    cin >> value;

    return value;  
}


int main() {

    int position = 4;


    while (true) {
        switch(position) {

            case 1:
                cout << endl << "Вы выбрали числовой треугольник." << endl;
                numericalTriangle();
                position = exit_program();
                break;

            case 2:
                cout << endl << "Вы выбрали Нахождение биномиальных коэффициентов." << endl;
                findingBinomialCoefficients();
                position = exit_program();
                break;

            case 3:
                cout << endl << "Вы выбрали Вычисление среднего арифметического введенных точек на прямой, заданных своими координатами. " << endl;
                calculatingTheArithmeticMean();
                position = exit_program();
                break;

            case 4:
                programMenu();
                cout << endl << "Введите что хотите выбрать из меню: ";
                cin >> position;
                break;

            default:
                cout << "Неверный формат ввода." << endl;

                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                programMenu();
                cin >> position;
                break;
        }
    }
    
    return 0;
}