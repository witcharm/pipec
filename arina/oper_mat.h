#ifndef _OPER_MAT_H_
#define _OPER_MAT_H_

//создает м-цу
double** create_mat(int size);

//записываем значения эл-тов м-цы
double** input_mat(int& size);

//выводим м-цу
void output_mat(double** mat, int size);

//очистка и удаление м-цы
void clean_mat(double** mat, int size);

//копирование одной м-цы во вторую
void copy_mat(double** mat_from, double** mat_to, int size);

//операция возведения в степень
void oper_power_mat(double** mat_1, double** mat_2, int size, int power, double** res);

//создание единичной м-цы
double** create_identity_mat(int size);

//операция умножения м-цы на число
void oper_of_mat_multip_by_num(double** mat_1, double** mat_2, int size, int num);

//операция сложения(вычитания)
void oper_addition_mat(double** mat_1, double** mat_2, int size);

//вычисление выражения с выводом промежуточных результатов
void calculator(double** mat, int size);

#endif // _OPER_MAT_H_
