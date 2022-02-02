#ifndef MATRIX_H
#define MATRIX_H

// Проверка введённых данных на натуральное значение
void checking_N(int x);

// Создание матрицы
double** create_matrix(int size);

// Очитска памяти, занимаемой матрицей
void free(double** matr, int size);

// Вывод матрицы на экран
void output(double** matr, int size);

// Создание минора по заданным строке и столбцу
double** create_minor(double** matr, int size, int row, int col);

// Нахождение определителя матрицы
double determinant(double** matr, int size);

// Нахождение обратной матрицы (перед вызовом нужна проверка на det != 0)
double** revers_matrix(double** matr, int size);

// Сложение двух матриц 
double** summation_matrixs(double** matr1, double** matr2, int size);

// Прибавление к матрице числа 
double** summation_matrix_num(double** matr, int size, double num);

// Умножение матрицы на число
double** multiply_matrix_num(double** matr, int size, double num);

// Умножение 2х матриц
double** multiply_matrixs(double** matr1, double** matr2, int size);

// Вычисление f(x)^2 , где f(x) = x^3-6x^2-5x+10 (вывод каждого шага)
double** main_func(double** matrix, int size);

// Вычисление значения системы уравнений 2X + Y = C1  и  X - 2Y = C2
void main_func(double** C1, double** C2);

#endif // MATRIX_H