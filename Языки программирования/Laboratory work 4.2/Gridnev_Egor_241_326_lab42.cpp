#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 1. Получение расширения файла
// Вход: полный путь к файлу (std::string file_path_full)
// Выход: расширение файла (std::string)
std::string file_format(const std::string file_path_full) {
    size_t position = file_path_full.find_last_of('.');
    return (position == std::string::npos) ? "" : file_path_full.substr(position + 1);
}

// 2. Получение имени файла
// Вход: полный путь к файлу (std::string file_path_full)
// Выход: имя файла без пути и расширения (std::string)
std::string file_name(const std::string file_path_full) {
    size_t position_slash = file_path_full.find_last_of("/\\");
    size_t position_dot = file_path_full.find_last_of('.');

    if (position_slash == std::string::npos) position_slash = -1; // Если слэш не найден, считаем начало строки
    if (position_dot == std::string::npos || position_dot < position_slash) position_dot = file_path_full.size();

    return file_path_full.substr(position_slash + 1, position_dot - position_slash - 1);
}

// 3. Получение расположения файла (путь без имени и расширения)
// Вход: полный путь к файлу (std::string file_path_full)
// Выход: путь к файлу без имени и расширения (std::string)
std::string file_path(const std::string file_path_full) {
    size_t position_slash = file_path_full.find_last_of("/\\");
    return (position_slash == std::string::npos) ? "" : file_path_full.substr(0, position_slash);
}

// 4. Получение названия диска
// Вход: полный путь к файлу (std::string file_path_full)
// Выход: название диска (char), если не найдено — пустой символ
char file_disk(const std::string file_path_full) {
    if (file_path_full.size() > 1 && file_path_full[1] == ':') {
        return file_path_full[0];
    }
    return '\0'; // Если символ диска не найден
}

// 5. Переименование файла (только работа со строками, изменение имени в строке)
// Вход: указатель на полный путь к файлу (std::string *file_path_full), новое имя (std::string new_name)
// Выход: bool — успешность операции
bool file_rename(std::string *file_path_full, const std::string new_name) {

    if (file_path_full == nullptr || new_name.empty()) {
        return false;
    }

    std::string path = file_path(*file_path_full);
    std::string format = file_format(*file_path_full);
    *file_path_full = path + "/" + new_name + (format.empty() ? "" : "." + format);
    return true;
}

// 6. Создание копии файла
// Вход: полный путь к файлу (std::string file_path_full)
// Выход: bool — успешность операции
bool file_copy(const std::string file_path_full) {
    // Открываем исходный файл для чтения
    std::ifstream src_file(file_path_full, std::ios::binary);
    if (!src_file.is_open()) {
        return false; // Если файл не открылся, возвращаем false
    }

    // Создаем имя для копии файла
    std::string new_file_path = file_path(file_path_full) + "/" + file_name(file_path_full) + "_copy";
    std::string format = file_format(file_path_full);
    if (!format.empty()) {
        new_file_path += "." + format;
    }

    // Открываем файл для записи
    std::ofstream dest_file(new_file_path, std::ios::binary);
    if (!dest_file.is_open()) {
        src_file.close();
        return false; // Если файл не открылся, возвращаем false
    }

    // Копируем содержимое из исходного файла в файл-копию
    dest_file << src_file.rdbuf();

    // Закрываем оба файла и возвращаем true
    src_file.close();
    dest_file.close();

    return true;
}

int main() {

    int choice;
    std::string file, new_name;

    do {
        std::cout << "Меню:\n";
        std::cout << "1. Получить расширение файла\n";
        std::cout << "2. Получить имя файла\n";
        std::cout << "3. Получить расположение файла\n";
        std::cout << "4. Получить название диска\n";
        std::cout << "5. Переименовать файл\n";
        std::cout << "6. Создать копию файла\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Введите полный путь к файлу: ";
                std::cin >> file;
                std::cout << "Расширение файла: " << file_format(file) << std::endl;
                break;
            case 2:
                std::cout << "Введите полный путь к файлу: ";
                std::cin >> file;
                std::cout << "Имя файла: " << file_name(file) << std::endl;
                break;
            case 3:
                std::cout << "Введите полный путь к файлу: ";
                std::cin >> file;
                std::cout << "Расположение файла: " << file_path(file) << std::endl;
                break;
            case 4:
                std::cout << "Введите полный путь к файлу: ";
                std::cin >> file;
                std::cout << "Название диска: " << file_disk(file) << std::endl;
                break;
            case 5:
                std::cout << "Введите полный путь к файлу: ";
                std::cin >> file;
                std::cout << "Введите новое имя файла: ";
                std::cin >> new_name;
                if (file_rename(&file, new_name)) {
                    std::cout << "Новое полное имя файла: " << file << std::endl;
                } else {
                    std::cout << "Ошибка переименования." << std::endl;
                }
                break;
            case 6:
                std::cout << "Введите полный путь к файлу: ";
                std::cin >> file;
                if (file_copy(file)) {
                    std::cout << "Копия файла успешно создана." << std::endl;
                } else {
                    std::cout << "Ошибка создания копии файла." << std::endl;
                }
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Некорректный выбор. Пожалуйста, попробуйте снова.\n";
        }

    } while (choice != 0);

    return 0;
}
