#ifndef _MATRIX_
#define _MATRIX_

void readf_matrix(int &size, double matrix[SIZE][SIZE]);

//�������� ������� �� ����� (�� ������ �������� �������)
void multiplication_by_number(const int size, const double factor, double matrix[SIZE][SIZE], double result_matrix[SIZE][SIZE]);

void copy_matrix(const int size, double matrix[SIZE][SIZE], double result_matrix[SIZE][SIZE]);

//������� �� ������ ������� ������������ ���� ������
void multiplication_of_two_matrix(const int size, double matrix_1[SIZE][SIZE], double matrix_2[SIZE][SIZE], double result_matrix[SIZE][SIZE]);

//���������� ����� ���� ������
void calc_sum_two_matrix(const int size, double matrix_1[SIZE][SIZE], double matrix_2[SIZE][SIZE], double result_matrix[SIZE][SIZE]);

//���������� ����� ������� ������� �� i-��� j-��� �������� 
void make_minor(const int size, double matrix[SIZE][SIZE], const int str, const int col, double result_matrix[SIZE][SIZE]);

//��������� ������������ ���������� �������
double calc_determ(const int size, double matrix[SIZE][SIZE]);

//��������� �������� ������� (��������� ���������� ������������ �� 0 ��� ������)
bool calc_inverse_matrix(const int size, double matrix[SIZE][SIZE], double result_matrix[SIZE][SIZE]);

//����� �������
void output_matrix(const int n, double matrix[SIZE][SIZE]);

//������ � ����� inputL.txt ����� �������
void create_L_matrix(const double numbers[]);

//������ � ����� inputR.txt ������ �������
void create_R_matrix(const double numbers[]);

//��������� ���������� ���������� ���������
bool eqils_check(const double numbers[], double (left_matrix)[3][3], double (right_matrix)[3][3]);

//������ ��������� ��������� ���� XAB - XC = 2C
void solve_matrix_equation(const int size_A, const int size_B, const int size_C, double matrix_A[SIZE][SIZE], double matrix_B[SIZE][SIZE], double matrix_C[SIZE][SIZE]);

#endif //_MATRIX_