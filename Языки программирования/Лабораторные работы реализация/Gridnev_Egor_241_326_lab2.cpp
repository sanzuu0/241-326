#include <iostream>
#include <limits>
#include <string>

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

    cout << "\nEnter a number:";

    while (!(cin >> height) || height <= 0) {
        cout << "Invalid input. Please enter a positive integer:";
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
        k = n - k; // Optimization: C(n, k) == C(n, n-k)

    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}


void findingBinomialCoefficients() {

    int n;

    cout << "\nEnter the value of n:";

    while (!(cin >> n) || n < 0) {
        cout << "Invalid input. Please enter a non-negative integer:";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int k = 0; k <= n; ++k) {

        long long binomialCoeff = binomialCoefficient(n, k);

        if (binomialCoeff > 0) {
            cout << "C(" << n << ", " << k << ") = " << binomialCoefficient(n, k) << endl;
        } else {
            cout << "C(" << n << ", " << k << ") = Overflow occurred" << endl;
        }
    }
}


void calculatingTheArithmeticMean() {

    double sum = 0.0;
    int count = 0;
    int element;

    cout << "\nEnter the coordinates of the points on a line (press 0 to finish input):";

    cin >> element;

    while (element != 0) {
        sum += element;
        count++;
        cin >> element;
    }
    cout << "\nArithmetic mean: " << (count == 0 ? 0 : sum / count) << endl;
}


int main() {

    int position = 4;

    while (true) {

        switch (position) {

            case 1:
                cout << "\nYou chose numerical triangle.";
                numericalTriangle();
                break;

            case 2:
                cout << "\nYou chose Finding binomial coefficients.";
                findingBinomialCoefficients();
                break;

            case 3:
                cout << "\nYou chose Calculating the arithmetic mean of the entered points on a line, given by their coordinates.";
                calculatingTheArithmeticMean();
                break;

            case 4:
                programMenu();
                break;

            default:
                cout << "Invalid input format.";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }

        cout << "\nEnter your choice from the menu:";

        while (!(cin >> position) || position < 1 || position > 4) {
            cout << "Invalid input. Please choose a number between 1 and 4:";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (position == 4) {
            cout << "Program terminated." << endl;
            break;
        }
    }

    return 0;
}
