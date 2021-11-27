#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "matrixs.h"
using namespace std;

// Проверка введённых данных
void checking(int x)
{
	while (cin.fail() || x < 1)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Недопустимый формат. Введите число занаво: ";
		cin >> x;
	}
}

// Заполнение матрицы рандомными числами
void filling_matrix(int(*matr)[100], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matr[i][j] = rand() % 6;
}

// Сложение двух матриц (результат будет храниться в matr1)
void summation_matrix(int(*matr1)[100], int(*matr2)[100], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matr1[i][j] += matr2[i][j];
}

// Прибавление к матрице числа (результат будет храниться в matr1)
void summation_num(int(*matr)[100], int size, int num)
{
	int unit_matrix[100][100] = { 0 };
	for (int i = 0; i < size; i++)
		unit_matrix[i][i] = num;
	summation_matrix(matr, unit_matrix, size);
}

// Умножение матрицы на число
void multiply_matrix(int(*matr)[100], int size, int num)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matr[i][j] *= num;
}

// Копирование матрицы
void copy_matrix(int(*matr)[100], int(*matr_copy)[100], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matr_copy[i][j] = matr[i][j];
}

// Возведение матрицы в степень (только 2 или 3)
void raise2degree_matrix(int(*matr)[100], int size, int degree)
{
	int matr_copy[100][100];
	copy_matrix(matr, matr_copy, size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			matr[i][j] = 0;
			for (int s = 0; s < size; s++)
				matr[i][j] += matr_copy[i][s] * matr_copy[s][j];
		}
	if (degree == 3)
	{
		int square_matr_copy[100][100];
		copy_matrix(matr, square_matr_copy, size);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				matr[i][j] = 0;
				for (int s = 0; s < size; s++)
					matr[i][j] += square_matr_copy[i][s] * matr_copy[s][j];
			}
	}
}

// Вывод матрицы на экран
void output(int(*matr)[100], int size) 
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << setw(7) << matr[i][j];
		cout << '\n';
	}
	cout << '\n';
}