#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "oper_mat.h"

using namespace std;

int main(int argc, const char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size = 0;
	double** mat = input_mat(size);

	//вычисление выражения с выводом промежуточных результатов
	calculator(mat, size);

	return 0;
	system("pause");
}
