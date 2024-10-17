#include <iostream>
#include <vector>
#include <limits>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::vector;
using std::streamsize;
using std::numeric_limits;
using std::stringstream;
using std::string;

void programMenu() {

    cout << "\nProgram Menu, enter the corresponding number to choose an action:" << endl;
    cout << "  1. Sort a numeric array in ascending order using the bubble sort algorithm." << endl;
    cout << "  2. Sort a character array (letters a-z) in ascending order using the counting sort algorithm." << endl;
    cout << "  3. Sort a numeric array in ascending order using the merge sort algorithm." << endl;
    cout << "  4. Exit." << endl;
}

vector<int>& bubbleSort(vector<int>& arr) {

    int size = arr.size();

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

void countingSort(vector<char>& arr) {

    const int ALPHABET_SIZE = 26;
    int count[ALPHABET_SIZE] = {0};

    for (char ch : arr) {
        count[ch - 'a']++;
    }

    int index = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        while (count[i] > 0) {
            arr[index++] = 'a' + i;
            count[i]--;
        }
    }
}

void merge(vector<int>& arr, int left, int middle, int right) {

    int size1 = middle - left + 1;
    int size2 = right - middle;

    vector<int> leftArr(size1), rightArr(size2);

    for (int i = 0; i < size1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < size2; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2) {

        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;

        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {

    if (left < right) {

        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

vector<int> readNumbers() {

    string input;
    getline(cin >> std::ws, input);
    stringstream ss(input);
    vector<int> arr;
    int number;

    while (ss >> number) {
        arr.push_back(number);
    }
    return arr;
}

vector<char> readChars() {

    string input;
    getline(cin >> std::ws, input);
    vector<char> arr;

    for (char ch : input) {
        if (ch != ' ') {
            arr.push_back(ch);
        }
    }
    return arr;
}

template <typename T>
void outputArray(const vector<T>& arr) {

    for (const T& element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    int position = 0;

    while (true) {
        programMenu();
        cout << "\nEnter your choice from the menu: ";

        while (!(cin >> position) || position < 1 || position > 4) {
            cout << "Invalid input. Please choose a number between 1 and 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (position == 4) {
            cout << "Program terminated." << endl;
            break;
        }

        switch (position) {
            case 1: {
                cout << "You chose to sort a numeric array using bubble sort.\n";
                cout << "Enter numbers in a single line, separated by spaces: ";
                vector<int> arr1 = readNumbers();
                bubbleSort(arr1);
                cout << "Sorted array: ";
                outputArray(arr1);
                break;
            }

            case 2: {
                cout << "You chose to sort a character array using counting sort.\n";
                cout << "Enter letters in a single line without spaces: ";
                vector<char> arr2 = readChars();
                countingSort(arr2);
                cout << "Sorted array: ";
                outputArray(arr2);
                break;
            }

            case 3: {
                cout << "You chose to sort a numeric array using merge sort.\n";
                cout << "Enter numbers in a single line, separated by spaces: ";
                vector<int> arr3 = readNumbers();
                mergeSort(arr3, 0, arr3.size() - 1);
                cout << "Sorted array: ";
                outputArray(arr3);
                break;
            }

            default:
                cout << "Invalid input format." << endl;
                break;
        }
    }
    return 0;
}