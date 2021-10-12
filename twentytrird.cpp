#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

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
