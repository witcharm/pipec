#ifndef MATRIXS_H
#define MATRIXS_H

// �������� �������� ������
void checking(int x);

// ���������� ������� ���������� �������
void filling_matrix(int(*matr)[100], int size);

// �������� ���� ������ (��������� ����� ��������� � matr1)
void summation_matrix(int(*matr1)[100], int(*matr2)[100], int size);

// ����������� � ������� ����� (��������� ����� ��������� � matr1)
void summation_num(int(*matr)[100], int size, int num);

// ��������� ������� �� �����
void multiply_matrix(int(*matr)[100], int size, int num);

// ����������� �������
void copy_matrix(int(*matr)[100], int(*matr_copy)[100], int size);

// ���������� ������� � ������� (������ 2 ��� 3)
void raise2degree_matrix(int(*matr)[100], int size, int degree);

// ����� ������� �� �����
void output(int(*matr)[100], int size);

#endif // MATRIXS_H