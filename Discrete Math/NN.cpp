#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

constexpr unsigned char Enter = 13, Backspace = 8, Esc = 27, Delete = 83, Up = 72, Down = 80, Left = 75, Right = 77;
char ch;

/*
	ñòðóêòóðà äàííûõ
	n - íîìåð ìëàäøåé ïîçèöèè ïîçèöèè
	a - ìàññèâ ñèìâîëîâ ñ ÷èëîì
*/
struct NN {
	int n = 0;
	vector<char> a = { '0' };
};

//àâòîð: Äàíèë Ëàìîâ
/*
	ñ÷èòûâàíèå íàòóðàëüíîãî ÷èñëà

	âîçâðùàåò ïðî÷èòàííîå íàòóðàëüíîå ÷èñëî
*/
NN* readNN() {
	NN* num = new NN();
	do {
		cout << "Âàøå ÷èñëî: ";
		for (int i = num->a.size() - 1; i >= 0; --i) cout << num->a[i];
		cout << endl << "Êîëè÷åñòâî ñèìâîëîâ: " << num->n << endl;

		ch = _getch();

		//äîáàâëåíèå öèôðû â ÷èñëo
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

		//óäàëåíèå öèôðû èç ÷èñëà
		if (ch == Backspace && num->n > 0) {
			if (num->n == 1) num->a[0] = '0';
			else num->a.erase(num->a.cbegin());
			--num->n;
		}

		system("cls");
	} while (ch != Enter && ch != Esc);
	return num;
}

//àâòîð: Äàíèë Ëàìîâ
/*
	âûâîäèò íàòóðàëüíîãî ÷èñëî íà ýêðàí
*/
void printNN(NN* n){
	cout << "Âàøå ÷èñëî: ";
	for (int i = n->a.size() - 1; i >= 0; --i) cout << n->a[i];
	cout << endl << "Êîëè÷åñòâî ñèìâîëîâ: " << n->n << endl;
}

//àâòîð: Äàíèë Ëàìîâ
/*
	óäàëåíèå íàòóðàëüíîãî ÷èñëà èç äèíàìè÷åñêîé ïàìÿòè
*/
NN* delNN(NN* n) {
	n->a.clear();
	delete n;
	return nullptr;
}

//N-1 àâòîð: Âàëåðèÿ Âåðåâèíà
/*
    ñðàâíåíèå íàòóðàëüíûõ ÷èñåë: 2 - åñëè ïåðâîå áîëüøå âòîðîãî, 0, åñëè ðàâíî, 1 èíà÷å

    ïðèíèìàåò íà âõîä 2 íàòóðàëüíûõ ÷èñëà
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

//N-2 àâòîð: Àíàñòàñèÿ Äàí÷åíêîâà
/*
	Ïðîâåðêà íà íîëü: åñëè ÷èñëî íå ðàâíî íóëþ, òî «äà» èíà÷å «íåò»

	ïðèíèìàåò íà âõîä íàòóðàëüíîå ÷èñëî
*/
void NZER_N_B(NN* n) {
	cout << (n->n != 0 ? "Äà" : "Íåò") << endl;
}

