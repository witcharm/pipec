#include <iostream>
#include <iomanip>
#include "oper_mat.h"
#include "check_input.h"

using namespace std;

//создает м-цу
double** create_mat(int size)
{
	double** mat = new double*[size];

	for (int i = 0; i < size; i++)
	{
		mat[i] = new double[size];
	}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			mat[i][j] = 0;

	return mat;
}

//записываем значения эл-тов м-цы
double** input_mat(int& size)
{
	cout << "Введите размер м-цы: ";
	cin >> size;
	check_input_int(size);

	double** mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			cout << "Введите эл-т м-цы c номером [" << i << "][" << j << "]: ";
			cin >> mat[i][j];
			check_input_double(mat[i][j]);
		}

	return mat;
}

//выводим м-цу
void output_mat(double** mat, int size)
{
	cout << "\n";

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << setw(10) << mat[i][j] << " ";
		cout << "\n";
	}
}

//очистка и удаление м-цы
void clean_mat(double** mat, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			mat[i][j] = 0;
		delete[] mat[i];
	}

	delete[] mat;
}

//копирование одной м-цы во вторую
void copy_mat(double** mat_from, double** mat_to, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			mat_to[i][j] = mat_from[i][j];
}

//операция возведения в степень
void oper_power_mat(double** mat_1, double** mat_2, int size, int power, double** res)
{
	for (int i = 0; i < (power - 1); i++)
	{
		double** res_mat = create_mat(size);

		for (int j = 0; j < size; j++)
			for (int h = 0; h < size; h++)
				for (int k = 0; k < size; k++)
					res_mat[j][h] += mat_1[j][k] * mat_2[k][h];

		copy_mat(res_mat, mat_1, size);
		clean_mat(res_mat, size);
	}

	copy_mat(mat_1, res, size);
}

//создание единичной м-цы
double** create_identity_mat(int size)
{
	double** identity_mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (i == j)
				identity_mat[i][j] = 1.0;
			else
				identity_mat[i][j] = 0;

	return identity_mat;
}

//операция умножения м-цы на число
void oper_of_mat_multip_by_num(double** mat_1, double** mat_2, int size, int num)
{
	double** res_mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			res_mat[i][j] = mat_1[i][j] * num;

	copy_mat(res_mat, mat_2, size);
	clean_mat(res_mat, size);
}

//операция сложения(вычитания)
void oper_addition_mat(double** mat_1, double** mat_2, int size)
{
	double** res_mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			res_mat[i][j] = mat_1[i][j] + mat_2[i][j];

	copy_mat(res_mat, mat_1, size);
	clean_mat(res_mat, size);
}

//вычисление выражения с выводом промежуточных результатов
void calculator(double** mat, int size)
{
	double** mat_1 = create_mat(size); //создаем переменные для слагаемых выражения
	double** mat_2 = create_mat(size);
	double** additional_mat = create_mat(size); //создаем дополнительную м-цу для преобразований

	cout << "\nA: ";
	output_mat(mat, size);

	cout << "\nA^2: ";
	oper_power_mat(mat, mat, size, 2, mat);
	output_mat(mat, size);

	cout << "\nx^3: ";
	copy_mat(mat, additional_mat, size);
	oper_power_mat(additional_mat, mat, size, 3, mat_1);
	output_mat(mat_1, size);

	cout << "\nx^2: ";
	copy_mat(mat, additional_mat, size);
	oper_power_mat(additional_mat, mat, size, 2, mat_2);
	output_mat(mat_2, size);

	cout << "\n(x^2)*(-10): ";
	oper_of_mat_multip_by_num(mat_2, mat_2, size, -10);
	output_mat(mat_2, size);

	cout << "\n(x^3)-10*(x^2): ";
	oper_addition_mat(mat_1, mat_2, size);
	output_mat(mat_1, size);

	cout << "\n7*x: ";
	oper_of_mat_multip_by_num(mat, mat_2, size, 7);
	output_mat(mat_2, size);

	cout << "\n(x^3)-10*(x^2)+7x: ";
	oper_addition_mat(mat_1, mat_2, size);
	output_mat(mat_1, size);

	cout << "\n-12*E: ";
	double** identity_mat = create_identity_mat(size);
	oper_of_mat_multip_by_num(identity_mat, mat_2, size, -12);
	output_mat(mat_2, size);

	cout << "\n(x^3)-10*(x^2)+7x-12E: ";
	oper_addition_mat(mat_1, mat_2, size);
	output_mat(mat_1, size);

	clean_mat(mat_1, size);
	clean_mat(mat_2, size);
	clean_mat(additional_mat, size);

	system("pause");
}
