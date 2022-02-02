// Никулина Юлия ПМИ-13, Лабораторная работа №6 (2 задание)   6 вариант
// Нахождение обратной матрицы к заданной матрице А, если она существует
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "matrix.h"
using namespace std;

int main()
{
	setlocale(0, "RUS");
	int size;
	cout << "Введите размер матрицы: ";
	cin >> size;
	checking_N(size);
	double** matrix = create_matrix(size);
	cout << "Исходная матрица:\n";
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> matrix[i][j];
	if (determinant(matrix, size) != 0)
	{
		cout << "Обратная матрица:" << '\n';
		double** result = create_matrix(size);
		result = revers_matrix(matrix, size);
		output(result, size);
		free(result, size);
	}
	else
		cout << "Обратную матрицу невозможно найти, так как определитель матрицы равен нулю";
	free(matrix, size);
	system("pause");
	return 0;
}