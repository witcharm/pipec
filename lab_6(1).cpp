// �������� ���� ���-13, ������������ ������ �6 (1 �������)  8 �������
// ���������� �������� ��������� (f(A))^2 ��� f(x) = x^3-6x^2-5x+10, ��� � - �������
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "matrix.h"
using namespace std;

int main()
{
	setlocale(0, "RUS");
	int size;
	cout << "������� ������ �������: ";
	cin >> size;
	checking_N(size);
	double** matrix = create_matrix(size), ** result = create_matrix(size);
	cout << "�������� �������:\n";
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