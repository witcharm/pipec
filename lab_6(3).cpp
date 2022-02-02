// �������� ���� ���-13, ������������ ������ �6 (3 �������)   8 �������
// ���������� �������� ������� ��������� 2X + Y = C1  �  X - 2Y = C2
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
	double** C1 = create_matrix(size);
	cout << "������� �1:\n";
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> C1[i][j];
	cout << '\n';
	double** C2 = create_matrix(size);
	cout << "������� �2:\n";
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