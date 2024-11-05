#include <iostream>

// + matrix* sum(const matrix* matrix2) - сложения матриц,
// + matrix* mult(const matrix* matrix2) - умножения двух матриц,
// + double trace() - след матрицы (сумма диагональных элементов квадратной матрицы),
// + double det()  - определитель матрицы (для квадратных),
// + matrix* mult_by_num(double num) - умножение матрицы на число,
// + void input() - ввести матрицу с клавиатуры,
// + void print() - печать матрицы в консоль,
// + int get_columns() - количество столбцов,
// + int get_rows() - количество строк
// + double get_elem(int i, int j) - вернуть (i,j) элемент


class Matrix {
private:
    int rows;
    int columns;
    double *data;

public:

    Matrix(int rows, int columns) : rows(rows), columns(columns) {
        data = new double[rows * columns]();
    }


    Matrix* sum(const Matrix* matrix2) {

        if (columns != matrix2->rows) {
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


    Matrix* mult(const Matrix* matrix2) const {

        if (columns != matrix2->rows) {
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


    double trace() {

        double trace_sum = 0;

        if (rows != columns) {
            std::cout << "Матрица не является квадратной";
            return 0;
        }

        for (int i = 0; i < rows; ++i) {
            trace_sum += data[i * (rows + 1)]; // Элемент на диагонали находится по индексу i * (n + 1)
        }

        return trace_sum;
    }

    double det() {
        if (rows != columns) {
            throw std::invalid_argument("Матрица должна быть квадратной для вычисления определителя.");
        }

        if (rows == 1) return data[0];
        if (rows == 2) return data[0] * data[3] - data[1] * data[2];

        double determinant = 0;
        for (int j = 0; j < columns; j++) {
            determinant += ((j % 2 == 0 ? 1 : -1) * get_elem(0, j) * minor(0, j).det());
        }
        return determinant;
    }


    // Минор для определителя
    Matrix minor(int row, int col) const {
        Matrix result(rows - 1, columns - 1);
        for (int i = 0, r = 0; i < rows; i++) {
            if (i == row) continue;
            for (int j = 0, c = 0; j < columns; j++) {
                if (j == col) continue;
                result.set_elem(r, c++, get_elem(i, j));
            }
            r++;
        }
        return result;
    }


    Matrix* mult_by_num(double num) {

        Matrix* result = new Matrix(rows, columns);

        for (int i = 0; i < columns * rows; i++) {
            data[i] = data[i] * num;
        }

        return result;
    }


    void input() {
       for (int i = 0; i < rows; i++) {
           for (int j = 0; j < columns; j++) {
               std::cin >> data[i * columns + j];
           }
       }
    }


    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << data[i * columns + j];
            }
        }
    }

    // Получение элемента (i, j)
    double get_elem(int i, int j) const {
        if (i >= rows || j >= columns || i < 0 || j < 0) throw std::out_of_range("Индекс вне диапазона");
        return data[i * columns + j];
    }


    // Установка элемента (i, j)
    void set_elem(int i, int j, double value) {
        if (i >= rows || j >= columns || i < 0 || j < 0) throw std::out_of_range("Индекс вне диапазона");
        data[i * columns + j] = value;
    }


    int get_rows() {
        return rows;
    }


    int get_columns() {
        return columns;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
