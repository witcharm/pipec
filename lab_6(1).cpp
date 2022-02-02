// Никулина Юлия ПМИ-13, Лабораторная работа №6 (1 задание)  8 вариант
// Вычисление значения уравнения (f(A))^2 для f(x) = x^3-6x^2-5x+10, где А - матрица
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "matrix.h"
using namespace std;

int main()
{
	setlocale(0, "RUS");
	int size;
	cout << "Введите размер матрицы: ";
	cin >> size;
	checking_N(size);
	double** matrix = create_matrix(size), ** result = create_matrix(size);
	cout << "Исходная матрица:\n";
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> matrix[i][j];
	cout << '\n';
	result = main_func(matrix, size);
	free(matrix, size);
	free(result, size);
	system("pause");
	return 0;
}