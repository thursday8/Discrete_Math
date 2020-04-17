#include <iostream>
#include <vector>
#include "NN.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	cout << "Discrete Math" << endl;
	NN* a = readNN();
	printNN(a);
	printNN(MUL_Nk_N(a, 20));

	return 0;
}