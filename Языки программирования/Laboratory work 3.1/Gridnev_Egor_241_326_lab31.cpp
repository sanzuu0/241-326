#include <iostream>
#include <vector>
#include <limits>
#include <sstream>

using namespace std;

// Функция: Сортировка пузырьком числового массива
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

// Функция: Сортировка символов методом подсчета
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

// Функция: Слияние массивов в сортировке слиянием
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

// Функция: Сортировка массива методом слияния
void mergeSort(vector<int>& arr, int left, int right) {

    if (left < right) {

        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// Функция: Чтение чисел из строки
vector<int> readNumbers() {

    string input;
    getline(cin >> ws, input);
    stringstream ss(input);
    vector<int> arr;
    int number;

    while (ss >> number) {
        arr.push_back(number);
    }
    return arr;
}

// Функция: Чтение символов из строки
vector<char> readChars() {

    string input;
    getline(cin >> ws, input);
    vector<char> arr;

    for (char ch : input) {
        if (ch != ' ') {
            arr.push_back(ch);
        }
    }
    return arr;
}

// Функция: Вывод массива
template <typename T>
void outputArray(const vector<T>& arr) {

    for (const T& element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {

    int choice = 0;

    while (choice != 4) {
        cout << "  1. Сортировать числовой массив по возрастанию с использованием алгоритма пузырьковой сортировки." << endl;
        cout << "  2. Сортировать массив символов (буквы a-z) по возрастанию с использованием алгоритма сортировки подсчетом." << endl;
        cout << "  3. Сортировать числовой массив по возрастанию с использованием алгоритма сортировки слиянием." << endl;
        cout << "  4. Выход." << endl;
        cout << "\nМеню программы, введите соответствующий номер для выбора действия: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "Вы выбрали сортировку числового массива с использованием пузырьковой сортировки.\n";
                cout << "Введите числа в одной строке, разделенные пробелами: ";
                vector<int> arr1 = readNumbers();
                bubbleSort(arr1);
                cout << "Отсортированный массив: ";
                outputArray(arr1);
                break;
            }

            case 2: {
                cout << "Вы выбрали сортировку массива символов с использованием сортировки подсчетом.\n";
                cout << "Введите буквы в одной строке без пробелов: ";
                vector<char> arr2 = readChars();
                countingSort(arr2);
                cout << "Отсортированный массив: ";
                outputArray(arr2);
                break;
            }

            case 3: {
                cout << "Вы выбрали сортировку числового массива с использованием сортировки слиянием.\n";
                cout << "Введите числа в одной строке, разделенные пробелами: ";
                vector<int> arr3 = readNumbers();
                mergeSort(arr3, 0, arr3.size() - 1);
                cout << "Отсортированный массив: ";
                outputArray(arr3);
                break;
            }

            case 4:
                cout << "Выход из программы.\n";
                break;

            default:
                cout << "Неверный выбор, попробуйте снова.\n";
        }
    }

    return 0;
}
