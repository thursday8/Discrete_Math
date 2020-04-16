#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

constexpr unsigned char Enter = 13, Backspace = 8, Esc = 27, Delete = 83, Up = 72, Down = 80, Left = 75, Right = 77;
char ch;

/*
	структура данных
	n - номер младшей позиции позиции
	a - массив символов с чилом
*/
struct NN {
	int n = 0;
	vector<char> a = { '0' };
};

//автор: Данил Ламов
/*
	считывание натурального числа

	возврщает прочитаанное натуральное число
*/
NN* readNN() {
	NN* num = new NN();
	do {
		cout << "Ваше число: ";
		for (int i = num->a.size() - 1; i >= 0; --i) cout << num->a[i];
		cout << endl << "Количество символов: " << num->n << endl;

		ch = _getch();

		//добавление цифры в числo
		if (ch >= '0' && ch <= '9') {
			if (num->n == 0 && ch != '0') {
				num->a[0] = ch;
				++num->n;
			}
			else if (num->n != 0){
				num->a.emplace(num->a.cbegin(), ch);
				++num->n;
			}
		}

		//удаление цифры из числа
		if (ch == Backspace && num->n > 0) {
			if (num->n == 1) num->a[0] = '0';
			else num->a.erase(num->a.cbegin());
			--num->n;
		}

		system("cls");
	} while (ch != Enter && ch != Esc);
	return num;
}

//автор: Данил Ламов
/*
	выводит натурального число на экран
*/
void printNN(NN* n){
	cout << "Ваше число: ";
	for (int i = n->a.size() - 1; i >= 0; --i) cout << n->a[i];
	cout << endl;
}

//N-1 автор: Валерия Веревина
/*
    сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе

    принимает на вход 2 натуральных числа
*/
int COM_NN_D(NN* n, NN* m) {
	if (n->a.size() > m->a.size()) return 2;
	else if (n->a.size() < m->a.size()) return 1;

	for (int i = n->a.size() - 1; i > 0; --i) {
		if (n->a[i] > m->a[i]) return 2;
		else if (n->a[i] < m->a[i]) return 1;
	}

	return 0;
}

//N-2 автор: Анастасия Данченкова
/*
	Проверка на ноль: если число не равно нулю, то «да» иначе «нет»

	принимает на вход натуральное число
*/
void NZER_N_B(NN* n) {
	cout << (n->n != 0 ? "Да" : "Нет") << endl;
}

//N-3 автор: Юлия Веселкова
/*
	добавление 1 к натуральному числу

	принимает на вход натурально число
*/
NN* ADD_1N_N(NN* n) {
	for (int i = 0; i < n->a.size(); ++i)
		if (n->a[i] < '9') {
			++n->a[i];
			break;
		}
		else {
			n->a[i] = '0';
			if (i < n->a.size() - 1) {
				++n->a[i + 1];
				if (n->a[i + 1] < '9') break;
			}
			else {
				n->a.push_back('1');
				++n->n;
			}
		}

	return n;
}


//N-6 автор: Юлия Веселкова
/*
    Умножение натурального числа на цифру
    
    принимает на вход натуральное число и цифру
*/
NN* MUL_ND_N(NN* n, int numeral) {
    int perenos1=0, perenos2=0;
    for (int i=0; i<n->a.size(); ++i)
    {
            perenos2=n->a[i]*numeral/10;
	    n->a[i] = (n->a[i]*numeral)%10+perenos1;
	    perenos1=perenos2;
    }
    if (perenos1!=0)n->a.emplace_back(perenos1);
    return n;
}

