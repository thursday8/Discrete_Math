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
	if (n != nullptr) {
		cout << "Âàøå ÷èñëî: ";
		for (int i = n->a.size() - 1; i >= 0; --i) cout << n->a[i];
		cout << endl << "Êîëè÷åñòâî ñèìâîëîâ: " << n->n << endl;
	}
	else cout << "×èñëà íå ñóùåñòâóåò" << endl;
}

//àâòîð: Äàíèë Ëàìîâ
/*
	óäàëåíèå íàòóðàëüíîãî ÷èñëà èç äèíàìè÷åñêîé ïàìÿòè
*/
NN* delNN(NN* n) {
	if (n != nullptr) {
		n->a.clear();
		delete n;
		return nullptr;
	}
	else cout << "×èñëà íå ñóùåñòâóåò." << endl;
}

//N-1 àâòîð: Âàëåðèÿ Âåðåâèíà
/*
    ñðàâíåíèå íàòóðàëüíûõ ÷èñåë: 2 - åñëè ïåðâîå áîëüøå âòîðîãî, 0, åñëè ðàâíî, 1 èíà÷å

    ïðèíèìàåò íà âõîä 2 íàòóðàëüíûõ ÷èñëà
*/
int COM_NN_D(NN* n, NN* m) {
	if (n->a.size() > m->a.size()) return 2;
	else if (n->a.size() < m->a.size()) return 1;

	for (int i = n->a.size() - 1; i >= 0; --i) {
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
	èñïîëüçóåò COM_NN_D - ñðàâíåíèå íàòóðàëüíûõ ÷èñåë: 2 - åñëè ïåðâîå áîëüøå âòîðîãî, 0, åñëè ðàâíî, 1 èíà÷å

	ïðèíèìàåò íà âõîä 2 íàòóðàëüíûõ ÷èñëà
*/
NN* SUB_NN_N(NN* n, NN* m) {
	NN* res = new NN();
	if (COM_NN_D(n, m) == 0) return res;
	if (COM_NN_D(n, m) == 1) return nullptr;

	res->a.erase(res->a.begin());

	/*
	bool swap = false;
	if (COM_NN_D(n, m) == 1) {
		NN* temp = n;
		n = m;
		m = temp;
		swap = true;
	}
	*/

	for (int i = 0; i < n->n; ++i) {
		//åñëè ñóùåñòâóþò ðàçðÿäû âû÷èòàåìîãî
		if (m->n > i) {
			//åñëè ñóùåñòâóþò ðàçðÿäû â îòâåòå
			if (res->n > i) {
				//åñëè çíà÷åíèå ðàçðÿä óìåíüøàåìîãî áîëüøå èëè ðàâíî çíà÷åíèÿ ðàçðÿäà âû÷èòàåìîãî
				if (n->a[i] + (n->a[i] == '0' ? 10 : 0) + res->a[i] >= m->a[i]) {
					//res->a[i] += n->a[i] - m->a[i] + '0';
					res->a[i] += n->a[i] + '9' + 1 - m->a[i];
					if (res->a[i] > '9') res->a[i] -= 10;
				}
				//åñëè çíà÷åíèå ðàçðÿä óìåíüøàåìîãî ìåíüøå çíà÷åíèþ ðàçðÿäà âû÷èòàåìîãî
				else {
					res->a[i] += n->a[i] + 10 - m->a[i] + '0';
					//if (res->a[i] > '0') res->a[i] -= 10;
					//çàíèìàåì
					int ind = i + 1;
					if (n->n  > ind) {
						do {
							//åñëè ñóùåñòâóþò ðàçðÿäû â îòâåòå
							if (res->n > ind) {
								--res->a[ind];
							}
							//åñëè â îòâåòå íåò ðàçðÿäîâ
							else {
								++res->n;
								res->a.push_back(-1);
							}
						} while (n->n - 1 > ind && n->a[++ind] == '0');
					}
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
				//res->a[i] = '9' + 1 + res->a[i] + n->a[i] -'0';
				//res->a[i] += n->a[i];
				res->a[i] += n->a[i];
				if (res->a[i] < '0') res->a[i] += 10;
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

	/*
	if (swap) {
		NN* temp = n;
		n = m;
		m = temp;
	}
	*/

	return res;
}

//N-6 àâòîð: Þëèÿ Âåñåëêîâà
/*
	óìíîæåíèå íàòóðàëüíîãî ÷èñëà íà öèôðó

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

//N-8 àâòîð: Àíàñòàñèÿ Äàí÷åíêîâà
/*
	óìíîæåíèå íàòóðàëüíûõ ÷èñåë
	èñïîëüçóåìå ôóíêöèè: 
		MUL_ND_N - óìíîæåíèå íàòóðàëüíîãî ÷èñëà íà öèôðó
		MUL_Nk_N - óìíîæåíèå íàòóðàëüíîãî ÷èñëà íà 10^k
		ADD_NN_N - ñëîæåíèå íàòóðàëüíûõ ÷èñåë

	ïðèíèìàåò íà âõîä 2 íàòóðàëüíûõ ÷èñëà
*/
NN* MUL_NN_N(NN* n, NN* m) {
	NN* res = new NN();
	if (n->n == 0 || m->n == 0) return res;
	res->a.erase(res->a.begin());

	for (int i = 0; i < n->n; ++i) {
		//óìíîæåíèå íàòóðàëüíîãî ÷èñëà íà öèôðó
		NN* temp = MUL_ND_N(m, n->a[i]);
		//óìíîæåíèå íàòóðàëüíîãî ÷èñëà íà 10 ^ k
		NN* temp2 = MUL_Nk_N(temp, i);
		delNN(temp);
		//ñëîæåíèå íàòóðàëüíûõ ÷èñåë
		temp = ADD_NN_N(res, temp2);
		delNN(temp2);
		delNN(res);
		res = temp;
	}

	return res;
}

//N-9 àâòîð: Þëèÿ Âåñåëêîâà
/*
	âû÷èòàíèå èç íàòóðàëüíîãî äðóãîãî íàòóðàëüíîãî, óìíîæåííîãî íà öèôðó äëÿ ñëó÷àÿ
	ñ íåîòðèöàòåëüíûì ðåçóëüòàòîì
	â ñëó÷àå, åñëè ðåçóëüòàò âûïîëíåíèÿ îòðèöàåëåí, âîçâðàùàåò íóëåâîé óêàçàòåëü
	èñïîëüçóåìå ôóíêöèè:
		SUB_NN_N - âû÷èòàíèå èç ïåðâîãî áîëüøåãî íàòóðàëüíîãî ÷èñëà âòîðîãî ìåíüøåãî èëè ðàâíîãî
		MUL_ND_N - óìíîæåíèå íàòóðàëüíîãî ÷èñëà íà öèôðó
		COM_NN_D - ñðàâíåíèå íàòóðàëüíûõ ÷èñåë: 2 - åñëè ïåðâîå áîëüøå âòîðîãî, 0, åñëè ðàâíî, 1 èíà÷å

	ïðèíèìàåò íà âõîä:
		1. íàòóðàëüíîå ÷èñëî èç êîòîðîãî âû÷èòàåì
		2. íàòóðàëüíîå ÷èñëî êîòîðîå âû÷èòàåì
		3. êîýôôèöèåíò äëÿ âòîðîãî íàòóðàëüíîãî ÷èñëà
*/
NN* SUB_NDN_N(NN* n, NN* m, const char& k) {
	NN* res, * m2;
	m2 = MUL_ND_N(m, k);
	//åñëè ðåçóëüòàò âû÷èòàíèÿ íå îòðèöàòåëåí
	if (COM_NN_D(n, m2) != 1) {
		res = SUB_NN_N(n, m2);
		delNN(m2);
		return res;
	}
	return nullptr;
}

//N-10 àâòîð: Âàëåðèÿ Âåðåâèíà
/*
	âû÷èñëåíèå ïåðâîé öèôðû äåëåíèÿ áîëüøåãî íàòóðàëüíîãî íà ìåíüøåå, äîìíîæåííîå íà 10^k,
	ãäå k - íîìåð ïîçèöèè ýòîé öèôðû (íîìåð ñ÷èòàåòñÿ ñ íóëÿ)
	èñïîëüçóåìå ôóíêöèè:
		MUL_Nk_N - óìíîæåíèå íàòóðàëüíîãî ÷èñëà íà 10^k
		COM_NN_D - ñðàâíåíèå íàòóðàëüíûõ ÷èñåë: 2 - åñëè ïåðâîå áîëüøå âòîðîãî, 0, åñëè ðàâíî, 1 èíà÷å
		SUB_NN_N - âû÷èòàíèå èç ïåðâîãî áîëüøåãî íàòóðàëüíîãî ÷èñëà âòîðîãî ìåíüøåãî èëè ðàâíîãî

	íà âõîä ïðèíèìàþòñÿ 2 íàòóðàëüíûõ ÷èñëà è ïîëîæèòåëüíóþ ñòåïåíü
*/
NN* DIV_NN_Dk(NN* n, NN* m, const unsigned int& k) {
	NN* res = new NN();
	++res->n;

	/*
	bool swap = false;
	if (COM_NN_D(n, m) == 1) {
		swap = true;
		NN* temp = n;
		n = m;
		m = temp;
	}
	*/

	//àëãîðèòìà íàõîæäåíèÿ ïåðâîé öèôðû îò äåëåíèÿ
	bool ud = true;
	for (int i = 1; i < m->n + 1; ++i)
		if (n->a[n->n - i] < m->a[m->n - i]) {
			ud = false;
			break;
		}
		else if (n->a[n->n - i] > m->a[m->n - i]) {
			break;
		}

	NN* temp = new NN();
	temp->a.erase(temp->a.begin());
	//åñëè ÷èñëî ïîäõîäèò ïî êîëè÷åñòâó ñèìâîëîâ
	if (ud) {
		for (int i = 1; i < m->n + 1; ++i) {
			++temp->n;
			temp->a.emplace(temp->a.begin(), n->a[n->n - i]);
		}
	}
	//åñëè ÷èñëî íå ïîäõîäèò ïî êîëè÷åñòâó ñèìâîëîâ
	else {
		for (int i = 1; i < m->n + 2; ++i) {
			++temp->n;
			temp->a.emplace(temp->a.begin(), n->a[n->n - i]);
		}
	}

	do {
		++res->a[0];
		NN* temp2 = SUB_NN_N(temp, m);
		delNN(temp);
		temp = temp2;
	} while (COM_NN_D(temp, m) != 1);

	/*
	if (swap) {
		NN* temp = n;
		n = m;
		m = temp;
	}
	*/

	temp = MUL_Nk_N(res, k);
	delNN(res);
	res = temp;
	return res;
}

//N-11 àâòîð: Äàí÷åíêîâà Àíàñòàñèÿ
/*
	÷àñòíîå îò äåëåíèÿ áîëüøåãî íàòóðàëüíîãî ÷èñëà íà ìåíüøåå èëè ðàâíîå 
	íàòóðàëüíîå ñ îñòàòêîì(äåëèòåëü îòëè÷åí îò íóëÿ)
	èñïîëüçóåìå ôóíêöèè:
		DIV_NN_Dk - âû÷èñëåíèå ïåðâîé öèôðû äåëåíèÿ áîëüøåãî íàòóðàëüíîãî íà ìåíüøåå, äîìíîæåííîå íà 10^k
		SUB_NDN_N - âû÷èòàíèå èç íàòóðàëüíîãî äðóãîãî íàòóðàëüíîãî, óìíîæåííîãî íà öèôðó
		MUL_Nk_N - óìíîæåíèå íàòóðàëüíîãî ÷èñëà íà 10^k

	ïðèíèìàåò íà âõîä 2 íàòóðàëüíûõ  ÷èñëà
*/
NN* DIV_NN_N(NN* n, NN* m) {
	if (m->n == 0) return nullptr;
	//temp - êîïèÿ n
	NN* res = new NN(), * temp = new NN();
	temp->a.erase(temp->a.cbegin());
	temp->n = n->n;
	for (int i = 0; i < n->n; ++i)
		temp->a.push_back(n->a[i]);
	
	bool ud = true;
	for (int i = 1; i < m->n + 1; ++i)
		if (n->a[n->n - i] < m->a[m->n - i]) {
			ud = false;
			break;
		}
		else if (n->a[n->n - i] > m->a[m->n - i]) break;

	//àëãîðèòì íàõîæäåíèÿ äåëåíèÿ
	int ind = n->n - m->n - (ud ? 0 : 1);
	while (COM_NN_D(temp, m) != 1) {
		//íàõîæäåíèå ïåðâîé öèôðû îò äåëåíèÿ äîìíîæåííîé íà íåîáõëäèìûé èíäåêñ
		NN* temp2 = DIV_NN_Dk(temp, m, ind);
		//âíåñåíèå ñòåïåíè â îòâåò
		NN* temp3 = ADD_NN_N(res, temp2);
		delNN(res);
		res = temp3;
		//óìåíüøåíèå temp
		delNN(temp2);
		//óìíîæåíèå íàòóðàëüíîãî ÷èñëà íà 10^k
		temp2 = MUL_Nk_N(m, ind);
		//óìíîæåíèå íàòóðàëüíîãî ÷èñëà íà öèôðó è âû÷èòàíèå èç temp
		temp3 = SUB_NDN_N(temp, temp2, res->a[ind]);
		delNN(temp2);
		delNN(temp);
		temp = temp3;
		--ind;
	}

	return res;
}

//N-12 àâòîð: Þëèÿ Âåñåëêîâà
/*
	îñòàòîê îò äåëåíèÿ áîëüøåãî íàòóðàëüíîãî ÷èñëà íà ìåíüøåå èëè ðàâíîå íàòóðàëüíîå ñ
	îñòàòêîì(äåëèòåëü îòëè÷åí îò íóëÿ)
	èñïîëüçóåìûå ôóíêöèè:
		DIV_NN_N - ÷àñòíîå îò äåëåíèÿ áîëüøåãî íàòóðàëüíîãî ÷èñëà íà ìåíüøåå èëè ðàâíîå
		SUB_NN_N - âû÷èòàíèå èç ïåðâîãî áîëüøåãî íàòóðàëüíîãî ÷èñëà âòîðîãî ìåíüøåãî èëè ðàâíîãî
		MUL_NN_N - óìíîæåíèå íàòóðàëüíûõ ÷èñåë

	ïðèíèìàåò íà âõîä 2 íàòóðàëüíûõ ÷èñëà:
		n - äåëèìîå
		m - äåëèòåëü
*/
NN* MOD_NN_N(NN* n, NN* m) {
	//öåëàÿ ÷àñòü îò äåëåíèÿ 
	NN* temp = DIV_NN_N(n, m);
	//öåëàÿ ÷àñòü îò äåëåíèÿ * äåëèòåëü
	NN* temp2 = MUL_NN_N(temp, m);
	delNN(temp);
	NN* res = SUB_NN_N(n, temp2);
	delNN(temp2);
	return res;
}

//N-13

NN* GCF_NN_N(NN* n, NN* m)
{
  NN * nn = new NN (), *mm=new NN();
  nn=n;
  mm=m;
  while (nn->a[0]!=0 && mm->a[0]!=0 && nn->n>1 && mm->n>1 )
  {
	  if (COM_NN_D (nn, mm)==2) nn=MOD_NN_N(nn, mm);
	  else mm=MOD_NN_N(mm,nn);
  }
	return nn+mm;
}



