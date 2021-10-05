#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <windows.h>

using namespace std;
vector <int> mass;
vector <int> X{ 1, 5, 9, 11, -6, -3 };
vector <int> Y{ 1, -12, 0, 5, -6, 2 };

// Доп. Функции

void MassBaseInit() {
	mass.push_back(2);
	mass.push_back(2);
	mass.push_back(1);
	mass.push_back(9);
	mass.push_back(9);
	mass.push_back(9);
	mass.push_back(5);
	mass.push_back(12);
	mass.push_back(2);
}

void MassCustomInit() {
	int N, p;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p;
		mass.push_back(p);
	}
}

void MassOutput() {
	for (int i = 0; i < mass.size(); i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
}

int SrArif(int i) {
	int sum, j;
	sum = 0;
	j = 0;
	for (; j <= i; j++) {
		sum += mass[j];
	}
	return int(sum / j);
}

void PointCustomInit() {
	int N, x, y;
	X.clear();
	Y.clear();
	cout << "Please input count of point -";
	cin >> N;
	cout << "Please input coord of points" << endl;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		X.push_back(x);
		Y.push_back(y);
	}
}


// 20 Лаба

char Lab20_First()
{
	vector <int> C, B;
	int cou = 1;
	for (int i = 1; i <= mass.size(); i++) {
		if (mass.size() == i) {
			B.push_back(cou);
			cou = 1;
			C.push_back(mass[i - 1]);
		}
		else if (mass[i] == mass[i - 1]) {
			cou++;
		}
		else {
			B.push_back(cou);
			cou = 1;
			C.push_back(mass[i-1]);
		}
	}
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < C.size(); i++) {
		cout << C[i] << " ";
	}
	cout << endl;
	return ' ';
}

char Lab20_Second()
{
	cout << "Please input L -";
	int L = 2;
	cin >> L;
	int cou = 1;
	for (int i = 1; i < mass.size(); i++) {
		if (mass[i] == mass[i - 1]) {
			cou++;
		}
		else {
			if (cou > L) {

				int temp = mass[i - cou + 2];
				mass[i - cou + 2] = 0;
				for (int j = i - cou + 1; j < i; j++) {
					if (mass[j] == temp) {
						mass.erase(mass.begin() + j);
						j--;
					}
				}
				cou = 1;
			}
		}
	}
	MassOutput();
	return ' ';
}

char Lab20_Third()
{
	vector <int> C, B;
	cout << "Please input K -";
	int K = 2;
	cin >> K;
	cout << endl;
	int cou = 1;
	for (int i = 1; i <= mass.size(); i++) {
		if (mass.size() == i) {
			B.push_back(cou);
			cou = 1;
			C.push_back(mass[i - 1]);
		}
		else if (mass[i] == mass[i - 1]) {
			cou++;
		}
		else {
			B.push_back(cou);
			cou = 1;
			C.push_back(mass[i - 1]);
		}
	}
	vector <int> array;
	int temp = C[K - 1]; // Значение элементов серии K
	int ttemp = B[K - 1]; // Длина элементов серии K
	C[K - 1] = C[C.size() - 1];
	B[K - 1] = B[B.size() - 1];
	B[B.size() - 1] = ttemp;
	C[C.size() - 1] = temp;

	for (int i = 0; i < C.size();++i) {
		for (int j = 0; j < B[i]; ++j) {
			array.push_back(C[i]);
		}
	}
	
	mass = array;
	MassOutput();
	return ' ';
}

char Lab20_Fourth()
{
	int c = 0;
	cout << "if you want custom points - input 1. Else input 0";
	cin >> c;
	if (c == 1) {
		PointCustomInit();
	}
	mass.clear();
	for (int i = 0; i < X.size(); ++i) {
		mass.push_back(sqrt(X[i] * X[i] + Y[i] * Y[i]));
	}
	int f = distance(mass.begin(), max_element(mass.begin(), mass.end()));
	cout << X[f] << " " << Y[f];
	return ' ';
}

char Lab20_Fifth()
{
	vector<vector <int>> Perim;
	int c = 0;
	cout << "if you want custom points - input 1. Else input 0";
	cin >> c;
	if (c == 1) {
		PointCustomInit();
	}
	vector <int> u{ 0 };
	Perim.push_back(u);
	Perim.push_back(u);
	Perim.push_back(u);
	Perim.push_back(u);
	for (int i = 0; i < X.size(); ++i) {
		for (int j = i + 1; j < X.size(); ++j) {
			for (int g = j + 1; g < X.size(); ++g) {
				int a = (sqrt(pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2))); // Расстояние между 1 и 2
				int b = (sqrt(pow(X[g] - X[j], 2) + pow(Y[g] - Y[j], 2))); // Расстояние между 3 и 2
				int с = (sqrt(pow(X[i] - X[g], 2) + pow(Y[i] - Y[g], 2))); // Расстояние между 3 и 1
				Perim[0].push_back(a + b + с); // Периметр
				Perim[1].push_back(i); // Индекс точки 1
				Perim[2].push_back(j); // Индекс точки 2
				Perim[3].push_back(g); // Индекс точки 3
			}
		}
	}
	int f = distance(Perim[0].begin(), max_element(Perim[0].begin(), Perim[0].end())); // Нужный столбец
	int q = Perim[1][f]; // Индекс нужной точки 1
	int w = Perim[2][f]; // Индекс нужной точки 2
	int e = Perim[3][f]; // Индекс нужной точки 3
	cout << Perim[0][f] << endl;
	cout << X[q] << " " << Y[q] << endl;
	cout << X[w] << " " << Y[w] << endl;
	cout << X[e] << " " << Y[e] << endl;
	return ' ';
}
void Menu() {
	int c;
	cout << "Input number of question (1-5)";
	cin >> c;
	if (c == 1) cout << Lab20_First();
	else if (c == 2) cout << Lab20_Second();
	else if (c == 3) cout << Lab20_Third();
	else if (c == 4) cout << Lab20_Fourth();
	else if (c == 5) cout << Lab20_Fifth();
}

int main()
{
	int c, a;
	cout << "If you want custom array - write 1. else write 0" << endl;
	cin >> c;
	if (c == 1) MassCustomInit();
	else MassBaseInit();
	MassOutput();
	Menu();
	while (true) {
		cout << endl << endl << "If you want switch question - write 1" << endl << "If you want switch array and switch quesion - write 2" << endl << "If you want end this - write 3" << endl;
		cout << "If you want watch array - write 4" << endl << "Remember array can be changed after question" << endl;
		cin >> c;
		if (c == 1) Menu();
		else if (c == 2) {
			cout << "If you want custom array - write 1. else write 0" << endl;
			cin >> a;
			if (a == 0) MassBaseInit();
			if (a == 1) MassCustomInit();
			Menu();
		}
		else if (c == 3) exit(0);
		else if (c == 4) MassOutput();
	}


	return 0;
}
