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


// 22 Лаба

char Lab22_First()
{
	for (int i = 0; i < matrix[0].size(); ++i) {
		iter_swap(max_element(matrix[i].begin(), matrix[i].end()), min_element(matrix[i].begin(), matrix[i].end()));
	}
	MatrixOutput();
	return ' ';
}

char Lab22_Second()
{
	vector <int> max;
	vector <int> min;
	MatrixRotate(); // Костыль
	for (int i = 0; i < matrix.size(); ++i) {
		int f = distance(matrix[i].begin(), max_element(matrix[i].begin(), matrix[i].end()));
		max.push_back(matrix[i][f]);
		f = distance(matrix[i].begin(), min_element(matrix[i].begin(), matrix[i].end()));
		min.push_back(matrix[i][f]);
	}
	int q = distance(max.begin(), max_element(max.begin(), max.end()));
	int k = distance(min.begin(), min_element(min.begin(), min.end()));
	swap_ranges(matrix[k].begin(), matrix[k].end(), matrix[q].begin());
	MatrixRotate();
	MatrixOutput();
	return ' ';
}

char Lab22_Third()
{
	int a, b;
	a = matrix.size() / 2;
	b = matrix[0].size() / 2;
	cout << endl;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			swap(matrix[i][j], matrix[i + a][j + b]);
		}
	}
	MatrixOutput();
	return ' ';
}

char Lab22_Fourth()
{
	cout << endl;
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix.size() - 1; ++j) {
			if (matrix[j][0] > matrix[j + 1][0]) {
				swap(matrix[j], matrix[j + 1]);
			}
		}
	}
	MatrixOutput();
	return ' ';
}

char Lab22_Fifth()
{
	cout << endl;
	mass.clear();
	int sum, k;
	for (int i = matrix.size() - 1; i >= 0; --i) {
		k = 0;
		sum = matrix[0][i];
		for (int j = i + 1; j < matrix.size(); ++j) {
			k++;
			sum += matrix[k][j];
		}
		mass.push_back(sum);
	}
	for (int i = 0; i < matrix.size() - 1; ++i) {
		k = -1;
		sum = 0;
		for (int j = i + 1; j < matrix.size(); ++j) {
			k++;
			if (k >= matrix.size()) break;
			sum += matrix[j][k];
		}
		mass.push_back(sum);
	}
	MassOutput();
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
	if (c == 1) cout << Lab22_First();
	else if (c == 2) cout << Lab22_Second();
	else if (c == 3) cout << Lab22_Third();
	else if (c == 4) cout << Lab22_Fourth();
	else if (c == 5) cout << Lab22_Fifth();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int c, a;
	cout << "Коли хочешь свой матрицу пиши 1. Иначе пиши все что хочешь" << endl;
	cin >> c;
	if (c == 1) MatrixCustomInit();
	else MatrixBaseInit();
	cout << "Коли хочешь видеть матрицу перед исполнением задания пиши 1. Иначе пиши все что хочешь" << endl;
	cin >> c;
	if (c == 1) AutoOut = true;
	Menu();
	while (true) {
		cout << endl << endl << "Коли хочешь поменять вопрос - пиши 1" << endl << "Коли хочешь поменять матрицу и вопрос - пиши 2" << endl << "Надоело - пиши 3" << endl;
		cout << "Увидеть ты желаешь матрицу - пиши 4" << endl << "Помни, что матрица может быть изменена после выполнения задания" << endl;
		cin >> c;
		if (c == 1) Menu();
		else if (c == 2) {

			cout << "Коли хочешь свой матрицу пиши 1. Иначе пиши 0" << endl;
			cin >> a;
			if (a == 0) MatrixBaseInit();
			if (a == 1) MatrixCustomInit();
			Menu();
		}
		else if (c == 3) exit(0);
		else if (c == 4) MatrixOutput();
	}
	return 0;
}
