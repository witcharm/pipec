#ifndef MATRIX_H
#define MATRIX_H

// �������� �������� ������ �� ����������� ��������
void checking_N(int x);

// �������� �������
double** create_matrix(int size);

// ������� ������, ���������� ��������
void free(double** matr, int size);

// ����� ������� �� �����
void output(double** matr, int size);

// �������� ������ �� �������� ������ � �������
double** create_minor(double** matr, int size, int row, int col);

// ���������� ������������ �������
double determinant(double** matr, int size);

// ���������� �������� ������� (����� ������� ����� �������� �� det != 0)
double** revers_matrix(double** matr, int size);

// �������� ���� ������ 
double** summation_matrixs(double** matr1, double** matr2, int size);

// ����������� � ������� ����� 
double** summation_matrix_num(double** matr, int size, double num);

// ��������� ������� �� �����
double** multiply_matrix_num(double** matr, int size, double num);

// ��������� 2� ������
double** multiply_matrixs(double** matr1, double** matr2, int size);

// ���������� f(x)^2 , ��� f(x) = x^3-6x^2-5x+10 (����� ������� ����)
double** main_func(double** matrix, int size);

// ���������� �������� ������� ��������� 2X + Y = C1  �  X - 2Y = C2
void main_func(double** C1, double** C2);

#endif // MATRIX_H