//N-3 àâòîð: Þëèÿ Âåñåëêîâà
/*
	äîáàâëåíèå 1 ê íàòóðàëüíîìó ÷èñëó

	ïðèíèìàåò íà âõîä íàòóðàëüíî ÷èñëî
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

//N-4 àâòîð: Âàëåðèÿ Âåðåâèíà
/*
	ñëîæåíèå íàòóðàëüíûõ ÷èñåë
	ïðè ñîçäàíèè èñïîëüçîâàëàñü ôóíêöèÿ COM_NN_D

	ïðèíèìàåò íà âõîä 2 íàòóðàëüíûõ ÷èñëà
*/
NN* ADD_NN_N(NN* n, NN* m) {
	NN* res = new NN();
	res->a.erase(res->a.begin());
	for (int i = 0; i < (COM_NN_D(n, m) == 2 ? n->n : m->n); ++i) {
		//åñëè ñóùåñòâóþò ðàçðÿäû ó âñåõ 3 ýëåìåíòîâ
		if (n->n > i && m->n > i && res->n > i)
			//åñëè ñóììà âññåõ ðàçðÿäîâ ìåíüøå 10
			if (n->a[i] + m->a[i] + res->a[i] - 3 * '0' < 10) res->a[i] += n->a[i] + m->a[i] - 2 * '0';
			else {
				++res->n;
				res->a[i] = res->a[i] + n->a[i] + m->a[i] - 2 * '0' - 10;
				res->a.push_back('1');
			}
		//åñëè ñóùåñòâóþò ðàçðÿäû òîëüêî ó ñëîãàåìûõ
		else if (n->n > i && m->n > i) 
			//åñëè ñóììà ðàçðÿäîâ ñëîãàåìûõ ìåíüøå 10
			if (n->a[i] + m->a[i] - 2 * '0' < 10) {
				++res->n;
				res->a.push_back(n->a[i] + m->a[i] - '0');
			}
			else {
				res->n += 2;
				res->a.push_back(n->a[i] + m->a[i] - '9' - 1);
				res->a.push_back('1');
			}
		//åñëè ñóùåñòâóþò ðàçðÿäû ó îäíîãî èç äâóõ ñëîãàåìûõ
		else
			//åñëè ñóùåñòâóåò ðàçðÿä ðåçóëüòàòà
			if (res->n > i)
				//åñëè ñóììà ðàçðÿäîâ ìåíüøå 10
				if (res->a[i] + (n->n > m->n ? n->a[i] : m->a[i]) - 2 * '0' < 10) res->a[i] += (n->n > m->n ? n->a[i] : m->a[i]) - '0';
				else {
					++res->n;
					res->a[i] += (n->n > m->n ? n->a[i] : m->a[i]) - '0' - 10;
					res->a.push_back('1');
				}
			else {
				++res->n;
				res->a.push_back(n->n > m->n ? n->a[i] : m->a[i]);
			}
	}

	if (res->a.size() == 0) res->a.push_back('0');

	return res;
}

//N-5 àâòîð: Àíàñòàñèÿ Äàí÷åíêîâà
/*
	âû÷èòàíèå èç ïåðâîãî áîëüøåãî íàòóðàëüíîãî ÷èñëà âòîðîãî ìåíüøåãî èëè ðàâíîãî
	èñïîëüçóåò COM_NN_D

	ïðèíèìàåò íà âõîä 2 íàòóðàëüíûõ ÷èñëà
*/
NN* SUB_NN_N(NN* n, NN* m) {
	NN* res = new NN();
	if (COM_NN_D(n, m) == 0) return res;

	res->a.erase(res->a.begin());
	bool swap = false;
	if (COM_NN_D(n, m) == 1) {
		NN* temp = n;
		n = m;
		m = temp;
		swap = true;
	}

	for (int i = 0; i < n->n; ++i) {
		//åñëè ñóùåñòâóþò ðàçðÿäû âû÷èòàåìîãî
		if (m->n > i) {
			//åñëè ñóùåñòâóþò ðàçðÿäû â îòâåòå
			if (res->n > i) {
				//åñëè çíà÷åíèå ðàçðÿä óìåíüøàåìîãî áîëüøå çíà÷åíèÿ ðàçðÿäà âû÷èòàåìîãî
				if (n->a[i] > m->a[i]) {
					res->a[i] += n->a[i] - m->a[i] + '0';
				}
				//åñëè çíà÷åíèå ðàçðÿä óìåíüøàåìîãî ìåíüøå èëè ðàâíî çíà÷åíèÿ ðàçðÿäà âû÷èòàåìîãî
				else {
					res->a[i] += n->a[i] + 10 - m->a[i] + '0';
					//çàíèìàåì
					int ind = i;
					do {
						//åñëè ñóùåñòâóþò ðàçðÿäû â îòâåòå
						if (res->n > ind) {
							--res->a[i];
						}
						//åñëè â îòâåòå íåò ðàçðÿäîâ
						else {
							++res->n;
							res->a.push_back(-1);
						}
					} while (n->a[++ind] == '0');
				}
			}
			//åñëè ðàçðÿäîâ â îòâåòå íåò
			else {
				//åñëè çíà÷åíèå ðàçðÿä óìåíüøàåìîãî áîëüøå èëè ðàâíî çíà÷åíèÿ ðàçðÿäà âû÷èòàåìîãî
				if (n->a[i] >= m->a[i]) {
					++res->n;
					res->a.push_back(n->a[i] - m->a[i] + '0');
				}
				//åñëè çíà÷åíèå ðàçðÿä óìåíüøàåìîãî ìåíüøå çíà÷åíèÿ ðàçðÿäà âû÷èòàåìîãî
				else {
					++res->n;
					res->a.push_back(n->a[i] + 10 - m->a[i] + '0');
					//àëãîðèòì çàíèìàíèÿ
					int ind = i;
					do {
						++res->n;
						res->a.push_back(-1);
					} while (n->a[++ind] == '0');
				}
			}
		}
		//åñëè ðàçðÿäîâ âû÷èòàåìîãî íå ñóùåñòâóåò 
		else {
			//åñëè ñóùåñòâóþò ðàçðÿäû â îòâåòå
			if (res->n > i) {
				res->a[i] = '9' + 1 + res->a[i] + n->a[i] -'0';
				if (res->a[i] == '9' + 1) res->a[i] = '0';
			}
			//åñëè ðàçðÿäîâ â îòâåòå íå ñóùåñòâóåò
			else {
				++res->n;
				res->a.push_back(n->a[i]);
			}
		}
	}

	//óäàëåíèå íîëåé ñïåðåäè ÷èñëà
	while (res->a[res->n - 1] == '0') {
		--res->n;
		res->a.erase(res->a.end() - 1);
	}

	if (swap) {
		NN* temp = n;
		n = m;
		m = temp;
	}

	return res;
}

