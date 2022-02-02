// Никулина Юлия ПМИ-13, Лабораторная работа №6 (3 задание)   8 вариант
// Вычисление значения системы уравнений 2X + Y = C1  и  X - 2Y = C2
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
	double** C1 = create_matrix(size);
	cout << "Матрица С1:\n";
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> C1[i][j];
	cout << '\n';
	double** C2 = create_matrix(size);
	cout << "Матрица С2:\n";
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> C2[i][j];
	cout << '\n';
	main_func(C1, C2);
	free(C1, size);
	free(C2, size);
	system("pause");
	return 0;
}