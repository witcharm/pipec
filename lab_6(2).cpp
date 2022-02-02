// �������� ���� ���-13, ������������ ������ �6 (2 �������)   6 �������
// ���������� �������� ������� � �������� ������� �, ���� ��� ����������
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "matrix.h"
using namespace std;

int main()
{
	setlocale(0, "RUS");
	int size;
	cout << "������� ������ �������: ";
	cin >> size;
	checking_N(size);
	double** matrix = create_matrix(size);
	cout << "�������� �������:\n";
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> matrix[i][j];
	if (determinant(matrix, size) != 0)
	{
		cout << "�������� �������:" << '\n';
		double** result = create_matrix(size);
		result = revers_matrix(matrix, size);
		output(result, size);
		free(result, size);
	}
	else
		cout << "�������� ������� ���������� �����, ��� ��� ������������ ������� ����� ����";
	free(matrix, size);
	system("pause");
	return 0;
}