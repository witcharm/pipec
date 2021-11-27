#ifndef _OPER_MAT_H_
#define _OPER_MAT_H_

//������� �-��
double** create_mat(int size);

//���������� �������� ��-��� �-��
double** input_mat(int& size);

//������� �-��
void output_mat(double** mat, int size);

//������� � �������� �-��
void clean_mat(double** mat, int size);

//����������� ����� �-�� �� ������
void copy_mat(double** mat_from, double** mat_to, int size);

//�������� ���������� � �������
void oper_power_mat(double** mat_1, double** mat_2, int size, int power, double** res);

//�������� ��������� �-��
double** create_identity_mat(int size);

//�������� ��������� �-�� �� �����
void oper_of_mat_multip_by_num(double** mat_1, double** mat_2, int size, int num);

//�������� ��������(���������)
void oper_addition_mat(double** mat_1, double** mat_2, int size);

//���������� ��������� � ������� ������������� �����������
void calculator(double** mat, int size);

#endif // _OPER_MAT_H_