//N-6 àâòîð: Þëèÿ Âåñåëêîâà
/*
	Óìíîæåíèå íàòóðàëüíîãî ÷èñëà íà öèôðó

	ïðèíèìàåò íà âõîä íàòóðàëüíîå ÷èñëî è öèôðó
*/
NN* MUL_ND_N(NN* n, const char& num) {
	NN* res = new NN;
	if (n->n == 0 || num == '0') return res;
	res->a.erase(res->a.begin());

	for (int i = 0; i < n->n; ++i) {
		//åñëè ðàçðÿä îòâåòà ñóùåñòâóåò
		if (res->n > i) {
			//åñëè ïðîèçâåäåíèå ìåíüøå 8
			if ((n->a[i] - '0') * (num - '0') < 8) {
				res->a[i] += (n->a[i] - '0') * (num - '0') + '0';
			}
			//åñëè ïðîèçâåäåíèå áîëüøå 8
			else {
				++res->n;
				res->a.push_back(((n->a[i] - '0') * (num - '0') + res->a[i]) / 10);
				res->a[i] = ((n->a[i] - '0') * (num - '0') + res->a[i]) % 10 + '0';
			}
		}
		//åñëè ðàçðÿä îòâåòà íå ñóùåñòâóåò
		else {
			//åñëè ïðîèçâåäåíèå ìåíüøå 10
			if ((n->a[i] - '0') * (num - '0') < 10) {
				++res->n;
				res->a.push_back((n->a[i] - '0') * (num - '0') + '0');
			}
			//åñëè ïðîèçâåäåíèå áîëüøå 10
			else {
				res->n += 2;
				res->a.push_back((n->a[i] - '0') * (num - '0') % 10 + '0');
				res->a.push_back((n->a[i] - '0') * (num - '0') / 10);
			}
		}
	}

	if (res->a[res->n - 1] < '0') res->a[res->n - 1] += '0';

	return res;
}

//N-7 àâòîð: Âàëåðèÿ Âåðåâèíà
/*
	óìíîæåíèå íàòóðàëüíîãî ÷èñëà íà 10^k

	ïðèíèìàåò íà âõîä íàòóðàëüíî ÷èñëî è ñòåïåíü â êîòîðóþ îíî áóäåò âîçâåäåíî
*/
NN* MUL_Nk_N(NN* n, const unsigned int& k) {
	NN* res = new NN();
	if (n->n == 0) return res;
	res->a.erase(res->a.begin());
	res->n = n->n + k;
	for (int i = 0; i < n->n; ++i) res->a.push_back(n->a[i]);
	for (int i = 0; i < k; ++i) res->a.emplace(res->a.cbegin(), '0');
	return res;
}

//N-9 автор: Юлия Веселкова
/*
    вычитание из натурального другого натурального, умноженного на цифру для случая
    с неотрицательным результатом
    в случае, если результат выполнения отрицаелен, возвращает -1
    принимает на вход:
        1. натуральное число из которого вычитаем
        2. натуральное число которое вычитаем
        3. коэффициент для второго натурального  числа
*/

NN* SUB_NDN_N (NN* n, NN* m, const unsigned int& k) {
	NN* res = new NN(), *m2 = newNN();
	int proverka;
	m2= MUL_ND_N (m, k);
	proverka =COM_NN_D (n, m2);
	if (proverka==2 || proverka ==1) res=SUB_NN_N (n, m2);
	else res={0}; //т.к. по условию функция не должна уйти в минус; можно заменить на 'ошибка' или что-то вроде того
	return res;
}


