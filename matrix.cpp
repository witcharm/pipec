#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "matrix.h"
using namespace std;

// �������� �������� ������ �� ����������� ��������
void checking_N(int x)
{
	while (cin.fail() || x < 1)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "������������ ������. ������� ����� ������: ";
		cin >> x;
	}
}

// �������� ������� 
double** create_matrix(int size)
{
	double** matr = new double* [size];
	for (int i = 0; i < size; i++)
	{
		matr[i] = new double[size];
		for (int j = 0; j < size; j++)
			matr[i][j] = 0;
	}
	return matr;
}

// ������� ������, ���������� ��������
void free(double** matr, int size)
{
	for (int i = 0; i < size; i++)
		delete[] matr[i];
	delete[] matr;
	matr = 0;
}

// ����� ������� �� �����
void output(double** matr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << setw(10) << matr[i][j];
		cout << '\n';
	}
	cout << '\n';
}

// �������� ������ �� �������� ������ � �������
double** create_minor(double** matr, int size, int row, int col)
{
	double** minor = create_matrix(size - 1);
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - 1; j++)
		{
			if (i < row && j < col)
				minor[i][j] = matr[i][j];
			if (i < row && j >= col)
				minor[i][j] = matr[i][j + 1];
			if (i >= row && j < col)
				minor[i][j] = matr[i + 1][j];
			if (i >= row && j >= col)
				minor[i][j] = matr[i + 1][j + 1];
		}
	return minor;
}

// ���������� ������������ �������
double determinant(double** matr, int size)
{
	if (size == 1)
		return matr[0][0];
	else
	{
		double det = 0;
		for (int j = 0; j < size; j++)
			det += matr[0][j] * pow(-1, j) * determinant(create_minor(matr, size, 0, j), size - 1);
		return det;
	}
}

// ���������� �������� ������� (����� ������� ����� �������� �� det != 0)
double** revers_matrix(double** matr, int size)
{
	double** rev_matr = create_matrix(size);
	double det = determinant(matr, size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			rev_matr[i][j] = 1 / det * pow(-1, i + j) * determinant(create_minor(matr, size, j, i), size - 1);
	return rev_matr;
}

// �������� ���� ������ 
double** summation_matrixs(double** matr1, double** matr2, int size)
{
	double** matr_copy = create_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matr_copy[i][j] = matr1[i][j] + matr2[i][j];
	return matr_copy;
}

// ����������� � ������� ����� 
double** summation_matrix_num(double** matr, int size, double num)
{
	double** unit_matrix = create_matrix(size);
	double** matr_copy = create_matrix(size);
	unit_matrix = multiply_matrix_num(unit_matrix, size, 0);
	for (int i = 0; i < size; i++)
		unit_matrix[i][i] = num;
	matr_copy = summation_matrixs(matr, unit_matrix, size);
	free(unit_matrix, size);
	return matr_copy;
}

// ��������� ������� �� �����
double** multiply_matrix_num(double** matr, int size, double num)
{
	double** matr_copy = create_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matr_copy[i][j] = matr[i][j] * num;
	return matr_copy;
}

// ��������� 2� ������
double** multiply_matrixs(double** matr1, double** matr2, int size)
{
	double** matr = create_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			matr[i][j] = 0;
			for (int s = 0; s < size; s++)
				matr[i][j] += matr1[i][s] * matr2[s][j];
		}
	return matr;
}

// ���������� f(x)^2 , ��� f(x) = x^3-6x^2-5x+10 (����� ������� ����)
double** main_func(double** matrix, int size)
{
	double** element1 = create_matrix(size), ** element2 = create_matrix(size), ** element3 = create_matrix(size);
	cout << "x^3:\n";
	element1 = multiply_matrixs(multiply_matrixs(matrix, matrix, size), matrix, size);
	output(element1, size);

	cout << "-6x^2:\n";
	element2 = multiply_matrixs(matrix, matrix, size);
	element2 = multiply_matrix_num(element2, size, -6);
	output(element2, size);

	cout << "-5x:\n";
	element3 = multiply_matrix_num(matrix, size, -5);
	output(element3, size);

	cout << "x^3-6x^2:\n";
	element1 = summation_matrixs(element1, element2, size);
	output(element1, size);

	cout << "(x^3-6x^2)-5x:\n";
	element1 = summation_matrixs(element1, element3, size);
	output(element1, size);

	cout << "(x^3-6x^2-5x)+10:\n";
	element1 = summation_matrix_num(element1, size, 10);
	output(element1, size);

	cout << "(f(x))^2:\n";
	element1 = multiply_matrixs(element1, element1, size);
	output(element1, size);
	free(element2, size);
	free(element3, size);
	return element1;
}

// ���������� �������� ������� ��������� 2X + Y = C1  �  X - 2Y = C2
void main_func(double** C1, double** C2)
{
	cout << "2X + Y = C1  ------>  Y = C1 - 2X" << '\n';
	cout << "X - 2Y = C2  ------>  X - 2C1 + 4X = C2  ------>   5X = C2 + 2C1  ------->  X = (C2 + 2C1) / 5" << '\n';
	cout << '\n' << "��������  X = (C2 + 2C1) / 5" << '\n';
	cout << '\n' << "2�1:" << '\n';
	double** element = create_matrix(2);
	element = multiply_matrix_num(C1, 2, 2);
	output(element, 2);
	cout << '\n' << "C2 + 2�1:" << '\n';
	element = summation_matrixs(C2, element, 2);
	output(element, 2);
	cout << '\n' << "X = (C2 + 2�1) / 5:" << '\n';
	element = multiply_matrix_num(element, 2, 0.2);
	output(element, 2);
	cout << '\n' << '\n' << '\n';

	cout << "2X + Y = C1  ------>  2X = C1 - Y" << '\n';
	cout << "X - 2Y = C2  ------>  X = C2 + 2Y  ------>   2X = 2C2 + 4Y  ------->  C1 - Y = 2C2  = 4Y " << '\n';
	cout << "5Y = C1 - 2C2  ------>  Y = (C1 - 2C2) / 5" << '\n';
	cout << '\n' << "��������  Y = (C1 - 2C2) / 5" << '\n';
	cout << '\n' << "-2�2:" << '\n';
	element = multiply_matrix_num(C2, 2, -2);
	output(element, 2);
	cout << '\n' << "C1 - 2C2:" << '\n';
	element = summation_matrixs(C1, element, 2);
	output(element, 2);
	cout << '\n' << "Y = (C1 - 2C2) / 5:" << '\n';
	element = multiply_matrix_num(element, 2, 0.2);
	output(element, 2);
}
