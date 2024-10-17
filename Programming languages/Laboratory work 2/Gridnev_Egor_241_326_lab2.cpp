#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

void programMenu() {

    cout << "\nProgram Menu, enter the corresponding number to choose an action:" << endl;
    cout << "  1. Numerical triangle." << endl;
    cout << "  2. Finding binomial coefficients." << endl;
    cout << "  3. Calculating the arithmetic mean of the entered points on a line, given by their coordinates." << endl;
    cout << "  4. Exit." << endl;
}

void numericalTriangle() {

    int height;
    cout << "\nEnter a positive integer for the height of the triangle: ";

    while (!(cin >> height) || height <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
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
        k = n - k;

    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

void findingBinomialCoefficients() {

    int n;
    cout << "\nEnter a non-negative integer for n: ";

    while (!(cin >> n) || n < 0) {
        cout << "Invalid input. Please enter a non-negative integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int k = 0; k <= n; ++k) {
        cout << "C(" << n << ", " << k << ") = " << binomialCoefficient(n, k) << endl;
    }
}

void calculatingTheArithmeticMean() {

    double sum = 0.0;
    int count = 0, element;

    cout << "\nEnter coordinates (integers) of points on a line (enter 0 to finish): ";

    while (cin >> element && element != 0) {
        sum += element;
        count++;
    }
    cout << "\nArithmetic mean: " << (count == 0 ? 0 : sum / count) << endl;
}

int getUserChoice() {

    int choice;
    cout << "\nEnter your choice from the menu: ";

    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Invalid input. Please choose a number between 1 and 4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

int main() {

    while (true) {
        programMenu();
        int choice = getUserChoice();

        if (choice == 4) {
            cout << "Program terminated." << endl;
            break;
        }

        switch (choice) {
            case 1:
                cout << "\nYou chose Numerical Triangle.\n";
                numericalTriangle();
                break;
            case 2:
                cout << "\nYou chose Finding Binomial Coefficients.\n";
                findingBinomialCoefficients();
                break;
            case 3:
                cout << "\nYou chose Calculating the Arithmetic Mean.\n";
                calculatingTheArithmeticMean();
                break;
        }
    }
    return 0;

}