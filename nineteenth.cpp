#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> mass;

// Доп. Функции

void MassBaseInit() {
    mass.push_back(2);
    mass.push_back(1);
    mass.push_back(9);
    mass.push_back(5);
    mass.push_back(-12);
    mass.push_back(2);
}

void MassCustomInit() {
    int N, p;
    cout << "Input lengh of array" << endl;
    cin >> N;
    cout << "Input elements of array" << endl;
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

// 19 Лаба

char Lab19_First()
{
    vector <int> arr;
    for (int i = 0; i < mass.size() - 1; i++) {
        if (mass[i] == mass[i + 1]) {
            mass.erase(mass.begin() + i);
            i--;
        }
    }
    MassOutput();

    return ' ';
}

char Lab19_Second()
{
    vector <int> arr;
    for (int i = 0; i < mass.size(); i++) {
        if (count(mass.begin(), mass.end(), mass[i]) == 2) {
            int k = mass[i];
            mass.erase(find(mass.begin() + i + 1, mass.end(), k));
            mass.erase(mass.begin() + i);
            i--;
        }
    }
    cout << mass.size() << endl;
    MassOutput();

    return ' ';
}

char Lab19_Third()
{
    int a = distance(mass.begin(), max_element(mass.begin(), mass.end()));
    int b = distance(mass.begin(), min_element(mass.begin(), mass.end()));
    mass.insert(mass.begin() + a + 1, 0);
    mass.insert(mass.begin() + b, 0);
    MassOutput();
    return ' ';
}

char Lab19_Fourth()
{
    for (int i = 0; i < mass.size(); i++) {
        if (mass[i] < 0) {
            mass.insert(mass.begin() + i + 1, 0);
        }
    }
    MassOutput();
    return ' ';
}

char Lab19_Fifth()
{
    for (int i = 0; i < mass.size(); i++) {
        if (mass[i] > 0) {
            mass.insert(mass.begin() + i, 0);
            i++;
        }
    }
    MassOutput();
    return ' ';
}

void Menu() {
    int c;
    cout << "Input number of question (1-5)";
    cin >> c;
    if (c == 1) cout << Lab19_First();
    else if (c == 2) cout << Lab19_Second();
    else if (c == 3) cout << Lab19_Third();
    else if (c == 4) cout << Lab19_Fourth();
    else if (c == 5) cout << Lab19_Fifth();
}

int main()
{
    int c,a;
    cout << "If you want custom array - write 1. else write 0" << endl;
    cin >> c;
    if(c == 0) MassBaseInit();
    if(c == 1) MassCustomInit();
    Menu();
    while (true) {
        cout << endl << endl << "If you want switch question - write 1" << endl << "If you want switch array and switch quesion - write 2" << endl << "If you want end this - write 3" << endl;
        cout <<"If you want watch array - write 4" << endl << "Remember array can be changed after question" << endl;
        cin >> c;
        if (c == 1) Menu();
        else if (c == 2) {
            cout << "If you want custom array - write 1. else write 0" << endl;
            cin >> a;
            if (a == 0) MassBaseInit();
            if (a == 1) MassCustomInit();
            Menu();
        }
        else if (c == 3) break;
        else if (c == 4) MassOutput();
    }
    
    
    return 0;
}
