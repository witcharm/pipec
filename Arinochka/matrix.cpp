#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "matrixs.h"
using namespace std;

int main()
{
	setlocale(0, "RUS");
    int size;
	cout << "Введите размер матрицы: ";
	cin >> size;
	checking(size);
	int matrix[100][100], element1[100][100], element2[100][100], element3[100][100];
	filling_matrix(matrix, size);
	cout << "Исходная матрица:\n";
	output(matrix, size);

	copy_matrix(matrix, element1, size);
	cout << "x^3:\n";
	raise2degree_matrix(element1, size, 3);
	output(element1, size);

	copy_matrix(matrix, element2, size);
	cout << "-6x^2:\n";
	raise2degree_matrix(element2, size, 2);
	multiply_matrix(element2, size, -6);
	output(element2, size);

	copy_matrix(matrix, element3, size);
	cout << "-5x:\n";
	multiply_matrix(element3, size, -5);
	output(element3, size);
	
	cout << "x^3-6x^2:\n";
	summation_matrix(element1, element2, size);
	output(element1, size);

	cout << "(x^3-6x^2)-5x:\n";
	summation_matrix(element1, element3, size);
	output(element1, size);
	
	cout << "(x^3-6x^2-5x)+10:\n";
	summation_num(element1, size, 10);
	output(element1, size);

	cout << "(x^3-6x^2-5x+10)^2:\n";
	raise2degree_matrix(element1, size, 2);
	output(element1, size);

	system("pause");
	return 0;
}