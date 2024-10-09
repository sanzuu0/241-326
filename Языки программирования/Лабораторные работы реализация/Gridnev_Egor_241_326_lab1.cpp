#include <bitset>
#include <climits>
#include <iostream>
#include <cfloat>

using std::cin;
using std::cout;
using std::bitset;
using std::hex;
using std::endl;
using std::boolalpha;


void myInformation() {
    cout << "Gridnev Egor Mihailovich, 241-326" << endl;
}


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

    cout << "Min bool = " << std::boolalpha << false
        << ", Max bool = " << std::boolalpha << true
        << ", Size of bool = " << sizeof(bool) << " bytes\n";

}


void numberRepresentation() {

    int number;

    cout << "\nEnter a number:";
    cin >> number;

    cout << "Binary representation: " << bitset<16>(number) << endl;
    cout << "bool: " << static_cast<bool>(number) << endl;
    cout << "double: " << static_cast<double>(number) << endl;
    cout << "char: " << static_cast<char>(number) << endl;
}


void solvingTheEquation() {

    double a, b;

    cout << "\nEnter the coefficients a * x = b:";
    cin >> a >> b;

    if (a != 0) {
        cout << a << " * x = " << b << endl;
        cout << "x = " << b << " / " << a << endl;
        cout << "x = " << b / a << endl;
    } else {
        cout << "Error: dividing by zero" << endl;
    }
}


void midPointOfTheSegment() {

    double a, b;

    cout << "\nEnter the coordinates of the segment on the straight line: ";
    cin >> a >> b;

    cout << "The middle of the segment is located at the point with the coordinate: " << (a + b) / 2.0 << endl;
}


int main() {

	myInformation();
	printDataTypeInfo();
	numberRepresentation();
	solvingTheEquation();
	midPointOfTheSegment();

	return 0;
}