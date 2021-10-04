#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;
vector <int> mass;
vector <int> X{ 1, 5, 9, 11, -6, -3 };
vector <int> Y{ 1, -12, 0, 5, -6, 2 };
vector<vector <int>> matrix;
bool AutoOut = false;

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
	cout << endl;
	cout << endl;
	for (int i = 0; i < mass.size(); i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
}

void MatrixCustomInit() {
	cout << "Введите количество столбцов (N) и количество строк (M)" << endl;
	int N, M, x;
	vector <int> C;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> x;
			matrix[i].push_back(x);
		}
		matrix.push_back(C);
	}
}

void MatrixBaseInit() {
	vector <int> C;
	C.push_back(13);
	C.push_back(14);
	C.push_back(15);
	C.push_back(16);
	matrix.push_back(C);
	C.clear();

	C.push_back(9);
	C.push_back(10);
	C.push_back(11);
	C.push_back(12);
	matrix.push_back(C);
	C.clear();


	C.push_back(5);
	C.push_back(6);
	C.push_back(7);
	C.push_back(8);
	matrix.push_back(C);
	C.clear();

	C.push_back(1);
	C.push_back(2);
	C.push_back(3);
	C.push_back(4);
	matrix.push_back(C);
}

void MatrixOutput() {
	cout << endl;
	cout << endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void MatrixRotate() {
	vector<vector <int>> temp_matrix;
	vector <int> line;
	for (int i = 0; i < matrix[0].size(); ++i) {
		for (int j = 0; j < matrix.size(); ++j) {
			line.push_back(matrix[j][i]);
		}
		temp_matrix.push_back(line);
		line.clear();
	}
	matrix = temp_matrix;
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
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		X.push_back(x);
		Y.push_back(y);
	}
}


// 23 Лаба

char Lab23_First()
{
	char x;
	cout << " Введи один любой символ, который поддерживается ASCII" << endl;
	cin >> x;
	cout << char(int(x) - 1) << " " << char(int(x) + 1);
	return ' ';
}

char Lab23_Second()
{
	string x;
	cout << " Введи строку" << endl;
	cin >> x;
	for (int i = 0; i < x.size(); ++i) {
		x.insert(x.begin() + i + 1, ' ');
		++i;
	}
	cout << x;
	return ' ';
}

int Lab23_Third()
{
	string x;
	int z = 0;
	cout << " Введи строку" << endl;
	cin >> x;
	for (int i = 0; i < x.size(); ++i) {
		if (x[i] <= 90 && x[i] >= 65) ++z;
	}
	return z;
}

char Lab23_Fourth()
{
	cout << " Введи строку" << endl;
	string x = "abbbctr";
	cin >> x;
	char z = 0;
	cout << " Введи символ" << endl;
	cin >> z;
	for (int i = 0; i < x.size(); ++i) {
		if (x[i] == z) { x.insert(x.begin() + i + 1, z); i++; }
	}
	cout << x;
	return ' ';
}

char Lab23_Fifth()
{
	cout << " Введи строку S" << endl;
	string x = "abbbctr";
	cin >> x;
	cout << endl << " Введи строку S0" << endl;
	string z = "bb";
	cin >> z;
	int cou = 0;
	for (int i = 0; i < x.size(); ++i) {
		bool flag = true;
		if (x[i] == z[0]) {
			for (int j = 1; j < z.size(); j++) {
				if (x[i + j] != z[j]) flag = false;
			}
			if (flag) cou++;
		}
	}
	cout << cou;
	return ' ';
}

void Menu() {
	int c;
	system("cls");
	cout << "Введи цифру от 1 до 5";
	cin >> c;
	if (AutoOut) {
		cout << endl <<"Далее выводится матрица до обработки" << endl;
		MatrixOutput();
	}
	if (c == 1) cout << Lab23_First();
	else if (c == 2) cout << Lab23_Second();
	else if (c == 3) cout << Lab23_Third();
	else if (c == 4) cout << Lab23_Fourth();
	else if (c == 5) cout << Lab23_Fifth();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int c;
	Menu();
	while (true) {
		cout << endl << endl << "Коли хочешь поменять вопрос - пиши 1" << endl << "Надоело - пиши 2" << endl;
		cin >> c;
		if (c == 1) Menu();
		else if (c == 2) exit(0);

	}
	return 0;
}
