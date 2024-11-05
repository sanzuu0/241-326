#include <iostream>



//Перегрузить методы класса матриц.
// Matrix(int i, int j); //констуктор, i - количество строк, j - количество столбцов, элементы определяются 0;
// Matrix(int i, int j, const double* arr); //констуктор, i - количество строк, j - количество столбцов, элементы определяются массивом arr;
// Matrix sum(const double * arr) и Matrix sum(const double * arr, int size)  - сложения матриц, результат возвращается или записывается в текущую матрицу соответственно;
// Matrix mult(const double * arr), или void mult(const double * arr), или
// Matrix mult(const double * arr, int size), или void mult(const double * arr, int size) - умножения двух матриц, результат возвращается или записывается в текущую матрицу соответственно;
// void input(int i, int j) - ввести матрицу с клавиатуры c заданными размерами, i - количество строк, j - количество столбцов;
// void input(int i, int j, double * arr) - инициализировать матрицу заданным массивом arr, i - количество строк, j - количество столбцов.

class Matrix {
private:
    int rows;
    int columns;
    const double* arr;
    double* data;

public:

    Matrix(int rows, int columns, const double* arr) : rows(rows), columns(columns), arr(arr) {
        data = new double[rows * columns]();
        for (int i = 0; i < rows * columns; i++) {
            data[i] = arr[i];
        }
    }

    Matrix(int rows, int columns) : rows(rows), columns(columns) {
        data = new double[rows * columns]();
        for (int i = 0; i < rows * columns; i++) {
            data[i] = 0;
        }
    }

    Matrix* sum(const double* arr) {

        if (columns != ) {
            throw std::invalid_argument("Число столбцов первой матрицы должно быть равно числу строк второй.");
        }

        Matrix* result = new Matrix(rows, matrix2->columns);

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < matrix2->columns; j++) {
                result->data[i * result->get_columns() + j] = 0;

                for (int k = 0; k < columns; k++) {
                    result->data[i * result->get_columns() + j] += data[i * columns + k] * matrix2->get_elem(k, j);
                }
            }
        }
        return result;
    }


};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
