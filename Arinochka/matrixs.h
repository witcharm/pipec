#ifndef MATRIXS_H
#define MATRIXS_H

// Проверка введённых данных
void checking(int x);

// Заполнение матрицы рандомными числами
void filling_matrix(int(*matr)[100], int size);

// Сложение двух матриц (результат будет храниться в matr1)
void summation_matrix(int(*matr1)[100], int(*matr2)[100], int size);

// Прибавление к матрице числа (результат будет храниться в matr1)
void summation_num(int(*matr)[100], int size, int num);

// Умножение матрицы на число
void multiply_matrix(int(*matr)[100], int size, int num);

// Копирование матрицы
void copy_matrix(int(*matr)[100], int(*matr_copy)[100], int size);

// Возведение матрицы в степень (только 2 или 3)
void raise2degree_matrix(int(*matr)[100], int size, int degree);

// Вывод матрицы на экран
void output(int(*matr)[100], int size);

#endif // MATRIXS_H