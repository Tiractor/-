#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector <int> mass;

char Lab24_First()
{
	setlocale(LC_ALL, "Russian");
	int z = 0;
	string x = "А я Олег любит пить  пиво";
	for (int i = 0; i < x.size(); ++i) {
		if (x[i + 1] == ' ' || i + 1 == x.size()) {
		
			if (int(x[i]) <= -1 && int(x[i]) >= -64) ++z;
		}
	}
	cout << z;
	return ' ';
}

char Lab24_Second()
{
	setlocale(LC_ALL, "Russian");
	int z = 0;
	string x = "А я Олег любит пить  пиво";
	for (int i = 0; i < x.size(); ++i) {
		if (x[i + 1] == ' ' || i + 1 == x.size()) {
			for (int j = i; j > 0; --j) {
				
				if (int(x[j]) <= -1 && int(x[j]) >= -64) ++z;
				else if (j == i) break;
				else {
					mass.push_back(z);
					z = 0;
					break;
				}
			}
		}
	}
	int q = distance(mass.begin(), min_element(mass.begin(), mass.end()));
	cout << mass[q];
	return ' ';
}

char Lab24_Third()
{
	setlocale(LC_ALL, "Russian");
	string x = "А я ОлОегО любит пить  пиво";
	char y = ' ';
	for (int i = 0; i < x.size(); ++i) {
		if (x[i] == ' ') {
			y = ' ';
		}
		else if (y != ' ' && y == x[i]) {
			x[i] = '.';
		}
		else if (y == ' '){
			y = x[i];
		}
	}
	cout << x;
	return ' ';
}

char Lab24_Fourth()
{
	setlocale(LC_ALL, "Russian");
	string x = "А я ОлОегО любит пить  пиво";
	int y = 0;
	for (int i = 0; i < x.size(); ++i) {
		if (x[i] == 'у' || x[i] == 'е' || x[i] == 'а' || x[i] == 'о' || x[i] == 'э' || x[i] == 'я' || x[i] == 'и' || x[i] == 'ю') {
			y++;
		}
		else if (x[i] == 'У' || x[i] == 'Е' || x[i] == 'А' || x[i] == 'О' || x[i] == 'Э' || x[i] == 'Я' || x[i] == 'И' || x[i] == 'Ю') {
			y++;
		}
	}
	cout << y;
	return ' ';
}

char Lab24_Fifth()
{
	setlocale(LC_ALL, "Russian");
	string x;
	cin >> x;
	string y;
	bool flag= false;
	for (int i = x.size()-2; i > 0; --i) {
		if (flag) {
			if(x[i] == 92) break;
			y.insert(y.begin() + 0, x[i]);
		}
		else if (x[i] == '.') flag = true;
	}
	cout << y;
	return ' ';
}

char Lab24_Sixth()
{
	setlocale(LC_ALL, "Russian");
	string x;
	cin >> x;
	string y;
	bool flag = false;
	bool Sflag = false;
	for (int i = x.size() - 2; i > 0; --i) {
		if (flag) {
			if (x[i] == 92 and Sflag) break;
			if (Sflag) y.insert(y.begin() + 0, x[i]);
			if (x[i] == 92) Sflag = true;
		}
		else if (x[i] == '.') flag = true;
	}
	if (y == ":" || y == "") cout << char(92);
	else cout << y;
	return ' ';
}

char Lab24_Seventh()
{
	setlocale(LC_ALL, "Russian");
	string x = "Программа";
	string a,b;
	for (int i = 0; i < x.size(); ++i) {
		if ((i + 1) % 2 == 0) a.push_back(x[i]);
		else b.push_back(x[i]);
	}
	reverse(b.begin(), b.end());
	cout << a << b;
	return ' ';
}

int main()
{
	cout << Lab24_Seventh();
	return 0;
}