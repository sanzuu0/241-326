#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;

// Функция 1: Проверка на палиндром
// Вход:
//  строка не более 255 символов
// Выход:
//  boolean значение
bool isPalindrome(const char* str) {

    int i = 0, j = strlen(str) - 1;

    while (i < j) {
        // Отсеивание пробелов слева
        if (isspace(str[i])) {
            i++;
        }
        // Отсеивание пробелов справа
        if (isspace(str[j])) {
            j--;
        }
        // Преобразование символов в нижний регистр
        if (tolower(str[i]) != tolower(str[j])) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// Функция 2: Поиск первого вхождения подстроки в строке
// Вход:
//  Строка в формате char*: str_for_searching_in
//  Строка поиска в формате char*: substring
//  Позиция в формате int: start_position
// Выход:
//  Позиция первого элемента в подстроках в формате int
int find_substring1(const char* string_for_search_in, const char* substring, int start_position) {

    int string_len = strlen(string_for_search_in);
    int substring_len = strlen(substring);

    for (int i = start_position; i <= string_len - substring_len; i++) {

        bool found = true;

        for (int j = 0; j < substring_len; j++) {

            if (string_for_search_in[i + j] != substring[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    return -1;
}

// Функция 3: Поиск всех вхождений подстроки в строке
// Вход:
//  Строка в формате char*: str_for_searching_in
//  Строка поиска в формате char*: substring
// Выход:
//  Массив позиций первого элемента в подстроках в формате int
vector<int> find_substring2(const char* str_for_search_in, const char* substring) {

    vector<int> positions;
    int start_position = 0;
    int found_position;

    while ((found_position = find_substring1(str_for_search_in, substring, start_position)) != -1) {
        positions.push_back(found_position);
        start_position = found_position + 1;
    }

    return positions;
}

// Функция 4: Шифр Цезаря (шифрование сдвигом)
// Вход:
//  Строка в формате char*: str_for_encrypt
//  Ключ смещения int: key
// Выход:
//  Получаем измененную строку
void encrypt(char* str_for_encrypt, int key) {

    for (int i = 0; str_for_encrypt[i] != '\0'; i++) {

        if (isalpha(str_for_encrypt[i])) {

            char base = islower(str_for_encrypt[i]) ? 'a' : 'A'; // база для букв (символ 'a' или 'A')
            str_for_encrypt[i] = (str_for_encrypt[i] - base + key) % 26 + base;

        } else if (isdigit(str_for_encrypt[i])) {

            char base = '0'; // База для цифр (символ '0')
            str_for_encrypt[i] = (str_for_encrypt[i] - base + key) % 10 + base;
        }
    }
}

// Функция 5: Поиск и вывод текста в кавычках
// Вход:
//  Строка в формате char*: text
// Выход:
//  Получаем измененную строку
void extract_titles(const char* text) {

    bool inside_quotes = false;
    string title;

    for (int i = 0; text[i] != '\0'; i++) {

        if (text[i] == '\"') {

            if (inside_quotes) {

                cout << title << " | ";
                title.clear();
            }
            inside_quotes = !inside_quotes;

        } else if (inside_quotes) {
            title += text[i];
        }
    }
    cout << endl;
}

int main() {
    int choice;
    char text[255];
    char substring[255];
    int key;
    int start_position;
    int index;

    do {
        cout << "\nМеню:\n";
        cout << "1. Проверка на палиндром\n";
        cout << "2. Поиск подстроки в строке\n";
        cout << "3. Шифрование сдвигами (Цезарь)\n";
        cout << "4. Извлечение названий из текста\n";
        cout << "5. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Введите строку для проверки на палиндром: ";
                cin.getline(text, 255);

                if (isPalindrome(text)) {
                    cout << "Строка является палиндромом.\n";
                } else {
                    cout << "Строка не является палиндромом.\n";
                }
                break;

            case 2:
                cout << "Введите строку для поиска: ";
                cin.getline(text, 255);
                cout << "Введите подстроку для поиска: ";
                cin.getline(substring, 255);
                cout << "Введите стартовую позицию для поиска: ";
                cin >> start_position;

                index = find_substring1(text, substring, start_position);

                if (index != -1) {
                    cout << "Подстрока найдена на позиции " << index << ".\n";
                } else {
                    cout << "Подстрока не найдена.\n";
                }

                break;

            case 3:
                cout << "Введите строку для шифрования: ";
                cin.getline(text, 255);
                cout << "Введите ключ сдвига: ";
                cin >> key;
                encrypt(text, key);
                cout << "Зашифрованная строка: " << text << endl;
                break;

            case 4:
                cout << "Введите строку с названиями в кавычках: ";
                cin.getline(text, 255);
                cout << "Результат: ";
                extract_titles(text);
                break;

            case 5:
                cout << "Выход из программы.\n";
                break;

            default:
                cout << "Неверный выбор, попробуйте снова.\n";
        }
    } while (choice != 5);
    return 0;
}
