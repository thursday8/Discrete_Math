#include "Natural numbers with zero.h"
#include <iostream>
using namespace std;

//N-1 автор: Валерия Веревина
/*
    сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе

    принимает на вход 2 натуральных числа
*/
const int COM_NN_D(const unsigned long int& n, const unsigned long int& m) {
    return n > m ? 2 : m > n ? 1 : 0;
}

//N-2 автор: Анастасия Данченкова
/*
    Проверка на ноль: если число не равно нулю, то «да» иначе «нет»

    принимает на вход натуральное число
*/
void NZER_N_B(const unsigned long int& n) {
    cout << (n != 0 ? "Да" : "Нет") << endl;
}

//N-3 автор: Юлия Веселкова
/*
    добавление 1 к натуральному числу

    принимает на вход натурально число
*/
const unsigned long int ADD_1N_N(const unsigned long int& n) {
    return n + 1;
}

//N-4 автор: Валерия Веревина
/*
    сложение натуральных чисел

    принимает на вход 2 натуральных числа
*/
const unsigned long int ADD_NN_N(const unsigned long int& n, const unsigned long int& m) {
    return n + m;
}

//N-5 автор: Анастасия Данченкова
/*
    вычитание из первого большего натурального числа второго меньшего или равного
    использует COM_NN_D

    принимает на вход 2 натуральных числа
*/
const unsigned long int SUB_NN_N(const unsigned long int& n, const unsigned long int& m) {
    return COM_NN_D(n, m) == 2 ? n - m : COM_NN_D(n, m) == 1 ? m - n : 0;
}

//N-6 автор: Юлия Веселкова
/*
    Умножение натурального числа на цифру

    приниает на вход натуральное число и цифру
*/
const long int MUL_ND_N(const unsigned long int& n, const long int& m) {
    return n * m;
}

//N-7 автор: Валерия Веревина
/*
    умножение натурального числа на 10^k

    принимает на вход натурально число и степень в которую оно будет возведено
*/
const unsigned long int MUL_Nk_N(const unsigned long int& n, const unsigned int& k) {
    return n * pow(10, k);
}

//N-8 автор: Анастасия Данченкова
/*
    Умножение натуральных чисел

    принимает на вход 2 натуральных числа
*/
const unsigned long int MUL_NN_N(unsigned long int n, unsigned long int m) {
    if (n == 0 || m == 0) return 0;
    int digit = 0;
    unsigned long int number1 = n < m ? n : m, number2 = n > m ? n : m, composition = 0;
    while (number1 > 0) {
        ++digit;
        number1 /= 10;
    }
    number1 = n < m ? n : m;

    for (int i = digit - 1; i >= 0; --i) {
        composition = ADD_NN_N(composition, MUL_ND_N(number2, number1 / MUL_Nk_N(1, i) * MUL_Nk_N(1, i)));
        number1 %= MUL_Nk_N(1, i);
    }

    return composition;
}

//N-9 автор: Юлия Веселкова
/*
    вычитание из натурального другого натурального, умноженного на цифру для случая
    с неотрицательным результатом
    в случае, если результат выполнения отрицаелен, возвращает -1

    принимает на вход:
        1. натуральное число из которого вычитаем
        2. натуральное число которое вычитаем
        3. коэффициент для второго натурального  числа с любым знаком
*/
const long int SUB_NDN_N(const unsigned long int& n, const unsigned long int& m, const long int& k) {
    if (k > 0 && 1 == COM_NN_D(n, MUL_ND_N(m, k))) return -1;
    return k > 0 ? SUB_NN_N(n, MUL_ND_N(m, k)) : k < 0 ? ADD_NN_N(n, MUL_ND_N(m, -k)) : 0;
}

//N-10 автор: Валерия Веревина
/*
    Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k,
    где k - номер позиции этой цифры (номер считается с нуля)

    на вход принимаются 2 натуральных числа и положительную степень
*/
const unsigned long int DIV_NN_Dk(unsigned long int& n, unsigned long int& m, unsigned int& k) {
    unsigned long int d = 10;
    d = n > m ? n / MUL_Nk_N(m, k) : m / MUL_Nk_N(n, k);
    while (d > 9) d = d / 10;
    return d;
}

//автор: Юлия Веселкова
/*
    Остаток от деления большего натурального числа на меньшее или равное натуральное с 
    остатком(делитель отличен от нуля)
    определяет какое число больше и находит остаток от деления этого числа на меньше натуральное число

    принимает на вход 2 натуральных числа
*/
const unsigned long int  MOD_NN_N(const unsigned long int& n, const unsigned long int& m) {
    return n > m ? n % m : m % n;
}

//автор: Юлия Веселкова
/*
    НОК двух натуральных чисел

    принимает на вход 2 натуральных числа
*/
const unsigned long int  LCM_NN_N(const unsigned long int& n, const unsigned long int& m) {
    return 0;
    //return n * m / nod(n, m);
}