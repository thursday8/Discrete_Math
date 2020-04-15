#include <iostream>
#include <conio.h>
#include <vector>
//#include "NN.h"
using namespace std;

constexpr unsigned char Enter = 13, Backspace = 8, Esc = 27, Delete = 83, Up = 72, Down = 80, Left = 75, Right = 77;
char ch;

/*
	структура данных
	n - номер младшей позиции позиции
	a - массив символов с чилом
*/
struct NN{
	int n = 0;
	vector<char> a = { '0' };
};

//считывает натуральное число
NN* readNN() {
	NN* num = new NN();
	do{
		cout << "Ваше число: ";
		for (int i = num->a.size() - 1; i >= 0; --i) cout << num->a[i];
		cout << endl << "Количество символов: " << num->n << endl;

		ch = _getch();

		//добавление цифры в числo
		if (ch >= '0' && ch <= '9') {
			if (num->n == 0) num->a[0] = ch;
			else num->a.emplace(num->a.cbegin(), ch);
			++num->n;
		}

		//удаление цифры из числа
		if (ch == Backspace && num->n > 0) {
			if (num->n == 1) num->a[0] = '0';
			else num->a.erase(num->a.cbegin());
			--num->n;
		}

		system("cls");
	} while(ch != Enter && ch != Esc);
	return num;
}

int main() {
	setlocale(LC_ALL, "ru");
	cout << "Discrete Math" << endl;
	//readNN();
	return 0;
}